#pragma force_active on
typedef unsigned int u32;

class fnMember {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8(void* arg);
    virtual u32 v9();
};

struct fnOuter {
    char pad[0x27a8];
    fnMember m;
};

extern "C" void fn_27_28D7E4(fnOuter* self, void* arg) {
    if (self->m.v9() == 1) {
        self->m.v8(arg);
    }
}
