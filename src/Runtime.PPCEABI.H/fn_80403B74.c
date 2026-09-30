typedef unsigned long u32;

extern u32 gTRKState[];

void TRKTargetSetStopped(u32 stopped) {
    gTRKState[0x98 / sizeof(u32)] = stopped;
}

u32 TRKTargetStopped(void) {
    return gTRKState[0x98 / sizeof(u32)];
}
