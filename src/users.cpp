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
    std::fstream file("csv/users.csv", std::ios::in);

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

    tinyxml2::XMLElement* users = doc.NewElement("users");
    doc.InsertFirstChild(users);

    for(auto& i:states_vec){
        tinyxml2::XMLElement* user = doc.NewElement("user");
        user->SetAttribute("user_id", i[0].c_str());
        users->InsertFirstChild(user);

        tinyxml2::XMLElement* f_name = doc.NewElement("f_name");
        f_name->SetText(i[1].c_str());
        user->InsertEndChild(f_name);
        
        tinyxml2::XMLElement* l_name = doc.NewElement("l_name");
        l_name->SetText(i[2].c_str());
        user->InsertEndChild(l_name);

        i[3].erase(std::remove_if(i[3].begin(), i[3].end(), isspace), i[3].end()); // removes trailing space
        tinyxml2::XMLElement* email = doc.NewElement("email");
        email->SetText(i[3].c_str());
        user->InsertEndChild(email);

        doc.InsertEndChild(users);
    }

    doc.SaveFile("xml/users.xml");
    //doc.Print();
}