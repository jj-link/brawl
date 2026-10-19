#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;

struct emSubRet {
    u8 pad[8];
    u32 unk8;
};

struct emSub {
    virtual void v0();
    virtual emSubRet* v1();
};

struct emOwner {
    u8 pad[0x10];
    emSub sub;
};

extern "C" {
u32 fn_41_345A0(emOwner* p) {
    return p->sub.v1()->unk8;
}
}
