#include <types.h>
#include <nw4r/g3d/g3d_scnmdl.h>
#include <nw4r/g3d/g3d_resmat.h>
#include <nw4r/g3d/g3d_resfile.h>
#include <gf/gf_copyefb.h>
#include <gf/gf_heap_manager.h>
#include <gf/gf_3d_scene.h>
#pragma force_active on

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual s32 slot4();
    virtual void slot5();
    virtual void slot6(s32, s32);
    virtual void slot7();
    virtual void slot8();
    virtual void* slot9();
    virtual void slot10();
    virtual void* slot11();
};

struct Class_90D8_base {
    char pad[8];
};

class Class_90D8 : public Class_90D8_base {
public:
    virtual void fn_27_7B274();
    virtual void fn_27_7AC18();
    virtual void fn_27_7AC28();
    virtual void fn_27_7AB50();
    virtual Object_vptr_0* fn_27_7B2EC();
    virtual void fn_27_7AB10();
    virtual void fn_27_7AD2C();
    virtual void* fn_27_7AEDC(void*, s32);
    virtual void* fn_27_7B22C(void*, s32);
};

struct HeapSource {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual Heaps::HeapType getHeapType();
};

struct HeapLevel2 {
    char pad[0xc0];
    HeapSource* heap;
};

struct HeapLevel1 {
    char pad[0xd8];
    HeapLevel2* level2;
};

struct MatAccess : nw4r::g3d::ScnMdl::CopiedMatAccess {
    char padding[16];

    MatAccess(nw4r::g3d::ScnMdl* model, u32 index)
        : nw4r::g3d::ScnMdl::CopiedMatAccess(model, index) {}
};

struct SelfObject {
    char pad[0xc8];
    HeapLevel1* level1;
};

extern "C" {
void fn_8018E808(void*);
void* fn_8018D174(void*, s32);
void fn_8018E5D4(void*, void*);
void* fn_8018D3F0(void*, s32);
u32 fn_8018F394(void*);
void* fn_8018F340(void*, s32);
void* fn_8018ECCC(void*, s32);
void* fn_801B0B40(void*, s32*, void**, s32, s32, void (*)());
void* fn_801B00FC(void*);
u32 fn_80190C60(void*, s32);
u32 fn_801F2D00(void*);
void fn_27_FF24(void*);
void fn_27_1004C(void*);
void fn_80047FCC();
char* strrchr(const char*, int);
int strcmp(const char*, const char*);
}

extern s32 lbl_27_data_4B8[];

extern "C" void fn_27_88E4(
    u8* self, Class_90D8* src, s32 layer, s32 arg3,
    void* arg4, s32 arg5, const char* arg6, s32 arg7)
{
    void* fileA;
    void* resList;
    void* fileB;
    void* fileC;
    s32 sp1C;
    void* sp18;
    void* copyB;
    void* copyC;
    void* spc;
    void* sp8;
    void* var31;
    void* scn;
    void* z4;
    GXTexObj cp;

    fileA = src->fn_27_7B22C(src->fn_27_7B2EC()->slot11(), arg7);
    fn_8018E808(&fileA);
    resList = fn_8018D174(&fileA, 0);
    nw4r::g3d::ResFile::Init(&fileA);

    if (arg4 != 0) {
        fileB = arg4;
        nw4r::g3d::ResFile::Init(&fileB);
        copyB = fileB;
        fn_8018E5D4(&fileA, &copyB);
    }

    void* resource = src->fn_27_7AEDC(src->fn_27_7B2EC()->slot9(), arg7);
    var31 = 0;
    if (resource != 0) {
        fileC = resource;
        nw4r::g3d::ResFile::Init(&fileC);
        copyC = fileC;
        fn_8018E5D4(&fileA, &copyC);
        if (arg5 != 0)
            var31 = fn_8018D3F0(&fileC, arg5);
    }

    arg4 = gfHeapManager::getMEMAllocator(
        ((SelfObject*)self)->level1->level2->heap->getHeapType());

    if (arg6 != 0) {
        u32 k;
        u32 cnt = fn_8018F394(&resList);
        if (cnt != 0) {
            u8* p = (u8*)fn_8018F340(&resList, cnt - 1);
            s32 off = *(s32*)(p + 8);
            char* name = off != 0 ? (char*)(p + off) : 0;
            char* us = strrchr(name, 0x5f);
            if (us != 0 && strcmp(us + 1, arg6) == 0) {
                ((u8*)resList)[0x61] = 1;
                self[0xb8] = 1;
                spc = resList;
                u32 half = fn_8018F394(&spc) >> 1;
                s32* idp = lbl_27_data_4B8;
                for (k = 0; k < 2; ++k) {
                    u8* q = (u8*)fn_8018ECCC(&spc, *idp);
                    if (q != 0 &&
                        (s32)(((u32)q[1] << 8) | q[2]) >= (s32)half) {
                        while (q[0] != 1) {
                            u32 nv = (((u32)q[1] << 8) | q[2]) - half;
                            q[1] = (u8)(nv >> 8);
                            q[2] = (u8)nv;
                            q += 8;
                        }
                    }
                    ++idp;
                }
            }
        }
    }

    z4 = 0;
    sp1C = 0;
    sp8 = resList;
    scn = fn_801B0B40(arg4, &sp1C, &sp8, arg3, 1, fn_80047FCC);
    *(u16*)(self + 0xc0) = 1;
    g_gfSceneRoot->add(
        (gfSceneRoot::LayerType)layer, (nw4r::g3d::ScnMdl*)scn);
    *(void**)((u8*)scn + 0x11c) = self + 0x2c;
    fn_27_FF24(scn);
    *(void**)((u8*)scn + 0xd4) = self + 0x34;
    fn_27_1004C(scn);

    if (var31 != 0) {
        s32 off2 = *(s32*)((u8*)var31 + 0x10);
        if (off2 != 0)
            z4 = (u8*)var31 + off2;

        u32 textureAddress = (u32)z4 & 0x1fffffff;
        if (gfCopyEFBMgr::getInstance()->isValid(1) == 1)
            cp = *gfCopyEFBMgr::getInstance()->getCopyEFBTex(1);

        for (u32 idx = 0; idx < fn_8018F394(&resList); ++idx) {
            MatAccess access((nw4r::g3d::ScnMdl*)scn, idx);
            sp18 = fn_801B00FC(&access);
            for (s32 j = 0; j < 8; ++j) {
                if (fn_80190C60(&sp18, j) == 1) {
                    if (textureAddress ==
                        (fn_801F2D00(
                            ((nw4r::g3d::ResTexObj*)&sp18)->GetTexObj(
                                (GXTexMapID)j)) & 0x1fffffff)) {
                        *((nw4r::g3d::ResTexObj*)&sp18)->GetTexObj(
                            (GXTexMapID)j) = cp;
                    }
                }
            }
        }
    }

    *(void**)(self + 0xc) = scn;
    *(s32*)(self + 0x10) = layer;
    ((Object_vptr_0*)scn)->slot6(2, 1);
}
