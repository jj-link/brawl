#pragma force_active on
typedef unsigned int u32;

extern char lbl_27_data_344F8[];

struct fn_27_Work {
    void *unk0;
    void *unk4;
    u32 unk8;
};

extern "C" void fn_27_1A5FB4(fn_27_Work *self)
{
    u32 flag = self->unk8;
    char *base = lbl_27_data_344F8;
    char *next = base + 0x48;
    self->unk0 = base;
    self->unk4 = next;
    self->unk8 = flag & 1;
}
