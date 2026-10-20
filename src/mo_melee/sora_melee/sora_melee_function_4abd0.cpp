#pragma force_active on
class Inner {
public:
    virtual void* f0();
    virtual void* f1(void* p);
};

struct Outer {
    char pad0[0x20];
    void* m20;
    char pad1[0x48 - 0x24];
    Inner* m48;
};

extern "C" {
    void fn_27_470FC(void* r3, void* r4, void* r5);

    void fn_27_4ABD0(Outer* self, void* a, void* b) {
        fn_27_470FC(self->m48->f1(b), self->m20, a);
    }
}
