#pragma force_active on
extern "C" {
struct fn_27_CBD44_S {
    int unk0;
    int unk4;
    unsigned int a : 10;
    unsigned int b : 5;
    unsigned int c : 17;
};

void fn_27_CBD44(struct fn_27_CBD44_S *p, unsigned int v)
{
    p->b = v;
}
}
