

#include <stddef.h>
#include <iostream>
#include <string.h>
#include "string.h"
#include "generic-field.h"
#include "port.h"
#define MAX 65535
#define MIN 0
using namespace std;


port::port(String type){
this->type=type;
};

port::~port(){}

bool pick_val(String* pkt, port this_port){
   String* output;
   size_t size;
   pkt->split("=, ",&output,&size);
   if(size ==0) {
    return false;
   }
   for(size_t i=0; i<size-1 ;i++ ){
        if(output[i].equals(this_port.type.data)){
         *pkt = output[i+1];
         delete [] output;
         return true;
      }
      
   }
   delete [] output;
    return false;
}


bool port::match(String packet){
   if(!pick_val(&packet,*this)){
   return false;
   }
   int val=packet.to_integer();
   return(val>=this->min && val<=this->max);
};

bool port::set_value(String value){
 String *out;
 size_t size=0;
 int val=0;
 bool retval =true;
 value.split("-",&out,&size);
 
   val = out[0].to_integer();
   (val>=MIN && val<=MAX)? this->min = val :retval=false;
   val = out[1].to_integer();
   (val>MIN && val<=MAX)?  this->max = val :  retval=false; 
   delete [] out;
   return (retval);

};

