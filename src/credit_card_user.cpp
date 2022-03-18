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
    std::fstream file("csv/credit_card_user.csv", std::ios::in);

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

    tinyxml2::XMLElement* credit_card_users = doc.NewElement("credit_card_users");
    doc.InsertFirstChild(credit_card_users);

    for(auto& i:states_vec){
        tinyxml2::XMLElement* credit_card_user = doc.NewElement("credit_card_user");
        credit_card_user->SetAttribute("card_id", i[0].c_str());
        credit_card_users->InsertFirstChild(credit_card_user);

        tinyxml2::XMLElement* user_id = doc.NewElement("user_id");
        user_id->SetText(i[1].c_str());
        credit_card_user->InsertEndChild(user_id);

        i[2].erase(std::remove_if(i[2].begin(), i[2].end(), isspace), i[2].end()); // removes trailing space
        tinyxml2::XMLElement* cc_id = doc.NewElement("cc_id");
        cc_id->SetText(i[2].c_str());
        credit_card_user->InsertEndChild(cc_id);
        
        doc.InsertEndChild(credit_card_users);
    }

    doc.SaveFile("xml/credit_card_user.xml");
    //doc.Print();
}