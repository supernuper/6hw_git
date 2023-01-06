#ifndef IP_H
#define IP_H

#include <stddef.h>
#include <iostream>
#include "string.h"
#include "generic-field.h"

//ip class, inherits from generic field
class ip : public GenericField {
    String type;
    unsigned int min;
    unsigned int max;

public:
    ip(String type);
    ~ip();
    bool match(String packet);
    bool set_value(String value);
    bool pick_val(String* pkt, ip this_ip);
};

#endif