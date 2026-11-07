#pragma force_active on
extern "C" void fn_8027EABC(void*, void*, unsigned int, int);
class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5(void*, int, int);
    int a, b, c;
    unsigned int f10;
    int f14;
    unsigned int f18;
};
extern Object_vptr_0* lbl_805A0EC8;
extern Object_vptr_0* lbl_805A0EB8;
struct Array {
    void* data;
    int size;
    unsigned int raw;
    unsigned int f0c;
    bool isOwned() const { return (raw & 0x80000000) == 0; }
    void dealloc() { fn_8027EABC(lbl_805A0EC8, data, (raw & 0x3fffffff) * 12, 0x15); }
    ~Array() { if (isOwned()) dealloc(); }
};
extern "C" Array* __dt__14Class_802A5860Fv(Array* self, int flag) {
    if (self) {
        unsigned int v = self->f0c;
        Object_vptr_0* h = lbl_805A0EC8;
        h->f10 = v;
        if (v == h->f18) h->slot4();
        self->~Array();
        if (flag > 0) lbl_805A0EB8->slot5(self, 0x10, 0x15);
    }
    return self;
}