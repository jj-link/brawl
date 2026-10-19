#pragma force_active on
typedef unsigned char u8;

extern float lbl_68_rodata_100;
extern float lbl_68_rodata_D4;

struct St68Entry {
    int pad0;
    float f;
    char rest[0x28 - 8];
};

struct St68 {
    char pad[0x175];
    u8 idx;
    char pad2[2];
    St68Entry *arr;
};

extern "C" bool fn_68_C980(St68 *self)
{
    St68Entry *e = &self->arr[self->idx];
    float f = e->f;
    if (f > lbl_68_rodata_100 && f < lbl_68_rodata_D4) {
        return true;
    }
    return false;
}
