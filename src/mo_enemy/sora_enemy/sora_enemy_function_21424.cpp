#pragma force_active on
typedef int s32;

extern "C" void fn_27_8B574(void* self, s32 flag);
extern "C" char lbl_41_data_3120[];

struct UnkObj {
    s32 unk0;
    void* unk4;
};

extern "C" {
UnkObj* fn_41_21424(UnkObj* self) {
    fn_27_8B574(self, 1);
    self->unk4 = lbl_41_data_3120;
    return self;
}
}
