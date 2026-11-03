#pragma force_active on
extern int fn_8039A274(void);
extern unsigned int fn_80399AC8(void);

typedef struct {
    unsigned char pad0[4];
    unsigned int unk4;
    unsigned char pad8[0x10];
    unsigned int unk18;
} Obj;

int fn_8039B070(Obj *arg0, unsigned int arg1) {
    unsigned int temp_r5;
    unsigned int temp_r0;

    temp_r5 = arg0->unk4;
    if (!(temp_r5 & 0x100) || (temp_r5 & 0x200)) {
        return -7;
    }
    if (arg1 == 0) {
        return -3;
    }
    if (!(temp_r5 & 1) || !(temp_r5 & 8)) {
        return -4;
    }
    temp_r0 = arg0->unk18;
    if (temp_r0 != 0 && !(temp_r0 & 0x40000)) {
        return -4;
    }
    if (fn_8039A274() == 0 && fn_80399AC8() != 0x48414541 && arg1 >= 0x4000) {
        return -3;
    }
    arg0->unk18 = arg1 | 0x40000;
    return 0;
}
