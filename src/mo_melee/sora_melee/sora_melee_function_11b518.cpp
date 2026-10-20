#pragma force_active on
typedef int s32;
typedef unsigned int u32;

struct Elem {
    u32 a;
    u32 b;
    u32 c;
};

struct Thing {
    char pad[0x18];
    s32 f18;
    Elem arr[4];
};

extern "C" {
Elem* fn_27_11B518(Thing* self, s32 idx)
{
    s32 n = (self->f18 >> 28) + idx;
    if (n >= 4) {
        n -= 4;
    }
    return &self->arr[n];
}
}
