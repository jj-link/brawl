#pragma force_active on
extern void InitializeProgramEndTrap(void);
extern void usr_put_initialize(void);
extern int TRKInitializeDispatcher(void);
extern int TRKInitializeEventQueue(void);
extern int TRKInitializeIntDrivenUART(int, int, int, unsigned char **);
extern int TRKInitializeMessageBuffers(void);
extern int TRKInitializeSerialHandler(void);
extern int TRKInitializeTarget(void);
extern void TRKTargetSetInputPendingPtr(unsigned char *);
extern int gTRKBigEndian;
extern unsigned char *gTRKInputPendingPtr;

static inline int TRKInitializeEndian(void) {
    unsigned char bytes[4];
    int result = 0;
    gTRKBigEndian = 1;
    bytes[0] = 0x12;
    bytes[1] = 0x34;
    bytes[2] = 0x56;
    bytes[3] = 0x78;
    if (*(unsigned long *)bytes == 0x12345678) {
        gTRKBigEndian = 1;
    } else if (*(unsigned long *)bytes == 0x78563412) {
        gTRKBigEndian = 0;
    } else {
        result = 1;
    }
    return result;
}

int TRKInitializeNub(void) {
    int result;
    int uartResult;

    result = TRKInitializeEndian();
    if (result == 0) {
        usr_put_initialize();
    }
    if (result == 0) {
        result = TRKInitializeEventQueue();
    }
    if (result == 0) {
        result = TRKInitializeMessageBuffers();
    }
    if (result == 0) {
        result = TRKInitializeDispatcher();
    }
    InitializeProgramEndTrap();
    if (result == 0) {
        result = TRKInitializeSerialHandler();
    }
    if (result == 0) {
        result = TRKInitializeTarget();
    }
    if (result == 0) {
        uartResult = TRKInitializeIntDrivenUART(0xE100, 1, 0, &gTRKInputPendingPtr);
        TRKTargetSetInputPendingPtr(gTRKInputPendingPtr);
        if (uartResult != 0) {
            result = uartResult;
        }
    }
    return result;
}