#include <types.h>
#pragma force_active on

extern "C" void fn_27_844D8(void*, s32);
extern "C" void __destroy_arr(void*, void (*)(void*, s32), u32, u32);
extern "C" void __dl__FPv(void*);
extern "C" void* getInstance__13soEventSystemFv();
extern "C" void* getManager__13soEventSystemFl(void*, s32);
extern char lbl_27_data_260C8[];

class ev_mgr {
public:
    virtual void f0() = 0;
    virtual void f1(s16) = 0;
    virtual void f2(s16) = 0;
};

extern "C" void* fn_27_D6B9C(void* self, s32 del) {
    if (self) {
        if ((u8*)self + 0xc != 0 && (u8*)self + 0x1c != 0) {
            __destroy_arr((u8*)self + 0x28, (void (*)(void*, s32))fn_27_844D8, 0xc, 1);
        }
        if (self && self) {
            s16 id = *(s16*)((u8*)self + 4);
            *(void**)self = (void*)lbl_27_data_260C8;
            if (id != -1) {
                void* sys = getInstance__13soEventSystemFv();
                ev_mgr* mgr = (ev_mgr*)getManager__13soEventSystemFl(sys, *(s16*)((u8*)self + 4));
                mgr->f1(*(s16*)((u8*)self + 6));
            }
        }
        if (del > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
