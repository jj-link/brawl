#pragma force_active on
struct Data3
{
    unsigned char padding[0x18];
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
};

struct Data3Out
{
    unsigned int unk0;
    unsigned int unk4;
    unsigned int unk8;
};

extern "C" void fn_27_25184(Data3Out *out, const Data3 *in)
{
    out->unk0 = in->unk18;
    out->unk4 = in->unk1C;
    out->unk8 = in->unk20;
}
