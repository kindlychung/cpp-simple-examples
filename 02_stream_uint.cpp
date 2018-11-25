#include <iostream>
#include <istream>
#include <streambuf>
class membuf : public std::basic_streambuf<char> {
   public:
    membuf(uint8_t const* p, size_t s) {
        setg((char*)p, (char*)p, (char*)p + s);
    }
};

class memstream : public std::istream {
   public:
    memstream(uint8_t const* p, size_t s)
        : std::istream(&_buffer), _buffer(p, s) {
        rdbuf(&_buffer);
    }

   private:
    membuf _buffer;
};

int main() {
    uint8_t buf[] = {0x00, 0x01, 0x02, 0x03};
    memstream s(buf, 4);
    char b;
    s.read(&b, 1);
    while (s.good()) {
        std::cout << "read: " << (int)b << '\n';
        s.read(&b, 1);
    }
    return 0;
}
