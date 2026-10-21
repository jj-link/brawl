#pragma force_active on
extern "C" {
int fn_800FA740(void*);
void add__11gfSceneRootFQ211gfSceneRoot9LayerTypePQ34nw4r3g3d6ScnMdl(void*, int, void*);
void fn_800B753C(void*, float);
void setUpdateRate__16gfModelAnimationFf(void*, float);
void fn_34_734(void*);
void fn_34_440(void*);
extern void* g_gfSceneRoot;
extern float lbl_34_rodata_38;
extern float lbl_34_rodata_3C;
}

extern "C" int fn_34_ED4(void* self) {
    char* p = (char*)self;
    if (fn_800FA740(*(void**)(p + 0x59c)) == 0) {
        return *(int*)(p + 0x1bc);
    }
    void* sel = *(void**)(p + 0x138);
    add__11gfSceneRootFQ211gfSceneRoot9LayerTypePQ34nw4r3g3d6ScnMdl(g_gfSceneRoot, 8, *(void**)((char*)sel + 0x10));
    fn_800B753C(sel, lbl_34_rodata_38);
    setUpdateRate__16gfModelAnimationFf(*(void**)((char*)sel + 0x14), lbl_34_rodata_3C);
    fn_34_734(self);
    fn_34_440(self);
    return 2;
}
