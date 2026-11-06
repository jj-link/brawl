#pragma force_active on

typedef float f32;
typedef int s32;
typedef unsigned int u32;

struct Vec3 {
    f32 x, y, z;
};

struct Subject {
    u32 next, prev, flags;
    char pad0[4];
    f32 x, y, z;
    char pad1[0x10];
    f32 left, right, top, bottom;
};

struct List {
    u32 count, first, last;
};

extern List lbl_8049DEDC;
extern const f32 lbl_805A23B0;

extern "C" void fn_800DB444();
extern "C" void fn_800DB5F4(Vec3*, Vec3*);

extern "C" void fn_800E2964(s32 self, s32* count, s32 limit) {
    Vec3 sp2c;
    Vec3 sp20;
    Vec3 sp14;
    Vec3 sp8;

    fn_800DB444();
    *count = 0;

    f32 zero = lbl_805A23B0;
    Subject* node = (Subject*)lbl_8049DEDC.first;
    Subject* end = (Subject*)&lbl_8049DEDC.first;
    s32 again;

    goto test;
loop:
    u32 kind = (node->flags >> 26) & 7;
    if (kind != 3) {
        if (kind != 2)
            goto advance;
    }

    f32 z;
    f32 y;
    f32 x;
    y = node->y;
    z = node->z;
    x = node->x;

    sp2c.x = x;
    sp20.x = x + node->left;
    sp2c.y = y;
    sp20.y = y + node->bottom;
    sp2c.z = z;
    sp20.z = zero;
    fn_800DB5F4(&sp20, &sp14);

    sp20.x = sp2c.x + node->right;
    sp20.y = sp2c.y + node->top;
    fn_800DB5F4(&sp20, &sp8);

    s32 index = *count;
    *count = index + 1;
    f32* dest = (f32*)(self + (index << 4));
    dest[0] = sp14.x < sp8.x ? sp14.x : sp8.x;
    dest[1] = sp14.x > sp8.x ? sp14.x : sp8.x;
    dest[3] = sp14.y < sp8.y ? sp14.y : sp8.y;
    dest[2] = sp14.y > sp8.y ? sp14.y : sp8.y;

advance:
    node = (Subject*)node->next;
test:
    again = 0;
    if (node != end) {
        if (*count < limit)
            again = 1;
    }
    if (again != 0)
        goto loop;
}