#pragma force_active on
extern "C" {
typedef struct {
    int unk0;
    int unk4;
    unsigned int f0 : 6;
    unsigned int f1 : 1;
    unsigned int f2 : 25;
} St;

int fn_62_6088(St *p)
{
    return p->f1;
}
}
