#pragma force_active on
typedef unsigned char u8;
typedef int s32;

struct Inner {
    char pad[0x68];
    s32 val;
};

struct Outer {
    Inner* inner;
    char pad[0xa - sizeof(Inner*)];
    u8 flag;
};

extern "C" void fn_27_112CC4(Outer* self, s32 n)
{
    if (self->flag != 1) {
        return;
    }
    Inner* in = self->inner;
    s32 max = 0x7FFFFFFF - in->val;
    if (max < n) {
        n = max;
    }
    in->val += n;
}
