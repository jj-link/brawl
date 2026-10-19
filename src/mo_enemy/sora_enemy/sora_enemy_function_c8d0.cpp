#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;

struct emInfoBase {
    virtual void* v0();
    virtual void* v1();
    virtual void* v2();
    virtual void* v3();
    virtual void* v4();
};

extern "C" emInfoBase* getInstance__6emInfoFv();

extern "C" void fn_41_C8D0(u8* self) {
    *(u32*)(self + 0x14) = 0;
    self[0] = 0;
    *(void**)(self + 0x4) = getInstance__6emInfoFv()->v2();
    *(u32*)(self + 0x8) = 0x10000 - 1;
    *(u32*)(self + 0xC) = 0x10000 - 1;
    *(u32*)(self + 0x10) = (u32)-2;
}
