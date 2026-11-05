#pragma force_active on
extern "C" {
void fn_18_1754(void* self, unsigned int flags);
void fn_18_17B0(void* self, int a, int b, float c);
void playSE__9sndSystemF5SndIDiiii(void* self, int a, int b, int c, int d, int e);
void printIndex__5MuMsgFUlUlPv(void* msg, unsigned long a, unsigned long b, void* c);
extern void* g_sndSystem;
extern double lbl_2_rodata_F58;

int fn_2_2DBE8(void* self, unsigned int flags) {
    unsigned short* counter = (unsigned short*)((char*)self + 0x42);
    int result = 0;

    if (flags & 1) {
        if (*counter == 0) {
            *counter = 5;
        } else {
            *counter = *counter - 1;
            if (*counter == 0) {
                fn_18_1754(self, 8);
            }
        }
        result = 1;
    } else if (flags & 2) {
        if (*counter == 5) {
            *counter = 0;
        } else {
            *counter = *counter + 1;
            if (*counter == 5) {
                fn_18_1754(self, 4);
            }
        }
        result = 1;
    }

    if (result != 0) {
        playSE__9sndSystemF5SndIDiiii(g_sndSystem, 0, -1, 0, 0, -1);
        void* msg = *(void**)((char*)self + 0x66C);
        printIndex__5MuMsgFUlUlPv(msg, 1, (unsigned long)*counter + 0xA, 0);
        fn_18_17B0(self, 0xCA, 1, (float)*counter);
    }

    return result;
}
}