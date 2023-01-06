#ifndef IP_H
#define IP_H

#include <stddef.h>
#include <iostream>
#include "string.h"
#include "generic-field.h"

class ip : public GenericField {
   

public:
 unsigned int min;
    unsigned int max;
    String type;
    bool match(String packet);
    bool set_value(String value);
    ip(String type);
    ~ip();
};

#endif