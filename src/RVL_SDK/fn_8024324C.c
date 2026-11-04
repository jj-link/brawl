#pragma force_active on
extern unsigned char lbl_805297D0[];
extern const char lbl_80481EF0[];
extern void *fn_8022F77C(void *);
extern unsigned char fn_8022F904(void *);
extern void fn_80231A14(unsigned int, const char *, unsigned short, unsigned short);
extern void fn_80231FB0(void *, int, int);
extern void fn_80232020(void *);
extern void fn_8024304C(unsigned short, unsigned char, void *);
extern void fn_8022F0E0(void *);
extern void fn_80242908(int);

void fn_8024324C(unsigned char *arg0)
{
    unsigned char *command;
    unsigned char *base;
    unsigned char status;
    unsigned short opcode;
    unsigned char *data;
    unsigned char *p;
    unsigned short cmd_opcode;

    status = arg0[0];
    command = 0;
    data = 0;
    *(unsigned short *)(lbl_805297D0 + 0x80) = arg0[1];
    opcode = arg0[2] + (arg0[3] << 8);
    if (opcode != 0xC03 && opcode != 0xC35 && opcode != 0) {
        command = fn_8022F77C(lbl_805297D0 + 0x70);
        if (command != 0) {
            p = command + *(unsigned short *)(command + 4);
            data = p + 0xA;
            cmd_opcode = p[8] + (p[9] << 8);
            if (cmd_opcode != opcode) {
                data = 0;
                fn_80231A14(0x70001, lbl_80481EF0, opcode, cmd_opcode);
            }
        }
        base = lbl_805297D0;
        if (fn_8022F904(base + 0x70) == 0) {
            fn_80231FB0(base + 0x4C, 0x3C, 8);
        } else {
            fn_80232020(base + 0x4C);
        }
    }
    fn_8024304C(opcode, status, data);
    if (command != 0) {
        fn_8022F0E0(command);
    }
    fn_80242908(0);
}
