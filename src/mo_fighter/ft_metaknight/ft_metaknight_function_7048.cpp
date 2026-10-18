#pragma force_active on
typedef unsigned char u8;
typedef int s32;
typedef unsigned int u32;

struct MetaKnightHeaderData {
    void* vtbl;
    u32 pad;
    void* ptr;
    s32 f0;
    s32 f1;
    s32 f2;
    s32 f3;
    s32 f4;
    s32 f5;
};

extern "C" void fn_111_5E60(MetaKnightHeaderData* self, u8 flag);
extern "C" u8 lbl_111_data_12E0[];

extern "C" MetaKnightHeaderData* fn_111_7048(MetaKnightHeaderData* self, s32 a, s32 b, s32 c, s32 d, s32 e, s32 f) {
    fn_111_5E60(self, 0);
    self->ptr = lbl_111_data_12E0;
    self->vtbl = lbl_111_data_12E0 + 8;
    self->f0 = a;
    self->f1 = b;
    self->f2 = c;
    self->f3 = d;
    self->f4 = e;
    self->f5 = f;
    return self;
}
