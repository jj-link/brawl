#include <mu/mu_object.h>
#include <nw4r/g3d/g3d_scngroup.h>
#pragma force_active on

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8(float);
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
};

extern "C" {
extern float lbl_805A23B0;
extern float lbl_805A23B4;
extern float lbl_805A23C0;
extern float lbl_805A23F0;
extern float lbl_805A2400;
extern float lbl_805A2448;
extern char lbl_8059E268[6];
void Pushback__Q34nw4r3g3d6ScnMdlFPvPvPc(void*, void*, char*);
}

static inline void setVisible(MuObject* object, float frame) {
    object->setFrameVisible(frame);
}

struct Self {
    unsigned char flags : 1;
    char pad[0xcb];
    MuObject* objects[11];
    nw4r::g3d::ScnGroup* scene;
};

extern "C" void fn_800E5318(Self* self, unsigned int value) {
    nw4r::g3d::ScnGroup* scene = self->scene;
    float frame;

    if (self->flags) {
        frame = lbl_805A2400 - (float)value;
        if (frame > lbl_805A2400)
            frame = lbl_805A2400;
    } else {
        frame = (float)value / lbl_805A23B4;
        if (frame > lbl_805A2400)
            frame = lbl_805A2400;
    }

    int j;
    MuObject* obj;
    MuObject* last;
    Self* current;
    MuObject** p = (MuObject**)((char*)self + 0xa4);

    for (j = 0x29; j < 0x2d; ++j) {
        scene->Remove(p[10]->m_sceneModel);
        ++p;
    }

    unsigned int n = value & ((int)(-value | value) >> 31);
    value = n < 999 ? n : 999;
    current = self;
    int i = 0;

    while (i < 3 && (value != 0 || i <= 0)) {
        obj = current->objects[1];
        obj->setFrameTex((float)(value % 10));
        obj->m_modelAnim->m_anmObjTexPatRes->SetUpdateRate(lbl_805A23B0);
        obj->setFrameMatCol(frame);
        obj->m_modelAnim->m_anmObjMatClrRes->SetUpdateRate(lbl_805A23B0);
        obj->m_modelAnim->m_anmObjVisRes->SetUpdateRate(lbl_805A23B0);
        obj->setFrameVisible(lbl_805A23C0);
        obj->setFrameNode(lbl_805A2448);
        obj->m_modelAnim->m_anmObjChrRes->SetUpdateRate(lbl_805A23B0);
        Pushback__Q34nw4r3g3d6ScnMdlFPvPvPc(
            scene, obj->m_sceneModel, lbl_8059E268);
        current = (Self*)((char*)current + 4);
        ++i;
        value /= 10;
    }

    last = self->objects[0];
    setVisible(last, self->flags ? lbl_805A23F0 : lbl_805A23C0);
    last->m_modelAnim->m_anmObjVisRes->SetUpdateRate(lbl_805A23B0);
    last->setFrameMatCol(frame);
    last->m_modelAnim->m_anmObjMatClrRes->SetUpdateRate(lbl_805A23B0);
    last->setFrameNode(lbl_805A2448);
    last->m_modelAnim->m_anmObjChrRes->SetUpdateRate(lbl_805A23B0);
    Pushback__Q34nw4r3g3d6ScnMdlFPvPvPc(
        scene, last->m_sceneModel, lbl_8059E268);
}