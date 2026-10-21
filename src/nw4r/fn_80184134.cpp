#include <types.h>
#pragma force_active on

class TargetClass {
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
    virtual void target(s32 a, s32 b, s32 c);
};

struct OuterStruct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    TargetClass* unk10;
};

extern "C" {
void fn_80184134(OuterStruct* self, s32 arg1, s32 arg2) {
    if (self->unk10) {
        self->unk10->target(arg1, arg2, 1);
    }
}
}
