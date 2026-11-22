#include <mu/mu_object.h>
#include <nw4r/g3d/g3d_scngroup.h>
#include <stdio.h>
#pragma force_active on
struct Self {
    char pad[0x50];
    MuObject* digits[4];
    char pad2[0x130];
    nw4r::g3d::ScnGroup* scene;
};
extern "C" void Pushback__Q34nw4r3g3d6ScnMdlFPvPvPc(void*, void*, char*);
extern char lbl_15_data_150[];
inline int clampValue(int value) {
    int n = value & ((-value & ~value) >> 31);
    return n < 9999 ? n : 9999;
}
extern "C" void fn_15_1424(Self* self, int value) {
    MuObject* obj;
    int i;
    nw4r::g3d::ScnGroup* scene = self->scene;
    int n;
    Self* p = self;
    int j = 0;
    do {
        scene->Remove((nw4r::g3d::ScnObj*)p->digits[0]->m_sceneModel);
        p = (Self*)((char*)p + 4);
        j++;
    } while (j < 4);
    n = clampValue(value);
    i = 0;
    while (i < 4 && (n > 0 || i == 0)) {
        obj = self->digits[i];
        char name[8];
        sprintf(name, lbl_15_data_150, i + 1);
        Pushback__Q34nw4r3g3d6ScnMdlFPvPvPc(scene, obj->m_sceneModel, name);
        obj->setFrameTex((float)(n % 10));
        i++;
        n /= 10;
    }
}
