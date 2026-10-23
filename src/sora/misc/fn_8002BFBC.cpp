#pragma force_active on

extern "C" int OSDisableInterrupts();
extern "C" void OSRestoreInterrupts(int);

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;
typedef long s32;

class gfRumble {
public:
    char pad0[0xE8];
    void* unkE8;

    void lbStopRumble(s32 arg0);
};

void gfRumble::lbStopRumble(s32 arg0) {
    char* slot = (char*)this + arg0 * 12;
    int enabled = OSDisableInterrupts();
    u32 cur = *(u32*)(slot + 0x8C);

    if (cur != 0) {
        while (cur != 0) {
            u32 nxt = *(u32*)cur;
            u32* link = (u32*)(slot + 0x8C);

            while (*link != cur) {
                link = (u32*)*link;
            }

            *link = nxt;
            *(u16*)(slot + 0x88) = *(u16*)(slot + 0x88) - 1;
            *(u32*)cur = (u32)unkE8;
            unkE8 = (void*)cur;
            cur = nxt;
        }
    }

    OSRestoreInterrupts(enabled);
    enabled = OSDisableInterrupts();
    *(u8*)(slot + 0x86) = 1;
    OSRestoreInterrupts(enabled);
}
