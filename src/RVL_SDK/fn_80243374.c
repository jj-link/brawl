#pragma force_active on
extern unsigned char lbl_805297D0[];
extern const char lbl_80481F18[];
extern const char lbl_80481F38[];
extern void *fn_8022F77C(void *);
extern unsigned char fn_8022F904(void *);
extern void fn_802319E4(int, const char *);
extern void fn_802319FC(int, const char *, int);
extern void fn_80231FB0(void *, int, int);
extern void fn_8024304C(unsigned short, unsigned char, void *);
extern void fn_80242DDC(unsigned short, void *, unsigned short);
extern void fn_8022F0E0(void *);
extern void fn_8023BC78(int);
extern void fn_80242908(int);

void fn_80243374(void)
{
    unsigned char *command;
    unsigned char *p;
    unsigned short cmd_opcode;
    unsigned char status;

    *(unsigned short *)(lbl_805297D0 + 0x80) = 1;
    command = fn_8022F77C(lbl_805297D0 + 0x70);
    if (command == 0) {
        fn_802319E4(0x70001, lbl_80481F18);
        return;
    }
    if (fn_8022F904(lbl_805297D0 + 0x70) == 0) {
        fn_80231FB0(lbl_805297D0 + 0x4c, 0x3c, 8);
    }
    p = command + *(unsigned short *)(command + 4);
    cmd_opcode = p[8] + (p[9] << 8);
    fn_802319FC(0x70001, lbl_80481F38, cmd_opcode);
    switch (cmd_opcode) {
        case 0xd:
        case 0x401:
        case 0x405:
        case 0x419:
        case 0x801:
        case 0x803:
        case 0x804:
        case 0x805:
        case 0x806:
            fn_8024304C(cmd_opcode, 0x1f, p + 0xa);
            break;
        default:
            status = 0x1f;
            fn_80242DDC(cmd_opcode, &status, 1);
            break;
    }
    fn_8022F0E0(command);
    fn_8023BC78(2);
    fn_80242908(0);
}
