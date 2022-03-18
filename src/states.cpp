#include <tinyxml2.h>

#include <fstream>
#include <vector>
#include <sstream>
#include <iostream>

int main(){
    std::vector<std::vector<std::string>> states_vec;
	std::vector<std::string> row;
	std::string line, word;
    std::fstream file("csv/states.csv", std::ios::in);

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

    tinyxml2::XMLElement* states = doc.NewElement("states");
    doc.InsertFirstChild(states);

    for(auto& i:states_vec){
        tinyxml2::XMLElement* state = doc.NewElement("state");
        state->SetAttribute("state_id", i[0].c_str());
        states->InsertFirstChild(state);

        tinyxml2::XMLElement* state_full = doc.NewElement("state_full");
        state_full->SetText(i[1].c_str());
        state->InsertEndChild(state_full);
        
        tinyxml2::XMLElement* state_short = doc.NewElement("state_short");
        state_short->SetText(i[2].c_str());
        state->InsertEndChild(state_short);

        tinyxml2::XMLElement* capital = doc.NewElement("capital");
        capital->SetText(i[3].c_str());
        state->InsertEndChild(capital);

        doc.InsertEndChild(states);
    }

    doc.SaveFile("xml/states.xml");
    //doc.Print();
}