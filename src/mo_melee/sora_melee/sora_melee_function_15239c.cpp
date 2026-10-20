#include <types.h>
#pragma force_active on

struct Pad {
    u32 a;
    u32 b;
};

struct Obj : public Pad {
    virtual u32 v0();
    virtual u32 v1();
    virtual u32 v2();
    virtual u32 v3();
    virtual u32 v4();
    virtual u32 v5();
    virtual u32 v6();
    virtual u32 v7();
    virtual u32 v8();
    virtual u32 v9();
    virtual u32 v10();
    virtual u32 v11();
    virtual u32 v12();
    virtual u32 v13();
    virtual u32 v14();
    virtual u32 v15();
    virtual u32 v16();
    virtual u32 v17();
    virtual u32 v18();
    virtual u32 v19();
    virtual u32 v20();
    virtual u32 v21();
    virtual u32 v22();
    virtual u32 v23();
    virtual u32 v24();
    virtual u32 v25();
    virtual u32 v26();
    virtual u32 v27();
    virtual u32 v28();
    virtual u32 v29();
    virtual u32 v30();
    virtual u32 v31();
};

extern "C" {
bool fn_27_15239C(void* r3, u8* r4, u8* r5) {
    u32 v = *(u32*)(r5 + 0x6C) & 0x1F;
    if (v - 9 <= 1) {
        Obj* b = *(Obj**)(*(u8**)(r4 + 0xD8) + 0x38);
        if (b->v29() == 0) {
            return 0;
        }
    }
    return 1;
}
}
