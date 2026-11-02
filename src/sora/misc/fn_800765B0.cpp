#include <types.h>
#pragma force_active on

class FaderClass {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4(s32);
};

extern "C" void fn_800765B0(char* self, s32 key1, s32 arg2) {
    if (*(u8*)(self + 0x6EF) == 0) {
        return;
    }
    if (*(u8*)(self + 0x6ED) == 0) {
        return;
    }
    char* p = self;
    u32 i = 0;
    do {
        if (key1 == *(s32*)(p + 0x2DC)) {
            if (*(u16*)(p + 0x2F0) == 0) {
                FaderClass* obj = (FaderClass*)(*(void**)(p + 0x2D4));
                if (obj != 0) {
                    obj->v4(arg2);
                }
                *(s32*)(p + 0x2D8) = -1;
                *(s32*)(p + 0x2DC) = -1;
                *(s32*)(p + 0x2E0) = -1;
                *(s32*)(p + 0x2E4) = 0;
                *(s32*)(p + 0x2E8) = 0x40;
                *(s32*)(p + 0x2EC) = 0;
                *(u16*)(p + 0x2F0) = 0;
            }
        }
        i += 1;
        p += 0x20;
    } while (i < 0x20);
}
