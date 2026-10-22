#pragma force_active on

extern "C" {

extern char lbl_27_data_45990[];

struct SoraMeleeArg {
    void* unk0;
    int unk4;
    int unk8;
    unsigned char unkC;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
};

void fn_27_1DC5E8(SoraMeleeArg* arg0, int arg1, int arg2, int arg3, int arg4, int arg5,
                  unsigned char arg6, int arg7, int sp8, int spC, int sp10, int sp14,
                  int sp18, int sp1C, int sp20, int sp24)
{
    arg0->unk0 = &lbl_27_data_45990;
    arg0->unk4 = arg1;
    arg0->unk8 = arg2;
    arg0->unkC = arg6;
    arg0->unk10 = arg7;
    arg0->unk14 = sp8;
    arg0->unk18 = spC;
    arg0->unk1C = sp10;
    arg0->unk20 = arg3;
    arg0->unk24 = arg4;
    arg0->unk28 = arg5;
    arg0->unk2C = sp14;
    arg0->unk30 = sp18;
    arg0->unk34 = sp1C;
    arg0->unk38 = sp20;
    arg0->unk3C = sp24;
}

}
