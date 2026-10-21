#pragma force_active on
extern "C" int fn_801D7AD8();
extern "C" void fn_801E0CC0();
extern "C" void OSUnlockMutex(void*);
extern unsigned char lbl_8049ED70[];

extern "C" void fn_8015D874(void) {
    while (fn_801D7AD8() != 0) {
        fn_801E0CC0();
    }
    OSUnlockMutex(lbl_8049ED70 + 4);
}
