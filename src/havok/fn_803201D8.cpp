#pragma force_active on
extern "C" {
extern void* lbl_805A0EC8;
void fn_8027EABC(void*, void*, unsigned int, int);
void fn_80320288(int, void*, int, int);
}

struct V {
    void* p; int n; unsigned int c;
    bool isOwned() const { return (c & 0x80000000) == 0; }
    void dealloc() { fn_8027EABC(lbl_805A0EC8, p, c * 4, 0x15); }
};
extern "C" int fn_80320500(int, V*, int, int, int*);

extern "C" int fn_803201D8(int a0, int a1, int a2, int a3) {
    int sp8 = a3;
    char buf[0x190];
    V v;
    v.p = buf; v.n = 0; v.c = 0x80000064;
    fn_80320288(a0, &v, a1, a3);
    int r = fn_80320500(a0, &v, a1, a2, &sp8);
    if (v.isOwned()) v.dealloc();
    return r;
}
