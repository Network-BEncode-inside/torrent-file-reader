
#include <string>
#include <iostream>
#include <stdlib.h>
#include <sstream>
#include <string.h>

#include "String.h"
#include "Exception.h"
#include "Indent.h"

Bencoding::Type Bencoding::String::getType()
{
    return STRING;
}

boost::shared_ptr<Bencoding::Element> Bencoding::String::factory(const char* const buffer, unsigned& offset)
{
    unsigned startingOffset = offset;
    return boost::shared_ptr<Bencoding::Element>(new Bencoding::String(buffer, offset));
}

Bencoding::String::~String()
{
    if (value != 0)
    {
        delete[] value;
    }
}

Bencoding::String::String(const char* const buffer, unsigned& offset) : value(0)
{
    length = intValue(buffer, offset);

    if (length <= 0)
    {
        throw Exception("Expected positive integer for length in string", offset);
    }

    if (buffer[offset] != ':')
    {
        throw Exception("Expected ':' in string", offset);
    }
    offset++;

    value = new char[length];
    memcpy(value, buffer+offset, length);
    offset += length;
}


std::ostream& operator<< (std::ostream& aStream, boost::shared_ptr<Bencoding::String> string)
{
    aStream << Bencoding::Indent::indent() << string->getValue();
    return aStream;
}
