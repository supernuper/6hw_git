
#include "string.h"
#include <stddef.h>
#include <iostream>
#include <string.h>
#include "string.h"
#include "ip.h"
#include "port.h"
#include "input.h"
#define FAIL 1;
#define SUCCESS 0;
using namespace std;
int main (int argc, char **argv){
    if(check_args(argc,argv)!=0)
     return FAIL;

    String field = argv[1];
    String *out;
    size_t size;
 

    field.split("=",&out,&size);
    if(size!=2){
        delete [] out;
        return FAIL;
    }
    out[0]=out[0].trim();
    out[1]=out[1].trim();
   
    if(out[0].equals("src-ip")||out[0].equals("dst-ip")){
        ip ip_filed(out[0]);
        if(ip_filed.set_value(out[1])){
            parse_input(ip_filed);
            delete [] out;
            return SUCCESS;
        }
        delete [] out;
    }
    else if(out[0].equals("src-port")||out[0].equals("dst-port")){
        port port_filed(out[0]);
        if(port_filed.set_value(out[1])){
            parse_input(port_filed);
            delete [] out;
            return SUCCESS;
        }
        delete [] out;
    }
    else 
    delete [] out;
return FAIL;
}

