//
// Created by spandan on 5/31/19.
//

#ifndef XMLWRITER_XMLWRITER_H
#define XMLWRITER_XMLWRITER_H
#include <vector>
#include <string>
#include <fstream>
#include <iostream>

class xmlWriter {
    public:
        xmlWriter(void){};
        bool open(const std::string strFile);
        void close();
        bool exist(const std::string);
        void writeOpenTag(std::string openTag);
        void writeCloseTag();
        void writeStartElementTag(std::string elementTag);
        void writeEndElementTag();
        void writeAttribute(const std::string outAttribute);
        void writeString(const std::string outString);
        void writeComment(const std::string commentString);

    private:
        std::ofstream outFile;
        int current_indent;
        int openTags;
        int openElements;
        std::vector<std::string> tempOpenTag;
        std::vector<std::string> tempElementTag;

    };



#endif //XMLWRITER_XMLWRITER_H
