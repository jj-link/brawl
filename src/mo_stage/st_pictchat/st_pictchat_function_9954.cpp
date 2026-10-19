#pragma force_active on
typedef unsigned int u32;

struct PictChat
{
    unsigned char padding[0x75C];
    u32 unk75C;
    unsigned char padding2[4];
    u32 unk764;
};

extern "C" void fn_73_9954(PictChat *self, u32 value1, u32 value2)
{
    self->unk75C = value1;
    self->unk764 = value2;
}
