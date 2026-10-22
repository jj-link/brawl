#include <types.h>
#pragma force_active on

extern char lbl_80529CF8[];
extern int fn_803F6150(const void*, const void*, unsigned long);
extern void fn_8023EC80(unsigned short);

void fn_8023ED38(const void* arg0) {
    char* ptr = lbl_80529CF8 + 0x1854;
    unsigned short i;
    for (i = 0; i < 3; i++) {
        if (*(unsigned char*)(ptr + 0xd) != 0 && fn_803F6150(ptr + 0x28, arg0, 6) == 0) {
            fn_8023EC80(i);
        }
        ptr += 0x34;
    }
}
