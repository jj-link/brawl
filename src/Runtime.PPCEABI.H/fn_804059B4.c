#pragma force_active on
extern int TRKInitializeNub(void);
extern int TRKNubWelcome(void);
extern int TRKNubMainLoop(void);
extern int TRKTerminateNub(void);
extern int TRK_mainError_8059BED0;

void TRK_main(void) {
    int err;

    err = TRKInitializeNub();
    TRK_mainError_8059BED0 = err;
    if (err == 0) {
        TRKNubWelcome();
        TRKNubMainLoop();
    }
    TRK_mainError_8059BED0 = TRKTerminateNub();
}
