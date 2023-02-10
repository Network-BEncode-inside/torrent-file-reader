
#ifndef INTEGER_H
#define INTEGER_H

#include "Element.h"

namespace Bencoding
{
class Integer : public Element
{
public:
    static boost::shared_ptr<Element> factory(const char* const buffer, unsigned& offset);
    virtual Type getType();
    const int getValue()
    {
        return value;
    }

private:
    Integer(const char* const buffer, unsigned& offset);

    int value;
};
}

std::ostream& operator<< (std::ostream& aStream, boost::shared_ptr<Bencoding::Integer> integer);

#endif
