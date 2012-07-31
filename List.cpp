
#include <sstream>
#include <iostream>

#include "List.h"
#include "Exception.h"
#include "Indent.h"

Bencoding::Type Bencoding::List::getType()
{
    return LIST;
}

boost::shared_ptr<Bencoding::Element> Bencoding::List::factory(const char* const buffer, unsigned& offset)
{
    return boost::shared_ptr<Bencoding::Element>(new Bencoding::List(buffer, offset));
}


Bencoding::List::List(const char* const buffer, unsigned& offset)
{
    if (buffer[offset] != 'l')
    {
        throw Exception("Expected 'l' in list", offset);
    }
    offset++;

    while (buffer[offset] != 'e')
    {
        boost::shared_ptr<Bencoding::Element> e = Bencoding::Element::factory(buffer, offset);
        list.push_back(e);
    }
    offset++;
}


std::ostream& operator<< (std::ostream& aStream, boost::shared_ptr<Bencoding::List> list)
{
    aStream << Bencoding::Indent::indent() << "List:" << std::endl;
    Bencoding::Indent::increase();
    std::list<boost::shared_ptr<Bencoding::Element> > l = list->getList();
    std::list<boost::shared_ptr<Bencoding::Element> >::iterator iter;
    for (iter = l.begin(); iter != l.end(); iter++)
    {
        aStream << *iter;
    }
    Bencoding::Indent::decrease();
    return aStream;
}
