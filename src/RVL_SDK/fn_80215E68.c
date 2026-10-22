#pragma force_active on
extern int lbl_805A0C48;
extern int lbl_8059ECE0;
extern int lbl_805A0C28;
extern int lbl_8059ECF0;
extern void *lbl_8059ECF4;
extern int lbl_805A078C;
extern unsigned int lbl_805A0C3C;
extern unsigned int lbl_804F67A0[4];
extern char lbl_8047C618[];
extern void fn_8021635C(void);
extern void fn_80216474(void);
extern void fn_8021658C(void);
extern void OSRegisterVersion(int);
extern long long OSGetTime(void);
extern void fn_801E75A0(void);
extern void OSRegisterShutdownFunction(void *);
extern int fn_80215C54(unsigned int);

int fn_80215E68(void) {
    int s;
    unsigned int v;
    if (lbl_805A0C48 != 0) return 1;
    OSRegisterVersion(lbl_8059ECE0);
    s = lbl_805A0C28;
    if (s != 0) {
        lbl_805A0C28 = 0;
        switch (s) {
        case 0: lbl_8059ECF4 = fn_8021635C; break;
        case 1: lbl_8059ECF4 = fn_80216474; break;
        case 2: case 3: case 4: case 5: lbl_8059ECF4 = fn_8021658C; break;
        }
        lbl_8059ECF0 = s;
    }
    lbl_805A0C48 = 1;
    if (lbl_805A078C != 0) {
        long long t = OSGetTime();
        *(unsigned short *)0x800030E0 = (unsigned short)(((t & 0xFFFF) + ((t >> 16) & 0xFFFF) + ((t >> 32) & 0xFFFF) + ((t >> 48) & 0xFFFF)) & 0x3FFF);
        lbl_805A0C3C = 0xF0000000;
    }
    v = (*(unsigned short *)0x800030E0 & 0x3FFF) << 8;
    lbl_804F67A0[0] = v | 0x4D000000;
    lbl_804F67A0[1] = v | 0x4D400000;
    lbl_804F67A0[2] = v | 0x4D800000;
    lbl_804F67A0[3] = v | 0x4DC00000;
    fn_801E75A0();
    OSRegisterShutdownFunction(lbl_8047C618);
    return fn_80215C54(0xF0000000);
}
