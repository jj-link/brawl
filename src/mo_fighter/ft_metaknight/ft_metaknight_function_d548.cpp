#include <types.h>
#pragma force_active on

struct SoundTarget {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual u32 v9(s32 index);
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15(s32 index, void* params);
};

extern "C" void fn_111_D548(void* unused, u8* obj) {
    struct Params {
        s32 id;
        u8 flag;
    } params;
    s32 index;

    params.id = 0x44d;
    params.flag = 0;

    for (index = 6; index < 12; ++index) {
        SoundTarget* target = *(SoundTarget**)(*(u8**)(obj + 0xD8) + 0x54);
        if (target->v9(index) == 1) {
            target = *(SoundTarget**)(*(u8**)(obj + 0xD8) + 0x54);
            target->v15(index, &params);
        }
    }
}
