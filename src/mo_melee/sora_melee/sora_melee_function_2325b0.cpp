#include <types.h>
#pragma force_active on

class Inner {
public:
    u32 pad;
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual int get(u32*);
};

extern "C" void fn_27_2325B0(u8* self, u32 arg1) {
    u8* node = *(u8**)(self + 0x40);
    while (node != 0) {
        u32 sp8 = 0;
        Inner* obj = *(Inner**)(node + 0x18);
        int ok;
        if (obj != 0 && obj->get(&sp8) != 0) {
            ok = 1;
        } else {
            ok = 0;
        }
        if (ok != 0 && sp8 == arg1) {
            if (*(u8*)(node + 0x2f) == 0) {
                *(u8*)(node + 0x2c) = 1;
            }
            return;
        }
        node = *(u8**)(node + 0x0);
    }
}
