#pragma force_active on

typedef struct Obj {
    int unk0;
    short unk4;
    int unk8;
    short unkC;
    int unk10;
    char unk14;
    char unk15;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
} Obj;

extern void *fn_8035DFE8(int);
extern int fn_8035AED0(int, int, int, void *, void *, void *);
extern void fn_8035E00C(void *);
extern void fn_80389014(void);
extern void fn_80389088(void);
extern void fn_80388FD4(void);

void *fn_803890B0(int unused, int arg1, int arg2) {
    Obj *obj;
    int temp;

    obj = (Obj *)fn_8035DFE8(0x2C);
    if (obj == 0) {
        return 0;
    }
    temp = fn_8035AED0(8, 8, 4, fn_80389014, fn_80389088, fn_80388FD4);
    obj->unk18 = temp;
    if (temp == 0) {
        fn_8035E00C(obj);
        return 0;
    }
    obj->unk14 = 0;
    obj->unk15 = 0;
    obj->unk24 = 0;
    obj->unk1C = 0;
    obj->unk10 = 0;
    obj->unk0 = arg1;
    obj->unk4 = arg2;
    obj->unk8 = 0;
    obj->unkC = 0;
    return obj;
}
