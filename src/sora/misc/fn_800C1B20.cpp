#include <types.h>
#pragma force_active on

extern "C" {
extern int lbl_80407C58[][2];

struct Entry {
    int pad[2];
    int key;   // 0x8
    int value; // 0xC
};

void fn_800C1B20(void* unused, Entry* p) {
    p->value = lbl_80407C58[p->key][0];
}
}
