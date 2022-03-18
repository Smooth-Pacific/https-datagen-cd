#include <tinyxml2.h>

#include <fstream>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>

int main(){
    std::vector<std::vector<std::string>> states_vec;
	std::vector<std::string> row;
	std::string line, word;
    std::fstream file("csv/credit_card.csv", std::ios::in);

	if(file.is_open()){
		while(getline(file, line)){
			row.clear();
 
			std::stringstream str(line);
 
			while(getline(str, word, ',')){
				row.push_back(word);
            }
			states_vec.push_back(row);
		}
	}

    tinyxml2::XMLDocument doc;

    tinyxml2::XMLElement* credit_cards = doc.NewElement("credit_cards");
    doc.InsertFirstChild(credit_cards);

    for(auto& i:states_vec){
        tinyxml2::XMLElement* credit_card = doc.NewElement("credit_card");
        credit_card->SetAttribute("card_id", i[0].c_str());
        credit_cards->InsertFirstChild(credit_card);

        i[1].erase(std::remove_if(i[1].begin(), i[1].end(), isspace), i[1].end()); // removes trailing space
        tinyxml2::XMLElement* cc_num = doc.NewElement("cc_num");
        cc_num->SetText(i[1].c_str());
        credit_card->InsertEndChild(cc_num);
        
        doc.InsertEndChild(credit_cards);
    }

    doc.SaveFile("xml/credit_card.xml");
    //doc.Print();
}