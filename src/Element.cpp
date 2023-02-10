
#include <stdlib.h>
#include <boost/pointer_cast.hpp>

#include "Element.h"
#include "Dictionary.h"
#include "Integer.h"
#include "String.h"
#include "List.h"
#include "Exception.h"

boost::shared_ptr<Bencoding::Element> Bencoding::Element::factory(const char* const buffer, unsigned& offset)
{
    if (buffer[offset] == 'd')
    {
        return Bencoding::Dictionary::factory(buffer, offset);
    }
    if (buffer[offset] == 'i')
    {
        return Bencoding::Integer::factory(buffer, offset);
    }
    if (buffer[offset] == 'l')
    {
        return Bencoding::List::factory(buffer, offset);
    }
    return Bencoding::String::factory(buffer, offset);
}

int Bencoding::Element::intValue(const char* const buffer, unsigned& offset)
{
    std::string numberString;

    while (isdigit(buffer[offset]))
    {
        numberString += buffer[offset++];
    }
    if (numberString.length() == 0)
    {
        throw Exception("Integer value does not start with number", offset);
    }
    return atoi(numberString.c_str());
}


std::ostream& operator<< (std::ostream& aStream, boost::shared_ptr<Bencoding::Element> element)
{
    switch (element->getType())
    {
    case Bencoding::DICTIONARY:
        aStream << boost::dynamic_pointer_cast<Bencoding::Dictionary>(element);
        break;

    case Bencoding::LIST:
        aStream << boost::dynamic_pointer_cast<Bencoding::List>(element);
        break;

    case Bencoding::INTEGER:
        aStream << boost::dynamic_pointer_cast<Bencoding::Integer>(element);
        break;

    case Bencoding::STRING:
        aStream << boost::dynamic_pointer_cast<Bencoding::String>(element);
        break;
    }
    return aStream;
}
