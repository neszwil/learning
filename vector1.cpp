#include<iostream>
#include<vector>

std::vector<int> function(std::vector<int>& v1, int hi, int low){
   std::vector<int> v2;
   for(auto element: v1){
      if(element>=low && element<=hi)
         v2.push_back(element);
   }
   return v2;
}

int main(){
   std::vector<int> sample_v{1,2,3,4,1,8};
   //std::vector<int> buff_v2;
   //buff_v2 = function(sample_v,2,1);
   for(auto element: function(sample_v,8,0))
      std::cout<<element;
   return 0;
}
