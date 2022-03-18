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
    std::fstream file("csv/merchants.csv", std::ios::in);

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

    tinyxml2::XMLElement* merchants = doc.NewElement("merchants");
    doc.InsertFirstChild(merchants);

    for(auto& i:states_vec){
        tinyxml2::XMLElement* merchant = doc.NewElement("merchant");
        merchant->SetAttribute("merch_id", i[0].c_str());
        merchants->InsertFirstChild(merchant);

        tinyxml2::XMLElement* merch_name = doc.NewElement("merch_name");
        merch_name->SetText(i[1].c_str());
        merchant->InsertEndChild(merch_name);

        i[2].erase(std::remove_if(i[2].begin(), i[2].end(), isspace), i[2].end()); // removes trailing space
        tinyxml2::XMLElement* business_category_id = doc.NewElement("business_category_id");
        business_category_id->SetText(i[2].c_str());
        merchant->InsertEndChild(business_category_id);
        
        doc.InsertEndChild(merchants);
    }

    doc.SaveFile("xml/merchants.xml");
    //doc.Print();
}