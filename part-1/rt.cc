
/// \file

#include <Magick++.h>

#include <cassert>
#include <chrono>
#include <iostream>
#include <string>
#include <vector>

#include "rng.h"

using namespace std;
using namespace Magick;

/// Check to see if \p filename ends with the extension \p extension.
/// \param filename A string that represents a file name
/// \param extension An extension such as ".txt" or ".gif"
/// \returns True if \p filename ends with \p extension, False otherwise
bool HasFileExtension(const string& filename, const string& extension) {
  return filename.size() >= extension.size() &&
         filename.compare(filename.size() - extension.size(), extension.size(),
                          extension) == 0;
}

/// Return a True or False depending on a random value.
/// Generates a random number and then decides to return True or False
bool CoinFlip() { return RandomDouble_11() > 0.0; }
/// Main function - Entry point for our ray tracer
/// The program takes two arguments which is the output file name and a
/// a brief message. The image generated by the main function is written
/// out as a GIF file.
int main(int argc, char const* argv[]) {
  InitializeMagick(*argv);
  // TODO: Process the command line arguemnts. Save args.at(1) to 
  // output_file_name and args.at(2) to message.
  string output_file_name;
  string message;

  // Check to make sure the user specified a GIF/gif file.
  if (not HasFileExtension(output_file_name, ".gif") &&
      not HasFileExtension(output_file_name, ".GIF")) {
    cout << "Please provide an output file name that ends in '.gif' or '.GIF'. "
            "Exiting.\n";
    exit(1);
  }

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

  // TODO: Define a const int named kNumberOfImages and assign it 10.

  // This vector will store each frame of our animated GIF.
  vector<Image> images;

  // Save the starting time so the elapsed time can
  // be calculated.
  chrono::time_point<chrono::high_resolution_clock> start =
      chrono::high_resolution_clock::now();

  // TODO: Write a triply nested for loop.
  //  - The outer most loop is the loop that controls how many images are
  //    created.
  //  - The middle loop is for each column in the image
  //  - The inner most loop is for each row in the image

  // Use this at the top of your inner most for loop to help catch errors.
  // This is a way to make sure you don't accidentally have the wrong
  // logic in your for loops. What an assertion does is it says this must
  // be true and if it isn't then the program is going to halt with an
  // error message. If your program halts, then you know you have
  // something wrong with your for loop counters.
  // assert(row < image.rows());
  // assert(column < image.columns());


  // The random_value is the intensity of the color at the
  // current pixel. Flip a coin to decide which channel is active.
  // It could be zero, one, two, or three channels that are assigned
  // random_value.
  double random_color_intensity = RandomDouble_01();
  double red = 0.0;
  double green = 0.0;
  double blue = 0.0;

  // TODO: Following the guidance from the README, determine what value
  // to assign red, green, and blue using the CoinFlip() function.

  // TODO: Create a new ColorRGB variable named pixel_color and construct it
  // with the values from red, green, and blue.

  // It may help you to debug what you are doing by printing
  // each pixel out. Remember you can always resize the image to be
  // something smaller by changing kImageWidth and recompiling.
  // Remember column is the x direction and row is the y direction.
  // cout << column << ":" << row << " " << pixel_color << "\n";

  // TODO: Set the color for pixel(row, column) to the calculated color,
  // for example: image.pixelColor(column, row, pixel_color);

  // TODO: Add this code to the end of the outermost for loop to add text
  // to the generated image and to add the image into our vector of images.
  // Let's write some text into the center of the image. This requires
  // Ghostscript which should already be installed on your computer.
  // image.font("Helvetica");
  // image.fontPointsize(72);
  // image.fillColor(Color("yellow"));
  // image.annotate(message, CenterGravity);
  //
  // images.push_back(image);

  // Our work is done, save the ending time
  chrono::time_point<chrono::high_resolution_clock> end =
      chrono::high_resolution_clock::now();

  // TODO: Write the images to an output file, for example
  // writeImages(images.begin(), images.end(), output_file_name);

  // Calculate the elapsed time by taking the difference between end
  // and start.
  chrono::duration<double> elapsed_seconds = end - start;

  // Display the elapsed number of seconds.
  cout << "Time elapsed: " << elapsed_seconds.count() << " seconds.\n";

  return 0;
}
