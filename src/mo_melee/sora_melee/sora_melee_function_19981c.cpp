#pragma force_active on
typedef struct {
    unsigned int unk0;
    unsigned int unk4;
    struct {
        unsigned int hi : 8;
        unsigned int f : 4;
        unsigned int lo : 20;
    } unk8;
} FnState;

extern "C" {
void fn_27_19981C(FnState* p, unsigned int v)
{
    p->unk8.f = v;
}
}
