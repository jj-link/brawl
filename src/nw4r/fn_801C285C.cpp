#include <string.h>
#pragma force_active on

struct Entry {
    unsigned char pad0[3];
    unsigned char flag;
    unsigned char enabled;
    unsigned char busy;
    unsigned char pad6[6];
    int state;
    unsigned char pad10[4];
    int result;
    unsigned char data[0x20];
    unsigned char pad38[4];
    void (*callback)(int, int);
};

extern "C" void* fn_801C2C04();
extern "C" Entry* fn_801C2C9C(void*, int);

extern "C" void fn_801C285C(int arg0, int arg1) {
    Entry* entry = fn_801C2C9C(fn_801C2C04(), arg0);
    switch (arg1) {
    case 0:
        entry->flag = 1;
        memset(entry->data, 0, 0x20);
        entry->state = 2;
        entry->result = 2;
        break;
    case -2:
        entry->result = 1;
        break;
    case -3:
        entry->state = 0;
        break;
    case -1:
        entry->state = 0;
        break;
    default:
        entry->state = 0;
        break;
    }
    if (arg1 != 0 && arg1 != -2 && entry->enabled != 0) {
        void (*callback)(int, int) = entry->callback;
        if (callback != 0) {
            callback(arg0, arg1);
            entry->callback = 0;
        }
    }
    entry->busy = 0;
}