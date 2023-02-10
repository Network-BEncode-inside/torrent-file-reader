
#ifndef STRING_H
#define STRING_H

#include "Element.h"

namespace Bencoding
{
class String : public Element
{
public:
    static boost::shared_ptr<Element> factory(const char* const buffer, unsigned& offset);

    virtual ~String();
    virtual Type getType();
    const char* const getValue()
    {
        return value;
    }

private:
    String(const char* const buffer, unsigned& offset);

    char* value;
    int length;
};
}

std::ostream& operator<< (std::ostream& aStream, boost::shared_ptr<Bencoding::String> string);

#endif
