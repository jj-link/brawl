#include <mu/mu_object.h>
#include <nw4r/g3d/g3d_scnmdl.h>
#include <stdio.h>
#pragma force_active on

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual float slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13(void*);
};

struct Work {
    char pad0[0x110];
    MuObject* object;
    char pad114[8];
    MuObject* objects[1];
    char pad120[0xb68-0x120];
    Object_vptr_0* renderer1;
    Object_vptr_0* renderer2;
    char padb70[0x1090-0xb70];
    int index;
    int base;
    unsigned char active;
    char pad1099[0x12b0-0x1099];
    int selected;
    char pad12b4[0x24];
    unsigned char extra;
};

extern "C" void Pushback__Q34nw4r3g3d6ScnMdlFPvPvPc(void*, void*, char*);

extern float lbl_805A2270;
extern float lbl_805A2248;
extern float lbl_805A2264;
extern char lbl_8059E0A0[8];

extern "C" void fn_800BC8F0(Work* self) {
    char buf[16];
    if (lbl_805A2270 != ((Object_vptr_0*)self->object->m_modelAnim->m_anmObjVisRes)->slot6()) {
        if (self->active) {
            int value = self->base + self->index * 4;
            self->object->setFrameVisible(lbl_805A2248);
            sprintf(buf, lbl_8059E0A0, value);
            self->renderer1->slot13(self->object->m_scnMdl);
            self->renderer2->slot13(self->object->m_scnMdl);
            Pushback__Q34nw4r3g3d6ScnMdlFPvPvPc(self->renderer1, self->object->m_scnMdl, buf);
        } else {
            int value = self->selected + 0x5f;
            self->object->setFrameVisible(lbl_805A2264);
            sprintf(buf, lbl_8059E0A0, value);
            self->renderer1->slot13(self->object->m_scnMdl);
            self->renderer2->slot13(self->object->m_scnMdl);
            Pushback__Q34nw4r3g3d6ScnMdlFPvPvPc(self->renderer2, self->object->m_scnMdl, buf);
        }
        if (self->extra) {
            self->renderer1->slot13(self->objects[self->selected]->m_scnMdl);
            Pushback__Q34nw4r3g3d6ScnMdlFPvPvPc(self->renderer1, self->objects[self->selected]->m_scnMdl, buf);
        }
    }
}