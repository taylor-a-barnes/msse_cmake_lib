# Creating a CMake Library

In `src/main.cpp`, you will find a code that initializes two vectors (`vector1` and `vector2`) with some values.
It then computes the dot product between the two vectors and prints the result.

You will use CMake to compile the code, and will provide a configuration option to use either the BLAS library or the Eigen library for evaluating the dot product.

## Tasks

1. Create a `CMakeLists.txt` file that enables this code to be compiled using CMake.
2. Modify the code so that rather than manually computing the dot product with a `for` loop, you instead use the `cblas_ddot` function from BLAS. Modify your `CMakeLists.txt` so that the code can be compiled properly with the BLAS dependency. Information about using BLAS in CMake is available [here](https://cmake.org/cmake/help/latest/module/FindBLAS.html).
3. Add a CMake configuration option to allow the user to select whether to use BLAS or Eigen.  If the user selects BLAS, your code should use the `cblas_ddot` function. If the user selects Eigen, your code should instead use the vector dot product tools available in Eigen (see [here](https://eigen.tuxfamily.org/dox/group__TutorialMatrixArithmetic.html) for information). Ensure that when the user configures the code to use BLAS, it **only** links against BLAS, and when the user configures the code to use Eigen, it **only** links against Eigen. If the user does not indicate which library to use, the CMake configuration process should link against one of the libraries as the default, and fall back to the other if the default library is not found (if neither is found, the configuration process should terminate with an error). Instructions for using Eigen in CMake are available [here](https://eigen.tuxfamily.org/dox/TopicCMakeGuide.html).

Hint: To convert from an `std::vector<double>` called `std_vector` to an Eigen3 vector called `eigen_vector`, you can do:
```
Eigen::Map<Eigen::VectorXd> eigen_vector(std_vector.data(), std_vector.size());
```

4. Create a GitHub Actions job that links your code against BLAS and runs the code.  You can run this calculation within a Docker container or directly on the GitHub runner (your choice).
5. Create another GitHub Actions job that links your code against Eigen and runs the code.  You can run this calculation within a Docker container or directly on the GitHub runner (your choice).
