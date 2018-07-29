// some comment

// #include is a DIRECTIVE
// referring to a dependency via <ANGLE_BRACKETS> pulls it from the
// system/implementation-defined default imports
#include <iostream>
#include <string>

// main functions have int types
// they return 0 if all is okay, non-zero codes for errors
// Main is called by the implementation / runtime, which is the layer
// that e.g. sets up the stack
// Type annotations take the form <TYPE> <VARNAME>
int main() {
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
    //   the buffer (i.e. prints).
    // * note: "::" is a scope operator, used to fish entities from namespaces
    std::cout << "Hello, World!" << std::endl;

    std::cout << "Ah! A friend. What is your name? ";
    std::string userName; // local (stack) variable
    std::cin >> userName;
    std::cout << "Greetings, " << userName << std::endl;

    // ON BUFFER FLUSHES
    // There are three main causes for a buffer flush:
    // 1. The buffer fills up - so the library flushes it automatically;
    // 2. The library might be asked to read from input;
    // 3. We explicitly tell it to do so

    std::cout << "\n*cough* Excuse me. Let's try that again.\n" << std::endl;

    // A CAVEAT ABOUT MULTIPLE << CALLS
    // In multithreaded programs, you might have multiple processes writing to the same buffer.
    // In that case, the two << calls above could be potentially split by another write.
    // In highly concurrent programs, it might be wiser to use
    //     std::cout << "Hello, world!\n" << std::flush;

    // VARIABLE INITIALISATION
    // <modifier> <type> <varname> = <initValue>
    //
    // OPERATOR OVERLOADING
    // Plus (+) is overloaded to concatenate strings
    const std::string greeting = " Greetings, " + userName + "! ";

    // A NOTE ABOUT STRING CONCATENATION
    // This won't work: "myString" + "secondString"
    // You can only concatenate std::strings, or std::strings with a string literal
    //
    // There is no operator overloading for string literals,
    // because literals are just syntactic sugar for character arrays.
    // Array vars are really just pointers for things on the heap, so adding
    // them is meaningless
    //
    // You can, however, kinda-concatenate string literals with spaces: "foo "    "bar".
    // This allows us to split very long strings over multiple lines.

    // "CONST" does pretty much what you would expect
    // Note the constructor syntax: type var(...), and method syntax: obj.fn(...)
    const std::string calloutPadding(greeting.size(), ' ');
    const std::string calloutBorder(greeting.size(), '*');

    // write out callout
    std::cout << "*" << calloutBorder  << "*" << std::endl;
    std::cout << "*" << calloutPadding << "*" << std::endl;
    std::cout << "*" << greeting       << "*" << std::endl;
    std::cout << "*" << calloutPadding << "*" << std::endl;
    std::cout << "*" << calloutBorder  << "*" << std::endl;


    return 0;
}