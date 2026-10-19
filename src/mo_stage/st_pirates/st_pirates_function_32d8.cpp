#pragma force_active on
typedef unsigned char u8;

extern "C" {
extern const float lbl_52_rodata_1C;
extern void* g_gfSceneRoot;
void setCurrentFrame__11gfSceneRootFf(void* root, float frame);
}

extern "C" void fn_52_32D8(u8* self) {
    setCurrentFrame__11gfSceneRootFf(g_gfSceneRoot, lbl_52_rodata_1C - *(float*)(self + 0x1dc));
}
