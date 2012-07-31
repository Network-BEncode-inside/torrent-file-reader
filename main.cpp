
#include <iostream>
#include <fstream>
#include "Dictionary.h"
#include "Exception.h"

int main(int argc, char** argv)
{
    if (argc < 2)
    {
        std::cerr << "Missing file name" << std::endl;
        return 1;
    }

    std::ifstream f(argv[1], std::ios::binary);
    f.seekg (0, std::ios::end);
    int length = f.tellg();
    f.seekg (0, std::ios::beg);

    char* buffer = new char[length];

    f.read(buffer, length);

    boost::shared_ptr<Bencoding::Element> dict;
    try
    {
        unsigned offset = 0;
        dict = Bencoding::Element::factory(buffer, offset);
    }
    catch (Bencoding::Exception& e)
    {
        std::cerr << "Exception thrown: " << e.what() << std::endl;
        return 2;
    }

    delete[] buffer;
    f.close();

    std::cout << dict << std::endl;

    return 0;
}
