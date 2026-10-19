#pragma force_active on
typedef struct
{
    void *unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
} Unk41_738;

extern Unk41_738 lbl_41_data_738;

extern "C" void fn_41_2834(void *r3, int r4, int r5, int r6)
{
    Unk41_738 *out = (Unk41_738 *)r3;
    out->unk00 = &lbl_41_data_738;
    out->unk10 = r4;
    out->unk14 = r5;
    out->unk18 = r6;
}
