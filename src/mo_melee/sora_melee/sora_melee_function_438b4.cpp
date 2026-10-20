#pragma force_active on
struct Sub {
    virtual void f0();
    virtual int f1(int);
};

struct Host {
    char pad[0x30];
    int m30;
    char pad2[0x24];
    Sub* m58;
};

extern "C" {
    void fn_27_4222C(int, int, int);

    void fn_27_438B4(Host* self, int a, int b) {
        fn_27_4222C(self->m58->f1(b), self->m30, a);
    }
}
