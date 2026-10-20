#pragma force_active on
struct Inner {
    virtual void f0();
    virtual void* f1(const unsigned int* a);
};

struct Holder {
    char pad[0x20];
    void* m20;
    char pad2[0x48 - 0x24];
    Inner* m48;
};

extern "C" void fn_27_46DF8(Holder* h, void* obj, int idx, const unsigned int* src);

extern "C" void fn_27_4902C(Holder* h, int idx, const unsigned int* src, const unsigned int* extra) {
    Holder* r = (Holder*)h->m48->f1(extra);
    fn_27_46DF8(r, h->m20, idx, src);
}
