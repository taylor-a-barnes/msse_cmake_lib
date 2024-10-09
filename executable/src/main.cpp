#include <iostream>
#include <vector>
#include <memory>

int main(int argc, char* argv[]) {

    std::vector<double> vector1 = {3.1, 8.06, 1.4, 4.3};
    std::vector<double> vector2 = {2.9, 0.9, 3.38, 4.0};

    // Compute the dot product between the two vectors
    // NOTE: You will need to replace this with a call to your library
    double result = 0.0;
    for (int index = 0; index < vector1.size(); index++) {
      result += vector1[index] * vector2[index];
    }

    // Print the result
    std::cout << "Result: " << result << std::endl;

    return 0;
}
