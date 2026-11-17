#pragma force_active on
#include <types.h>
#include <gf/gf_heap_manager.h>
#include <gf/gf_model.h>
#include <nw4r/g3d/g3d_scnmdl.h>
#include <stdio.h>

struct Obj {
    char pad[0x10];
    void* scn;
    gfModelAnimation* anim;
};

struct Self {
    char pad[0x3E0];
    Obj* objs[0xD6];
    void* mdls[0x1E];
};

extern "C" {
extern char lbl_1_data_4DF0[];
void Pushback__Q34nw4r3g3d6ScnMdlFPvPvPc(void*, void*, char*);
}

extern "C" void fn_1_12C78(Self* self)
{
    char* dt = lbl_1_data_4DF0;
    MEMAllocator* alloc;
    int buf8[2];
    char name[32];

    for (u32 i = 0; i < 0xD6; i++) {
        self->objs[i]->anim->setUpdateRate(0.0f);
    }

    alloc = gfHeapManager::getMEMAllocator((Heaps::HeapType)0x2A);

    const u8 tbl[96] = {
        0x00, 0x01, 0x01, 0x00, 0x01, 0x00, 0x18, 0x00, 0x02, 0x00, 0x02, 0x01,
        0x02, 0x00, 0x19, 0x00, 0x02, 0x00, 0x19, 0x00, 0x19, 0x00, 0x19, 0x00,
        0x02, 0x00, 0x04, 0x01, 0x04, 0x01, 0x17, 0x01, 0x17, 0x01, 0x17, 0x01,
        0x17, 0x01, 0x17, 0x01, 0x04, 0x01, 0x04, 0x01, 0x0A, 0x01, 0x19, 0x00,
        0x1A, 0x00, 0x1A, 0x00, 0x1A, 0x00, 0x1A, 0x00, 0x1A, 0x00, 0x1B, 0x00,
        0x1B, 0x00, 0x1B, 0x00, 0x1B, 0x00, 0x1B, 0x00, 0x03, 0x00, 0x03, 0x00,
        0x03, 0x00, 0x01, 0x00, 0x04, 0x01, 0x04, 0x01, 0x00, 0x01, 0x19, 0x01,
        0x19, 0x01, 0x19, 0x01, 0x19, 0x01, 0x19, 0x01, 0x19, 0x01, 0x00, 0x00
    };
    int cnt[30] = { 16, 6, 2, 4, 2, 2, 1, 1, 1, 4, 7, 7, 1, 3, 6, 5, 5, 2, 1, 5, 1, 1, 4, 1, 1, 2, 1, 5, 1, 2 };
    int idx[30] = { 42, 43, 74, 76, 85, 88, 89, 90, 91, 112, 117, 125, 134, 136, 140, 141, 153, 159, 160, 163, 164, 170, 172, 180, 190, 191, 195, 196, 201, 210 };

    for (u32 i = 0; i < 0x1E; i++) {
        self->mdls[i] = nw4r::g3d::ScnMdl::Construct(alloc, (int)buf8, cnt[i], self->objs[idx[i]]->scn);
    }

    for (u32 i = 0; i < 8; i++) {
        sprintf(name, dt + 0xB8, i);
        Pushback__Q34nw4r3g3d6ScnMdlFPvPvPc(self->mdls[0], self->objs[0x3C + i]->scn, name);
    }
    for (u32 i = 0; i < 5; i++) {
        sprintf(name, dt + 0xB8, i);
        Pushback__Q34nw4r3g3d6ScnMdlFPvPvPc(self->mdls[1], self->objs[0x44 + i]->scn, name);
    }

    Pushback__Q34nw4r3g3d6ScnMdlFPvPvPc(self->mdls[2], self->objs[0x4B]->scn, dt + 0xC0);
    Pushback__Q34nw4r3g3d6ScnMdlFPvPvPc(self->mdls[4], self->objs[0x56]->scn, dt + 0xC8);
    Pushback__Q34nw4r3g3d6ScnMdlFPvPvPc(self->mdls[4], self->objs[0x57]->scn, dt + 0xD4);

    for (int i = 0; i < 4; i++) {
        Pushback__Q34nw4r3g3d6ScnMdlFPvPvPc(self->mdls[5 + i], self->objs[0x5C + i]->scn, dt + 0xC0);
    }
    Pushback__Q34nw4r3g3d6ScnMdlFPvPvPc(self->mdls[5], self->objs[0x60]->scn, dt + 0xC0);

    for (int i = 0; i < 4; i++) {
        sprintf(name, dt + 0xB8, i);
        Pushback__Q34nw4r3g3d6ScnMdlFPvPvPc(self->mdls[9], self->objs[0x71 + i]->scn, name);
    }
    for (int i = 0; i < 7; i++) {
        sprintf(name, dt + 0xB8, i);
        Pushback__Q34nw4r3g3d6ScnMdlFPvPvPc(self->mdls[10], self->objs[0x76 + i]->scn, name);
    }

    Pushback__Q34nw4r3g3d6ScnMdlFPvPvPc(self->mdls[12], self->objs[0x87]->scn, dt + 0xC0);
    Pushback__Q34nw4r3g3d6ScnMdlFPvPvPc(self->mdls[13], self->objs[0x89]->scn, dt + 0xC0);
    Pushback__Q34nw4r3g3d6ScnMdlFPvPvPc(self->mdls[13], self->objs[0x8A]->scn, dt + 0xE0);
    Pushback__Q34nw4r3g3d6ScnMdlFPvPvPc(self->mdls[13], self->objs[0x8B]->scn, dt + 0xE8);

    for (int i = 0; i < 6; i++) {
        sprintf(name, dt + 0xB8, i);
        Pushback__Q34nw4r3g3d6ScnMdlFPvPvPc(self->mdls[14], self->objs[0x8E + i]->scn, name);
    }
    for (int i = 0; i < 5; i++) {
        sprintf(name, dt + 0xB8, i);
        Pushback__Q34nw4r3g3d6ScnMdlFPvPvPc(self->mdls[15], self->objs[0x94 + i]->scn, name);
    }
    for (int i = 0; i < 5; i++) {
        sprintf(name, dt + 0xB8, i);
        Pushback__Q34nw4r3g3d6ScnMdlFPvPvPc(self->mdls[16], self->objs[0x9A + i]->scn, name);
    }

    Pushback__Q34nw4r3g3d6ScnMdlFPvPvPc(self->mdls[17], self->mdls[18], dt + 0xC0);
    Pushback__Q34nw4r3g3d6ScnMdlFPvPvPc(self->mdls[17], self->objs[0xA2]->scn, dt + 0xE0);
    Pushback__Q34nw4r3g3d6ScnMdlFPvPvPc(self->mdls[18], self->objs[0xA1]->scn, dt + 0xC0);
    Pushback__Q34nw4r3g3d6ScnMdlFPvPvPc(self->mdls[19], self->mdls[20], dt + 0xC0);
    Pushback__Q34nw4r3g3d6ScnMdlFPvPvPc(self->mdls[19], self->objs[0xA6]->scn, dt + 0xE0);
    Pushback__Q34nw4r3g3d6ScnMdlFPvPvPc(self->mdls[20], self->objs[0xA5]->scn, dt + 0xC0);
    Pushback__Q34nw4r3g3d6ScnMdlFPvPvPc(self->mdls[21], self->objs[0xAB]->scn, dt + 0xC0);
    Pushback__Q34nw4r3g3d6ScnMdlFPvPvPc(self->mdls[23], self->objs[0xB5]->scn, dt + 0xC0);
    Pushback__Q34nw4r3g3d6ScnMdlFPvPvPc(self->mdls[25], self->objs[0xC1]->scn, dt + 0xC0);
    Pushback__Q34nw4r3g3d6ScnMdlFPvPvPc(self->mdls[25], self->objs[0xC2]->scn, dt + 0xC0);
    Pushback__Q34nw4r3g3d6ScnMdlFPvPvPc(self->mdls[24], self->mdls[25], dt + 0xC0);
    Pushback__Q34nw4r3g3d6ScnMdlFPvPvPc(self->mdls[28], self->objs[0xCA]->scn, dt + 0xC0);
}
