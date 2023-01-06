#include <stddef.h>
#include <iostream>
#include <cmath>
#include "generic-field.h"
#include "string.h"
#include "ip.h"

#define MIN 0
#define MAX 255
#define BYTE 8
#define WORD 32
#define SIZE 5
#define ADRESS 4
#define MASK 2
#define PACKET 4


//Constracto
ip::ip(String type){
    this->type=type;
};

//Destractor
ip::~ip(){}

//Finds current ip rule 
bool ip::pick_val(String* pkt, ip this_ip){
    String* output;
    size_t size;
    pkt->split("=, ",&output,&size);
    if(size == 0){
        return false;
    }
    else if(size != PACKET){
        delete []output;
        return false;
    }
    for(size_t i=0; i<size-1 ;i++ ){
        if(output[i].equals(this_ip.type)){
            *pkt = output[i+1];
            delete [] output;
            return true;
        }
    }
    delete []output;
    return false;
}

//Defines ip adress limits 
bool ip_to_num(unsigned int* ip_num, size_t size, String* output){
    int byte_num;
    for (size_t i=0; i<size; i++){
        byte_num = output[i].to_integer();
        if(byte_num < MIN || byte_num > MAX){
            delete []output;
            return false;
        }
        *ip_num = *ip_num << BYTE;
        *ip_num += byte_num;
    }
    return true;    
}

//Checks if packet matchs to rule 
bool ip::match(String packet){
    if(!pick_val(&packet,*this)){
        return false;
    }
    String* output;
    size_t size; 
    unsigned int ip_num = 0;
    packet.split(".", &output, &size);
    if(size != ADRESS){
        delete []output; 
        return false;   
    }
    if(!ip_to_num(&ip_num, size, output)){
        return false;
    }
    delete []output;
    return (ip_num >= this->min && ip_num <= this->max);     
};

//Set possible values to ip field
bool ip::set_value(String value){
    String* output;
    String* output_a;
    size_t size;
    unsigned int ip_num = 0;
    //Check address 
    value.split(".", &output_a, &size);
    if(size != ADRESS){
        delete []output_a; 
        return false;   
    }
    output_a[ADRESS-1].split("/", &output, &size);
    if(size != MASK){
        delete []output_a;
        delete []output; 
        return false;   
    }
    delete []output_a;
    delete []output;
    //Done check 
    value.split("./", &output, &size);
    if(size != SIZE){
        delete []output; 
        return false;   
    }
    if(!ip_to_num(&ip_num, size - 1, output)){
        return false;
    }
    int mask = output[size-1].to_integer(); 
    if(mask < 0 || mask > WORD){
        delete []output;
        return false;
    }
    this->min = (mask == 0)? 0 : ip_num - (ip_num % (1 << (WORD-mask)));
    this->max = min + pow(2, (WORD-mask)) - 1;
    delete []output; 
    return true;
};