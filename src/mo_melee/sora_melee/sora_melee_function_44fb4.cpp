#pragma force_active on
class Inner {
public:
    virtual void f0();
    virtual int f1(int v);
};

class Outer {
public:
    char _0[0x30];
    void* m30;
    char _1[0x58 - 0x34];
    Inner* m58;
};

extern "C" void fn_27_42348(int r, void* p, int a);

extern "C" void fn_27_44FB4(Outer* self, int a, int b) {
    int r = self->m58->f1(b);
    fn_27_42348(r, self->m30, a);
}
