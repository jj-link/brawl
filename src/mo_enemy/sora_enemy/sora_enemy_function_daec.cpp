#pragma force_active on
typedef unsigned int u32;

extern "C" void* getManager__11soArchiveDbFUl(u32);
extern "C" void fn_80045E64(void*, u32);

extern "C" void fn_41_DAEC(u32* p) {
    if (p[2] != 0xffff) {
        void* mgr = getManager__11soArchiveDbFUl(1);
        fn_80045E64(mgr, p[2]);
    }
    if (p[1] != 0xffff) {
        void* mgr = getManager__11soArchiveDbFUl(1);
        fn_80045E64(mgr, p[1]);
    }
    if (p[0] != 0xffff) {
        void* mgr = getManager__11soArchiveDbFUl(1);
        fn_80045E64(mgr, p[0]);
    }
    if (p[5] != 0xffff) {
        void* mgr = getManager__11soArchiveDbFUl(1);
        fn_80045E64(mgr, p[5]);
    }
}
