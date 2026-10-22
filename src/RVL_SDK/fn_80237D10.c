#pragma force_active on
extern unsigned char lbl_805A0D30;
extern char lbl_804806BC[];
extern void fn_802319FC(int, void *, int);
extern void fn_80232780(void **);
extern void *fn_8022EE58(unsigned short);
extern void *memcpy(void *, const void *, unsigned int);

struct Obj {
    unsigned short unk0;
    void *unk4;
    short unk8;
    short unkA;
    short unkC;
    short unkE;
    unsigned char unk10;
    unsigned char unk11;
    unsigned char unk12;
    signed char unk13;
    unsigned char unk14;
    signed char unk15;
    signed char unk16;
    unsigned char unk17;
    signed char unk18;
};

void fn_80237D10(struct Obj *arg0, int arg1, int arg2, void *arg3, int arg4, int arg5) {
    void *result;

    if (lbl_805A0D30 >= 5) {
        fn_802319FC(0x504, lbl_804806BC, arg4);
    }
    arg0->unk16 = (signed char)arg1;
    arg0->unk18 = 1;
    arg0->unkE = (short)arg2;
    arg0->unk13 = (signed char)arg4;
    arg0->unk15 = (signed char)arg5;
    if (arg3 != 0) {
        fn_80232780(&arg0->unk4);
        if (*(unsigned short *)arg3 != 0) {
            result = fn_8022EE58(*(unsigned short *)arg3);
            arg0->unk4 = result;
            if (result != 0) {
                arg0->unk0 = *(unsigned short *)arg3;
                memcpy(result, *(void **)((char *)arg3 + 4), *(unsigned short *)arg3);
            }
        }
    }
}
