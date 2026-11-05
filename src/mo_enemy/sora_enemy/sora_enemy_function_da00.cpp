#pragma force_active on
typedef unsigned int u32;

extern "C" void* getManager__11soArchiveDbFUl(u32);
extern "C" int fn_80045DC0(void*, u32, u32);

extern "C" int fn_41_DA00(u32* p) {
    if (p[2] != 0xffff) {
        void* mgr = getManager__11soArchiveDbFUl(1);
        if (fn_80045DC0(mgr, p[2], 0) == 0) return 0;
    }
    if (p[1] != 0xffff) {
        void* mgr = getManager__11soArchiveDbFUl(1);
        if (fn_80045DC0(mgr, p[1], 0) == 0) return 0;
    }
    if (p[0] != 0xffff) {
        void* mgr = getManager__11soArchiveDbFUl(1);
        if (fn_80045DC0(mgr, p[0], 0) == 0) return 0;
    }
    if (p[5] != 0xffff) {
        void* mgr = getManager__11soArchiveDbFUl(1);
        if (fn_80045DC0(mgr, p[5], 0) == 0) return 0;
    }
    return 1;
}