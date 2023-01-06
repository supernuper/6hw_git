#ifndef PORT_H
#define PORT_H

#include <stddef.h>
#include <iostream>
#include "string.h"
#include "generic-field.h"

//port class, inherits from generic field
class port : public GenericField{
    String type;
    int max;
    int min;

public:
    port(String type);
    ~port();
    bool match(String packet);
    bool set_value(String value);
    bool pick_val(String* pkt, port this_port);
};

#endif