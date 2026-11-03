#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;

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

extern "C" void fn_8006B0C8(Outer* self, u8* buffer, u32 index) {
    u32* arr = (u32*)buffer;
    Inner* in = self->inner;
    u32 o1 = arr[index];
    u32 o2 = arr[index + 1];
    u32 size = o2 - o1;
    memcpy(in->buf + in->pos, buffer + o1, size);
    in->pos += size;
}