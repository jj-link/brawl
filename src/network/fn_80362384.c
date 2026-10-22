#pragma force_active on
typedef struct Obj {
    int unk0;
    int (*unk4)(int, int);
    int unk8;
    int unkC;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
} Obj;

extern int fn_8037EFE8(void);
extern void fn_8037EFEC(int, int);
extern void fn_8037F074(int, int);
extern int fn_8037EAFC(int, int, int, int, int, int, int, int, void *, void *);
extern void fn_803622B0(void);

void fn_80362384(Obj *arg0) {
    int temp;

    temp = fn_8037EFE8();
    arg0->unk1C = temp;
    if (temp == 0) {
        arg0->unk30 = 1;
        arg0->unk2C = 1;
        return;
    }
    fn_8037EFEC(temp, 0);
    fn_8037F074(arg0->unk1C, arg0->unk10);
    if (arg0->unk4 != 0) {
        arg0->unk4(arg0->unk1C, arg0->unk20);
    }
    arg0->unk28 = fn_8037EAFC(arg0->unk8, arg0->unkC, 0, 0, arg0->unk1C, 0, 0, 0, (void *)fn_803622B0, arg0);
}
