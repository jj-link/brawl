#pragma force_active on
#include <mu/mu_object.h>

extern float lbl_805A2448;
extern float lbl_805A23B0;

class AnmChrSlots {
public:
    virtual void s08();
    virtual void s0C();
    virtual void s10();
    virtual void s14();
    virtual void s18();
    virtual void s1C();
    virtual float s20();
    virtual void s24();
    virtual void setFrame(float);
};

class Owner {
public:
    char pad0[0x8];
    MuObject* m_arr[14];
};

extern "C" void* fn_800E3FB0(Owner* self) {
        MuObject** p;
    MuObject* first = self->m_arr[11];
    if (((AnmChrSlots*)first->m_modelAnim->m_anmObjChrRes)->s20() >= lbl_805A2448) {
        int i = 2;
        p = self->m_arr;
        while (i < 6) {
            ((AnmChrSlots*)p[10]->m_modelAnim->m_anmObjChrRes)->setFrame(lbl_805A23B0);
            p++;
            i++;
        }
        p = self->m_arr;
        i = 2;
        while (i < 6) {
            p[10]->setFrameNode(lbl_805A23B0);
            i++;
            p++;
        }
        return NULL;
    }
    return self->m_arr[3];
}
