#pragma force_active on
typedef struct {
    unsigned int hi : 6;
    unsigned int f : 3;
    unsigned int lo : 23;
} FtFlagsBits;

typedef struct {
    int unk0;
    int unk4;
    FtFlagsBits word8;
} FtFlags;

extern "C" {
void fn_27_1CF6B0(FtFlags* p, unsigned int v)
{
    p->word8.f = v;
}
}
