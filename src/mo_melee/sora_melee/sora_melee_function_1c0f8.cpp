#include <so/anim/so_anim_chr.h>
#include <types.h>
#pragma force_active on

class Mid;
class Obj4 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3(Mid*, s16*, float, float);
};
class Low {
public:
    char pad[0x6c];
    Obj4* obj;
};
class Mid {
public:
    char pad[0xd8];
    Low* low;
};
class Self {
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
    virtual float v12();
    virtual void v13();
    virtual void v14();
    virtual float v15();
    char pad[0x38];
    soAnimChr anim;
    char pad2[0x168 - 0x58];
    Mid* mid;
};
extern "C" void fn_27_1BF30(Self*, s16*, int);
extern "C" const float lbl_27_rodata_35C;
extern "C" void fn_27_1C0F8(Self* self, s16* arg) {
    if (self->anim.isEnd() == 1) {
        union { s16 value; int align; } temp;
        temp.value = *arg;
        fn_27_1BF30(self, &temp.value, 0);
    } else {
        float f = lbl_27_rodata_35C;
        if (*(void**)&self->anim != 0) {
            f = self->v15();
        }
        s16 value = *arg;
        Obj4* obj = self->mid->low->obj;
        float t = self->v12();
        obj->v3(self->mid, &value, t, f);
    }
}