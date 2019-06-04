//
// Created by spandan on 5/31/19.
//

#include "xmlWriter.h"

//=============================================================================
//== Description
//== --------------------------------------------------------------------------
//== This function is used to check if the XML file exists
//=============================================================================


bool xmlWriter::exist(const std::string fileName){
    std::fstream checkFile(fileName);
    return checkFile.is_open();
}
//=============================================================================
//== Function Name  :   XmlWriter::open
//== Description
//== --------------------------------------------------------------------------
//== This function is used to open the XML file, first checking to see if it
//== exists first
//=============================================================================
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
//=============================================================================

//== Description
//== --------------------------------------------------------------------------
//== This function is used to close the XML file
//=============================================================================
void xmlWriter::close() {
    if (outFile.is_open()) {
        outFile.close();
    }
    else {
        std::cout << "File already closed.\n";
    }

}
//=============================================================================
//== Function Name  :   XmlWriter::writeOpenTag
//== Description
//== --------------------------------------------------------------------------
//== This function creates a new tag, checking that the file is open, and saves
//== the tag name in a vector to keep track of it
//=============================================================================
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
//=============================================================================
//== Function Name  :   XmlWriter::writeCloseTag
//== Description
//== --------------------------------------------------------------------------
//== This function closes the currently open tag
//=============================================================================
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
//=============================================================================
//== Function Name  :   XmlWriter::writeStartElementTag
//== Description
//== --------------------------------------------------------------------------
//== This function creates a new element tag and saves the name to a vector
//=============================================================================
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
//=============================================================================
//== Function Name  :   XmlWriter::writeEndElementTag
//== Description
//== --------------------------------------------------------------------------
//== This function closed the currently opened element tag
//=============================================================================
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
//=============================================================================
//== Function Name  :   XmlWriter::writeAttribute
//== Description
//== --------------------------------------------------------------------------
//== This function writes an attribute (if any) after the element tag is first
//== opened and before the output for the element is written
//=============================================================================
void xmlWriter::writeAttribute(const std::string outAttribute) {
    if (outFile.is_open()) {
        outFile << " " << outAttribute;
    }
    else {
        std::cout << "File is closed. Unable to write to file.\n";
    }
}
//=============================================================================
//== Function Name  :   XmlWriter::writeString
//== Description
//== --------------------------------------------------------------------------
//=============================================================================
void xmlWriter::writeString(const std::string outString) {
    if (outFile.is_open()) {
        outFile << ">" << outString;
    }
    else {
        std::cout << "File is closed. Unable to write to file.\n";
    }
}

//=============================================================================
//== Function Name  :   XmlWriter::writeComment
//== Description
//== --------------------------------------------------------------------------
//=============================================================================
// This function writes the comment to the xml file


void xmlWriter::writeComment(const std::string commentString) {
    if(outFile.is_open()){
        outFile << "<!-- "<< commentString << "-->\n";
    }
    else{
        std::cout << "File is closed. Unable to write file.\n";
    }
}