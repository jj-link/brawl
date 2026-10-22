#pragma force_active on
typedef unsigned short u16;

typedef struct Blk {
    int x0;
    int x4;
    char pad[0x84];
    int x8c;
    char pad2[0x50];
    int xe0;
    char pad3[0x30];
    int x114;
} Blk;

extern Blk lbl_804ECE00[2];
extern u16 lbl_805A0B98;
extern const char* lbl_8059EB30;
extern int lbl_8047C080[4];

u16 fn_801DC2C4(void);
void fn_801E0704(int* p);
void fn_80209864(void);
void OSRegisterVersion(const char* ver);
void OSCreateAlarm(void* alarm);
void OSRegisterShutdownFunction(int* info);

void fn_8020A37C(void) {
    Blk* p;
    int i;
    if (lbl_804ECE00[0].x114 == 0 || lbl_804ECE00[1].x114 == 0) {
        lbl_805A0B98 = fn_801DC2C4();
        OSRegisterVersion(lbl_8059EB30);
        fn_80209864();
        p = lbl_804ECE00;
        i = 0;
        do {
            p->x4 = -3;
            fn_801E0704(&p->x8c);
            OSCreateAlarm(&p->xe0);
            i += 1;
            p += 1;
        } while (i < 2);
        lbl_804ECE00[0].x114 = 0x80000000;
        lbl_804ECE00[1].x114 = 0x80000000;
        OSRegisterShutdownFunction(lbl_8047C080);
    }
}
