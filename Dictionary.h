
#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <map>
#include <boost/shared_ptr.hpp>
#include <iostream>

#include "String.h"
#include "Element.h"

namespace Bencoding
{

    class Dictionary : public Element
    {
    public:
        static boost::shared_ptr<Element> factory(const char* const buffer, unsigned& offset);
        virtual Type getType();

        inline std::map<boost::shared_ptr<String>, boost::shared_ptr<Element> > const& getMap()
            {
                return dict;
            }

    private:
        Dictionary(const char* const buffer, unsigned& offset);

        std::map<boost::shared_ptr<String>, boost::shared_ptr<Element> > dict;
    };

}

std::ostream& operator<< (std::ostream& aStream, boost::shared_ptr<Bencoding::Dictionary> dictionary);

#endif
