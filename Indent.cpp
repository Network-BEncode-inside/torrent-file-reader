
#include "Indent.h"

unsigned Bencoding::Indent::level = 0;

std::string Bencoding::Indent::indent()
{
    std::string ret = "";
    for (int cnt=0; cnt<level; cnt++)
    {
        ret += ' ';
    }

    return ret;
}


void Bencoding::Indent::increase()
{
    level += 2;
}


void Bencoding::Indent::decrease()
{
    level -= 2;
    if (level < 0)
    {
        level = 0;
    }
}
