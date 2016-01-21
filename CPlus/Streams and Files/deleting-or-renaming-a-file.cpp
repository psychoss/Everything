#include <iostream>
#include <cstdio>
#include <cerrno>

using namespace std;

int main(int argc, char **argv) {

    if (argc != 2) {
        cerr << "You must supply a file name to remove." << endl;
        return (EXIT_FAILURE);
    }

    if (remove(argv[1]) == -1) {  // remove() returns -1 on error
        cerr << "Error: " << strerror(errno) << endl;
        return (EXIT_FAILURE);
    }
    else {
        cout << "File '" << argv[1] << "' removed." << endl;
    }
}
/*
#include <iostream>
#include <string>
#include <boost/filesystem/operations.hpp>
#include <boost/filesystem/fstream.hpp>

using namespace std;
using namespace boost::filesystem;

int main(int argc, char** argv) {

   // Do parameter checking...

   try {
      path p = complete(path(argv[1], native));
      remove(p);
   }
   catch (exception& e) {
      cerr << e.what() << endl;
   }
   return(EXIT_SUCCESS);
}
 */