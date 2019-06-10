//
// Created by spandan on 5/31/19.
//

#include "xmlWriter.h"


bool xmlWriter::exist(const std::string fileName){
    std::fstream checkFile(fileName);
    return checkFile.is_open();
}

bool xmlWriter::open(const std::string strFile) {

    if (exist(strFile)){
        std::cout << "Error: File already exists.\n";
        return false;
    }

    outFile.open(strFile);
    if (outFile.is_open()) {
        std::cout << "File created successfully.\n";

        outFile << "<?xml version='1.0' encoding='us-ascii'?>\n";
        current_indent = 0;
        openTags = 0;
        openElements = 0;
        return true;
    }

    return false;
}

void xmlWriter::close() {
    if (outFile.is_open()) {
        outFile.close();
    }
    else {
        std::cout << "File already closed.\n";
    }

}

void xmlWriter::writeOpenTag(const std::string openTag) {
    if (outFile.is_open()) {
        for (int i = 0; i < current_indent; i++) {
            outFile << "\t";
        }
        tempOpenTag.resize(openTags + 1);
        outFile << "<" << openTag << ">\n";
        tempOpenTag[openTags] = openTag;
        current_indent += 1;
        openTags += 1;
    }
    else {
        std::cout << "File is closed. Unable to write to file.\n";
    }
}

void xmlWriter::writeCloseTag() {
    if (outFile.is_open()) {
        current_indent -= 1;
        for (int i = 0; i < current_indent; i++) {
            outFile << "\t";
        }
        outFile << "</" << tempOpenTag[openTags - 1] << ">\n";
        tempOpenTag.resize(openTags - 1);
        openTags -= 1;
    }
    else {
        std::cout << "File is closed. Unable to write to file.\n";
    }
}

void xmlWriter::writeStartElementTag(const std::string elementTag) {
    if (outFile.is_open()) {
        for (int i = 0; i < current_indent; i++) {
            outFile << "\t";
        }
        tempElementTag.resize(openElements + 1);
        tempElementTag[openElements] = elementTag;
        openElements += 1;
        outFile << "<" << elementTag;
    }
    else {
        std::cout << "File is closed. Unable to write to file.\n";
    }
}


void xmlWriter::writeEndElementTag() {
    if (outFile.is_open()) {
        outFile << "</" << tempElementTag[openElements - 1] << ">\n";
        tempElementTag.resize(openElements - 1);
        openElements -= 1;
    }
    else {
        std::cout << "File is closed. Unable to write to file.\n";
    }
}


void xmlWriter::writeAttribute(const std::string outAttribute) {
    if (outFile.is_open()) {
        outFile << " " << outAttribute;
    }
    else {
        std::cout << "File is closed. Unable to write to file.\n";
    }
}

void xmlWriter::writeString(const std::string outString) {
    if (outFile.is_open()) {
        outFile << ">" << outString;
    }
    else {
        std::cout << "File is closed. Unable to write to file.\n";
    }
}


void xmlWriter::writeComment(const std::string commentString) {
    if(outFile.is_open()){
        outFile << "<!-- "<< commentString << "-->\n";
    }
    else{
        std::cout << "File is closed. Unable to write file.\n";
    }
}
