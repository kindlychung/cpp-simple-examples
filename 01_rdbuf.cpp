#include <fstream>   // std::ofstream
#include <iostream>  // std::streambuf, std::cout

int main() {
    std::streambuf *file_stream_buf, *backup;
    std::ofstream file_stream;
    file_stream.open("test.txt");
    backup = std::cout.rdbuf();             // back up cout's streambuf
    file_stream_buf = file_stream.rdbuf();  // get file's streambuf
    std::cout.rdbuf(file_stream_buf);       // assign streambuf to cout
    std::cout << "This is written to the file";
    std::cout.rdbuf(backup);  // restore cout's original streambuf
    file_stream.close();
    return 0;
}
