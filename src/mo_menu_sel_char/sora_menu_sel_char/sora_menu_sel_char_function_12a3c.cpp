#pragma force_active on
extern "C" {
extern void* g_muWifiInterfaceTask;
extern void* g_sndSystem;
extern char* g_GameGlobal;
extern const int lbl_10_rodata_590[];

int fn_800D69C8(void*, int);
void fn_800FD96C(int, int);
void fn_10_145F0(void*, int);
void fn_800B9804(void*, int);
void fn_10_11C50(void*);
void fn_10_15A84(void*, int);
void fn_10_14F38(void*, int, int);
void playSE__9sndSystemF5SndIDiiii(void*, int, int, int, int, int);
void fn_10_19374(void*, int);
void fn_800D7E4C(void*, int);
int fn_10_12E58(void*);
int fn_10_99B8(void*);
}

extern "C" void fn_10_12A3C(void* self) {
    char* base = (char*)self;
    void* wifi = g_muWifiInterfaceTask;

    if (*(int*)(base + 0x428) > 0) {
        if (--*(int*)(base + 0x428) > 0)
            return;
    }

    if (*(unsigned char*)(base + 0x426)) {
        int result = fn_800D69C8(wifi, *(int*)(base + 0x1b0));
        if ((unsigned int)(result - 1) > 1)
            return;

        if (result == 1) {
            int value = *(int*)(base + 0x42c);
            fn_800FD96C(*(int*)(base + 0x41c), 0);
            *(int*)(base + 0x420) = 0;
            fn_10_145F0(self, 0x25);
            fn_10_145F0(self, 0x26);
            fn_10_145F0(self, 0x27);
            *(int*)(base + 0x1dc) = value;

            if (value >= 0)
                fn_800B9804(base + 4, value & 0xff);

            fn_10_11C50(self);

            if (value >= 0) {
                char* p = *(char**)(base + 0x1a8);
                *(float*)(p + 0x90) = *(float*)(p + 0x84);
                *(float*)(p + 0x94) = *(float*)(p + 0x88);
                *(float*)(p + 0x98) = *(float*)(p + 0x8c);
            }

            int zero = 0;
            *(int*)base = zero;
            fn_10_15A84(self, 1);
            *(int*)(base + 0x1d8) = zero;
            fn_10_14F38(self, 0, *(int*)(base + 0x1b4));
            playSE__9sndSystemF5SndIDiiii(g_sndSystem, 0x26, -1, 0, 0, -1);
        } else {
            fn_10_19374(self, 3);
            *(int*)(base + 0x428) = 120;
            fn_800D7E4C(wifi, *(int*)(base + 0x1b0));
        }

        *(unsigned char*)(base + 0x426) = 0;
    } else {
        int state = lbl_10_rodata_590[fn_10_12E58(self)];

        if (state == 0) {
            unsigned int mode =
                *(unsigned char*)(*(char**)(g_GameGlobal + 0x10) + 4);

            if ((unsigned int)(mode - 13) > 2 &&
                fn_10_99B8(*(void**)(base + 0x1f4)))
                state = 1;
        }

        if (state != *(int*)(base + 0x430)) {
            fn_10_19374(self, state);
            if (state == 1)
                playSE__9sndSystemF5SndIDiiii(
                    g_sndSystem, 0x2052, -1, 0, 0, -1);
        }
    }
}
