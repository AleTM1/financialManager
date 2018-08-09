


#include "Loader.h"
#include "View.h"


bool Loader::isFirstTime() {

    std::ifstream inputFile;
    inputFile.open(DEFAULTPATH);

    std::string inputContent;
    std::string buffer;

    while(!inputFile.eof()){

        inputFile>>buffer;
        inputContent.append(buffer);

    }

    inputFile.close();

    return inputContent.empty();

}
