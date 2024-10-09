# Creating a CMake Library

In the previous Problem Set, you wrote a simple C++ code that could be compiled to use either the BLAS or Eigen library to compute the dot product of two vectors.  In this problem, you will implement the same functionality in a library.  You may use Docker to assist in any of the following steps, but use of Docker is not required for this problem.

1. Create a library that implements a function called `dot_wrapper`, which computes and returns the dot product of two vectors.  The function should have the following interface:

```
double dot_wrapper(std::vector<double>& vector1, 
                   std::vector<double>& vector2);
```

The library must support CMake compilation, and must support a configuration option to allow users to either compile the library against BLAS, or to compile it against Eigen.
If the library is compiled to support BLAS, it should not link against Eigen, and vice versa.
If the user does not indicate which library to use, the CMake configuration process should link against one of the libraries as the default, and fall back to the other if the default library is not found (if neither is found, the configuration process should terminate with an error).
The `dot_wrapper` function should use the user-selected library to compute and return the dot product of the two vectors.
You should place all of your library code and CMake files in the `library` subdirectory of this repository.

2. Ensure that your library can be installed as a CMake package by creating a suitable `<library_name>Config.cmake.in` file and making any necessary modifications to the `CMakeLists.txt` file.
Consumers should be able to incorporate your library into their build process with the following lines of CMake:

```
           find_package(<library_name> 1.0 REQUIRED)
           target_link_libraries(<consumer_name> <library_name>::<library_name>)
```

3. There is code in the `executable` subdirectory that performs a dot product of two vectors manually.
Modify the code in the `executable` subdirectory so that it instead uses your library.
The executable should compile with CMake, and its `CMakeLists.txt` should not link against BLAS or Eigen explicitly.

Hint: If you get errors during either the CMake configure process or the compile process for the executable, it may be due to a problem with your library’s CMake files.
Look carefully at how your library links against BLAS / Eigen.

4. This repository currently includes a GitHub Action workflow that builds and executes the executable in the `executable` subdirectory.
Modify this workflow so that it also builds your library, and so that the executable builds and runs properly.
Create a matrix of variations of this job in which you vary whether the library is compiled to use BLAS or Eigen, as well as whether the library is compiled as a shared library or a static library (this should result in a total of four variations).


## Hints

You may re-use any code you created in previous problem sets.
You may also use the following code to assist in creating your `dot_wrapper` function:

```
double dot_wrapper(std::vector<double>& vector1, 
                   std::vector<double>& vector2) {

    // BLAS version
#if _USE_BLAS
    return cblas_ddot(vector1.size(), vector1.data(), 1, vector2.data(), 1);
#endif

    // Eigen version
#if _USE_Eigen
    Eigen::Map<Eigen::VectorXd> eigen_vector1(vector1.data(), vector1.size());
    Eigen::Map<Eigen::VectorXd> eigen_vector2(vector2.data(), vector2.size());
    return eigen_vector1.dot(eigen_vector2);
#endif
}
```

If something goes wrong during the compile process, remember the tools we discussed for examining files (for example, `nm` and `readelf`).