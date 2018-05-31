#include<fstream>
#include<iostream>
#include<string>
#include<algorithm>
 
int main(){
    std::ifstream istr("test.txt");
    if(istr.is_open()){
        std::string tmp;
        while(std::getline(istr, tmp)){
            std::string::const_iterator p, q = tmp.begin(), end = tmp.end();
             
            while((p = std::find_if(q, end, isdigit)) != end){//查看该行是否还有数字
                
                std::cout<<std::stoul(tmp.substr(distance(tmp.cbegin(), p), distance(p, q)))<<" ";//将p~q的字串转化为数字
            }
        }
    }
     
    return 0;
}