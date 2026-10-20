#pragma force_active on
typedef struct {
    int unk0;
    int unk1;
    unsigned int pad : 4;
    signed int f : 4;
    unsigned int rest : 24;
} S;

extern "C" int fn_27_FF158(S *s)
{
    return s->f;
}
