#pragma force_active on
typedef unsigned int u32;

struct SomeObj {
    char* p0;
    char* p4;
    u32 p8;
};

extern "C" char lbl_27_data_34CA8[];

extern "C" void fn_27_1A5690(SomeObj* self) {
    u32 v = self->p8;
    self->p0 = lbl_27_data_34CA8;
    self->p4 = lbl_27_data_34CA8 + 0x48;
    self->p8 = v & 0x7FFFF;
}
