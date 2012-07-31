
#ifndef LIST_H
#define LIST_H

#include <list>

#include "Element.h"

namespace Bencoding
{
    class List : public Element
    {
    public:
        static boost::shared_ptr<Element> factory(const char* const buffer, unsigned& offset);
        virtual Type getType();
        inline std::list<boost::shared_ptr<Element> > getList()
            {
                return list;
            }

    private:
        List(const char* const buffer, unsigned& offset);

        std::list<boost::shared_ptr<Element> > list;
    };
}

std::ostream& operator<< (std::ostream& aStream, boost::shared_ptr<Bencoding::List> list);

#endif

