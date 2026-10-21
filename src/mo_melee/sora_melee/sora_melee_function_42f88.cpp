#include <types.h>
#pragma force_active on

struct Sub {
    virtual void* v0();
    virtual void* v1(u32 a);
};

class Obj {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38(u32 a);

    u8 pad4[0x30 - 4];
    u32 m30;
    u8 pad34[0x58 - 0x34];
    Sub* m58;
    u32 m5C;
    u32 m60;
    u8 pad64[2];
    u16 m66_hi : 1;
    u16 m66_lo : 15;
};

extern "C" void fn_27_41B40(void* r3, void* r4, u32 r5, u32 r6, float f1, float f2, float f3);

extern "C" void fn_27_42F88(Obj* self, u32 a, u32 b, float f1, float f2, float f3) {
    Sub* sub = self->m58;
    void* r = sub->v1(b);
    fn_27_41B40(r, (u8*)self + 0x38, self->m30, a, f1, f2, f3);
    self->m66_hi = 0;
    self->v38(0);
    self->m5C = 0;
    self->m60 = 0;
}
