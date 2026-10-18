#pragma force_active on
extern void* g_gfSceneRoot;

extern "C" void fn_801AC758(void*);
extern "C" void fn_8000DB40(void*, int);

extern "C" void fn_1_7EE0() {
    void* root = g_gfSceneRoot;
    fn_801AC758(*reinterpret_cast<void**>(static_cast<char*>(root) + 0x44));
    fn_8000DB40(root, 8);
}
