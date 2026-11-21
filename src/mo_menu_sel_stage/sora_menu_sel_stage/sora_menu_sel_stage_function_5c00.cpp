#include <mu/mu_object.h>
#pragma force_active on

class Scene {
public:
    virtual void s08(); virtual void s0C(); virtual void s10(); virtual void s14();
    virtual void s18(); virtual void s1C(); virtual void s20(); virtual void s24();
    virtual void s28(); virtual void s2C(); virtual void s30(); virtual void s34();
    virtual void s38(); virtual void detach(void*);
};

struct ResourceOwner { char pad[0x10]; void* resource; };

struct Menu {
    char pad0[0x50];
    Scene* scene;
    MuObject* models[109];
    char pad1[0x0C];
    Scene* scn;
    char pad2[0x2C];
    int mode;
    int selected;
    char pad3[0x5F00];
    int base;
};

extern const float lbl_11_rodata_0[];
extern const char lbl_11_data_290[];
extern int lbl_11_data_43C;
extern int lbl_11_data_440[];
extern int lbl_11_data_490;
extern int lbl_11_data_498[];
extern signed char lbl_11_bss_C;
extern signed char lbl_11_bss_D;

extern "C" {
void fn_801AAFF0(void*, int);
void fn_801AB014(void*, int);
void Pushback__Q34nw4r3g3d6ScnMdlFPvPvPc(void*, void*, char*);
void fn_800B3C5C(void*, const void*, int);
void fn_11_6130(void*, int);
int sprintf(char*, const char*, ...);
}

inline void resetScene(Menu* self) {
    self->scn->detach(((ResourceOwner*)self->models[108])->resource);
    MuObject* object;
    int frame;
    int i;
    for (i = 0; i < 7; i++) {
        object = self->models[i + 93];
        if (object) {
            object->setFrameVisible(lbl_11_rodata_0[0]);
            frame = i + self->base + 12;
            fn_801AAFF0(object->m_scnMdl, frame);
            fn_801AB014(object->m_scnMdl, frame);
        }
    }
}
inline void attachScene(Menu* self, int index) {
    ResourceOwner* owner = (ResourceOwner*)self->models[108];
    void* res = owner->resource;
    char buffer[0x10];
    sprintf(buffer, lbl_11_data_290, index + 1);
    Pushback__Q34nw4r3g3d6ScnMdlFPvPvPc(self->scn, res, buffer);
}
inline int resolveStage(Menu* self, int stage) {
    if (stage != 0) return stage;
    stage = 0;
    if (self->selected >= 0) stage = self->selected + 2;
    return stage;
}
extern "C" void fn_11_5C00(Menu* self, int stage) {
    int old = self->mode;
    int index = -1;
    char* p;
    MuObject* object;
    int frame;
    int i;
    void* res;
    int change = 0;
    if (stage != old) {
        if (stage >= 2 && stage < 0x29) {
            index = stage - 2;
            if (old == 0 && index == self->selected) change = 0;
            else change = 1;
        } else if (stage != 0) {
            index = -1;
        } else {
            index = self->selected;
            if (index >= 0) {
                if (old < 2 || old >= 0x29) change = 1;
                else change = 0;
            }
        }
        if (index >= 0) {
            self->scn->detach(((ResourceOwner*)self->models[108])->resource);
            p = (char*)self;
            i = 0;
            do {
                object = *(MuObject**)(p + 0x1C8);
                if (object != 0) {
                    object->setFrameVisible(lbl_11_rodata_0[0]);
                    frame = i + self->base + 0xC;
                    fn_801AAFF0(object->m_scnMdl, frame);
                    fn_801AB014(object->m_scnMdl, frame);
                }
                i++;
                p += 4;
            } while (i < 7);
            attachScene(self, index);
            if (change) {
                if (lbl_11_bss_C == 0) {
                    lbl_11_data_440[3] = lbl_11_data_43C;
                    lbl_11_data_440[8] = lbl_11_data_43C;
                    lbl_11_data_440[13] = lbl_11_data_43C;
                    lbl_11_data_440[18] = lbl_11_data_43C;
                    lbl_11_bss_C = 1;
                }
                if (lbl_11_bss_D == 0) {
                    lbl_11_data_498[3] = lbl_11_data_490;
                    lbl_11_data_498[8] = lbl_11_data_490;
                    lbl_11_data_498[13] = lbl_11_data_490;
                    lbl_11_data_498[18] = lbl_11_data_490;
                    lbl_11_bss_D = 1;
                }
                if (index >= 0) fn_800B3C5C(self->models[index + 14], &lbl_11_data_440[5], 1);
                else fn_800B3C5C(self->models[104], &lbl_11_data_498[5], 1);
                if (index >= 0) fn_800B3C5C(self->models[index + 53], &lbl_11_data_440[5], 1);
            }
        } else {
            resetScene(self);
        }
        if (index >= 0) self->selected = index;
        stage = resolveStage(self, stage);
        if (stage != 0) fn_11_6130(self, stage);
        else self->scene->detach(((ResourceOwner*)self->models[11])->resource);
    }
}
