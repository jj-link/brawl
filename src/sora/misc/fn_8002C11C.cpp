#pragma force_active on

extern "C" int OSDisableInterrupts(void);
extern "C" void OSRestoreInterrupts(int);

typedef unsigned short u16;
typedef unsigned long u32;

class gfRumble {
public:
    char pad0[0xE8];
    void* unkE8;

    void HSD_PadRumbleRemove(long arg0);
};

void gfRumble::HSD_PadRumbleRemove(long arg0) {
    u32* link;
    u32 next;
    u32 cur;
    char* slot = (char*)this + arg0 * 12;
    int enabled = OSDisableInterrupts();
    cur = *(u32*)(slot + 0x8C);

    if (cur != 0) {
        while (cur != 0) {
            next = *(u32*)cur;
            link = (u32*)(slot + 0x8C);

            while (*link != cur) {
                link = (u32*)*link;
            }

            *link = next;
            *(u16*)(slot + 0x88) = *(u16*)(slot + 0x88) - 1;
            *(u32*)cur = (u32)unkE8;
            unkE8 = (void*)cur;
            cur = next;
        }
    }

    OSRestoreInterrupts(enabled);
}
