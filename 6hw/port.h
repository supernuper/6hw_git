#ifndef PORT_H
#define PORT_H

#include <stddef.h>
#include <iostream>
#include "string.h"
#include "generic-field.h"


class port : public GenericField{
    public:
    int max;
    int min;
    String type;
     bool match(String packet);
     bool set_value(String value);
     port(const char* str);
     port(String type);
    ~port();
};




#endif