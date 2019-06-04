#include <iostream>
#include "xmlWriter.h"
#include <stdexcept>
#include <regex>


struct rpt_file{
    std::string date;
    std::string time;
    std::string number_damages;
    std::string file_name;
    std::string location;
    std::string damage_severity;

};

rpt_file readRptFile(const std::string& report_file_name){
    rpt_file output{};
    std::fstream report_file_stream(report_file_name);
    if(report_file_stream.is_open()){
        std::string rpt_line;
        while(std::getline(report_file_stream, rpt_line)){
            std::regex date_pattern("Date:\\d+");
            std::regex time_pattern("Time:\\s\\d+");
            std::regex file_name_pattern("\\w+.dat$");
            std::regex number_damage_pattern("\\d+$");
            std::smatch matched_string;
            if(std::regex_search(rpt_line, matched_string, date_pattern)){
                output.date = matched_string.str();
            }
            else if(std::regex_search(rpt_line, matched_string, time_pattern)){
                output.time = matched_string.str();
            }
            else if(std::regex_search(rpt_line, matched_string, number_damage_pattern)){
                output.number_damages = matched_string.str();
            }
            else if(std::regex_search(rpt_line, matched_string, file_name_pattern)){
                output.file_name = matched_string.str();
            }
        }
        return output;
    }
    else{
        throw std::invalid_argument("file not present");
    }
}


void writeXml(const rpt_file& xml_file_struct){
        xmlWriter xml;
    if(xml.open("../rpt_new.xml")){
        xml.writeComment("This is a comment");
        xml.writeOpenTag("diagnosticReport");
            xml.writeStartElementTag("dateTime");
                xml.writeString(xml_file_struct.date);
                xml.writeEndElementTag();
            xml.writeStartElementTag("dataName");
                xml.writeString(xml_file_struct.file_name);
                xml.writeEndElementTag();
            xml.writeStartElementTag("numberOfDamages");
                xml.writeString(xml_file_struct.number_damages);
                xml.writeEndElementTag();
            xml.writeStartElementTag("damageId");
                xml.writeString("");
                xml.writeEndElementTag();
            xml.writeStartElementTag("Location");
                xml.writeString(xml_file_struct.location);
                xml.writeEndElementTag();
            xml.writeStartElementTag("Severity");
                xml.writeString(xml_file_struct.damage_severity);
                xml.writeEndElementTag();
        xml.writeCloseTag();

        xml.close();
        std::cout << "Success!\n";


}


int main() {

}
