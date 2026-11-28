#include <types.h>
#include <string.h>
#include <sr/sr_common.h>
#include <nw4r/g3d/g3d_resmdl.h>
#include <gr/collision/gr_collision_data.h>
#include <gr/ground.h>

#pragma force_active on

struct Fn63Work {
    void* data;
    void* indices;
    void* entries;
    u16 count;
};

extern "C" {
extern const f32 lbl_63_rodata_0[];
extern const char lbl_63_data_568[];
bool fn_27_239FD8(void*);
}

extern "C" void fn_63_2414(
    Stage* unused, grCollData* output, Fn63Work* work, Ground* object
) {
    const f32* values = lbl_63_rodata_0;
    f32 minX;
    f32 maxX;
    f32 minY;
    f32 c1;
    f32 c0;
    f32 maxY;
    u32 raw;
    u32 nameOff;
    u32 modelNameOff;
    u32 n2;
    u16 n;
    u16 idx;
    u8 phase;
    nw4r::g3d::ResNodeData* node;
    char* name;
    char* e;
    char* modelName;
    char* name2;
    f32* p;
    s16* ip;

    if (output == 0) return;
    if (work == 0) return;
    if (object == 0) return;
    if (!fn_27_239FD8(work)) return;

    raw = work->count * 20;
    n = (u16)raw;
    minX = maxX = minY = maxY = values[0];

    work->data = operator new[]((raw * 8) & 0x7FFF8, Heaps::StageInstance);
    work->indices = operator new[](0x140, Heaps::StageInstance);
    work->entries = operator new[](0x870, Heaps::StageInstance);

    memset(work->data, 0, ((u32)n * 8) & 0x7FFF8);
    memset(work->indices, 0, 0x140);
    memset(work->entries, 0, 0x870);

    phase = 0;
    for (idx = 0; idx != n; idx++) {
        p = (f32*)((char*)work->data + idx * 8);
        switch (phase) {
        case 0:
            p[0] = values[9];
            p[1] = values[10];
            break;
        case 1:
            p[0] = values[11];
            p[1] = values[10];
            break;
        }
        if (p[0] < minX) minX = p[0];
        if (p[0] > maxX) maxX = p[0];
        if (p[1] < minY) minY = p[1];
        if (p[1] > maxY) maxY = p[1];

        phase++;
        if (phase == 2) phase = 0;
    }

    u16 base;
    for (base = 0; base < 20; ++base) {
        ip = (s16*)((char*)work->indices + (u32)base * 0x10);
        ip[0] = (u16)((u16)base * 2);
        ip[1] = (u16)base * 2 + 1;
        ip[2] = -1;
        ip[3] = -1;
        ip[4] = -1;
        ip[5] = -1;
        ip[6] = 1;
        ((u16*)ip)[7] |= 0x8100;
    }

    nw4r::g3d::ResMdl resMdl;
    nw4r::g3d::ScnMdl* sceneModel = object->m_sceneModels[0];
    if (sceneModel == 0) return;

    resMdl = sceneModel->m_resMdl;
    if (!resMdl.IsValid()) return;

    u32 j;
    u32 matchCount;
    matchCount = 0;
    j = 0;
    u32 nodeCount = resMdl.GetResNodeNumEntries();
    minX = values[0];
    maxX = values[2];

    for (; j != nodeCount; j++) {
        node = resMdl.GetResNode(j).ptr();
        nameOff = node->m_nodeNameStrOffset;
        name = nameOff ? (char*)node + nameOff : 0;

        if (strstr(name, lbl_63_data_568) != 0) {
            e = (char*)&((grCollData::JointData*)work->entries)[matchCount];
            *(u16*)e = matchCount;
            *(u16*)(e + 2) = 1;
            *(f32*)(e + 0x14) = minX;
            *(f32*)(e + 0x18) = minX;
            *(f32*)(e + 0x1C) = maxX;
            *(f32*)(e + 0x20) = maxX;
            *(u16*)(e + 0x24) = matchCount * 2;
            *(u16*)(e + 0x26) = 2;

            modelNameOff = *(s32*)((char*)resMdl.ptr() + 0x3C);
            modelName = modelNameOff
                ? (char*)resMdl.ptr() + modelNameOff
                : 0;
            strcpy(e + 0x2C, modelName);

            n2 = node->m_nodeNameStrOffset;
            name2 = n2 ? (char*)node + n2 : 0;
            strcpy(e + 0x4C, name2);

            matchCount++;
        }
    }

    output->m_vtxLen = n;
    output->m_lineLen = 20;
    output->m_jointLen = 20;
    output->m_unk1 = 0;
    output->m_vtxDatas = (grCollData::VtxData*)work->data;
    output->m_lineDatas = (grCollData::LineData*)work->indices;
    output->m_jointDatas = (grCollData::JointData*)work->entries;
}
