#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;

extern "C" u32 strlen(const char* s);
extern "C" void* memcpy(void* dst, const void* src, u32 n);

struct Inner {
    u8 pad[0x4C];
    u32 pos;
    u8* buf;
};

struct Outer {
    u8 pad[0x1D0];
    Inner* inner;
};

extern "C" void fn_80069F2C(Outer* self, const char* str) {
    Inner* in;
    u32 len = strlen(str);
    in = self->inner;
    memcpy(in->buf + in->pos, str, len);
    in->pos += len;
}
