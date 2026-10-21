#pragma force_active on
extern "C" void OSDisableInterrupts(void);
extern "C" void OSRestoreInterrupts(void);

class gfPadSystem {
public:
    char pad0[0x30];
    int unk30;
    void consumeFrameCounter(int);
};

void gfPadSystem::consumeFrameCounter(int arg0) {
    OSDisableInterrupts();
    unk30 -= arg0;
    OSRestoreInterrupts();
}
