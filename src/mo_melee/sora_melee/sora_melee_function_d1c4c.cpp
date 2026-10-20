#pragma force_active on
typedef struct {
    unsigned int unk0;
    unsigned int unk4;
    unsigned int kind : 6;
    unsigned int rest : 26;
} FtBits;

extern "C" void fn_27_D1C4C(FtBits* p, unsigned int v)
{
    p->kind = v;
}
