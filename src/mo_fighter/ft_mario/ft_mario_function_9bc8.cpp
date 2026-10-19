#pragma force_active on
extern "C" void fn_27_135DE8(void* self);

struct VirtualBase {
    virtual void v0() {}
    virtual void v1() {}
    virtual void v2() {}
    virtual void v3() {}
    virtual void v4() {}
    virtual void v5() {}
    virtual void v6() {}
    virtual void v7() {}
    virtual void v8() {}
    virtual void v9() {}
    virtual void v10() {}
    virtual void v11() {}
    virtual void v12() {}
};
struct VirtualTarget : VirtualBase {
    virtual void call(int a, int b, int c);
};

struct AccesserHolder {
    AccesserHolder* next;
    VirtualTarget* target;
};

struct Self {
    unsigned char pad[0x2dbd4];
    unsigned char flag;
};

extern "C" void fn_91_9BC8(Self* self) {
    if (self->flag == 1) {
        AccesserHolder* holder = *(AccesserHolder**)((char*)self + 0x60);
        holder = *(AccesserHolder**)((char*)holder + 0xd8);
        VirtualTarget* target = *(VirtualTarget**)((char*)holder + 0x28);
        target->call(0, 0, 2);
    }
    fn_27_135DE8(self);
}
