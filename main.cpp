// some comment

// #include is a DIRECTIVE
// referring to a dependency via <ANGLE_BRACKETS> pulls it from the
// system/implementation-defined default imports
#include <iostream>

// main functions have int types
// they return 0 if all is okay, non-zero codes for errors
// Main is called by the implementation / runtime, which is the layer
// that e.g. sets up the stack
int main() {
    // Type annotations take the form <TYPE> <VARNAME>

    // WHAT'S GOING ON HERE?
    // - "<<" is an output operator - it writes the right operand's characters onto
    //   the left operand's stream
    // - "<<" is left-associative, that is it groups the whole expression to the left
    //   as an operand, e.g. (a + b) << c, not a + (b << c).
    //   That is, it 'associates' together all the 'things' on the left.
    // - So. We write 'Hello, world!' into std::cout.
    // - This expression returns the std::cout stream.
    // - Then we write std::endl onto std::cout. Endl is called a 'manipulator' - it
    //   changes the state of the stream. Specifically, it writes a newline and flushes
    //   the buffer.
    std::cout << "Hello, World!" << std::endl;

    // "::" is a scope operator, used to fish entities from namespaces

    return 0;
}