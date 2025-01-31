
char * axpyfunc = "
void axpy_kernel(size_t n, double a, const double *x, double *y) {
    if (n == 0 || x == nullptr || y == nullptr) {
        throw std::invalid_argument("Invalid input: size must be greater than 0 and pointers must not be null.");
    }

    for (size_t i = 0; i < n; ++i) {
        y[i] = a * x[i] + y[i];
    }
}
";

//Call LLM to generate doxygen doc for the function provided in the axpyfunc string. 
int main (int argc, char * argv[]) {


}




