#include <types.h>
#include <mu/mu_object.h>
#include <nw4r/g3d/g3d_scnmdl.h>
#include <nw4r/g3d/g3d_scngroup.h>
#pragma force_active on

struct Entry {
    unsigned char scene;
    char pad[3];
    char* node;
    unsigned char frame;
    char tail[3];
};

struct Self {
    char pad[0x94];
    MuObject* object;
    char pad2[0x124];
    nw4r::g3d::ScnGroup* scenes[2];
};

extern "C" {
extern Entry lbl_14_rodata_3E8[];

void Pushback__Q34nw4r3g3d6ScnMdlFPvPvPc(void*, void*, char*);

inline void update(Self* self, int selected, MuObject& object) {
    int i;

    Entry* entry = lbl_14_rodata_3E8;
    for (i = 0; i < 8; i++, entry++) {
        self->scenes[entry->scene]->Remove(
            (nw4r::g3d::ScnObj*)object.m_sceneModel);
    }

    if (selected != 7) {
        Pushback__Q34nw4r3g3d6ScnMdlFPvPvPc(
            self->scenes[lbl_14_rodata_3E8[selected].scene],
            object.m_sceneModel,
            lbl_14_rodata_3E8[selected].node);
        object.setFrameNode((float)lbl_14_rodata_3E8[selected].frame);
    }
}

void fn_14_37C8(Self* self, int selected) {
    update(self, selected, *self->object);
}
}
