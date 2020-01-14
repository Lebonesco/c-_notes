#include <fstream>


void file_handling()
{
    char *file = "file_name";
    std::ifstream ifs(file); // open read only file
    std::ofstream ofs(file); // open write only file
    std::fstream iofs(file); // open file

    std::fstream iofs;
    iofs.open(file);

    iofs.is_open();
    iofs << "Hello World";
    iofs.write("Foo", 3);
    iofs.flush();
    iofs.bad(); // failed to write
    char str[4];
    iofs.read(str, 4);
    iofs.fail(); // failed to read
}