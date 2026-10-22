#pragma force_active on
extern "C" void fn_8015CDA8(void);
extern "C" int OSDisableInterrupts(void);
extern "C" void OSRestoreInterrupts(int);
extern "C" void OSInitMutex(void*);
extern "C" void fn_801E0704(void*);
extern "C" char lbl_80464610[0x68];
extern "C" char lbl_8049ED58[0x18];
extern "C" int lbl_805A0498;
extern "C" unsigned char lbl_805A04A0;

extern "C" void* fn_8015D36C(void* arg0) {
    int state;
    fn_8015CDA8();
    *((unsigned char*)arg0 + 0x6F) = 0;
    *(void**)arg0 = lbl_80464610;
    state = OSDisableInterrupts();
    if (lbl_805A04A0 == 0) {
        OSInitMutex(lbl_8049ED58);
        fn_801E0704(&lbl_805A0498);
        lbl_805A04A0 = 1;
    }
    OSRestoreInterrupts(state);
    return arg0;
}
