// Partial match: instruction differences remain.
#include <snd/snd_system.h>
#pragma force_active on

struct WifiTask {
    char pad0[0xfd5];
    unsigned char fd5;
    char padfd6[4];
    unsigned short fda;
};

struct GfApplication {
    char pad0[0xd0];
    unsigned char flags;
};

struct IfMngr {
    char pad0[0x50];
    unsigned char mode;
};

struct Self {
    char pad0[0x2c];
    unsigned char f2c;
    char pad2d[0xbb - 0x2d];
    unsigned char fbb;
    char padbc[0x12c - 0xbc];
    int stateText;
    int state;
    int s134;
    int s138;
    int s13c;
    int s140;
    int s144;
    int s148;
    unsigned char b14c;
    unsigned char b14d;
    unsigned char b14e;
    unsigned char active;
    unsigned char b150;
    char pad151[3];
    int wifi;
    int p158;
    int s15c;
    unsigned char b160;
    unsigned char b161;
    unsigned char b162;
    char pad163[5];
    int count;
    int threshold;
    int timer;
    unsigned int u174;
    unsigned int u178;
    unsigned char b17c;
    char pad17d[3];
    int s180;
};

extern "C" {
void fn_1_34E4();
void fn_27_256838(Self*);
void fn_27_2559E4(Self*);
void fn_27_25A3BC(Self*, int, int);
void fn_27_255C24(Self*);
void fn_27_255C94(Self*);
unsigned int fn_27_24D18C();
int fn_800C9E88(WifiTask*, int);
int fn_800CAA60(WifiTask*, int);
int fn_800CB00C(WifiTask*);
int fn_800CBCB0(WifiTask*, int*);
int fn_800C9B00(int);
int fn_800C9B14(int);
void fn_800CC1A4(WifiTask*, int, int);
int fn_800CC1BC(WifiTask*);
void fn_800CCCE8(WifiTask*);
int fn_800CCEB8(WifiTask*);
void fn_800CCEC4(WifiTask*, int);
int fn_800CF18C(WifiTask*);
void fn_800D0A58(WifiTask*, int, int);
int fn_800D1854(WifiTask*);
int fn_800D1D10(WifiTask*, int);
void fn_800D1E58(WifiTask*, int);
unsigned char fn_800D4EF0(WifiTask*, void*, void*, void*);
void fn_800D5268(WifiTask*, int, unsigned char, int);
unsigned int fn_800D68C8(WifiTask*, unsigned char*);
unsigned char fn_800D6958(WifiTask*);
int fn_800D69C8(WifiTask*, int);
int fn_800D7A7C(WifiTask*, unsigned char*, int*);
int fn_800D8D60(WifiTask*);
int fn_800D9F58(WifiTask*);
void fn_800C856C(WifiTask*, int);
int fn_800FCC84(IfMngr*);
void fn_800FCC7C(IfMngr*, int);
void fn_800FCD1C(IfMngr*, unsigned int);
void fn_800FCDD4(IfMngr*, int);
void fn_800FCDF8(IfMngr*, int);
void fn_800FCE00(IfMngr*);
int fn_800FCE08(IfMngr*);
void fn_800FCE10(IfMngr*, int, int, int);
void fn_800FCE90(IfMngr*);
int fn_800FCED0(IfMngr*);
void fn_800FCF10(IfMngr*, int);
void fn_800FCF9C(IfMngr*, void*);
void fn_800FD0F0(IfMngr*, int);
int fn_800FD0FC(IfMngr*);
void fn_800FD108(IfMngr*);
int fn_80110310(void*, int*);
void fn_800790FC(int, int);
void OSReport(const char*, ...);

extern WifiTask* g_muWifiInterfaceTask;
extern IfMngr* g_IfWifiprMngr;
extern GfApplication* g_gfApplication;
extern unsigned char lbl_27_bss_59D8;
extern unsigned char lbl_27_bss_59F8[];
extern int lbl_27_data_536E8[];
extern int lbl_805A0448;
extern int lbl_805A01D8;
}

inline bool wifiBusy(Self* self, int* data) {
    if (!lbl_27_bss_59D8) return false;
    if (self->wifi) return true;

    WifiTask* task = g_muWifiInterfaceTask;
    self->wifi = fn_800CC1BC(task);
    if (self->wifi == 0 && fn_800CCEB8(task) &&
        fn_800CF18C(task) == 1) {
        OSReport((const char*)data + 0xd4);
        fn_800CCEC4(task, 0);
        self->wifi = 2;
        fn_800CC1A4(task, 0xe, 2);
    }
    return self->wifi != 0;
}

inline WifiTask* wifiInterfaceTask() {
    return g_muWifiInterfaceTask;
}

inline int readiness(WifiTask* task, int threshold) {
    int result = 0;
    if ((int)task->fd5 >= threshold) {
        if (fn_800CF18C(task) > 1) {
            result = 1;
        }
    }
    return result;
}

extern "C" void fn_27_259188(Self* self) {
    int* data;
    IfMngr* mgr;
    WifiTask* task;
    int list[4];
    int flagA;
    int r27;
    int i;
    int n;
    int j;
    int r;
    int r23;
    unsigned int v;
    unsigned char sp9;
    unsigned char sp8;
    int sp14;
    int sp10;
    int sp0c;
    unsigned int idx;
    unsigned char* p;

    data = lbl_27_data_536E8;
    if (!self->active) {
        return;
    }

    fn_1_34E4();
    task = wifiInterfaceTask();
    mgr = g_IfWifiprMngr;

    switch (self->state) {
    case 0x0: goto STATE0;
    case 0x93: goto STATE93;
    case 0x2a4: goto STATE2A4;
    case 0x2bc: goto STATE2BC;
    case 0x2c9: goto STATE2C9;
    case 0x2e7: goto TAIL2E7;
    case 0x30e: goto CASE30E;
    case 0x327: goto TAIL327;
    default: return;
    }

STATE0:
    self->stateText = data[0x5c / 4];
    self->state = 0x93;

STATE93:
    fn_27_256838(self);
    fn_27_2559E4(self);
    if (task->fda == 0) {
        task->fda = 0x1a4;
    }

STATE2A4:
    if (wifiBusy(self, data)) goto BAIL;

    n = 0;
    for (i = 0; i < self->count; ++i) {
        if (fn_800C9E88(task, i) != 0) {
            list[n++] = i;
        } else {
            fn_27_25A3BC(self, i, 0);
        }
    }

    flagA = readiness(task, self->threshold);

    if (self->b162 == 0 && self->b160 != 0) {
        self->b162 = 1;
        for (j = 0; j < n; ++j) {
            r = fn_800D69C8(task, list[j]);
            switch (r) {
            case 0:
                self->b162 = 0;
                break;
            case 1:
                break;
            case 2:
                goto DISCONNECT;
            default:
                self->b162 = 0;
                break;
            }
        }
    }

    if (self->b162 == 0) {
        r27 = fn_800D6958(task);
        if ((unsigned int)r27 != 0xffu) {
            r27 = r27 + 2;
        } else {
            r27 = 1;
        }
        if (r27 != fn_800FCC84(mgr)) {
            fn_800FCC7C(mgr, r27);
        }
        sp9 = 0;
        v = fn_800D68C8(task, &sp9);
        if (v != self->u178) {
            self->u178 = v;
            self->u174 = v;
        }
        if (sp9 != 0 || (self->u178 + 0x10000u) == 0xffffu) {
            fn_800FCDF8(mgr, 0);
            self->timer = 0x12e;
        } else {
            fn_800FCDD4(mgr, 1);
            fn_800FCD1C(mgr, self->u174);
            if (self->u174 != 0) {
                self->u174 = self->u174 - 1;
            }
            if (self->timer >= (int)self->u174) {
                self->timer = self->timer - 0x3c;
                g_sndSystem->playSE((SndID)0xa, -1, 0, 0, -1);
            }
        }
    } else {
        r23 = (flagA != 0);
        if (r23 != fn_800FCC84(mgr)) {
            fn_800FCC7C(mgr, r23);
        }
        fn_800FCDF8(mgr, flagA);
        if (flagA != 0) {
            fn_800FCDD4(mgr, 0);
            fn_800FCD1C(mgr, task->fda);
            if (self->timer >= (int)task->fda) {
                self->timer = self->timer - 0x3c;
                g_sndSystem->playSE((SndID)0xa, -1, 0, 0, -1);
            }
        } else {
            self->timer = 0x12e;
        }
    }

    switch (self->s138) {
    case 0x0:
        self->s134 = data[0x60 / 4];
        self->s138 = 0x120;
        goto L_1d8;
    case 0x120:
    case 0x1d8:
        goto L_1d8;
    case 0x1f3:
        goto L_1f3;
    case 0x259:
        goto L_259;
    case 0x26b:
        goto L_26b;
    case 0x275:
    case 0x27d:
        goto L_27d;
    case 0x292:
        goto L_292;
    default:
        goto DONE2A4;
    }

L_1d8:
    if (self->b160 != 0 && self->b161 == 0) {
        self->b161 = fn_800D4EF0(
            task, lbl_27_bss_59F8, &self->b17c, &self->s180);
    }

    switch (self->s140) {
    case 0x0:
        self->s13c = data[0x64 / 4];
        self->s140 = 0x12a;
        goto B_body;
    case 0x12a:
    case 0x182:
        goto B_body;
    case 0x140:
    case 0x155:
        goto B_140;
    case 0x166:
        goto STATE166;
    case 0x167:
        goto STATE167;
    case 0x18c:
    case 0x191:
        goto B_980;
    case 0x1a7:
        goto STATE1A7;
    case 0x1a8:
        goto B_a48;
    case 0x1ae:
        goto B_body;
    default:
        goto subC;
    }

B_body:
    if (self->fbb == 0) {
        goto B_NoBB;
    }
    if (self->b161 == 0) {
        goto B_2598e0;
    }
    fn_27_255C24(self);
    fn_800FCF9C(mgr, lbl_27_bss_59F8);
    self->s13c = data[0x68 / 4];
    self->s140 = 0x140;
    goto subC;

B_748:
    if (wifiBusy(self, data)) goto BAIL;
    if (fn_800D7A7C(task, &sp8, &sp14) != 0 &&
        sp8 == self->b17c && sp14 == self->s180) {
        goto L890;
    }
    self->s13c = data[0x6c / 4];
    self->s140 = 0x155;
    goto subC;

B_140:
    if (self->fbb != 0 && fn_800FCED0(mgr) == 1) {
        goto B_748;
    }
    if (self->fbb != 0) {
        r = fn_800FCED0(mgr) - 2;
        fn_800D5268(task, r == 0, self->b17c, self->s180);
    }

L890:
    if (fn_800FCED0(mgr) != 0) {
        fn_800FCE90(mgr);
    }
    self->s13c = data[0x70 / 4];
    self->s140 = 0x166;
    goto subC;

STATE166:
    self->s13c = data[0x74 / 4];
    self->s140 = 0x167;
    goto subC;

STATE167:
    fn_27_255C94(self);
    self->b161 = 0;

B_2598e0:
    if (fn_80110310(&self->p158, &sp10) == 0) {
        goto L910;
    }
    if (sp10 >= 0) {
        goto L924;
    }
    goto L910;

B_NoBB:
    if (self->b150 != 0) {
        goto FINISH;
    }

L910:
    self->s13c = data[0x78 / 4];
    self->s140 = 0x182;
    goto subC;

L924:
    fn_27_255C24(self);
    g_sndSystem->playSE((SndID)0x2054, -1, 0, 0, -1);
    fn_800FD0F0(mgr, self->p158);
    self->s13c = data[0x7c / 4];
    self->s140 = 0x18c;
    goto subC;

WAIT191:
    self->s13c = data[0x80 / 4];
    self->s140 = 0x191;
    goto subC;

B_980:
    if (self->fbb != 0 && self->b161 == 0 &&
        fn_800FD0FC(mgr) != 0) {
        goto WAIT191;
    }
    goto B_9a8;

B_9a8:
    if (self->fbb != 0 && self->b161 == 0 && mgr->mode == 1) {
        g_sndSystem->playSE((SndID)0x2052, 0x10000, 0, 0, -1);
        self->b14d = 1;
        goto FINISH;
    }
    if (self->b161 != 0) {
        if (fn_800FD0FC(mgr) != 0) {
            fn_800FD108(mgr);
        }
        goto B_body;
    }
    self->s13c = data[0x84 / 4];
    self->s140 = 0x1a7;
    goto subC;

STATE1A7:
    self->s13c = data[0x88 / 4];
    self->s140 = 0x1a8;
    goto subC;

B_a48:
    fn_27_255C94(self);
    self->s13c = data[0x8c / 4];
    self->s140 = 0x1ae;
    goto subC;

subC:
    switch (self->s148) {
    case 0x0:
        self->s144 = data[0x90 / 4];
        self->s148 = 0x1b4;
        goto C_aa4;
    case 0x1b4:
    case 0x1c5:
        goto C_aa4;
    case 0x1d3:
        goto C_b1c;
    default:
        goto C_b48;
    }

C_aa4:
    if (self->fbb != 0 && fn_800CAA60(task, self->s15c) != 0) {
        fn_800CCCE8(task);
        idx = fn_27_24D18C();
        if ((unsigned char)idx == 0xff) {
            idx = 4;
        }
        p = (unsigned char*)task + (unsigned char)idx * 0x218;
        p[0xc5] = 4;
        fn_800D0A58(task, 0, 0xfe);
        goto C_b1c;
    }
    self->s144 = data[0x94 / 4];
    self->s148 = 0x1c5;
    goto C_b48;

C_b1c:
    if (self->fbb != 0 && fn_800D1854(task) != 0) {
        goto C_b5c;
    }
    self->s144 = data[0x98 / 4];
    self->s148 = 0x1d3;
    goto C_b48;

C_b48:
    self->s134 = data[0x9c / 4];
    self->s138 = 0x1d8;
    goto DONE2A4;

C_b5c:
    if (fn_800FD0FC(mgr) != 0) {
        fn_800FD108(mgr);
    }
    if (fn_800FCED0(mgr) != 0) {
        fn_800FCE90(mgr);
    }
    goto L_1f3;

WAIT_1F3:
    if (wifiBusy(self, data)) goto BAIL;
    self->s134 = data[0xa0 / 4];
    self->s138 = 0x1f3;
    goto DONE2A4;

L_1f3:
    if (fn_800D9F58(task) == 0) {
        goto WAIT_1F3;
    }
    if (fn_800FD0FC(mgr) != 0) {
        fn_800FD108(mgr);
    }
    if (fn_800FCED0(mgr) != 0) {
        fn_800FCE90(mgr);
    }
    goto L_259;

WAIT_259:
    if (wifiBusy(self, data)) goto BAIL;
    self->s134 = data[0xa4 / 4];
    self->s138 = 0x259;
    goto DONE2A4;

L_259:
    if (fn_800D8D60(task) == 0) {
        goto WAIT_259;
    }
    fn_800C856C(task, 0);
    goto L_26b;

WAIT_26B:
    if (wifiBusy(self, data)) goto BAIL;
    self->s134 = data[0xa8 / 4];
    self->s138 = 0x26b;
    goto DONE2A4;

L_26b:
    if (fn_800CB00C(task) == 0) {
        goto WAIT_26B;
    }
    fn_800D1E58(task, 1);
    self->s134 = data[0xac / 4];
    self->s138 = 0x275;
    goto DONE2A4;

WAIT_27D:
    if (wifiBusy(self, data)) goto BAIL;
    self->s134 = data[0xb0 / 4];
    self->s138 = 0x27d;
    goto DONE2A4;

L_27d:
    if (fn_800D1D10(task, 1) == 0) {
        goto WAIT_27D;
    }
    fn_800FCE00(mgr);
    fn_800790FC(lbl_805A01D8, 0);
    g_sndSystem->playSE((SndID)0x16, 0x10000, 0, 0, -1);
    fn_27_255C24(self);
    goto L_292;

WAIT_292:
    if (wifiBusy(self, data)) goto BAIL;
    self->s134 = data[0xb4 / 4];
    self->s138 = 0x292;
    goto DONE2A4;

L_292:
    if (fn_800FCE08(mgr) == 0) {
        goto WAIT_292;
    }
    self->b14e = 1;
    goto FINISH;

DONE2A4:
    self->stateText = data[0xb8 / 4];
    self->state = 0x2a4;
    return;

BAIL:
    self->f2c = (unsigned char)(self->f2c & ~2);
    goto STATE2BC;

WAIT2BC:
    if (self->b150 != 0) {
        goto FINISH;
    }
    self->stateText = data[0xbc / 4];
    self->state = 0x2bc;
    return;

STATE2BC:
    if ((g_gfApplication->flags >> 7) & 1) {
        goto WAIT2BC;
    }
    self->b14c = 1;
    g_sndSystem->playSE((SndID)0x22, 0x10000, 0, 0, -1);
    goto STATE2C9;

WAIT2C9:
    self->stateText = data[0xc0 / 4];
    self->state = 0x2c9;
    return;

STATE2C9:
    if (lbl_805A0448 != 0) {
        goto WAIT2C9;
    }
    {
        int error = fn_800CBCB0(task, &sp0c);
        if (fn_800FD0FC(mgr) != 0) {
            fn_800FD108(mgr);
        }
        if (fn_800FCED0(mgr) != 0) {
            fn_800FCE90(mgr);
        }
        fn_800FCE10(mgr, 1, fn_800C9B00(error), 0);
        if (fn_800C9B14(error) != 0) {
            fn_800FCF10(mgr, sp0c);
        }
    }
    goto TAIL2E7;

WAIT2E7:
    self->stateText = data[0xc4 / 4];
    self->state = 0x2e7;
    return;

TAIL2E7:
    if (fn_800FCED0(mgr) == 1) {
        goto WAIT2E7;
    }
    if (fn_800FCED0(mgr) != 0) {
        fn_800FCE90(mgr);
    }
    goto FINISH;

DISCONNECT:
    self->b162 = 0;
    self->f2c = (unsigned char)(self->f2c & ~2);
    self->b14c = 1;
    self->wifi = 2;
    goto CASE30E;

WAIT30E:
    if (self->b150 != 0) {
        goto FINISH;
    }
    self->stateText = data[0xc8 / 4];
    self->state = 0x30e;
    return;

CASE30E:
    if ((g_gfApplication->flags >> 7) & 1) {
        goto WAIT30E;
    }
    g_sndSystem->playSE((SndID)0x22, 0x10000, 0, 0, -1);
    if (fn_800FD0FC(mgr) != 0) {
        fn_800FD108(mgr);
    }
    if (fn_800FCED0(mgr) != 0) {
        fn_800FCE90(mgr);
    }
    fn_800FCE10(mgr, 1, 0x1b, 0);
    goto TAIL327;

WAIT327:
    self->stateText = data[0xcc / 4];
    self->state = 0x327;
    return;

TAIL327:
    if (fn_800FCED0(mgr) == 1) {
        goto WAIT327;
    }
    if (fn_800FCED0(mgr) != 0) {
        fn_800FCE90(mgr);
    }

FINISH:
    self->active = 0;
    self->stateText = data[0xd0 / 4];
    self->state = 0x338;
    return;
}
