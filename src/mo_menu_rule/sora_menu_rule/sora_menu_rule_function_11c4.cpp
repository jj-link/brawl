#include <types.h>
#pragma force_active on

extern "C" {
extern char lbl_18_data_670[];
extern char lbl_18_data_5D8[];
void* fn_18_12A4(void*);
void fn_18_CE0(void*, int);
void __construct_array(void*, void (*)(void*), void (*)(void*), unsigned long, int);
void fn_800B96E8(void*, int);
}

struct Class_FA8_base { char pad[0x668]; };
class Class_FA8 : public Class_FA8_base {
public:
    virtual void fn_18_48E8();
    virtual void fn_18_20C8();
    virtual void fn_18_B30();
    virtual void fn_18_2BBC();
    virtual void fn_18_3338();
    virtual void fn_18_12D8(int);
};

extern "C" void* fn_18_11C4(void* self, int a, int b) {
    char* p = (char*)self;
    *(void**)(p + 0x668) = lbl_18_data_670;
    __construct_array(p + 0x48, (void (*)(void*))fn_18_12A4, (void (*)(void*))fn_18_CE0, 0xa8, 9);
    *(u16*)(p + 0x640) = 0;
    *(void**)(p + 0x648) = lbl_18_data_5D8;
    *(int*)(p + 0x64c) = a;
    *(int*)(p + 0x650) = b;
    *(int*)(p + 0x630) = 1;
    *(u16*)(p + 0x42) = 0;
    ((Class_FA8*)self)->fn_18_12D8(0xff);
    for (unsigned int i = 0; i < 8; i++) {
        fn_800B96E8(p + 0x48 + (u8)i * 0xa8, (u8)i);
    }
    fn_800B96E8(p + 0x588, 0xf0);
    return self;
}