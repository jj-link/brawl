#pragma force_active on
struct Self {
    char pad0[8];
    char* p8;
    char* pC;
    char* p10;
    char* p14;
    char* p18;
    char* p1C;
    char pad20[4];
    int f24;
    unsigned int state;
    unsigned char b2C;
};

extern "C" {
void fn_24_2F48(void*);
void fn_1_FD24(void*);
void kill__10gfHomeMenuFv(void*);
void fn_24_4C8(void*, void*);
void fn_24_920(void*, void*);
void fn_24_E2C(void*, void*);
void fn_24_1344(void*, void*);
void* getInstance__16CameraControllerFv(void);
void changeInput__16CameraControllerFQ216CameraController4Kind(void*, int);
void endKeepScreen__17gfKeepFrameBufferFv(void*);
void fn_24_64C(void*);
void fn_24_A0C(void*);
void fn_24_10D4(void*);
void fn_24_1424(void*);
void fn_24_5DC(void*);
unsigned int fn_24_6B4(void*);
unsigned int fn_24_30D8(void*);
unsigned int fn_24_2FC8(void*);
void fn_24_6DC(void*);
void fn_24_9E8(void*);
unsigned int fn_24_A90(void*);
unsigned int fn_24_31F4(void*);
void fn_24_A2C(void*);
void fn_24_AB4(void*);
void fn_24_1030(void*);
unsigned int fn_24_113C(void*);
void fn_24_116C(void*);
void fn_24_1400(void*);
void start__10gfHomeMenuFv(void*);
unsigned int setBan__10gfHomeMenuFUlUl(void*, unsigned int, unsigned int);
void fn_1_FF20(void*);
void fn_1_4A44(void*, int, int, int);
void* fn_80024790(void*);
void* getInstance__14gfSceneManagerFv(void);
extern char* g_gfApplication;
extern void* g_gfHomeMenu;
extern char* lbl_1_bss_20;
extern char lbl_804221E8;
}

extern "C" int fn_1_F6D0(Self* self) {
    if (self->p1C != 0) {
        fn_24_2F48(self->p1C);
    }
    switch (self->state) {
    case 0:
        fn_1_FD24(self);
        if (self->p10 == 0) {
            kill__10gfHomeMenuFv(g_gfHomeMenu);
        }
        self->state = 1;
        break;
    case 1:
        if ((((unsigned char*)self->p8)[9] >> 7) & 1) {
            self->state = 2;
        }
        break;
    case 2:
        if (self->pC != 0) {
            fn_24_4C8(self->pC, self->p8);
        }
        if (self->p10 != 0) {
            fn_24_920(self->p10, self->p8);
        }
        if (self->p14 != 0) {
            fn_24_E2C(self->p14, self->p8);
        }
        if (self->p18 != 0) {
            fn_24_1344(self->p18, self->p8);
        }
        changeInput__16CameraControllerFQ216CameraController4Kind(getInstance__16CameraControllerFv(), 9);
        if ((*(int*)(g_gfApplication + 0xE4) >> 24) == 1) {
            self->state = 0xF;
        } else {
            self->state = 3;
        }
        break;
    case 3:
        if (self->pC != 0) {
            self->state = 4;
        } else {
            self->state = 7;
        }
        break;
    case 4:
        endKeepScreen__17gfKeepFrameBufferFv(g_gfApplication + 0xD0);
        if (self->pC != 0) {
            fn_24_64C(self->pC);
        }
        if (self->p10 != 0) {
            fn_24_A0C(self->p10);
        }
        if (self->p14 != 0) {
            fn_24_10D4(self->p14);
        }
        if (self->p18 != 0) {
            fn_24_1424(self->p18);
        }
        fn_24_5DC(self->pC);
        *(int*)((char*)self->pC + 0x1D4) = 1;
        self->state = 5;
        break;
    case 5:
        if (fn_24_6B4(self->pC) == 1 && fn_24_30D8(self->p1C) == 1) {
            if (self->f24 != 0) {
                if (fn_24_2FC8(self->p1C) == 1) {
                    self->f24 = 0;
                } else {
                    self->f24 = 1;
                }
            }
            fn_24_6DC(self->pC);
        }
        if (*(int*)((char*)self->pC + 0x1D4) == 0xB) {
            self->state = 6;
        }
        break;
    case 6:
        self->state = 7;
        break;
    case 7:
        if (self->p10 != 0) {
            self->state = 8;
        } else {
            self->state = 0xB;
        }
        break;
    case 8:
        endKeepScreen__17gfKeepFrameBufferFv(g_gfApplication + 0xD0);
        if (self->pC != 0) {
            fn_24_64C(self->pC);
        }
        if (self->p10 != 0) {
            fn_24_A0C(self->p10);
        }
        if (self->p14 != 0) {
            fn_24_10D4(self->p14);
        }
        if (self->p18 != 0) {
            fn_24_1424(self->p18);
        }
        fn_24_9E8(self->p10);
        *(int*)((char*)self->p10 + 0x4C) = 1;
        self->state = 9;
        break;
    case 9:
        if (fn_24_A90(self->p10) == 1 && fn_24_31F4(self->p1C) == 1) {
            if (self->f24 != 0) {
                if (fn_24_2FC8(self->p1C) == 1) {
                    self->f24 = 0;
                } else {
                    self->f24 = 1;
                }
            }
            fn_24_A2C(self->p10);
            fn_24_AB4(self->p10);
        }
        if (*(int*)((char*)self->p10 + 0x4C) == 6) {
            self->state = 0xA;
        }
        break;
    case 10:
        self->state = 0xB;
        break;
    case 11:
        if (self->p14 != 0) {
            self->state = 0xC;
        } else {
            self->state = 0xF;
        }
        break;
    case 12:
        endKeepScreen__17gfKeepFrameBufferFv(g_gfApplication + 0xD0);
        if (self->pC != 0) {
            fn_24_64C(self->pC);
        }
        if (self->p10 != 0) {
            fn_24_A0C(self->p10);
        }
        if (self->p14 != 0) {
            fn_24_10D4(self->p14);
        }
        if (self->p18 != 0) {
            fn_24_1424(self->p18);
        }
        fn_24_1030(self->p14);
        *(int*)((char*)self->p14 + 0x58) = 1;
        self->state = 0xD;
        break;
    case 13:
        if (fn_24_113C(self->p14) == 1 && fn_24_31F4(self->p1C) == 1) {
            if (self->f24 != 0) {
                if (fn_24_2FC8(self->p1C) == 1) {
                    self->f24 = 0;
                } else {
                    self->f24 = 1;
                }
            }
            fn_24_116C(self->p14);
        }
        if (*(int*)((char*)self->p14 + 0x58) == 0xB) {
            self->state = 0xE;
        }
        break;
    case 14:
        self->state = 0xF;
        break;
    case 15:
        if (self->p18 != 0) {
            self->state = 0x10;
        } else {
            self->state = 0x13;
        }
        break;
    case 16:
        if (self->pC != 0) {
            fn_24_64C(self->pC);
        }
        if (self->p10 != 0) {
            fn_24_A0C(self->p10);
        }
        if (self->p14 != 0) {
            fn_24_10D4(self->p14);
        }
        if (self->p18 != 0) {
            fn_24_1424(self->p18);
        }
        fn_24_1400(self->p18);
        *(int*)((char*)self->p18 + 0x4C) = 1;
        self->state = 0x11;
        start__10gfHomeMenuFv(g_gfHomeMenu);
        setBan__10gfHomeMenuFUlUl(g_gfHomeMenu, 1, 0);
        break;
    case 17:
        setBan__10gfHomeMenuFUlUl(g_gfHomeMenu, 1, 0);
        if (((unsigned char*)lbl_1_bss_20)[self->b2C + 0xF] != 0) {
            self->state = 0x12;
        }
        break;
    case 18:
        if (setBan__10gfHomeMenuFUlUl(g_gfHomeMenu, 0, 0) == 1) {
            self->state = 0x13;
        }
        break;
    case 19:
        if (self->pC != 0) {
            fn_24_64C(self->pC);
        }
        if (self->p10 != 0) {
            fn_24_A0C(self->p10);
        }
        if (self->p14 != 0) {
            fn_24_10D4(self->p14);
        }
        if (self->p18 != 0) {
            fn_24_1424(self->p18);
        }
        fn_1_FF20(self);
        endKeepScreen__17gfKeepFrameBufferFv(g_gfApplication + 0xD0);
        self->state = 0x14;
        break;
    case 20: {
        fn_80024790(&lbl_804221E8);
        int temp = self->f24;
        void* mgr = getInstance__14gfSceneManagerFv();
        *(int*)((char*)mgr + 0x284) = temp;
        *(int*)((char*)mgr + 0x288) = 2;
        break;
    }
    }
    if ((int)self->state >= 4 && self->p10 == 0) {
        fn_1_4A44(lbl_1_bss_20, self->b2C, 0x29, 0x2B);
    }
    return 0;
}
