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

extern "C" void fn_80076674(char* self, s32 key1, u32 key2, s32 arg3) {
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
            if (key2 == *(u32*)(p + 0x2E0)) {
                FaderClass* obj = (FaderClass*)(*(void**)(p + 0x2D4));
                if (obj != 0) {
                    obj->v4(arg3);
                }
            }
        }
        i += 1;
        p += 0x20;
    } while (i < 0x20);
}
