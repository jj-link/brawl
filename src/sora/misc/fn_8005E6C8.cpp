#include <types.h>
#pragma force_active on

extern "C" {
extern char lbl_8059DAB0[6];
extern char lbl_80453DB8[];
extern s32 lbl_805A014C;
extern s32 lbl_805A0150;
extern s32 lbl_805A0154;
extern s32 lbl_805A0158;
extern s32 lbl_805A015C;
extern s32 lbl_805A0160;
extern s32 lbl_805A0164;
extern void* g_gfSceneRoot;

void* __ct__6gfTaskFPCcQ26gfTask8Categoryiib(void* self, const char* name, int category, int a, int b, bool c);
void* __ct__10ecTraceMgrFv(void* self);
void fn_8001ABE4(unsigned long count);
void* __nwa__FUlQ25Heaps8HeapType(unsigned long size, int heap);
void* __construct_new_array(void* block, void (*ctor)(), void (*dtor)(), unsigned long size, int count);
void* getMEMAllocator__13gfHeapManagerFQ25Heaps8HeapType(int heap);
void* fn_801AB6CC(void* allocator, unsigned long a, unsigned long b);
void add__11gfSceneRootFQ211gfSceneRoot9LayerTypePQ34nw4r3g3d6ScnMdl(void* self, int layer, void* mdl);
void gfMemFill__FPvUcUl(void* p, unsigned char c, unsigned long n);
void fn_8005E898();
void fn_8005E8B0();
void fn_8005E908();
}

struct gfTaskFlags2C {
    u8 b0 : 1;
    u8 b1 : 1;
    u8 b2 : 1;
    u8 b3 : 1;
    u8 b4 : 1;
    u8 flag2 : 1;
    u8 b6 : 1;
    u8 b7 : 1;
};

struct gfTask {
    char pad0[0x2C];
    gfTaskFlags2C unk2C;
    char pad2D[0xF];
    void* unk3C;
    s8 unk40;
    s8 unk41;
    s8 unk42;
    s8 unk43;
    s32 unk44;
    s32 unk48;
    void* unk4C;
    void* unk50;
    void* unk54;
    void* unk58;
    s32 unk5C;
    void* unk60;
    u32 unk64;
    u32 unk68;
    s32 unk6C;
    s32 unk70;
    s32 unk74;
    s32 unk78;
    s32 unk7C;
    s8 unk80;
    s8 unk81;
    char pad82[2];
    s32 unk84;
    char pad88[8];
    s32 unk90;
    s32 unk94;
    void* unk98;
};

extern "C" gfTask* fn_8005E6C8(gfTask* arg0, u32 arg1, u32 arg2, u32 arg3) {
    __ct__6gfTaskFPCcQ26gfTask8Categoryiib(arg0, lbl_8059DAB0, 0xE, 0xB, 7, true);
    arg0->unk3C = lbl_80453DB8;
    __ct__10ecTraceMgrFv(&arg0->unk98);
    fn_8001ABE4(arg2);
    arg0->unk60 = __construct_new_array(__nwa__FUlQ25Heaps8HeapType(arg1 * 0x84 + 0x10, 3), (void (*)())fn_8005E908, 0, 0x84, arg1);
    arg0->unk58 = __construct_new_array(__nwa__FUlQ25Heaps8HeapType(arg2 * 0x18 + 0x10, 3), (void (*)())fn_8005E898, (void (*)())fn_8005E8B0, 0x18, arg2);
    arg0->unk4C = fn_801AB6CC(getMEMAllocator__13gfHeapManagerFQ25Heaps8HeapType(2), 0, arg1);
    add__11gfSceneRootFQ211gfSceneRoot9LayerTypePQ34nw4r3g3d6ScnMdl(g_gfSceneRoot, 4, arg0->unk4C);
    arg0->unk50 = fn_801AB6CC(getMEMAllocator__13gfHeapManagerFQ25Heaps8HeapType(2), 0, arg1);
    add__11gfSceneRootFQ211gfSceneRoot9LayerTypePQ34nw4r3g3d6ScnMdl(g_gfSceneRoot, 7, arg0->unk50);
    arg0->unk54 = arg0->unk4C;
    gfMemFill__FPvUcUl(arg0->unk60, 0, (u32)arg1 * 0x84);
    arg0->unk64 = arg1;
    if (arg3 < arg1) {
        arg1 = arg3;
    }
    arg0->unk68 = arg1;
    arg0->unk5C = arg2;
    arg0->unk7C = 0;
    arg0->unk78 = 0;
    arg0->unk74 = 0;
    arg0->unk70 = 0;
    arg0->unk6C = 0;
    arg0->unk81 = 0;
    arg0->unk84 = 0;
    arg0->unk90 = 0;
    arg0->unk94 = 0;
    arg0->unk80 = 0;
    arg0->unk44 = 3;
    arg0->unk48 = 3;
    arg0->unk40 = 0;
    arg0->unk41 = 0;
    arg0->unk42 = 0;
    arg0->unk43 = 0;
    lbl_805A0160 = 0;
    lbl_805A015C = 0;
    lbl_805A0158 = 0;
    lbl_805A0154 = 0;
    lbl_805A0150 = 0;
    lbl_805A014C = 0;
    arg0->unk2C.flag2 = 0;
    lbl_805A0164 = 0;
    return arg0;
}
