extern "C" {
void OSUnlockMutex(void*);
unsigned int fn_801D536C(void);
int fn_801DEDC4(void*);
}

extern int lbl_80494910[6];

#pragma force_active on
extern "C" void fn_8001B7A4(void) {
    if ((fn_801D536C() & 0xF0000000) != 0) {
        int ok = ((fn_801DEDC4(lbl_80494910) - 1) == 0);
        if (ok) {
            OSUnlockMutex(lbl_80494910);
        }
    }
}
