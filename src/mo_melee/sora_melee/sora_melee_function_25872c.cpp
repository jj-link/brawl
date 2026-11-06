#pragma force_active on
extern "C" {
void OSReport(const char* fmt, ...);
void fn_27_255B10(void* self);
void fn_27_256838(void* self);
int fn_27_258D18(void* self);
int fn_800C9B00(int);
int fn_800C9B14(int);
int fn_800CBCB0(int, int*);
void* fn_800DCA5C(int, int, unsigned char);
void* fn_800DCA94(int);
int fn_800DCACC(int);
void fn_800DCAE8(int, int, int, int);
void fn_800DCBA4(int);
int fn_800DCBF0(int);
void fn_800DCC30(int, int);
int fn_80110310(int*, int*);
void fn_8013E3E8(void*, int);
void* getInstance__8ipSwitchFv(void);
void playSE__9sndSystemF5SndIDiiii(void* sys, int id, int a, int b, int c, int d);
extern int g_IfMngr;
extern char g_Network[];
extern void* g_gfApplication;
extern int g_muWifiInterfaceTask;
extern void* g_sndSystem;
extern unsigned char lbl_27_bss_59D8;
extern char lbl_27_data_53438[];
extern int lbl_805A0448;
}

extern "C" void fn_27_25872C(void* arg0) {
    char* d = lbl_27_data_53438;
    int wifi;
    int ifm;
    unsigned char* self = (unsigned char*)arg0;
    int sp10;
    int spC;
    int sp8;
    int state;

    if (self[0x11B] != 0) {
        state = *(int*)(self + 0x12C);
        wifi = g_muWifiInterfaceTask;
        ifm = g_IfMngr;
        switch (state) {
        case 0x00: goto L810;
        case 0x6A: goto L820;
        case 0xCD: goto L830;
        case 0xDA: goto LAAC;
        case 0xF7: goto LB0C;
        case 0x101: goto LB58;
        case 0x128: goto LBF8;
        case 0x132: goto LC34;
        case 0x133: goto LCC8;
        case 0x13E: goto LC74;
        case 0x13F: goto LC88;
        case 0x146: goto LCB4;
        case 0x147: goto LCC8;
        default: goto LCE0;
        }

    L810:
        *(int*)(self + 0x128) = *(int*)(d + 0x5C);
        *(int*)(self + 0x12C) = 0x6A;
    L820:
        fn_27_256838(self);
        fn_27_255B10(self);
    L830:
        if (lbl_27_bss_59D8 != 0) {
            if (fn_27_258D18(self) != 0) goto LACC;
        }
        switch (*(int*)(self + 0x134)) {
        case 0x00: goto L890;
        case 0x74:
        case 0x91:
        case 0xC9: goto LA0;
        case 0xC1: goto L948;
        default: goto LA84;
        }

    L890:
        *(int*)(self + 0x130) = *(int*)(d + 0x60);
        *(int*)(self + 0x134) = 0x74;
    LA0:
        if (self[0x11C] != 0) goto LC48;
        if (self[0xBB] == 0) goto L934;
        if (fn_80110310(&sp10, &spC) == 0) goto L934;
        if (spC < 0 && self[0x125] != 0) goto L934;
        playSE__9sndSystemF5SndIDiiii(g_sndSystem, 0x2054, -1, 0, 0, -1);
        fn_800DCA5C(ifm, sp10, self[0x126]);
        if (self[0x125] != 0) {
            unsigned char v = (unsigned char)spC;
            ((unsigned char*)getInstance__8ipSwitchFv())[0x25] = v;
        }
        goto L948;

    L934:
        *(int*)(self + 0x130) = *(int*)(d + 0x64);
        *(int*)(self + 0x134) = 0x91;
        goto LA84;

    L948:
        if (self[0x11C] != 0) goto LC48;
        if (self[0xBB] == 0) goto LA2C;
        switch (fn_800DCACC(ifm)) {
        case 0: goto LA5C;
        case 1: goto LA48;
        case 2: goto L990;
        case 3: goto L9D0;
        default: goto LA10;
        }

    L990:
        OSReport(d + 0xA0);
        playSE__9sndSystemF5SndIDiiii(g_sndSystem, 0x2052, 0x10000, 0, 0, -1);
        fn_800DCA94(ifm);
        self[0x11F] = 1;
        goto LA98;

    L9D0:
        OSReport(d + 0xAC);
        playSE__9sndSystemF5SndIDiiii(g_sndSystem, 0x2052, 0x10000, 0, 0, -1);
        fn_800DCA94(ifm);
        self[0x11E] = 1;
        goto LC48;

    LA10:
        if (fn_800DCACC(ifm) == 1) fn_800DCA94(ifm);
        goto LA5C;

    LA2C:
        if (fn_800DCACC(ifm) == 1) fn_800DCA94(ifm);
        goto LA5C;

    LA48:
        *(int*)(self + 0x130) = *(int*)(d + 0x68);
        *(int*)(self + 0x134) = 0xC1;
        goto LA84;

    LA5C:
        if (self[0x125] != 0) {
            unsigned char* ip = (unsigned char*)getInstance__8ipSwitchFv();
            ip[0x25] = 0xFF;
        }
        *(int*)(self + 0x130) = *(int*)(d + 0x6C);
        *(int*)(self + 0x134) = 0xC9;

    LA84:
        *(int*)(self + 0x128) = *(int*)(d + 0x70);
        *(int*)(self + 0x12C) = 0xCD;
        goto LCE0;

    LA98:
        fn_8013E3E8(*(void**)(g_Network + 0x34), 2);

    LAAC:
        if (self[0x11C] != 0) goto LC48;
        *(int*)(self + 0x128) = *(int*)(d + 0x74);
        *(int*)(self + 0x12C) = 0xDA;
        goto LCE0;

    LACC:
        fn_8013E3E8(*(void**)(g_Network + 0x34), 2);
        self[0x11D] = 1;
        goto LB0C;

    LAEC:
        if (self[0x11C] != 0) goto LC48;
        *(int*)(self + 0x128) = *(int*)(d + 0x78);
        *(int*)(self + 0x12C) = 0xF7;
        goto LCE0;

    LB0C:
        if ((((unsigned char*)g_gfApplication)[0xD0] >> 7) & 1) goto LAEC;
        playSE__9sndSystemF5SndIDiiii(g_sndSystem, 0x22, 0x10000, 0, 0, -1);
        goto LB58;

    LB44:
        *(int*)(self + 0x128) = *(int*)(d + 0x7C);
        *(int*)(self + 0x12C) = 0x101;
        goto LCE0;

    LB58:
        if (lbl_805A0448 != 0) goto LB44;
        wifi = fn_800CBCB0(wifi, &sp8);
        if (fn_800DCACC(ifm) == 1) fn_800DCA94(ifm);
        if (fn_800DCBF0(ifm) != 0) fn_800DCBA4(ifm);
        fn_800DCAE8(ifm, 0, fn_800C9B00(wifi), 0);
        if (fn_800C9B14(wifi) != 0) fn_800DCC30(ifm, sp8);
        goto LBF8;

    LBE4:
        *(int*)(self + 0x128) = *(int*)(d + 0x80);
        *(int*)(self + 0x12C) = 0x128;
        goto LCE0;

    LBF8:
        if (fn_800DCBF0(ifm) == 1) goto LBE4;
        if (fn_800DCBF0(ifm) != 0) fn_800DCBA4(ifm);
        *(int*)(self + 0x128) = *(int*)(d + 0x84);
        *(int*)(self + 0x12C) = 0x132;
        goto LCE0;

    LC34:
        *(int*)(self + 0x128) = *(int*)(d + 0x88);
        *(int*)(self + 0x12C) = 0x133;
        goto LCE0;

    LC48:
        if (fn_800DCACC(ifm) != 1) goto LC88;
        fn_800DCA94(ifm);
        *(int*)(self + 0x128) = *(int*)(d + 0x8C);
        *(int*)(self + 0x12C) = 0x13E;
        goto LCE0;

    LC74:
        *(int*)(self + 0x128) = *(int*)(d + 0x90);
        *(int*)(self + 0x12C) = 0x13F;
        goto LCE0;

    LC88:
        if (fn_800DCBF0(ifm) == 0) goto LCC8;
        fn_800DCBA4(ifm);
        *(int*)(self + 0x128) = *(int*)(d + 0x94);
        *(int*)(self + 0x12C) = 0x146;
        goto LCE0;

    LCB4:
        *(int*)(self + 0x128) = *(int*)(d + 0x98);
        *(int*)(self + 0x12C) = 0x147;
        goto LCE0;

    LCC8:
        self[0x11B] = 0;
        *(int*)(self + 0x128) = *(int*)(d + 0x9C);
        *(int*)(self + 0x12C) = 0x14C;

    LCE0:
        if (self[0x11B] != 0) {
            self[0x11A] = 1;
            self[0x119] = 1;
        }
    }
}
