#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;
typedef int s32;

extern u8 lbl_27_data_14580[];

struct Obj {
    void *vt;
    u8 flag;
    void *ptr;
    s32 val;
};

struct Src {
    u32 pad0;
    u32 bits;
};

extern "C" {
void fn_27_9EFA8(Obj *self, Src *src)
{
    u32 x = src->bits;
    s32 v = (s32)(((x >> 21) & 0x3Fu) << 26) >> 27;
    self->vt = lbl_27_data_14580;
    self->flag = 0;
    self->ptr = (u8 *)src + 8;
    self->val = v;
}
}
