#include <string.h>
#pragma force_active on

extern char lbl_80529CF8[];
extern void fn_80232020(void*);

typedef struct {
    unsigned short field8;
    unsigned short fieldA;
    unsigned char data[0xF8];
} LocalStruct;

void fn_8023D6CC(void* arg1, void* src, unsigned int size, int condition) {
    LocalStruct local;
    char* base = lbl_80529CF8;
    void* fn_ptr;
    unsigned char flag_byte;
    unsigned int copy_size;
    unsigned char* p_dst;
    unsigned short remaining;

    fn_ptr = *(void**)(base + 0x167C);
    flag_byte = *(unsigned char*)(base + 0x16AE);

    fn_80232020(base + 0x1680);
    *(unsigned char*)(base + 0x16AE) = 0;

    if (condition == 0) {
        p_dst = local.data;
        copy_size = (size < 0xF8) ? size : 0xF8;
        local.fieldA = copy_size;
        local.field8 = 0;
        remaining = copy_size;
        while (remaining > 0) {
            *p_dst++ = *(unsigned char*)src;
            src = (unsigned char*)src + 1;
            remaining--;
        }
    } else {
        local.fieldA = 0;
        local.field8 = 9;
        local.data[0] = 0;
    }

    memset(base + 0x16A8, 0, 6);

    if (flag_byte & 1) {
        *(void**)(base + 0x167C) = (void*)0;
        if (fn_ptr != (void*)0) {
            ((void (*)(LocalStruct*))fn_ptr)(&local);
        }
    }
}