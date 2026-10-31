#include <types.h>
#pragma force_active on

extern "C" {

extern void* g_GameGlobal;
extern void* g_gfSceneRoot;
extern char lbl_31_rodata_50[];
extern char lbl_31_rodata_B8[];

struct Menu {
    char pad[0x494];
    void* resFile494;
    void* resFile498;
    void* resFile49C;
    void* scnMdl4A0;
    int state;
    int previous;
    char pad2[0x128];
    void* res5D4;
    void* res5D8;
    char pad3[0x9];
    char flag5E5;
};

struct Record {
    char pad[0x28];
    unsigned char flags;
};

void* fn_1_3E50(void*);
int isLoadFinishMenuSound__6muMenuFv(void*);
Record* getGlobalRecordMenuDatap__10GameGlobalFv(void*);
void* fn_80015DB4(void*, int, int, int, u16);
void Init__Q34nw4r3g3d7ResFileFPv(void*);
void* GetResAnmScn__Q34nw4r3g3d7ResFileFi(void*, int);
void fn_801971D0(void*, void*);
void fn_8000D6DC(void*, void*);
void fn_31_1B80(Menu*, void*, int, void*);
void fn_31_1C74(Menu*, void*, int);
void fn_31_6B4(Menu*);
void* getMEMAllocator__13gfHeapManagerFQ25Heaps8HeapType(int);
void* fn_801AB6CC(void*, int, int);
void add__11gfSceneRootFQ211gfSceneRoot9LayerTypePQ34nw4r3g3d6ScnMdl(void*, int, void*);
void fn_31_1D3C(Menu*);

int fn_31_292C(Menu* self) {
    void* menu = fn_1_3E50(self->res5D8);
    if (!menu)
        return self->state;
    if (!isLoadFinishMenuSound__6muMenuFv(menu))
        return self->state;

    void* spC;
    void* sp8 = 0;

    Record* record = getGlobalRecordMenuDatap__10GameGlobalFv(g_GameGlobal);
    void* p = !(((unsigned int)record->flags << 24) >> 31)
        ? fn_80015DB4(self->res5D4, 0, 1, 1, (u16)0xFFFE)
        : fn_80015DB4(self->res5D4, 0, 1, 0x65, (u16)0xFFFE);
    self->resFile498 = p;
    Init__Q34nw4r3g3d7ResFileFPv(&self->resFile498);
    void* anm = GetResAnmScn__Q34nw4r3g3d7ResFileFi(&self->resFile498, 0);
    sp8 = anm;
    spC = anm;
    fn_801971D0(&sp8, &spC);
    fn_8000D6DC(g_gfSceneRoot, &sp8);

    void* p2 = fn_80015DB4(self->res5D4, 0, 1, 0, (u16)0xFFFE);
    self->resFile494 = p2;
    Init__Q34nw4r3g3d7ResFileFPv(&self->resFile494);
    fn_31_1B80(self, lbl_31_rodata_50, 0xD, &self->resFile494);
    fn_31_1C74(self, lbl_31_rodata_B8, 2);
    fn_31_6B4(self);

    void* p3 = fn_80015DB4(self->res5D4, 0, 1, 3, (u16)0xFFFE);
    self->resFile49C = p3;
    Init__Q34nw4r3g3d7ResFileFPv(&self->resFile49C);
    void* heap = getMEMAllocator__13gfHeapManagerFQ25Heaps8HeapType(0x2A);
    void* mdl = fn_801AB6CC(heap, 0, 0xB2);
    self->scnMdl4A0 = mdl;
    add__11gfSceneRootFQ211gfSceneRoot9LayerTypePQ34nw4r3g3d6ScnMdl(g_gfSceneRoot, 8, mdl);
    self->flag5E5 = 1;
    fn_31_1D3C(self);
    return 1;
}
}
