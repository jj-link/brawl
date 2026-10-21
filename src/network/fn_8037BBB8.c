#pragma force_active on
typedef struct {
    int unk0;
    unsigned char *unk4;
    int unk8;
    int unkC;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
} S;

void fn_8037BBB8(S *p)
{
    p->unkC = 0;
    p->unk10 = 0;
    if (p->unk20 == 0) {
        *p->unk4 = 0;
    }
}
