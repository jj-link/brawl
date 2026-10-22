#pragma force_active on
extern "C" void fn_800FD44C(void* a, void* b);
extern "C" void fn_800FD630(void* self);
extern "C" void fn_800FBDEC(void* a, void* b);
extern "C" void* create__12ifWifiprTaskFv(void* self);
extern "C" void* add__11gfSceneRootFQ211gfSceneRoot9LayerTypePQ34nw4r3g3d6ScnMdl(void* root, int layer, void* mdl);
extern void* g_gfSceneRoot;

extern "C" void fn_800FCB84(char* self) {
    fn_800FD44C(*(void**)(self + 0x18), *(void**)(self + 0x14));
    fn_800FD630(*(void**)(self + 0x14));
    fn_800FBDEC(*(void**)(self + 0x38), *(void**)(self + 0x14));
    *(void**)(self + 0x3C) = create__12ifWifiprTaskFv(
        add__11gfSceneRootFQ211gfSceneRoot9LayerTypePQ34nw4r3g3d6ScnMdl(g_gfSceneRoot, 8, *(void**)(self + 0x14)));
    *(unsigned char*)(self + 0x50) = 0;
}
