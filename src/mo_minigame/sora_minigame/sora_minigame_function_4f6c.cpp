#pragma force_active on
typedef unsigned int u32;

struct Matrix {
    u32 v[12];
};

extern void* g_gfSceneRoot;

extern "C" {
extern void* lbl_20_bss_8;
extern const float lbl_20_rodata_54[];
extern const float lbl_20_rodata_58[];

void setFrame__16gfModelAnimationFd(void*, double);
void setUpdateRate__16gfModelAnimationFf(void*, float);
void add__11gfSceneRootFQ211gfSceneRoot9LayerTypePQ34nw4r3g3d6ScnMdl(void*, int, void*);
void setIdentity__6MatrixFv(Matrix*);
void fn_8003F074(Matrix*, float, float, float);
void fn_801AAF04(void*, int, Matrix*);
void fn_801AF9F4(void*);

void fn_20_4F6C(void* self) {
    char* entry =
        (char*)*(u32*)&lbl_20_bss_8 + *(int*)((char*)self + 0x50) * 0x18;
    entry += *(int*)((char*)self + 0x58) << 2;
    *(u32*)((char*)self + 0x2C) = *(u32*)(entry + 0x3B0);
    u32 mdl = *(u32*)(entry + 0x448);
    *(u32*)((char*)self + 0x30) = mdl;

    setFrame__16gfModelAnimationFd((void*)mdl, lbl_20_rodata_54[0]);
    setUpdateRate__16gfModelAnimationFf(*(void**)((char*)self + 0x30), lbl_20_rodata_58[0]);

    add__11gfSceneRootFQ211gfSceneRoot9LayerTypePQ34nw4r3g3d6ScnMdl(
        g_gfSceneRoot, 0, *(void**)((char*)self + 0x2C));

    Matrix m;
    setIdentity__6MatrixFv(&m);
    fn_8003F074(&m, *(float*)((char*)self + 0x34), *(float*)((char*)self + 0x38),
                *(float*)((char*)self + 0x3C));
    fn_801AAF04(*(void**)((char*)self + 0x2C), 0, &m);
    fn_801AF9F4(*(void**)((char*)self + 0x2C));
}
}
