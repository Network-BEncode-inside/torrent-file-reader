
#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <stdexcept>
#include <sstream>

namespace Bencoding
{
class Exception : public std::runtime_error
{
public:
    Exception(const std::string message, const unsigned offset) : runtime_error(createMessage(message, offset))
    {
    };

private:
    std::string createMessage(const std::string start, const unsigned offset)
    {
        std::stringstream message;
        message << start;
        message << " - offset: ";
        message << offset;
        return message.str();
    }
};
}

#endif
