#include <types.h>
#include <gf/gf_model.h>
#pragma force_active on

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1(int, int, int);
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6(int, int);
    virtual void slot7();
    virtual void slot8(float);
};
struct Context {
    char pad0[0x24];
    int state;
    char pad28[0x14];
    void* field3c;
    char pad40[4];
    Object_vptr_0* object;
    gfModelAnimation* anim;
    char pad4c[0xa];
    u16 flags;
    u8 flags58;
    u8 pad59;
    u8 count;
    char pad5b[0x15];
    void (*callback)(Object_vptr_0*, void*);
    void* callbackArg;
};
extern float lbl_805A1958;
extern float lbl_805A195C;
extern "C" void fn_8006242C(Context*);
extern "C" void fn_801AF9F4(void*);

extern "C" void fn_80062190(Context* self, float rate) {
    if (self->count > 1)
        rate *= lbl_805A195C / (float)self->count;
    switch (self->state) {
    case 1:
    if (!(self->flags58 & 0x10)) {
        fn_8006242C(self);
        if (self->object && self->field3c) {
            if (self->flags58 & 1) {
                if (self->anim && !(self->flags & 0x7e))
                    self->anim->setUpdateRate(lbl_805A1958);
            } else {
                if (self->anim) {
                    if (!(self->flags & 0x7e)) {
                        self->anim->setUpdateRate(rate);
                    } else {
                        if (!(self->flags & 2) && self->anim->m_anmObjChrRes)
                            self->anim->m_anmObjChrRes->SetUpdateRate(rate);
                        if (!(self->flags & 4) && self->anim->m_anmObjVisRes)
                            self->anim->m_anmObjVisRes->SetUpdateRate(rate);
                        if (!(self->flags & 8) && self->anim->m_anmObjTexPatRes)
                            self->anim->m_anmObjTexPatRes->SetUpdateRate(rate);
                        if (!(self->flags & 0x10) && self->anim->m_anmObjTexSrtRes)
                            self->anim->m_anmObjTexSrtRes->SetUpdateRate(rate);
                        if (!(self->flags & 0x20) && self->anim->m_anmObjMatClrRes)
                            self->anim->m_anmObjMatClrRes->SetUpdateRate(rate);
                        if (!(self->flags & 0x40) && self->anim->m_anmObjShpRes)
                            self->anim->m_anmObjShpRes->SetUpdateRate(rate);
                    }
                }
            }
            fn_801AF9F4(self->object);
            self->object->slot6(2, 0);
            self->object->slot1(1, 0, 0);
            self->object->slot6(2, 1);
            if ((self->flags & 0x80) && self->callback)
                self->callback(self->object, self->callbackArg);
        }
    }
    }
}
