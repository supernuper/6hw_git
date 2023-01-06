
// int main (){
//     String israel(" 12 3456 78 9 "); //= String();
//     cout << israel.length << endl;
//     //israel = String(" 12 3456 78 9 ");
//     cout << israel.data << endl;
//     //cout << israel.length << endl;
//     String levy(israel);
//     cout << levy.data << endl;
//     cout << levy.length << endl;
//     //String levy = String("i love");
//     int x = israel.equals(levy);
//     cout << x << endl;
//     int y = israel.equals("  12 3456 789 "); 
//     cout << y << endl;
//     // y = levy.equals("123 456 78"); 
//     //cout << y << endl;
//     String cuco;
//     cuco = israel.trim();
//     //cout << cuco.data << endl;
//     cout << cuco.length << endl;
//     //int p = cuco.to_integer();
//     //cout << p << endl;
//     return 0;
// }


// #include <stddef.h>
// #include <iostream>
// #include <string.h>
// #include "string.h"
// #include <stdlib.h>

// using std::cout ;
// using std::endl;
// String::String():data(NULL),length(0){};


//  String::String(const String &str){
//    this->length = str.length;
//    this->data = new char[str.length+1];
//    strcpy(this->data,str.data);
//  };

    
//  String::String(const char *str){
//   if(str==NULL){
//     this->length =0;
//     this->data = NULL;
//   }
//   else{
//   this->length = strlen(str);
//   this->data = new char[this->length+1];
//   strcpy(this->data,str);
//   }
//  };
   
//  String::~String(){
//   delete[] this->data;
//   };

//  String& String::operator=(const String &rhs){
//   if(this != &rhs){
//     delete[] this->data;
//     this->length = rhs.length;
//     this->data = new char[rhs.length+1];
//     strcpy(this->data,rhs.data);
//   }

//   return(*this);
//  };

//  String& String::operator=(const char *str){
//    if(this->data != str){
//     delete[] this->data;
//     this->length = strlen(str);
//     this->data = new char[this->length+1];
//     strcpy(this->data,str);
//   }
  
//   return(*this);
//  };
// //--------------------------------------------------------------------------//
// bool String::equals(const String &rhs) const {
//  if(this->length == rhs.length){
//   return(!strcmp(this->data,rhs.data));
//   }
//  return(false);  
// };
// //--------------------------------------------------------------------------//
// bool String::equals(const char *rhs) const{ 
//   return(!strcmp(this->data,rhs));
//   };
// //--------------------------------------------------------------------------//
// int String::to_integer() const{
//   int res=0;
//   for(size_t i=0 ; i< this->length ; i++){
//     res = (this->data[i]-'0')+ res*10; 
//   }
//   return res;
// };

// //--------------------------------------------------------------------------//
// String String::trim() const{

// };

//  void String::split(const char *delimiters, String **output, size_t *size) const{

//  };
// // void String::split(const char *delimiters, String **output, size_t *size) const{
// //   *size=0;
// //   int len_del= strlen(delimiters);
// //   std::cout<<"len_del = "<<len_del<<std::endl;
// //   int* sep = new int[this->length]; 
// //   for(size_t i = 0 ; i < this->length ; i++){
// //     for(int j = 0 ; j < len_del ; j++  ){
// //       sep[i]=0;
// //       if(this->data[i] == delimiters[j]){
// //         std::cout<<"this is the data"<<this->data[i]<<"and del"<<delimiters[j]<<std::endl;
// //          *size+=1;
// //          sep[i]=1;
// //          std::cout<<"sep["<<i<<"] ="<<sep[i]<<std::endl;
// //       }    
// //     }
// //   }
// //   std::cout<<"size "<<*size <<std::endl;
// //   if(output != NULL){
// //    *output = new String[*size +1];
// //     size_t size_str=0;
// //     size_t size_all=0;
// //     int j=0;
// //     for(size_t i=0 ; i<(this->length) ; i++){
// //       if(!sep[i]){
// //         size_str+=1;
// //       }
// //       if(sep[i] || i == (this->length-1)){
// //             output[j];
// //             output[j]->length = size_str;
// //              std::cout<<"size_str = "<<size_str<<std::endl;
// //             output[j]->data = new char[size_str+1];
            
// //             strncpy(output[j]->data,this->data+size_all,size_str);
// //             std::cout<<"output len = "<< output[j]->length<<" data = "<<output[j]->data<<std::endl;
// //             size_all+=size_str+1;
// //             size_str=0;
// //             j++;
// //             std::cout<<"j= "<<j<<"i= "<<i<<std::endl;
// //           }
// //     }
// //   }
// //   delete [] sep;
// // }; 