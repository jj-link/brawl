#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef int s32;

struct Entry {
    u8 a;
    u8 pad;
    u16 b;
};

struct Inner {
    u8 pad0[0x8c];
    u8 count;
    Entry entries[1];
};

struct Outer {
    Inner* inner;
    u8 pad1[0xa - 4];
    u8 flag;
};

extern "C" void fn_27_112D90(Outer* self, u8 val, u16 val2)
{
    if (self->flag != 1) {
        return;
    }
    u8 n = self->inner->count;
    if ((s32)n >= 0x100) {
        n = 0xff;
    }
    self->inner->entries[n].a = val;
    self->inner->entries[n].b = val2;
    self->inner->count = (u8)(n + 1);
}
