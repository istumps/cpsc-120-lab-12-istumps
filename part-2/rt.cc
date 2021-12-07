// Isaac Stumps
// CPSC 120-18
// 2021-12-6
// istumps@csu.fullerton.edu
// @istumps
//
// Lab 12-02
//
// Program to make a dynamic image using vectors
//
/// \file

#include <Magick++.h>

#include <cassert>
#include <chrono>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

#include "ray.h"
#include "rng.h"
#include "utilities.h"
#include "vec3.h"

using namespace std;
using namespace Magick;

/// RayColor computes the color the ray \p r sees through the camera lens.
/// Given a Ray \p r, calculate the color that is visible to the ray.
/// In this iteration, the ray can only see the sky. The color of the sky
/// smoothly changes between the \c sky_top color and the \c sky_bttom color.
/// As the names suggest, \c sky_top is the color of the sky at the top of
/// the image and \c sky_bottom is the color of the sky at the bottom of
/// the image.
///
/// \param r A ray eminating from the camera through the scene
/// \returns The color visible from that ray
ColorRGB RayColor(const Ray &r) {
  // Greenish brown
  ColorRGB sky_top(.5, .4, 0);
  // Bluish purple
  ColorRGB sky_bottom(.2, .1, .5);
  Vec3 unit_direction = UnitVector(r.direction());
  double t = 0.5 * (unit_direction.y() + 1.0);
  ColorRGB c = (1.0 - t) * sky_top + t * sky_bottom;

  return c;
}

/// Main function - Entry point for our ray tracer
/// The program takes one argument which is the output file name. Specify a
/// filename with an ending the GraphicsMagick knows how to write out as an
/// image file such as png, jpg, jpeg, gif, etc.
int main(int argc, char const *argv[]) {
  InitializeMagick(*argv);
  vector<string> args = vector<string>(argv, argv + argc);
  string output_file_name;
  try {
    output_file_name = (args.at(1));
  } catch (exception const &problem) {
    cout << "Ran into problem getting the arguments. \n";
    cout << problem.what() << "\n";
    return 1;
  }
  /// Image definition in main
  /// The image is the output from the virtual camera. The image is what
  /// you will see when you open the output in an image viewer. The image's
  /// dimensions are specified in pixels and are therefore in integer units.
  /// The aspect ratio represents the ratio of width / height. The ratio
  /// 16:9 is the ratio used for wide format movies. Traditional 35mm film
  /// photographs have an image that is 36 mm x 24 mm which has an aspect
  /// ratio of 36:24 or 1.5.
  const double kAspectRatio = 16.0 / 9.0;
  // Set the image width to 400 pixels
  const int kImageWidth = 512;
  // Calculate the height of the image using the width and aspect ratio.
  // Remember to round the number to the closest integer.
  const int kImageHeight = int(lround(kImageWidth / kAspectRatio));
  // Create a new Image object using the file name provided on the
  // command line.
  ColorRGB yellow(1, 1, 0);
  // Create a yellow image the size that we'd like. Use yellow or some
  // obviously wrong color (a color not in our image)to help us debug
  // our output.
  Image image(Geometry(kImageWidth, kImageHeight), yellow);
  // Print out some information about the image to help us debug what's
  // going on.
  cout << "Your image has " << image.columns() << " columns (x direction) and "
       << image.rows() << " rows (y direction).\n";

  /// Camera definition in main
  /// The [viewport](https://en.wikipedia.org/wiki/Viewport) is the
  /// rectangular viewing region visible to the camera. You can think of it
  /// as the dimensions of the camera's film or sensor. The coordinates
  /// are specfied in floating point units (doubles). Unlike an image which
  /// has its dimensions expressed as pixels, the camera's viewport dimensions
  /// can be expressed in whatever units you would like to use. Since we are
  /// creating a make believe image of make believe things, you can imagine
  /// the size of the objects to be as small (millimeters) or as large
  /// (kilometers) as you like.
  // The height of the viewport
  const double kViewportHeight = 2.0;
  // The width of the viewport is calculated using the height and the
  // previously defined aspect ratio.
  const double kViewportWidth = kAspectRatio * kViewportHeight;
  // The focal length is the distance between the projection plane (the end
  // of the lens) and the projection point (the inside of the camera).
  const double kFocalLength = 1.0;
  // The origin is as we expect. Everything in our world will be measured
  // from the center of the camera.
  const Point3 kOrigin{0, 0, 0};
  // Create a vector that represents the horizontal direction with respect
  // to the viewport.
  const Vec3 kHorizontal{kViewportWidth, 0, 0};
  // Create a vecotr that represents the vertical direction with respect
  // to the viewport
  const Vec3 kVertical{0, kViewportHeight, 0};
  // Calculate a vector that starts at the origin and points to the lower
  // left hand corner of the viewport. We will use this when we generate
  // all the rays that emanate out from the viewplane.
  const Vec3 kLowerLeftCorner =
      kOrigin - kHorizontal / 2 - kVertical / 2 - Vec3(0, 0, kFocalLength);

  /// Rendering the image in main
  /// Using nested loops, start from the top row of the viewplane and
  /// calculate the color for each pixel in each column of the image.
  /// The image (the output file) is the result of this calculation so
  /// keep in mind that each ray that is created maps onto a pixel in the
  /// image.
  // Save the starting time so the elapsed time can
  // be calculated.
  chrono::time_point<chrono::high_resolution_clock> start =
      chrono::high_resolution_clock::now();

  for (int column = 0; column < image.columns(); column++) {
    for (int row = 0; row < image.rows(); row++) {
      assert(row < image.rows());
      assert(column < image.columns());
      double u = NAN;
      u = double(column) / image.columns() - 1;
      double v = NAN;
      v = double(row) / image.rows() - 1;
      Ray r(kOrigin,
            kLowerLeftCorner + u * kHorizontal + v * kVertical - kOrigin);
      ColorRGB pixel_color;
      pixel_color = RayColor(r);
      image.pixelColor(column, row, pixel_color);
    }
  }

  chrono::time_point<chrono::high_resolution_clock> end =
      chrono::high_resolution_clock::now();

  image.write(output_file_name);
  // Calculate the elapsed time by taking the difference between end
  // and start.
  chrono::duration<double> elapsed_seconds = end - start;

  // Display the elapsed number of seconds.
  cout << "Time elapsed: " << elapsed_seconds.count() << " seconds.\n";

  return 0;
}
