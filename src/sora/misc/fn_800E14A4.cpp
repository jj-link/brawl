#include <types.h>
#pragma force_active on

class Animation {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void setFrame(float frame);
};

struct ModelAnimation {
    char pad[0xC];
    Animation* animation;
};

struct MuObject {
    char pad[0x14];
    ModelAnimation* modelAnimation;
};

struct State {
    char pad0[0x18];
    u32 field18;
    u32 field1C;
    char pad1[0x8];
    MuObject* objects[6];
};

extern float lbl_805A23C0;
extern float lbl_805A23E4;

extern "C" void setFrameNode__8MuObjectFf(MuObject* obj, float frame);
extern "C" void fn_800E1588(State* self, int a, int b, int c);

extern "C" void fn_800E14A4(State* self, u32 value, int flag) {
    MuObject** p;
    int i;
    u32 old = self->field18;
    s32 changed = (old != self->field1C);
    if (flag != 0) {
        if (value != old) {
            i = 2;
            p = self->objects - 8;
            while (i < 6) {
                setFrameNode__8MuObjectFf(p[10], lbl_805A23E4);
                p++;
                i++;
            }
            i = 2;
            p = self->objects - 8;
            while (i < 6) {
                p[10]->modelAnimation->animation->setFrame(lbl_805A23C0);
                p++;
                i++;
            }
        }
    } else if (!changed) {
        fn_800E1588(self, value, 1, 0);
    }
    self->field18 = value;
}
