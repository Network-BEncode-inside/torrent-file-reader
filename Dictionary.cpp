
#include <iostream>
#include <boost/pointer_cast.hpp>

#include "Dictionary.h"
#include "Exception.h"
#include "Indent.h"

Bencoding::Type Bencoding::Dictionary::getType()
{
    return DICTIONARY;
}

boost::shared_ptr<Bencoding::Element> Bencoding::Dictionary::factory(const char* const buffer, unsigned& offset)
{
    return boost::shared_ptr<Element>(new Dictionary(buffer, offset));
}


Bencoding::Dictionary::Dictionary(const char* const buffer, unsigned& offset)
{
    if (buffer[offset] != 'd')
    {
        throw Exception("Dictionary does not start with 'd'", offset);
    }
    offset++;

    while (buffer[offset] != 'e')
    {
        boost::shared_ptr<String> key = boost::dynamic_pointer_cast<String>(Element::factory(buffer, offset));
        boost::shared_ptr<Element> value = Element::factory(buffer, offset);
        if (key == 0)
        {
            throw Exception("Dictionary key not a string", offset);
        }
        dict[key] = value;
    }
    offset++;
}


std::ostream& operator<< (std::ostream& aStream, boost::shared_ptr<Bencoding::Dictionary> dictionary)
{
    aStream << Bencoding::Indent::indent() << "Dictionary:" << std::endl;
    Bencoding::Indent::increase();
    std::map<boost::shared_ptr<Bencoding::String>, boost::shared_ptr<Bencoding::Element> > dict = dictionary->getMap();
    std::map<boost::shared_ptr<Bencoding::String>, boost::shared_ptr<Bencoding::Element> >::iterator iter;
    for (iter = dict.begin(); iter != dict.end(); iter++)
    {
        aStream << Bencoding::Indent::indent() << "Key:" << std::endl;
        Bencoding::Indent::increase();
        aStream << iter->first << std::endl;
        Bencoding::Indent::decrease();
        aStream << Bencoding::Indent::indent() << "Value:" << std::endl;
        Bencoding::Indent::increase();
        aStream << iter->second << std::endl;
        Bencoding::Indent::decrease();
    }
    Bencoding::Indent::decrease();
    return aStream;
}
