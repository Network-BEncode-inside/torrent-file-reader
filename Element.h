
#ifndef ELEMENT_H
#define ELEMENT_H

#include <boost/shared_ptr.hpp>

namespace Bencoding
{

    enum Type
    {
        DICTIONARY,
        LIST,
        INTEGER,
        STRING
    };

    class Element
    {
    public:
        static boost::shared_ptr<Element> factory(const char* const buffer, unsigned& offset);
        virtual Type getType() = 0;

    protected:
        int intValue(const char* const buffer, unsigned& offset);
    };

}

std::ostream& operator<< (std::ostream& aStream, boost::shared_ptr<Bencoding::Element> element);

#endif
