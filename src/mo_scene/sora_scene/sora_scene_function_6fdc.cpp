#pragma force_active on
extern "C" void fn_801AC758(void*);
extern "C" void fn_8000DB40(void*, int);
extern void* g_gfSceneRoot;

extern "C" void fn_1_6FDC(void* self) {
    char* root = static_cast<char*>(g_gfSceneRoot);
    fn_801AC758(*reinterpret_cast<void**>(root + 0x40));
    fn_801AC758(*reinterpret_cast<void**>(root + 0x44));
    unsigned char* sub = *reinterpret_cast<unsigned char**>(static_cast<char*>(self) + 0x8);
    if (sub[0xc] == 0) {
        fn_8000DB40(root, 2);
    }
    fn_8000DB40(root, 6);
    fn_8000DB40(root, 8);
}
