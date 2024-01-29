#include <iostream>

#include "umjunsik.hpp"

#ifdef DEBUG

template <typename T>
struct debug;

#else

template <typename T>
struct debug { };

#endif // DEBUG

constexpr const char umjunsik_program[] = UMJUNSIK_PROGRAM;

int main(int argc, char* argv[])
{
    std::cout << "Hello, world!" << std::endl;
    std::cout << UMJUNSIK_PROGRAM << std::endl;

    debug<umm::cstring_t<umjunsik_program>> d;

    return 0;
}
