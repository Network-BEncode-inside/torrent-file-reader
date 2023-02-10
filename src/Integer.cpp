
#include "Integer.h"
#include "Exception.h"
#include "Indent.h"

Bencoding::Type Bencoding::Integer::getType()
{
    return INTEGER;
}

boost::shared_ptr<Bencoding::Element> Bencoding::Integer::factory(const char* const buffer, unsigned& offset)
{
    return boost::shared_ptr<Bencoding::Element>(new Bencoding::Integer(buffer, offset));
}


Bencoding::Integer::Integer(const char* const buffer, unsigned& offset)
{
    if (buffer[offset] != 'i')
    {
        throw Exception("Expected 'i' in integer", offset);
    }
    offset++;

    value = intValue(buffer, offset);

    if (buffer[offset] != 'e')
    {
        throw Exception("Expected 'e' in integer", offset);
    }
    offset++;
}


std::ostream& operator<< (std::ostream& aStream, boost::shared_ptr<Bencoding::Integer> integer)
{
    aStream << Bencoding::Indent::indent() << integer->getValue();
    return aStream;
}
