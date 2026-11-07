#include <types.h>
#include <mu/mu_object.h>
#pragma force_active on

extern "C" {
int fn_800B61C0(void* obj);
void fn_800B5854(void* obj, int a, int b, int c, int d);
extern const float lbl_805A23B0;
}

class Anim {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual float slot6();
};

struct Slot {
    s32 state;
    MuObject* obj;
    char pad[4];
};

struct Self {
    char pad[0x26c];
    Slot slots[3];
};

extern "C" void fn_800E4638(Self* self) {
    float f31 = lbl_805A23B0;
    if (((unsigned char*)self)[0x28C] != 0) {
        for (s32 i = 0; i < 3; i++) {
            if (self->slots[i].state == 1) {
                void* a = *(void**)((char*)self->slots[i].obj + 0x14);
                Anim* anim = *(Anim**)((char*)a + 0xC);
                f31 = anim->slot6();
                break;
            }
        }
    }
    for (s32 i = 0; i < 3; i++) {
        if (self->slots[i].state == 2) {
            MuObject* obj = self->slots[i].obj;
            if (fn_800B61C0(obj) != 0) {
                self->slots[i].state = 1;
                if (((unsigned char*)self)[0x28C] != 0) {
                    fn_800B5854(obj, 1, 0x11, 1, 0);
                    obj->setFrameNode(f31);
                    obj->setFrameMatCol(f31);
                }
            }
        }
    }
}
