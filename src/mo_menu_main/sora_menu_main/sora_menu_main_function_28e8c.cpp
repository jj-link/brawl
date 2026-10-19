#pragma force_active on
typedef unsigned int u32;

struct Data {
    unsigned char pad000[0x654];
    u32 unk654;
    unsigned char pad658[0x14];
    u32 unk66C;
    u32 unk670;
    u32 unk674;
    u32 unk678;
    unsigned char pad67C[0x18];
    u32 unk694;
    u32 unk698;
    u32 unk69C;
    u32 unk6A0;
};

extern "C" void fn_2_28E8C(Data* self, u32 a, u32 b, u32 c) {
    self->unk654 = a;
    self->unk670 = 0;
    self->unk674 = 0;
    self->unk678 = b;
    self->unk66C = c;
    self->unk6A0 = 0;
    self->unk694 = 0;
    self->unk698 = 0;
    self->unk69C = 0;
}
