#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef int s32;

struct GXColor {
    u8 r, g, b, a;
};

struct CopiedMatAccess {
    u8 data[0x34];
};

struct ResMat {
    u8 pad[0xC];
    u32 id;
};

struct ScnMdl {
    u8 pad[0xE8];
    void* resMdl;
};

struct MuObject {
    u8 pad[0xC];
    ScnMdl* scn;
};

struct Self {
    u8 pad0[0x44];
    void* f44;
    MuObject* obj;
    u8 pad48[0x4];
    u32 f50;
    u8 pad54[0x1C];
    u8 f70;
};

extern "C" {
extern char lbl_38_data_0[];
extern char lbl_38_data_8[];
extern float lbl_38_rodata_0[];
extern void* g_GameGlobal;
extern void* g_gfSceneRoot;

void* getData__9gfArchiveF11ARCNodeTypeiUs(void*, int, int, u16);
void Init__Q34nw4r3g3d7ResFileFPv(void*);
u32 fn_8018D568(void*);
void* fn_8018D4D0(void*, u32);
void* create__8MuObjectFPQ34nw4r3g3d7ResFilePCciPQ34nw4r3g3d7ResFileQ25Heaps8HeapType(void*, const char*, int, void*, int);
void* getGlobalRecordMenuDatap__10GameGlobalFv(void*);
void fn_800B6E08(void*, float*);
void fn_80192A44(const void*, u32*, u16*, u16*, u32*, float*, float*, u8*);
void fn_801F28F0(void*, u32, u16, u16, u32, u32, u32, u8);
void fn_800B70D0(void*, const char*, void*);
void* GetResMat__Q34nw4r3g3d6ResMdlCFPCc(const void*, const char*);
void __ct__Q44nw4r3g3d6ScnMdl15CopiedMatAccessFPQ34nw4r3g3d6ScnMdlUl(void*, void*, u32);
void* fn_801B01BC(void*);
void fn_80191B9C(void*, u32, GXColor*);
void fn_80191AA4(void*, u32, GXColor*);
void add__11gfSceneRootFQ211gfSceneRoot9LayerTypePQ34nw4r3g3d6ScnMdl(void*, u32, void*);
}

extern "C" void fn_38_4D4(Self* self, void* archive) {
    float* rodata = lbl_38_rodata_0;
    void* file = 0;
    float vecA[3];
    float vecB[3];
    float sp2C;
    float sp28;
    u32 sp24;
    u32 sp20;
    u16 spC;
    u16 spA;
    u8 sp8;
    u8 sp50[0x20];
    CopiedMatAccess sp70;
    u32 color2;
    u32 color;
    void* channels;
    void* mdl;

    file = getData__9gfArchiveF11ARCNodeTypeiUs(archive, 2, 1, 0xFFFE);
    Init__Q34nw4r3g3d7ResFileFPv(&file);
    if (fn_8018D568(&file) <= self->f50) {
        self->f50 = 0;
    }
    self->f44 = fn_8018D4D0(&file, self->f50);
    file = getData__9gfArchiveF11ARCNodeTypeiUs(archive, 2, 0, 0xFFFE);
    Init__Q34nw4r3g3d7ResFileFPv(&file);
    self->obj = (MuObject*)create__8MuObjectFPQ34nw4r3g3d7ResFilePCciPQ34nw4r3g3d7ResFileQ25Heaps8HeapType(&file, lbl_38_data_0, 1, 0, 0x2A);

    void* rec = getGlobalRecordMenuDatap__10GameGlobalFv(g_GameGlobal);
    if (!((((u8*)rec)[0x28] >> 7) & 1)) {
        vecA[0] = rodata[6];
        vecA[1] = rodata[7];
        vecA[2] = rodata[8];
        fn_800B6E08(self->obj, vecA);
    } else {
        vecB[0] = rodata[9];
        vecB[1] = rodata[10];
        vecB[2] = rodata[8];
        fn_800B6E08(self->obj, vecB);
    }

    fn_80192A44(&self->f44, &sp20, &spA, &spC, &sp24, &sp28, &sp2C, &sp8);
    fn_801F28F0(sp50, sp20, spA, spC, sp24, 0, 0, sp8);
    fn_800B70D0(self->obj, lbl_38_data_8, sp50);
    self->f70 = 0;

    ScnMdl* scn = self->obj->scn;
    mdl = scn->resMdl;
    ResMat* mat = (ResMat*)GetResMat__Q34nw4r3g3d6ResMdlCFPCc(&mdl, lbl_38_data_8);
    __ct__Q44nw4r3g3d6ScnMdl15CopiedMatAccessFPQ34nw4r3g3d6ScnMdlUl(&sp70, scn, mat->id);
    channels = fn_801B01BC(&sp70);
    fn_80191B9C(&channels, 2, (GXColor*)&color);
    ((u8*)&color)[3] = self->f70;
    color2 = color;
    fn_80191AA4(&channels, 2, (GXColor*)&color2);
    add__11gfSceneRootFQ211gfSceneRoot9LayerTypePQ34nw4r3g3d6ScnMdl(g_gfSceneRoot, 8, self->obj->scn);
}
