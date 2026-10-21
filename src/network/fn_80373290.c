#include <string.h>
#pragma force_active on

struct X {
    unsigned char data[0x434];
    int field_434;
};

void fn_80373290(struct X** arg0, int arg1, const char* arg2) {
    struct X* p = *arg0;
    strncpy((char*)p, arg2, 0x100);
    p->data[0xFF] = 0;
    p->field_434 = arg1;
}
