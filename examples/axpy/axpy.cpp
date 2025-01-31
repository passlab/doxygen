/**
 * @file axpy_example.cpp
 * @brief Example implementation of the AXPY operation.
 *
 * This file demonstrates the AXPY operation (`y = a * x + y`) using a
 * kernel function and a main function to test it.
 *
 * @details
 * The AXPY operation is a common linear algebra operation, where:
 * - `a` is a scalar
 * - `x` and `y` are vectors
 * - The operation updates vector `y` as `y = a * x + y`.
 *
 * The example includes:
 * - Dynamic memory allocation for vectors.
 * - Error handling for invalid inputs.
 * - User-specified vector size via command-line argument.
 */

#include <iostream>
#include <vector>
#include <stdexcept>
#include <cstdlib> // for std::atoi

/**
 * @brief Performs the AXPY operation: `y = a * x + y`.
 *
 * This kernel function computes the AXPY operation in-place for the given
 * vectors `x` and `y`. It updates vector `y` based on the formula:
 * `y[i] = a * x[i] + y[i]` for all elements `i` in the vectors.
 *
 * @param n The number of elements in the vectors.
 * @param a The scalar multiplier.
 * @param x Pointer to the input vector `x` of size `n`.
 * @param y Pointer to the input/output vector `y` of size `n`.
 *
 * @pre
 * - `n > 0`: The size of the vectors must be greater than 0.
 * - `x` and `y` must not be null pointers.
 * - `x` and `y` must point to memory regions of at least `n` elements.
 *
 * @post
 * - Each element of `y` is updated as `y[i] = a * x[i] + y[i]`.
 * - The input vector `x` remains unchanged.
 *
 * @sideeffect
 * - The vector `y` is modified in place.
 *
 * @throws std::invalid_argument if `n` is zero or if `x` or `y` is null.
 *
 * @note The input vectors `x` and `y` must have the same length.
 * @warning Ensure `n` matches the allocated size of the vectors to avoid undefined behavior.
 */
void axpy_kernel(size_t n, double a, const double *x, double *y) {
    if (n == 0 || x == nullptr || y == nullptr) {
        throw std::invalid_argument("Invalid input: size must be greater than 0 and pointers must not be null.");
    }

    for (size_t i = 0; i < n; ++i) {
        y[i] = a * x[i] + y[i];
    }
}

/**
 * @brief Main function to demonstrate the AXPY operation with user-specified vector size.
 *
 * This function initializes two vectors and a scalar, performs the AXPY
 * operation, and displays the result. The size of the vectors is provided
 * as a command-line argument.
 *
 * @param argc The number of command-line arguments.
 * @param argv The array of command-line arguments.
 *             `argv[1]` should specify the size of the vectors.
 *
 * @return `0` on success, non-zero on failure.
 *
 * @pre
 * - `argc == 2`: Exactly one command-line argument is provided.
 * - `argv[1]` must represent a positive integer.
 *
 * @post
 * - The result of the AXPY operation is printed to the standard output.
 *
 * @sideeffect
 * - Allocates memory dynamically for vectors.
 * - Prints results to the standard output.
 *
 * @throws std::invalid_argument if the vector size is invalid.
 */
int main(int argc, char *argv[]) {
    try {
        if (argc != 2) {
            throw std::invalid_argument("Usage: ./axpy_example <vector_size>");
        }

        // Parse the vector size from the command-line argument
        int n = std::atoi(argv[1]);
        if (n <= 0) {
            throw std::invalid_argument("Vector size must be a positive integer.");
        }

        const double a = 2.5; /*< Scalar multiplier */

        // Initialize input vectors with example values
        std::vector<double> x(n, 1.0);  // Vector `x` initialized with 1.0
        std::vector<double> y(n, 2.0);  // Vector `y` initialized with 2.0

        // Display the original vectors
        std::cout << "Original vectors:\n";
        std::cout << "x = ";
        for (double val : x) std::cout << val << " ";
        std::cout << "\ny = ";
        for (double val : y) std::cout << val << " ";
        std::cout << "\n";

        // Perform the AXPY operation
        axpy_kernel(n, a, x.data(), y.data());

        // Display the result
        std::cout << "\nResult after AXPY (y = a * x + y):\n";
        std::cout << "y = ";
        for (double val : y) std::cout << val << " ";
        std::cout << "\n";
    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << "\n";
        return 1;
    }

    return 0;
}

