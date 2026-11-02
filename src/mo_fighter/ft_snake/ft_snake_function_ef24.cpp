#include <types.h>
#pragma force_active on

extern "C" float randf__Fv();
extern "C" const float lbl_122_rodata_C;

struct TableEntry {
    u32 key;
    float value;
};

class Target {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void call(s32, s32, s32, s32);
};

extern "C" void fn_122_EF24(u8* self) {
    s32 i = 0;
    float f1 = randf__Fv();
    float f2 = lbl_122_rodata_C;
    TableEntry* table;
    u32 key;
    for (; (table = *(TableEntry**)(*(u8**)(self + 0x2D03C) + 0x8C), key = table[i].key) != 0xFFFFFFFF; i++) {
        f2 += table[i].value;
        if (f1 <= f2) {
            Target* t = *(Target**)(*(u8**)(*(u8**)(self + 0x60) + 0xD8) + 0x50);
            t->call(key, 1, 0, 0);
            return;
        }
    }
}
