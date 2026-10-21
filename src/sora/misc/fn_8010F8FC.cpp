#pragma force_active on
extern "C" void startMelee__9IfStgeditFPQ34nw4r3g3d8ScnGroup(void* self, void* group);
extern "C" void add__11gfSceneRootFQ211gfSceneRoot9LayerTypePQ34nw4r3g3d6ScnMdl(void* root, int layer, void* mdl);
extern void* g_gfSceneRoot;

extern "C" void fn_8010F8FC(char* self) {
    startMelee__9IfStgeditFPQ34nw4r3g3d8ScnGroup(*(void**)(self + 0x10), *(void**)(self + 0x4));
    add__11gfSceneRootFQ211gfSceneRoot9LayerTypePQ34nw4r3g3d6ScnMdl(g_gfSceneRoot, 8, *(void**)(self + 0x4));
}
