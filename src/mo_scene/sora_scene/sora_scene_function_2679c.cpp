#include <types.h>
#pragma force_active on

extern "C" {
extern double lbl_1_rodata_A28;

struct Entry {
    unsigned char pad[0x15];
    unsigned char flag;
    unsigned char pad16[2];
    float value;
    unsigned char rest[0x34];
};

int fn_1_2679C(void* self) {
    int result = 0;

    switch (*(int*)self) {
    case 0:
        result = 1;
        break;
    case 1:
        result = 2;
        break;
    case 2:
        result = 4;
        break;
    }

    for (unsigned char i = 0; i < 3; ++i) {
        Entry* entry = &((Entry*)self)[i];
        if (entry->value >= lbl_1_rodata_A28) {
            result = 3;
            break;
        }
        if (entry->flag == 1) {
            result = 5;
            break;
        }
    }

    return result;
}
}
