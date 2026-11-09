#include <types.h>
#pragma force_active on

struct Pad5C {
    char pad[0x5C];
};

struct IObj : Pad5C {
    virtual void v0(int);
};

extern "C" {
void remove__11gfSceneRootFPQ34nw4r3g3d6ScnMdl(void* root, void* mdl);
void exit__6gfTaskFv(void* task);
void fn_8007EA78(void* p, int x);
void fn_8000D7B8(void* root);
void* getBuffer__14gfFileIOHandleCFv(void* h);
void free__13gfHeapManagerFPv(void* p);
void release__14gfFileIOHandleFv(void* h);
void fn_803F0D4C(u32 n, void (*dt)(void*, s16));
void __dt__14gfFileIOHandleFv(void* h, s16 flag);
void* __dt__9gfArchiveFv(void* a, s16 flag);
void* getInstance__14gfSceneManagerFv(void);
void* __dynamic_cast(void* p, s32 a, const void* b, const void* c, s32 d);
void fn_2_12F58(void);
void fn_801E9F0C(int);
void fn_80073F84(void* snd, int x);
void setBGMVol__9sndSystemFbf(void* snd, bool b, f32 v);
void playBGM__9sndSystemFiUlb(void* snd, s32 a, u32 b, bool c);

extern void* g_gfSceneRoot;
extern void* g_sndSystem;
extern char lbl_2_data_19A0[];
extern char lbl_2_data_19D0[];
extern f32 lbl_2_rodata_AB8;

void fn_2_246B8(void* arg0) {
    char* self = (char*)arg0;

    void* p6C8 = *(void**)(self + 0x6C8);
    if (p6C8 != 0) {
        remove__11gfSceneRootFPQ34nw4r3g3d6ScnMdl(g_gfSceneRoot, *(void**)((char*)p6C8 + 0x10));
    }

    void* p6B4 = *(void**)(self + 0x6B4);
    if (p6B4 != 0) {
        remove__11gfSceneRootFPQ34nw4r3g3d6ScnMdl(g_gfSceneRoot, *(void**)((char*)p6B4 + 0x10));
    }

    void* p6CC = *(void**)(self + 0x6CC);
    if (p6CC != 0) {
        exit__6gfTaskFv(p6CC);
        *(void**)(self + 0x6CC) = 0;
    }

    void* p670 = *(void**)(self + 0x670);
    if (p670 != 0) {
        fn_8007EA78(p670, 1);
        *(void**)(self + 0x670) = 0;
    }

    IObj* p = *(IObj**)(self + 0x6C8);
    if (p != 0) {
        if (p != 0) {
            p->v0(1);
        }
        *(void**)(self + 0x6C8) = 0;
    }

    IObj* q = *(IObj**)(self + 0x6B4);
    if (q != 0) {
        if (q != 0) {
            q->v0(1);
        }
        *(void**)(self + 0x6B4) = 0;
    }

    fn_8000D7B8(g_gfSceneRoot);

    if (*(u32*)(self + 0x6AC) != 0) {
        s32 off;
        s32 i = 0;
        off = 0;
        do {
            if (*(u8*)(self + 0x6AA) != 0 || i != 2) {
                void* buf = getBuffer__14gfFileIOHandleCFv((void*)(*(u32*)(self + 0x6AC) + off));
                free__13gfHeapManagerFPv(buf);
                release__14gfFileIOHandleFv((void*)(*(u32*)(self + 0x6AC) + off));
            }
            i += 1;
            off += 4;
        } while (i < 3);
        fn_803F0D4C(*(u32*)(self + 0x6AC), __dt__14gfFileIOHandleFv);
        *(u32*)(self + 0x6AC) = 0;
    }

    void* p6BC = *(void**)(self + 0x6BC);
    if (p6BC != 0) {
        __dt__9gfArchiveFv(p6BC, 1);
        *(void**)(self + 0x6BC) = 0;
    }

    void* p6B8 = *(void**)(self + 0x6B8);
    if (p6B8 != 0) {
        free__13gfHeapManagerFPv(p6B8);
        *(void**)(self + 0x6B8) = 0;
    }

    void* inst = getInstance__14gfSceneManagerFv();
    __dynamic_cast(*(void**)((char*)inst + 4), 4, lbl_2_data_19A0, lbl_2_data_19D0, 0);
    fn_2_12F58();
    fn_801E9F0C(1);

    if (*(u8*)(self + 0x6A9) != 0) {
        fn_80073F84(g_sndSystem, 0);
        setBGMVol__9sndSystemFbf(g_sndSystem, false, lbl_2_rodata_AB8);
    }

    s32 val = *(s32*)(self + 0x684);
    if (val >= 0) {
        playBGM__9sndSystemFiUlb(g_sndSystem, val, 0, true);
    }
}
}
