#include<iostream>
#include<vector>
#include<cmath>

std::vector<int> pow_vector(std::vector<int>& v, int pow_2){
   std::vector<int> buff;
   for(auto element: v){
      buff.push_back(pow(element, pow_2));
   }
   return buff;
}

int main(){
   std::vector<int> v1{1,2,3,4,5,6};
   std::vector<int> v2;
   v2 = pow_vector(v1,2);
   for(auto element: v2) std::cout<<element;
return 0;
}
