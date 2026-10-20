#pragma force_active on
extern "C" {
extern char lbl_83_data_0[];
extern unsigned char lbl_83_data_BC[];
extern const float lbl_83_rodata_0;
extern const float lbl_83_rodata_4;

void __ct__7stMeleeFPCcQ26Stages11srStageKind(void*, const char*, int);
void __ct__13grTenganEventFv(void*);
int randi__Fl(long);

void* fn_83_A4(void* self) {
    unsigned char* p = (unsigned char*)self;
    __ct__7stMeleeFPCcQ26Stages11srStageKind(p, lbl_83_data_0, 46);
    *(void**)(p + 0x3c) = lbl_83_data_BC;
    __ct__13grTenganEventFv(p + 0x1d8);
    __ct__13grTenganEventFv(p + 0x284);
    __ct__13grTenganEventFv(p + 0x330);
    __ct__13grTenganEventFv(p + 0x3dc);
    __ct__13grTenganEventFv(p + 0x488);
    __ct__13grTenganEventFv(p + 0x534);
    __ct__13grTenganEventFv(p + 0x61c);

    *(float*)(p + 0x5e4) = lbl_83_rodata_0;
    *(int*)(p + 0x5ec) = -1;
    *(int*)(p + 0x604) = -1;
    *(int*)(p + 0x608) = -1;
    p[0x614] = 0;
    *(int*)(p + 0x60c) = 0;
    p[0x610] = 0;
    p[0x611] = 1;
    p[0x612] = 2;
    p[0x613] = 3;

    unsigned int a;
    unsigned int b;
    for (int i = 0; i < 32; ++i) {
        a = randi__Fl(4);
        if (a >= 3) a = 3;
        b = randi__Fl(4);
        if (b >= 3) b = 3;

        unsigned char t;
        unsigned char* pa;
        unsigned char* pb;
        pb = p + b;
        pa = p + a;
        t = pa[0x610];
        pa[0x610] = pb[0x610];
        pb[0x610] = t;
    }

    p[0x6f8] = 0;
    p[0x615] = 0;
    *(float*)(p + 0x6c8) = lbl_83_rodata_4;
    p[0x617] = 0;
    p[0x618] = 0;
    *(float*)(p + 0x6cc) = lbl_83_rodata_4;
    *(float*)(p + 0x6d0) = lbl_83_rodata_0;
    *(float*)(p + 0x6d4) = lbl_83_rodata_0;
    *(float*)(p + 0x6d8) = lbl_83_rodata_0;
    *(float*)(p + 0x6dc) = lbl_83_rodata_0;
    *(float*)(p + 0x6e0) = lbl_83_rodata_0;
    *(float*)(p + 0x6e4) = lbl_83_rodata_0;
    *(float*)(p + 0x6e8) = lbl_83_rodata_0;
    *(float*)(p + 0x6ec) = lbl_83_rodata_0;
    *(float*)(p + 0x6f0) = lbl_83_rodata_4;
    *(float*)(p + 0x6f4) = lbl_83_rodata_4;
    *(int*)(p + 0x6fc) = 0;
    *(int*)(p + 0x700) = 0;
    return self;
}
}
