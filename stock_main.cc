#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include<vector>
#include <sstream> 
#include<map>


int Most_comman(const std::vector<int>&v) {
    int max = 0;
int most_common = -1;
std::map<int,int> m;
for (auto vi = v.begin(); vi != v.end(); vi++) {
  m[*vi]++;
  if (m[*vi] > max) {
    max = m[*vi]; 
    most_common = *vi;
  }
}
return most_common;
}


int main()
{     
    // testing 

    	std::map<std::string,std::vector<int>> stock_data;
        std::vector<int> price_diff;
       int count_key = 0;
    std::ifstream data("SBICARD.NS.csv");
    if (!data.is_open())
    {
        std::exit(EXIT_FAILURE);
    }
    std::string str,map_key;
    std::getline(data, str); // skip the first line
    bool is_map_key = true;
    while (std::getline(data, str))
    {
          if (str.find("null") != std::string::npos)  
          continue;
       // std::cout<<"__" <<str<<" ";
       // return 0;
        std::istringstream iss(str);
        std::string token;
        while (std::getline(iss, token, ','))
        {   
          
            if(is_map_key ){
                map_key = token;
                //std::cout<<"key == "<< map_key<<" ";
                is_map_key = false;
                continue;
            }
          stock_data[map_key].push_back(stod(token));
            // process each token
     
        }
        is_map_key = true;
        //std::cout << std::endl;
    }

   // std::cout<<stock_data.size()<<"\n";

    for(const auto& map_ele:stock_data){
        std::cout<<map_ele.first<<" = "<<map_ele.second[1]-map_ele.second[0]<<"\n";
        price_diff.push_back(map_ele.second[1]-map_ele.second[0]);
        // for(const auto& map_val: map_ele.second){
        //     std::cout<<map_val<<"\n";
        // }
    //    break;
    }
    std::cout<<"Most comman = "<<Most_comman(price_diff)<<"\n";



}