#pragma force_active on
typedef int s32;
typedef unsigned int u32;
typedef unsigned char u8;

extern "C" {
void* fn_41_473DC(void* acc, s32 v);
void fn_41_47470(void* out, void* p, void* acc);
void fn_41_477EC(u32 id, void* p, void* acc, u32 flag, u32 n);
void fn_41_47D8C(void* out, u32 zero, void* self, void* p, void* acc);
}

extern u8 lbl_41_bss_504[];

struct ValueObj {
    virtual void unused0();
    virtual void unused1();
    virtual void unused2();
    virtual void unused3();
    virtual s32 getValue(u32 id);
};

struct ModuleHolder {
    unsigned char padding[0x64];
    ValueObj* value;
};

struct Accesser {
    unsigned char padding[0xD8];
    ModuleHolder* holder;
};

extern "C" s32 fn_41_3AD88(void* self, Accesser* acc) {
    u8 sp8[0x18];
    ValueObj* v = acc->holder->value;
    void* p = fn_41_473DC(acc, v->getValue(0x10000007));
    fn_41_47470(sp8, p, acc);
    u32 id = *(u32*)(lbl_41_bss_504 + 0x8);
    if (id == 0xB) {
        fn_41_477EC(id, p, acc, 1, 3);
    } else {
        fn_41_477EC(id, p, acc, 1, 2);
    }
    fn_41_47D8C(sp8, 0, self, p, acc);
    return 0;
}
