#pragma force_active on
typedef unsigned char u8;
typedef int s32;

struct Inner {
    virtual void v0() = 0;
    virtual s32* at(s32 index) = 0;
    virtual void v2() = 0;
    virtual s32 size() = 0;
};

struct Outer {
    u8 pad[0x2c];
    Inner* m_inner;
};

extern "C" void fn_27_4E290(Outer* self) {
    s32 i = 0;
    while (i < self->m_inner->size()) {
        *self->m_inner->at(i) = 0;
        i++;
    }
}
