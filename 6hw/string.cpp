#include <stddef.h>
#include <iostream>
#include <string.h>
#include "string.h"

//Initiates an empty string
String::String():data(NULL),length(0){};

//Initiates string from other string
String::String(const String &str){
    this->length = str.length;
    this->data = new char[str.length + 1];
    strcpy(this->data, str.data);
};

//Initiates a string from char array
String::String(const char *str){
    this->length = strlen(str);
    this->data = new char[this->length + 1];
    strcpy(this->data, str);
};

//Destractor
String::~String(){
    delete[] this->data;
};

//Changes this from String
String& String::operator=(const String &rhs){
    if(this != &rhs){
        delete[] this->data;
        this->length = rhs.length;
        this->data = new char[rhs.length + 1];
        strcpy(this->data, rhs.data);
    } 
    return *this;
};

//Changes this from char array
String& String::operator=(const char *str){
    if(this->data != str){ 
        delete[] this->data;    
        this->length = strlen(str);
        this->data = new char[this->length + 1];
        strcpy(this->data, str);
    } 
    return *this;
};

//Returns true iff the contents of this equals to the contents of rhs
bool String::equals(const String &rhs) const{
    if(this->length == rhs.length){
        return(!strcmp(this->data, rhs.data));
    }
    return false;
};

//Returns true iff the contents of this equals to rhs
bool String::equals(const char *rhs) const{
    return(!strcmp(this->data, rhs));
};

//Splits this to several sub-strings according to delimiters
void String::split(const char *delimiters, String **output, size_t *size)
const{
    size_t del_num = strlen(delimiters);
    int* del_by = new int [this->length+1];
    bool last=false;
    del_by[this->length]=1;
    *size=1;

    for(size_t i=0 ; i<this->length ; i++){ 
        del_by[i]=0;
        for(size_t j=0 ; j < del_num ; j++){
            if(this->data[i] == delimiters[j]){
                del_by[i]=1;
                last = true;  
            }
        }
        (i==0 && del_by[0])? *size=0:*size=*size;
        if(!del_by[i] && last){
            *size=*size+1;
            last=false;
            }
    }
    if(output != NULL && *size>=1){
        *output = new String [*size];
        for(size_t i =0, j=0,last_i=0; i<=this->length ; i++){
            if(del_by[i] ==1){
                if(i>last_i){
                    (*output)[j].data = new char[i-last_i+1];
                    (*output)[j].data[i-last_i]='\0';
                    (*output)[j].length=i-last_i;
                    strncpy((*output)[j].data,this->data+(last_i),i-last_i);
                    j++;
                }
                    last_i=i+1;
            }
        }
    }
    delete [] del_by;
};

//converts this to an integer
int String::to_integer() const{
    int num = 0;
    for (size_t i = 0; i < this->length; i++){
        num = num*10 + (*(this->data + i) - '0');
    }
    return num;
};

//Removes any leading or trailing white-spaces
String String::trim() const{
    String no_space;
    int begin = 0; 
    int end = this->length;
    for(size_t i = 0; i < this->length; i++){
        if(*(this->data + i) != ' '){
           break; 
        }
        begin++; 
    }
    for(size_t i = this->length - 1; i >= 0; i--){
        if(*(this->data + i) != ' '){
           break; 
        }
        end--; 
    }
    no_space.length = end - begin;
    no_space.data = new char[no_space.length + 1];
    strncpy(no_space.data, (this->data) + begin, no_space.length);
    no_space.data[no_space.length] = '\0';   
    return no_space;   
};