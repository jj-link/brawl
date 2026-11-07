#pragma force_active on
typedef unsigned short u16;
typedef int s32;

typedef struct Ctx {
    char pad0[0x0c];
    s32 unkC;
    s32 unk10;
    void *unk14;
    void *unk18;
    char pad1C[0x04];
    u16 unk20;
    char pad22[0x02];
    void *unk24;
    char pad28[0x04];
    void *unk2C;
    char pad30[0x08];
    s32 unk38;
    s32 unk3C;
    char pad40[0x20];
    s32 unk60;
    s32 unk64;
    char pad68[0x0c];
    char pad74[0x04];
    char pad78[0xa8];
    s32 unk120;
    char pad124[0x3c];
    s32 unk160;
    char pad164[0x0c];
    s32 unk170;
    char pad174[0x0c];
    s32 unk180;
    char pad184[0x04];
    s32 unk188;
    char pad18C[0x08];
    s32 unk194;
} Ctx;

extern char lbl_804908D0[];
extern char lbl_8059FAA8;
extern char lbl_8059FAB0;
extern char lbl_8059FAB8;
extern char lbl_8059FAC0;
extern char lbl_8059FAC8;
extern char lbl_8059FAD0;
extern char lbl_8059FAD4;
extern char lbl_8059FADC;
extern s32 lbl_805A1064;

int fn_8037B644(void *, void *, s32);
int fn_8037B7B4(void *, s32, s32);
int fn_8037B98C(void *, void *, void *);
void fn_8037BA34(void *, s32);
void fn_8037BB6C(void *, u16);
void fn_8037BBB8(void *);
int fn_8037BBDC(void *);
void fn_8037BDD4(void *, s32, s32);
void *fn_8037F338(void *);
int sprintf(char *, const char *, ...);
char *strstr(const char *, const char *);

void fn_80381148(Ctx *arg0) {
    char sp8[0x18];
    char *base = lbl_804908D0;
    char *r29;
    char *s;

    if (arg0->unk60 == 0) {
        if (arg0->unk194 == 0) {
            r29 = (char *)arg0 + 0x54;
        } else {
            r29 = (char *)arg0 + 0x78;
        }
        if (arg0->unk160 != 0 && arg0->unk180 == 0) {
            s = &lbl_8059FAA8;
        } else {
            s = &lbl_8059FAB8;
            if (arg0->unkC == 3) {
                s = &lbl_8059FAB0;
            }
        }
        fn_8037B644(r29, s, 0);
        if (arg0->unk188 != 0 || lbl_805A1064 != 0) {
            fn_8037B644(r29, arg0->unk14, 0);
        } else {
            fn_8037B644(r29, arg0->unk24, 0);
        }
        fn_8037B644(r29, base + 0xc, 0);
        if ((u16)arg0->unk20 == 0x50) {
            fn_8037B98C(r29, &lbl_8059FAC0, arg0->unk18);
        } else {
            fn_8037B644(r29, &lbl_8059FAC8, 0);
            fn_8037B644(r29, arg0->unk18, 0);
            fn_8037BA34(r29, 0x3a);
            fn_8037BB6C(r29, arg0->unk20);
            fn_8037B644(r29, &lbl_8059FAD0, 2);
        }
        if (arg0->unk2C == 0 || strstr(arg0->unk2C, base + 0x18) == 0) {
            fn_8037B98C(r29, base + 0x18, base + 0x28);
        }
        if (arg0->unk38 != 0) {
            fn_8037B98C(r29, base + 0x38, base + 0x44);
        } else {
            fn_8037B98C(r29, base + 0x38, &lbl_8059FAD4);
        }
        if (arg0->unk160 != 0 && arg0->unk180 == 0) {
            sprintf(sp8, &lbl_8059FADC, arg0->unk170);
            fn_8037B98C(r29, base + 0x50, sp8);
            fn_8037B98C(r29, base + 0x60, fn_8037F338(arg0));
        }
        if (arg0->unk2C != 0) {
            fn_8037B644(r29, arg0->unk2C, 0);
        }
        fn_8037B644(r29, &lbl_8059FAD0, 2);
        if (arg0->unk194 != 0) {
            if (fn_8037B7B4((char *)arg0 + 0x54, *(s32 *)(r29 + 4), *(s32 *)(r29 + 0xc)) == 0) {
                arg0->unk120 = 1;
                arg0->unk3C = 0x11;
                return;
            }
            fn_8037BBB8(r29);
        }
    }
    if (fn_8037BBDC(arg0) != 0 && arg0->unk64 >= arg0->unk60) {
        fn_8037BBB8((char *)arg0 + 0x54);
        if (arg0->unk160 != 0 && arg0->unk180 == 0) {
            arg0->unk10 = 6;
        } else {
            arg0->unk10 = 7;
        }
        fn_8037BDD4(arg0, 0, 0);
    }
}
