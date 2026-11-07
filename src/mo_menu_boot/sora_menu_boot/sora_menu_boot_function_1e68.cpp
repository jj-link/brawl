#include <string.h>
#include <stdio.h>
#pragma force_active on
extern "C" void* getMsgData__5MuMsgFUlPPv(void*, unsigned long, void**);
extern char lbl_22_data_308[];
extern char lbl_22_data_30C[];

struct Obj {
    char pad[0x44];
    int a44, a48, a4c;
    char str[0x114];
    void* msg;
};

extern "C" void fn_22_1E68(Obj* self) {
    if (self->a44 > 0) {
        char b[256]; void* s;
        memset(b, 0, 256);
        memcpy(b, getMsgData__5MuMsgFUlPPv(self->msg, 0x1b, &s), (unsigned long)s);
        strcat(self->str, b);
        int v = self->a44;
        char c[256];
        memset(c, 0, 256);
        sprintf(c, lbl_22_data_308, v);
        strcat(self->str, c);
        char d[256]; void* t;
        memset(d, 0, 256);
        memcpy(d, getMsgData__5MuMsgFUlPPv(self->msg, 0x1e, &t), (unsigned long)t);
        strcat(self->str, d);
        strcat(self->str, lbl_22_data_30C);
    }
    if (self->a48 > 0) {
        char b[256]; void* s;
        memset(b, 0, 256);
        memcpy(b, getMsgData__5MuMsgFUlPPv(self->msg, 0x1c, &s), (unsigned long)s);
        strcat(self->str, b);
        int v = self->a48;
        char c[256];
        memset(c, 0, 256);
        sprintf(c, lbl_22_data_308, v);
        strcat(self->str, c);
        char d[256]; void* t;
        memset(d, 0, 256);
        memcpy(d, getMsgData__5MuMsgFUlPPv(self->msg, 0x1e, &t), (unsigned long)t);
        strcat(self->str, d);
        strcat(self->str, lbl_22_data_30C);
    }
    if (self->a4c > 0) {
        char b[256]; void* s;
        memset(b, 0, 256);
        memcpy(b, getMsgData__5MuMsgFUlPPv(self->msg, 0x1d, &s), (unsigned long)s);
        strcat(self->str, b);
        int v = self->a4c;
        char c[256];
        memset(c, 0, 256);
        sprintf(c, lbl_22_data_308, v);
        strcat(self->str, c);
        char d[256]; void* t;
        memset(d, 0, 256);
        memcpy(d, getMsgData__5MuMsgFUlPPv(self->msg, 0x1e, &t), (unsigned long)t);
        strcat(self->str, d);
        strcat(self->str, lbl_22_data_30C);
    }
    char b[256]; void* s;
    memset(b, 0, 256);
    memcpy(b, getMsgData__5MuMsgFUlPPv(self->msg, 0x1f, &s), (unsigned long)s);
    strcat(self->str, b);
}
