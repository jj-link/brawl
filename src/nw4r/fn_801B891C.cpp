#include <nw4r/snd/snd_AxVoice.h>
#include <revolution/OS/OSInterrupt.h>
#pragma force_active on

extern "C" void* fn_801B77F8();
extern "C" u32 fn_801B7EE0(void*);

extern "C" int fn_801B891C(void* arg) {
    BOOL enabled = OSDisableInterrupts();
    if (!*(void**)((char*)arg + 0x10)) {
        OSRestoreInterrupts(enabled);
        return 0;
    }

    AXVPB* vpb = *(AXVPB**)arg;
    u32 current = vpb
        ? (vpb->pb.addr.currentAddressHi << 16) +
              vpb->pb.addr.currentAddressLo
        : 0;
    u32 address = fn_801B7EE0(fn_801B77F8());
    int format = *(u32*)((char*)arg + 0x14);

    if (address != 0) {
        address += 0x80000000;
    }

    u32 start = 0;
    switch (format) {
    case 0:
        start = address * 2 + 2;
        break;
    case 25:
        start = address;
        break;
    case 10:
        start = address >> 1;
        break;
    }

    u32 end = start;
    switch (*(int*)((char*)arg + 0x14)) {
    case 0:
        end = start + 0x200;
        break;
    case 25:
        end = start + 0x100;
        break;
    case 10:
        end = start + 0x80;
        break;
    }

    if (start <= current && current < end) {
        OSRestoreInterrupts(enabled);
        return 1;
    }

    OSRestoreInterrupts(enabled);
    return 0;
}
