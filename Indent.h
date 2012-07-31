
#ifndef INDENT_H
#define INDENT_H

#include <string>

namespace Bencoding
{
    class Indent
    {
    public:
        static std::string indent();
        static void increase();
        static void decrease();

    private:
        static unsigned level;
    };
}

#endif
