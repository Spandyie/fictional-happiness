#include <iostream>
#include "xmlWriter.h"
#include <stdexcept>
#include <regex>


struct rpt_file_struct{
    std::string date;
    std::string time;
    std::string number_damages;
    std::string file_name;
    std::string location;
    std::string damage_severity;

};

rpt_file_struct readRptFile(const std::string& report_file_name){
    rpt_file_struct output{};
    std::fstream report_file_stream(report_file_name);
    int counter=0;
    if(report_file_stream.is_open()){
        std::string rpt_line;
        while(std::getline(report_file_stream, rpt_line)){

            std::smatch matched_string;
            if(counter == 2){

                output.date = rpt_line.substr(rpt_line.find(":")+1);          // substring everything after ":"
            }
            else if(counter == 3){
                output.time = rpt_line.substr(rpt_line.find(":")+1);
            }
            else if(counter == 4){
                output.file_name = rpt_line.substr(rpt_line.find(":")+1);
            }
            else if(counter == 5){
                std::regex reg_pattern("\\d+");
                std::smatch match_string;
                std::regex_search(rpt_line, match_string, reg_pattern);
                output.number_damages = match_string.str();
                if(std::stoi(output.number_damages) == 0){
                    break;
                }
            }
         else if(counter >= 10){
                output.damage_severity = rpt_line;
            }
            counter++;
        }

        }
        return output;

    }


void writeXml(const rpt_file_struct& xml_file_struct) {
    xmlWriter xml;
    if (xml.open("../rpt_new.xml")) {
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
}

int main() {
    std::string file_name{"/home/spandan/CLionProjects/xmlWriter/Coupon1_reduced_12_13_16_08_43_26_500kHz_ALL_dpi.rpt"};
    auto xml_rpt_file = readRptFile(file_name);
    writeXml(xml_rpt_file);
    return 0;
}
