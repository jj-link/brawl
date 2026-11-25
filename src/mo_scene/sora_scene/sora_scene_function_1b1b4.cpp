#include <cm/cm_camera_controller.h>
#pragma force_active on

typedef unsigned char u8;

struct S3 {
    u8 a, b, c;
};

struct S90 {
    long long data[0x12];
};

struct S284 {
    int data[0xa1];
};

struct GData {
    S3 header;
    S90 first;
    S284 second;
};

struct DataFlags {
    char pad[8];
    u8 mode : 6;
    u8 rest : 2;
};

struct GGlobal {
    char pad[8];
    GData* data;
};

struct Loader {
    char pad[0x57];
    u8 f57;
};

struct LoaderManager {
    void* p[14];
};

struct FighterManager {
    char pad[0x6a];
    u8 f6a;
    char pad6b[2];
    bool f6d;
    u8 f6e1 : 1;
    u8 f6e2 : 1;
    u8 f6eRest : 6;
};

struct Self {
    char pad[8];
    Loader* ldr[7];
    void* l24;
    void* l28;
    void* l2c;
    void* l30;
    void* l34;
    void* l38;
    void* l3c;
    void* p40;
    void* p44;
    void* p48;
    char pad4c[8];
    void* p54;
    char pad58[8];
    void* p60;
    void* p64;
    void* p68;
    char pad6c[0x2c];
    void* p98;
    char pad9c[0x14];
    void* pb0;
};

extern "C" {
    extern GGlobal* g_GameGlobal;
    extern LoaderManager* g_stLoaderManager;
    extern FighterManager* g_ftManager;
    extern void* g_gfApplication;
    extern void* lbl_805A01D8;
    extern GData lbl_1_bss_90;
    extern char lbl_1_data_1F88[];
    extern char lbl_1_data_1E00[];

    void fn_1_139E0(void*);
    void fn_1_1A5A0(void*, void*);
    void fn_1_1A4DC(void*);
    void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
    void* fn_27_255420(void*);
    void fn_27_2554C0(void*, int);
    void fn_800790FC(void*, int);
    void fn_8004E858(void*);
    void fn_80016900(void*, int, int);
    void fn_27_23A410();
    void fn_27_109148(void*, int);
    void fn_27_1F1844(int);
    void* fn_27_244350(void*);
    void* fn_27_246E74(void*, int);
    void fn_27_241E30(void*, void*);
    void* fn_27_250DB8(void*);
    void* fn_27_27F0A8();
    void fn_27_23BB10(Loader*);
    void* fn_27_25CB9C(void*);
    void fn_27_241F34(void*);
    void fn_80110410(void*);
}

static inline void copyLoaders(void** dst, Self* self) {
    dst[0] = self->ldr[0];
    dst[1] = self->ldr[1];
    dst[2] = self->ldr[2];
    dst[3] = self->ldr[3];
    dst[4] = self->ldr[4];
    dst[5] = self->ldr[5];
    dst[6] = self->ldr[6];
}

extern "C" void fn_1_1B1B4(Self* self) {
    u8* saved;
    FighterManager* manager;
    fn_1_139E0(self);

    GData* data = g_GameGlobal->data;
    u8* bytes = (u8*)data;
    ((DataFlags*)data)->mode = 32;
    *(unsigned short*)(bytes + 0x1a) = 0x28;
    lbl_1_bss_90 = *data;

    fn_1_1A5A0(self, data);

    void* p = __nw__FUlQ25Heaps8HeapType(0x48, 15);
    if (p) p = fn_27_255420(p);
    self->p64 = p;
    saved = (u8*)&lbl_1_bss_90;
    fn_27_2554C0(p, (saved[0x8a] >> 6) & 1);

    fn_800790FC(lbl_805A01D8, 0x3c);
    fn_8004E858(g_GameGlobal);
    fn_80016900(g_gfApplication, 0, 0);
    fn_27_23A410();
    fn_1_1A4DC(self);

    self->ldr[0] = (Loader*)g_stLoaderManager->p[0];
    self->ldr[1] = (Loader*)g_stLoaderManager->p[1];
    self->ldr[2] = (Loader*)g_stLoaderManager->p[2];
    self->ldr[3] = (Loader*)g_stLoaderManager->p[3];
    self->l24 = g_stLoaderManager->p[7];
    self->l34 = g_stLoaderManager->p[8];
    self->l2c = g_stLoaderManager->p[9];
    self->l30 = g_stLoaderManager->p[10];
    self->l28 = g_stLoaderManager->p[11];
    self->l38 = g_stLoaderManager->p[12];
    self->l3c = g_stLoaderManager->p[13];

    fn_27_109148(g_ftManager, 0);
    g_ftManager->f6a = (saved[9] >> 5) & 7;
    unsigned int flag = (saved[0xb] >> 5) & 1;
    g_ftManager->f6d = (-flag | flag) >> 31;
    u8 mode = saved[0x13];
    bool special = false;
    if (mode == 1 && (saved[0xa] & 1)) {
        special = true;
    }
    manager = g_ftManager;
    manager->f6e1 = mode == 1;
    manager->f6e2 = special;

    fn_27_1F1844(0);
    CameraController::getInstance()->changeInput((CameraController::Kind)2);

    p = __nw__FUlQ25Heaps8HeapType(0x1bc, 15);
    if (p) p = fn_27_244350(p);
    self->p44 = p;

    p = __nw__FUlQ25Heaps8HeapType(0x104, 15);
    if (p) p = fn_27_246E74(p, 0);
    self->p48 = p;

    char* q = (char*)__nw__FUlQ25Heaps8HeapType(0x48, 15);
    if (q) {
        fn_27_241E30(q, lbl_1_data_1F88);
        *(void**)(q + 0x3c) = lbl_1_data_1E00;
    }
    self->p60 = q;

    p = __nw__FUlQ25Heaps8HeapType(0xd0, 15);
    if (p) p = fn_27_250DB8(p);
    self->p54 = p;
    self->pb0 = fn_27_27F0A8();

    for (int i = 0; i < 7; i++) {
        if (self->ldr[i]) self->ldr[i]->f57 = 6;
        if (self->ldr[i]) fn_27_23BB10(self->ldr[i]);
    }

    if (self->p68) copyLoaders((void**)((char*)self->p68 + 0x48), self);
    if (self->p44) copyLoaders((void**)((char*)self->p44 + 0x74), self);
    if (self->p44) *(void**)((char*)self->p44 + 0x90) = self->p48;
    if (self->p48) copyLoaders((void**)((char*)self->p48 + 0x58), self);
    *(void**)((char*)self->p44 + 0x1b8) = self->p54;

    p = __nw__FUlQ25Heaps8HeapType(0x58, 15);
    if (p) p = fn_27_25CB9C(p);
    self->p98 = p;
    if (p) fn_27_241F34(p);

    fn_80110410(data);
}
