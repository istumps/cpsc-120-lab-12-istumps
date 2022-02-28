# Rendering the Sky


## Requirements

Complete the program such that it creates an output image file of an imaginary sky. Select appropriate values for `sky_bottom` and `sky_top`.

Complete any `TODO` comments found in the project.

Close any file streams that you open and report any errors encountered.

To compile your program, you use the `make` command. A Makefile is provided for this exercise.

The Makefile has the following targets:
  
* all: builds the project
* clean: removes object and dependency files
* spotless: removes everything the clean target removes and all binaries
* format: outputs a [`diff`](https://en.wikipedia.org/wiki/Diff) showing where your formatting differes from the [Google C++ style guide](https://google.github.io/styleguide/cppguide.html)
* lint: output of the [linter](https://en.wikipedia.org/wiki/Lint_(software)) to give you tips on how to improve your code
* header: check to make sure your files have the appropriate header
* test: run tests to help you verify your program is meeting the assignment's requirements. This does not grade your assignment.
* unittest: run unit tests to verify parts of your program performs according to the instructor supplied unit tests.

## Inline Documentation
The project is thoroughly documented inline using the [Doxygen](https://en.wikipedia.org/wiki/Doxygen) format. The documentation establishes a framework for you to follow so that you can implement all the details of the program. To generate HTML formatted documents to view on your computer use the make target `doc`.

The inline documentation is saved in `doc/html`. To view the documentation, use the command `gio open doc/html/index.html` which will open the index file in your web browser.

Then you can install `doxygen` using the command `sudo apt install doxygen doxygen-latex graphviz`.

## Don't Forget

Please remember that:

- You need to put a header in every file.
- You need to follow the [Google C++ Style Guide](https://google.github.io/styleguide/cppguide.html).
- Remove the `TODO` comments.

## Testing Your Code

Computers only ever do exactly what they are told, exactly the way they are told it, and never anything else. Testing is an important process to writing a program. You need to test for the program to behave correctly and test that the program behaves incorrectly in a predictable way.

As programmers we have to remember that there are a lot of ways that we can write the wrong program and only one to a few ways to write the correct program. We have to be aware of [cognitive biases](https://en.wikipedia.org/wiki/List_of_cognitive_biases) that we may exercise that lead us to believe we have correctly completed our program. That belief may be incorrect and our software may have errors. [Errors in software](https://www.wired.com/2005/11/historys-worst-software-bugs/) may lead to loss of [life](https://www.nytimes.com/2019/03/14/business/boeing-737-software-update.html), [property](https://en.wikipedia.org/wiki/Mariner_1), [reputation](https://en.wikipedia.org/wiki/Pentium_FDIV_bug), or [all of the above](https://en.wikipedia.org/wiki/2009%E2%80%9311_Toyota_vehicle_recalls).

### Test strategy

Start simple, and work your way up. Good tests are specific, cover a broad range of fundamentally different possibilities, can identify issues quickly, easily, and directly, without need for much set up, and can almost be diagnosed by inspection if the code fails to execute the test correctly.

## Example Output

Please ensure your program's output is identical to the example below.

```
$ make unittest
set -e; clang++ -MM -g -O3 -Wall -pipe -std=c++17  -D LINUX -I/usr/include/GraphicsMagick -D AMD64 utilities.cc \
| sed 's/\(utilities\)\.o[ :]*/\1.o utilities.d : /g' > utilities.d; \
[ -s utilities.d ] || rm -f utilities.d
set -e; clang++ -MM -g -O3 -Wall -pipe -std=c++17  -D LINUX -I/usr/include/GraphicsMagick -D AMD64 vec3.cc \
| sed 's/\(vec3\)\.o[ :]*/\1.o vec3.d : /g' > vec3.d; \
[ -s vec3.d ] || rm -f vec3.d
set -e; clang++ -MM -g -O3 -Wall -pipe -std=c++17  -D LINUX -I/usr/include/GraphicsMagick -D AMD64 rt.cc \
| sed 's/\(rt\)\.o[ :]*/\1.o rt.d : /g' > rt.d; \
[ -s rt.d ] || rm -f rt.d
set -e; clang++ -MM -g -O3 -Wall -pipe -std=c++17  -D LINUX -I/usr/include/GraphicsMagick -D AMD64 rng.cc \
| sed 's/\(rng\)\.o[ :]*/\1.o rng.d : /g' > rng.d; \
[ -s rng.d ] || rm -f rng.d
set -e; clang++ -MM -g -O3 -Wall -pipe -std=c++17  -D LINUX -I/usr/include/GraphicsMagick -D AMD64 ray.cc \
| sed 's/\(ray\)\.o[ :]*/\1.o ray.d : /g' > ray.d; \
[ -s ray.d ] || rm -f ray.d
rm: cannot remove 'unittest': No such file or directory
make: [Makefile:132: cleanunittest] Error 1 (ignored)
rm: cannot remove '*_unittest.o': No such file or directory
make: [Makefile:133: cleanunittest] Error 1 (ignored)
clang++ -g -O3 -Wall -pipe -std=c++17  -D LINUX -I/usr/include/GraphicsMagick -D AMD64 -c vec3.cc
clang++ -g -O3 -Wall -pipe -std=c++17  -D LINUX -I/usr/include/GraphicsMagick -D AMD64 -c vec3_unittest.cc
clang++ -g -O3 -Wall -pipe -std=c++17  -D LINUX -I/usr/include/GraphicsMagick -D AMD64 -c ray.cc
clang++ -g -O3 -Wall -pipe -std=c++17  -D LINUX -I/usr/include/GraphicsMagick -D AMD64 -c ray_unittest.cc
clang++ "" -g -O3 -Wall -pipe -std=c++17 -lGraphicsMagick++ -o unittest vec3.o vec3_unittest.o ray.o ray_unittest.o -lgtest -lgtest_main -lpthread
./unittest
Running main() from /build/googletest-j5yxiC/googletest-1.10.0/googletest/src/gtest_main.cc
[==========] Running 23 tests from 2 test suites.
[----------] Global test environment set-up.
[----------] 19 tests from Vec3Test
[ RUN      ] Vec3Test.GetX
[       OK ] Vec3Test.GetX (0 ms)
[ RUN      ] Vec3Test.GetY
[       OK ] Vec3Test.GetY (0 ms)
[ RUN      ] Vec3Test.GetZ
[       OK ] Vec3Test.GetZ (0 ms)
[ RUN      ] Vec3Test.UnaryMinus
[       OK ] Vec3Test.UnaryMinus (0 ms)
[ RUN      ] Vec3Test.Size
[       OK ] Vec3Test.Size (0 ms)
[ RUN      ] Vec3Test.SubscriptOperator
[       OK ] Vec3Test.SubscriptOperator (0 ms)
[ RUN      ] Vec3Test.Length
[       OK ] Vec3Test.Length (0 ms)
[ RUN      ] Vec3Test.LengthSquared
[       OK ] Vec3Test.LengthSquared (0 ms)
[ RUN      ] Vec3Test.PlusOperator
[       OK ] Vec3Test.PlusOperator (0 ms)
[ RUN      ] Vec3Test.MinusOperator
[       OK ] Vec3Test.MinusOperator (0 ms)
[ RUN      ] Vec3Test.MultiplicationOperator
[       OK ] Vec3Test.MultiplicationOperator (0 ms)
[ RUN      ] Vec3Test.DivisionOperator
[       OK ] Vec3Test.DivisionOperator (0 ms)
[ RUN      ] Vec3Test.Equality
[       OK ] Vec3Test.Equality (0 ms)
[ RUN      ] Vec3Test.Inequality
[       OK ] Vec3Test.Inequality (0 ms)
[ RUN      ] Vec3Test.Dot
[       OK ] Vec3Test.Dot (0 ms)
[ RUN      ] Vec3Test.Cross
[       OK ] Vec3Test.Cross (0 ms)
[ RUN      ] Vec3Test.UnitVector
[       OK ] Vec3Test.UnitVector (0 ms)
[ RUN      ] Vec3Test.Reflect
[       OK ] Vec3Test.Reflect (0 ms)
[ RUN      ] Vec3Test.StreamInsertionOperator
[       OK ] Vec3Test.StreamInsertionOperator (0 ms)
[----------] 19 tests from Vec3Test (0 ms total)

[----------] 4 tests from RayTest
[ RUN      ] RayTest.GetOrigin
[       OK ] RayTest.GetOrigin (0 ms)
[ RUN      ] RayTest.GetDirection
[       OK ] RayTest.GetDirection (0 ms)
[ RUN      ] RayTest.At
[       OK ] RayTest.At (0 ms)
[ RUN      ] RayTest.StreamInsertionOperator
[       OK ] RayTest.StreamInsertionOperator (0 ms)
[----------] 4 tests from RayTest (0 ms total)

[----------] Global test environment tear-down
[==========] 23 tests from 2 test suites ran. (1 ms total)
[  PASSED  ] 23 tests.
$ make
clang++ -g -O3 -Wall -pipe -std=c++17  -D LINUX -I/usr/include/GraphicsMagick -D AMD64 -c rng.cc
clang++ -g -O3 -Wall -pipe -std=c++17  -D LINUX -I/usr/include/GraphicsMagick -D AMD64 -c rt.cc
clang++ -g -O3 -Wall -pipe -std=c++17  -D LINUX -I/usr/include/GraphicsMagick -D AMD64 -c utilities.cc
clang++ -g -O3 -Wall -pipe -std=c++17 -lGraphicsMagick++ -o rt ray.o rng.o rt.o vec3.o utilities.o 
$ ./rt
Please provide a path to a file.
$ ./rt blue_sky.png
Your image has 512 columns (x direction) and 288 rows (y direction).
Time elapsed: 0.0911893 seconds.
```
