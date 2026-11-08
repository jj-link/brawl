#pragma force_active on
extern "C" void fn_80333E08(int, int, void*);
extern "C" void fn_8027EABC(void*, void*, unsigned int, int);
extern "C" void* lbl_805A0EC8;
struct V {
    void* data;
    int size;
    unsigned int raw;
    bool isOwned() const { return (raw & 0x80000000) == 0; }
    void dealloc() { fn_8027EABC(lbl_805A0EC8, data, raw * 4, 0x15); }
};
extern "C" void fn_80333DA8(int a0, int a1, void* a2) {
    V v;
    v.data = a2;
    v.size = 1;
    v.raw = 0x80000001;
    fn_80333E08(a0, a1, &v);
    if (v.isOwned()) v.dealloc();
}