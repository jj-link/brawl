#pragma force_active on
typedef struct {
    unsigned int unk0;
    unsigned int unk4;
    unsigned int unk8;
} S;

extern "C" {
int fn_27_D2B28(S* p)
{
    return ((int)((p->unk8 << 4) & 0xF8000000u)) >> 28;
}
}
