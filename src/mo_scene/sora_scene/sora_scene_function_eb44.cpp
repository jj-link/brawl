#include <types.h>
#pragma force_active on

struct Loader {
    unsigned int fields[7];
    bool a : 1;
    bool b : 1;
    bool c : 1;
    unsigned char rest : 5;
};

struct Self {
    char pad0[0x369];
    u8 b369;
    u8 b36A;
    u8 b36B;
    s32 i36C;
    u32 state;
    s32 counter;
    char* p378;
    char* p37C;
    char* p380;
    char* p384;
    char* p388;
    char* p38C;
    char* p390;
};

extern "C" {
extern char* g_gfApplication;
extern char* g_gfSceneRoot;
extern char* g_sndSystem;
extern char* g_stLoaderManager;
extern char lbl_1_data_49E0[];
extern const float lbl_1_rodata_710;
extern const float lbl_1_rodata_714;

void fn_24_2F48(void*);
void fn_1_F2E4(void*);
void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
void* __ct__9gfArchiveFv(void*);
void fn_1_3C68(void*, int, const char*, void*, int);
int fn_1_3E50(void*);
void loadMenuSound__6muMenuFv(void);
void fn_1_F48C(void*);
void fn_25_137C(void*);
void fn_25_142C(void*, float, float, float, float);
void endKeepScreen__17gfKeepFrameBufferFv(void*);
void* getInstance__14gfSceneManagerFv(void);
void startKeepScreen__17gfKeepFrameBufferFv(void*);
void fn_24_16D4(void*);
int fn_24_16F0(void*);
void fn_24_17FC(void*);
void fn_24_18E0(void*);
void fn_24_21E8(void*);
void fn_24_2170(void*);
void fn_24_2270(void*);
void fn_24_2950(void*);
void fn_24_1928(void*);
void fn_24_1940(void*);
void fn_24_1958(void*);
void fn_24_20D4(void*);
void fn_24_22D8(void*);
void fn_24_2388(void*);
unsigned int fn_24_2FC8(void*);
unsigned int fn_24_31F4(void*);
unsigned int fn_24_33CC(void*, int);
void fn_25_1394(void*);
void fn_25_2FFC(void*);
void fn_25_315C(void*);
void fn_25_339C(void*);
void fn_1_F388(void*);
void fn_8000DB40(void*, int);
void playSE__9sndSystemF5SndIDiiii(void*, int, int, int, int, int);
}

extern "C" int fn_1_EB44(Self* self) {
    fn_24_2F48(self->p390);
    switch (self->state) {
    case 0: {
        fn_1_F2E4(self);
        char* a = (char*)__nw__FUlQ25Heaps8HeapType(0x80, 0x2B);
        if (a != 0) a = (char*)__ct__9gfArchiveFv(a);
        self->p378 = a;
        Loader* obj = (Loader*)__nw__FUlQ25Heaps8HeapType(0x20, 0x2B);
        if (obj != 0) {
            obj->fields[0] = 0;
            obj->fields[1] = 0;
            obj->fields[2] = 0;
            obj->fields[3] = 0;
            obj->fields[4] = 0;
            obj->a = false;
            obj->b = false;
            obj->fields[6] = 0;
            obj->fields[5] = 0xff;
            obj->c = false;
        }
        self->p37C = (char*)obj;
        fn_1_3C68(obj, 0x2B, lbl_1_data_49E0, self->p378, 0);
        self->state = 1;
        break;
    }
    case 1: {
        u32 v = (fn_1_3E50(self->p37C) == 0);
        if (v == 0) self->state = 2;
        break;
    }
    case 2:
        loadMenuSound__6muMenuFv();
        fn_1_F48C(self);
        if (self->p380 != 0) {
            *(int*)(self->p380 + 0xAC) = 1;
            fn_25_137C(self->p380);
            fn_25_142C(self->p380, lbl_1_rodata_710, lbl_1_rodata_710, lbl_1_rodata_710, lbl_1_rodata_710);
        }
        endKeepScreen__17gfKeepFrameBufferFv(g_gfApplication + 0xD0);
        if (*(int*)((char*)getInstance__14gfSceneManagerFv() + 0x280) != 1) {
            fn_24_16D4(self->p38C);
            self->state = 3;
        } else {
            self->state = 0xC;
        }
        break;
    case 3:
        if (fn_24_16F0(self->p38C) == 0) self->state = 4;
        break;
    case 4:
        *(int*)(self->p38C + 0x60) = 1;
        fn_24_17FC(self->p38C);
        fn_24_18E0(self->p38C);
        self->state = 5;
        self->counter = 0;
        break;
    case 5:
        if (self->counter >= 0x10) self->state = 6;
        break;
    case 6:
        *(int*)(self->p384 + 0x1454) = 1;
        self->state = 7;
        break;
    case 7:
        if (*(int*)(self->p384 + 0x1454) == 0xB) self->state = 8;
        break;
    case 8:
        *(int*)(self->p388 + 0x78) = 1;
        fn_24_21E8(self->p388);
        *(u8*)(self->p388 + 0x73) = 1;
        self->state = 9;
        break;
    case 9:
        if (*(int*)(self->p38C + 0x5C) >= 0xBB) {
            *(int*)(self->p388 + 0x78) = 0x12;
            self->state = 0xA;
        }
        break;
    case 10:
        *(int*)(self->p384 + 0x1454) = 0xC;
        fn_25_315C(self->p384);
        fn_25_339C(self->p384);
        *(int*)(self->p388 + 0x78) = 0x13;
        fn_24_2950(self->p388);
        fn_24_2170(self->p388);
        fn_24_2270(self->p388);
        fn_24_1928(self->p38C);
        self->state = 0xB;
        break;
    case 11:
        if (*(int*)(self->p38C + 0x5C) >= 0xD1A) self->state = 0xC;
        break;
    case 12: {
        char* t = self->p38C;
        if (t != 0) fn_24_1940(t);
        *(int*)(self->p388 + 0x78) = 1;
        fn_24_20D4(self->p388);
        *(u8*)(self->p388 + 0x73) = 0;
        self->state = 0xD;
        break;
    }
    case 13: {
        char* t = self->p38C;
        u32 v;
        if (t == 0) {
            v = 1;
        } else {
            v = (*(int*)(t + 0x60) - 3) == 0;
        }
        if (v == 1) self->state = 0xE;
        break;
    }
    case 14: {
        char* q;
        q = *(char**)g_stLoaderManager;
        if (q != 0) *(u8*)(q + 0x5D) = (u8)(*(u8*)(q + 0x5D) & 0xFFFFFFDF);
        q = *(char**)(g_stLoaderManager + 4);
        if (q != 0) *(u8*)(q + 0x5D) = (u8)(*(u8*)(q + 0x5D) & 0xFFFFFFDF);
        q = *(char**)(g_stLoaderManager + 8);
        if (q != 0) *(u8*)(q + 0x5D) = (u8)(*(u8*)(q + 0x5D) & 0xFFFFFFDF);
        q = *(char**)(g_stLoaderManager + 0xC);
        if (q != 0) *(u8*)(q + 0x5D) = (u8)(*(u8*)(q + 0x5D) & 0xFFFFFFDF);
        self->state = 0xF;
        break;
    }
    case 15: {
        char* p = self->p388;
        if (*(int*)(p + 0x78) == 0x12) {
            if (*(u8*)(p + 0x72) == 1) {
                self->i36C = 1;
            } else {
                self->i36C = 0;
            }
            self->state = 0x12;
        }
        break;
    }
    case 16: {
        char* t = self->p380;
        if (t != 0) fn_25_1394(t);
        if (self->p384 != 0) {
            *(int*)(self->p384 + 0x1454) = 0xC;
            fn_25_315C(self->p384);
            fn_25_339C(self->p384);
        }
        if (self->p388 != 0) {
            *(int*)(self->p388 + 0x78) = 0x13;
            fn_24_2170(self->p388);
        }
        fn_1_F388(self);
        self->state = 0x11;
        break;
    }
    case 17: {
        startKeepScreen__17gfKeepFrameBufferFv(g_gfApplication + 0xD0);
        int v = self->i36C;
        char* mgr = (char*)getInstance__14gfSceneManagerFv();
        *(int*)(mgr + 0x284) = v;
        *(int*)(mgr + 0x288) = 2;
        break;
    }
    case 18: {
        char* t = self->p380;
        if (t != 0) fn_25_1394(t);
        if (self->p384 != 0) {
            *(int*)(self->p384 + 0x1454) = 0xC;
            fn_25_315C(self->p384);
            fn_25_339C(self->p384);
        }
        if (self->p388 != 0) {
            *(int*)(self->p388 + 0x78) = 0x13;
            fn_24_2170(self->p388);
        }
        fn_1_F388(self);
        startKeepScreen__17gfKeepFrameBufferFv(g_gfApplication + 0xD0);
        int v = self->i36C;
        char* mgr = (char*)getInstance__14gfSceneManagerFv();
        *(int*)(mgr + 0x284) = v;
        *(int*)(mgr + 0x288) = 2;
        self->state = self->state + 1;
        break;
    }
    }

    self->counter = self->counter + 1;
    fn_8000DB40(g_gfSceneRoot, 0);
    fn_8000DB40(g_gfSceneRoot, 8);

    switch (self->state) {
    case 5:
    case 7:
    case 9:
    case 11:
        if (self->b369 == 0) {
            if (fn_24_2FC8(self->p390) == 1) {
                playSE__9sndSystemF5SndIDiiii(g_sndSystem, 1, -1, 0, 0, -1);
                playSE__9sndSystemF5SndIDiiii(g_sndSystem, 0x13, -1, 0, 0, -1);
                self->b36B = 1;
                self->b369 = 1;
            } else if (fn_24_31F4(self->p390) == 1) {
                if (self->p380 != 0) {
                    fn_25_142C(self->p380, lbl_1_rodata_710, lbl_1_rodata_710, lbl_1_rodata_710, lbl_1_rodata_714);
                }
                if (fn_24_33CC(self->p390, 0x200) == 1) {
                    playSE__9sndSystemF5SndIDiiii(g_sndSystem, 2, -1, 0, 0, -1);
                } else {
                    playSE__9sndSystemF5SndIDiiii(g_sndSystem, 1, -1, 0, 0, -1);
                }
                self->b36A = 1;
                self->b369 = 1;
            }
        }
        if (self->b36B == 1) {
            self->b36B = 0;
            self->state = 0x10;
        }
        if (self->b36A == 1) {
            fn_25_2FFC(self->p384);
            fn_24_22D8(self->p388);
            fn_24_1958(self->p38C);
            self->state = 0xC;
            self->b36A = 0;
        }
        break;
    case 13:
    case 15:
        if (fn_24_31F4(self->p390) == 1) fn_24_2388(self->p388);
        break;
    default:
        break;
    }
    return 0;
}
