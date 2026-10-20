#pragma force_active on
typedef unsigned int u32;

extern "C" void* getManager__11soArchiveDbFUl(u32);
extern "C" u32 fn_80046998();
extern "C" u32 fn_800469AC(void*);

extern "C" int fn_27_145028() {
    void* mgr = getManager__11soArchiveDbFUl(0);
    if (fn_80046998() == 1 || fn_800469AC(mgr) == 1) {
        return 0;
    }
    return 1;
}
