#include <gf/gf_pad_status.h>
#include <types.h>
#pragma force_active on

extern "C" {
extern void* g_gfPadSystem;
extern void* g_gfApplication;
extern void* g_gfSceneRoot;
extern const float lbl_1_rodata_9D0[4];

void getSysPadStatus__11gfPadSystemFiP11gfPadStatus(void*, int, gfPadStatus*);
int isReady__14gfFileIOHandleCFv(const void*);
unsigned int fn_25_1260(void*);
unsigned int fn_25_638(void*);
int fn_37_1094(void*);
void fn_37_1078(void*);
int fn_37_10FC(void*);
unsigned int fn_37_13D0(void*);
void fn_37_1424(void*);
void fn_1_20540(void*);
void fn_1_20608(void*);
void fn_1_20700(void*);
void endKeepScreen__17gfKeepFrameBufferFv(void*);
void startKeepScreen__17gfKeepFrameBufferFv(void*);
void* getInstance__14gfSceneManagerFv();
void fn_25_137C(void*);
void fn_25_1394(void*);
void fn_25_C58(void*, float, float, float, float);
void fn_25_C78(void*, int);
void fn_25_13A8(void*, void*, void*, float);
void fn_25_97C(void*);
void fn_25_A84(void*);
void fn_25_9E8(void*);
void fn_25_A90(void*);
void fn_25_339C(void*);
void fn_25_315C(void*);
void fn_8000DB40(void*, int);
}

struct FnObj {
    float x;
    float y;
    float z;
    float w;
    char* ptr;
};

struct Self {
    char pad0[8];
    void* ptr8;
    void* ptrC;
    void* ptr10;
    void* ptr14;
    char pad18[12];
    unsigned char byte24;
    unsigned char byte25;
    char pad26[2];
    int state;
    char pad2C[12];
};

extern "C" int fn_1_200F0(Self* s) {
    const float* f = lbl_1_rodata_9D0;
    gfPadStatus pad;
    FnObj o1;
    FnObj o2;

    getSysPadStatus__11gfPadSystemFiP11gfPadStatus(g_gfPadSystem, 0xf0, &pad);

    switch (s->state) {
    case 0:
        fn_1_20540(s);
        s->state = 1;
        break;

    case 1: {
        int wait;
        if (isReady__14gfFileIOHandleCFv((char*)s + 0x18) == 0) {
            wait = 1;
        } else if (fn_25_1260(s->ptr8) == 1) {
            wait = 1;
        } else if (fn_25_638(s->ptrC) == 1) {
            wait = 1;
        } else if (isReady__14gfFileIOHandleCFv((char*)s + 0x2c) == 0) {
            wait = 1;
        } else {
            wait = fn_37_1094(s->ptr14) == 1;
        }

        if (wait == 0) {
            fn_37_1078(s->ptr14);
            s->state = 2;
        }
        break;
    }

    case 2:
        if (fn_37_10FC(s->ptr14) == 0) {
            fn_1_20608(s);
            endKeepScreen__17gfKeepFrameBufferFv((char*)g_gfApplication + 0xd0);
            s->state = 3;
            if (*(int*)((char*)getInstance__14gfSceneManagerFv() + 0x280) <= 0) {
                s->state = 3;
            }
            if (*(int*)((char*)getInstance__14gfSceneManagerFv() + 0x280) >= 1) {
                *(int*)((char*)s->ptr8 + 0xac) = 1;
                fn_25_137C(s->ptr8);
                fn_25_C58(&o1, f[0], f[1], f[1], f[2]);
                fn_25_C58(&o2, f[0], f[1], f[1], f[2]);
                fn_25_13A8(s->ptr8, &o1, &o2, f[3]);
                fn_25_C78(&o2, -1);
                fn_25_C78(&o1, -1);
                s->state = 9;
            }
        }
        break;

    case 3:
        *(int*)((char*)s->ptrC + 0x80) = 1;
        *(int*)((char*)s->ptr14 + 0x12c) = 1;
        fn_25_137C(s->ptr8);
        fn_25_97C(s->ptrC);
        s->state = 4;
        break;

    case 4:
        if (*(int*)((char*)s->ptrC + 0x80) == 3) {
            s->state = 5;
        }
        break;

    case 5:
        s->state = 6;
        break;

    case 6:
        *(int*)((char*)s->ptr10 + 0x1454) = 1;
        s->state = 7;
        break;

    case 7:
        if (*(int*)((char*)s->ptr10 + 0x1454) == 11) {
            s->state = 8;
        }
        break;

    case 8:
        fn_25_A84(s->ptrC);
        fn_25_9E8(s->ptrC);
        fn_25_339C(s->ptr10);
        s->state = 9;
        break;

    case 9:
        *(int*)((char*)s->ptr14 + 0x12c) = 3;
        s->state = 10;
        break;

    case 10:
        if (*(int*)((char*)s->ptr14 + 0x12c) == 0x18) {
            s->state = 11;
        }
        break;

    case 11:
        fn_25_1394(s->ptr8);
        s->state = 12;
        break;

    case 12:
        fn_1_20700(s);
        startKeepScreen__17gfKeepFrameBufferFv((char*)g_gfApplication + 0xd0);
        {
            char* mgr = (char*)getInstance__14gfSceneManagerFv();
            *(int*)(mgr + 0x284) = 0;
            *(int*)(mgr + 0x288) = 2;
        }
        s->state = s->state + 1;
        break;
    }

    fn_8000DB40(g_gfSceneRoot, 0);
    fn_8000DB40(g_gfSceneRoot, 8);

    switch (s->state) {
    case 4:
    case 7:
    case 10:
        break;
    default:
        goto after_state_check;
    }

    if (s->byte24 == 0 && fn_37_13D0(s->ptr14) == 1 &&
        ((pad.m_buttonsPressedThisFrame.bits & 0x1000) ||
         (pad.m_buttonsPressedThisFrame.bits & 0x100000))) {
        s->byte25 = 1;
        s->byte24 = 1;
    }

    if (s->byte25 == 1) {
        fn_25_A90(s->ptrC);
        *(int*)((char*)s->ptr10 + 0x1454) = 11;
        fn_25_315C(s->ptr10);
        fn_25_339C(s->ptr10);
        *(int*)((char*)s->ptr14 + 0x12c) = 4;
        fn_37_1424(s->ptr14);
        s->state = 10;
        s->byte24 = 1;
        s->byte25 = 0;
    }

after_state_check:
    return 0;
}
