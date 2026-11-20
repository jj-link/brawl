#pragma force_active on

#include <gf/gf_model.h>
#include <gf/gf_heap_manager.h>
#include <sr/sr_common.h>

extern "C" {
void fn_8018E5D4(nw4r::g3d::ResFile* dst, const nw4r::g3d::ResFile* src);
int fn_8018D108(nw4r::g3d::ResFile* resFile, int idx);
int fn_8018E458(nw4r::g3d::ResFile* resFile);
int fn_8018E4A4(nw4r::g3d::ResFile* resFile);
int fn_8018E4F0(nw4r::g3d::ResFile* resFile);
int fn_8018E40C(nw4r::g3d::ResFile* resFile);
int fn_8018E53C(nw4r::g3d::ResFile* resFile);
void fn_801AAFF0(void* scnMdl, int value);
void fn_801AB014(void* scnMdl, int value);
nw4r::g3d::ScnMdl* fn_801B0B40(MEMAllocator* allocator, u32* size, nw4r::g3d::ResMdl* resMdl, u32 flags, int one, void (*callback)());
void fn_801B0A28();
void setFrame__16gfModelAnimationFd(gfModelAnimation* self, double frame);
void* __nw__FUlQ25Heaps8HeapType(u32, Heaps::HeapType);
void* __ct1__16gfModelAnimationFd(void*, void*, void*, int, int, Heaps::HeapType);
extern int lbl_80455D70[4];
extern const float lbl_805A2200;
}

class MuObject {
public:
    u32 flags;
    u32 unk4;
    u32 unk8;
    nw4r::g3d::ScnMdl* m_scnMdl;
    nw4r::g3d::ScnMdl* m_sceneModel;
    gfModelAnimation* m_modelAnim;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    u8 unk38;
    float unk3C;
    float unk40;
    float unk44;
    float unk48;
    float unk4C;
    float unk50;
    Heaps::HeapType m_heap;
    int unk58;
    void* unk5C;
};

extern "C" MuObject* fn_800B2474(MuObject* self, nw4r::g3d::ResFile* modelFile, int modelNode, int priority, nw4r::g3d::ResFile* textureFile, int doAnim, Heaps::HeapType heap) {
    u32 size;
    u32 textureCopy;
    u32 sp14;
    u32 resMdlCopy;
    u32 resFileCopy;
    u32 selfCopy;
    void* vt = lbl_80455D70;
    int* p = &self->unk24;
    self->unk5C = vt;
    self->flags |= 0x80000000;
    self->unk4 = 0;
    self->unk8 = 0;
    self->m_scnMdl = NULL;
    self->m_sceneModel = NULL;
    self->m_modelAnim = NULL;
    self->unk18 = 0;
    self->unk1C = 0;
    self->unk20 = 0;
    do {
        *p = 0;
        p++;
    } while (p < &self->unk34);
    self->unk34 = -1;
    self->unk38 = 0xFF;
    self->m_heap = (Heaps::HeapType)0x2B;
    self->unk58 = 0;
    MEMAllocator* allocator = gfHeapManager::getMEMAllocator(heap);
    self->m_heap = heap;
    self->unk4 = *(u32*)modelFile;
    if (textureFile != NULL) {
        textureCopy = *(u32*)textureFile;
        fn_8018E5D4((nw4r::g3d::ResFile*)&self->unk4, (const nw4r::g3d::ResFile*)&textureCopy);
    } else {
        selfCopy = self->unk4;
        fn_8018E5D4((nw4r::g3d::ResFile*)&self->unk4, (const nw4r::g3d::ResFile*)&selfCopy);
    }
    self->unk8 = fn_8018D108((nw4r::g3d::ResFile*)&self->unk4, modelNode);
    u32 animFlags;
    if (doAnim != 0) {
        u32 flags = 0;
        if (fn_8018E458((nw4r::g3d::ResFile*)&self->unk4) != 0) {
            flags |= 0x10B;
        }
        if (fn_8018E4A4((nw4r::g3d::ResFile*)&self->unk4) != 0) {
            flags |= 3;
        }
        if (fn_8018E4F0((nw4r::g3d::ResFile*)&self->unk4) != 0) {
            flags |= 0x204;
        }
        if (fn_8018E40C((nw4r::g3d::ResFile*)&self->unk4) != 0) {
            flags |= 0x40;
        }
        if (fn_8018E53C((nw4r::g3d::ResFile*)&self->unk4) != 0) {
            flags |= 0x7000;
        }
        animFlags = flags | 0x10B;
    } else {
        animFlags = 0;
    }
    sp14 = self->unk8;
    textureFile = (nw4r::g3d::ResFile*)fn_801B0B40(allocator, &size, (nw4r::g3d::ResMdl*)&sp14, animFlags, 1, fn_801B0A28);
    if (priority != 0) {
        fn_801AAFF0(textureFile, priority);
        fn_801AB014(textureFile, priority);
    }
    self->m_scnMdl = (nw4r::g3d::ScnMdl*)textureFile;
    self->m_sceneModel = (nw4r::g3d::ScnMdl*)textureFile;
    self->unk44 = lbl_805A2200;
    self->unk40 = lbl_805A2200;
    self->unk3C = lbl_805A2200;
    self->unk50 = lbl_805A2200;
    self->unk4C = lbl_805A2200;
    self->unk48 = lbl_805A2200;
    char* node = (char*)((nw4r::g3d::ResMdl*)&self->unk8)->GetResNode(0).ptr();
    for (;;) {
        int off = *(int*)(node + 0x5C);
        char* next;
        if (off == 0) {
            next = NULL;
        } else {
            next = node + off;
        }
        if (next == NULL) {
            break;
        }
        node = next;
    }
    self->unk34 = node ? *(int*)(node + 0xC) : 0;
    if (doAnim == 0) {
        return self;
    }
    modelFile = (nw4r::g3d::ResFile*)__nw__FUlQ25Heaps8HeapType(0x20, heap);
    if (modelFile) {
        resMdlCopy = self->unk8;
        resFileCopy = self->unk4;
        modelFile = (nw4r::g3d::ResFile*)__ct1__16gfModelAnimationFd(modelFile, &resFileCopy, &resMdlCopy, 1, modelNode, heap);
    }
    gfModelAnimation::bind((nw4r::g3d::ScnMdl*)textureFile, (gfModelAnimation*)modelFile);
    self->m_modelAnim = (gfModelAnimation*)modelFile;
    ((gfModelAnimation*)modelFile)->_spacer[0] = 0;
    setFrame__16gfModelAnimationFd((gfModelAnimation*)modelFile, lbl_805A2200);
    return self;
}
