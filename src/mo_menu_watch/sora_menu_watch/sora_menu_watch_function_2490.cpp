#include <mu/mu_object.h>
#include <nw4r/g3d/g3d_scngroup.h>
#include <stdio.h>
#include <types.h>
#pragma force_active on

struct WatchObj {
    char pad0[0x80];
    MuObject* objects[3];
    char pad1[0x198 - 0x8c];
    nw4r::g3d::ScnGroup* scene;
};

extern "C" const char lbl_15_data_150[];
extern "C" void Pushback__Q34nw4r3g3d6ScnMdlFPvPvPc(void*, void*, char*);

inline int minValue(int a, int b) { return a < b ? a : b; }
inline int clampValue(int value) {
    return minValue(value & ((-value & ~value) >> 31), 999);
}

inline void removeDigits(WatchObj* self, nw4r::g3d::ScnGroup* scene) {
    for (int i = 0; i < 3; ++i) {
        scene->Remove(self->objects[i]->m_sceneModel);
    }
}

inline void showDigits(WatchObj* self, int value) {
    int num;
    nw4r::g3d::ScnGroup* scene = self->scene;
    int count;
    removeDigits(self, scene);
    num = clampValue(value);
    count = 0;
    char buf[8];
    while (count < 3 && (num > 0 || count == 0)) {
        MuObject* obj = self->objects[count];
        sprintf(buf, lbl_15_data_150, count);
        Pushback__Q34nw4r3g3d6ScnMdlFPvPvPc(scene, obj->m_sceneModel, buf);
        obj->setFrameTex((float)(num % 10));
        ++count;
        num /= 10;
    }
}

extern "C" void fn_15_2490(WatchObj* self, int value) {
    showDigits(self, value);
}
