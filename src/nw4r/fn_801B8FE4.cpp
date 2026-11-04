#pragma force_active on
#include <nw4r/snd/snd_AxVoice.h>
#include <revolution/OS/OSInterrupt.h>

extern "C" int fn_801B891C(void*);

static inline u32 Convert(const void* base, u32 address, int format) {
    u32 physical = (u32)base;
    if (physical != 0) {
        physical += 0x80000000;
    }
    u32 result = 0;
    switch (format) {
    case 0: {
        u32 offset = address - physical * 2;
        result = (offset & 15) + (offset >> 4) * 14 - 2;
        break;
    }
    case 25:
        result = address - physical;
        break;
    case 10:
        result = address - (physical >> 1);
        break;
    }
    return result;
}

extern "C" u32 fn_801B8FE4(void* arg) {
    using namespace nw4r::snd::detail;
    AxVoiceParamBlock* block = (AxVoiceParamBlock*)arg;
    BOOL enabled = OSDisableInterrupts();
    if (!block->IsAvailable()) {
        OSRestoreInterrupts(enabled);
        return 0;
    }
    if (!*(const void**)((char*)arg + 0x10)) {
        OSRestoreInterrupts(enabled);
        return 0;
    }
    if (fn_801B891C(arg)) {
        u32 result = Convert(*(const void**)((char*)arg + 0x10),
                             block->GetEndAddress(),
                             *(int*)((char*)arg + 0x14));
        OSRestoreInterrupts(enabled);
        return result + 1;
    }
    u32 result = Convert(*(const void**)((char*)arg + 0x10),
                         block->GetCurrentAddress(),
                         *(int*)((char*)arg + 0x14));
    OSRestoreInterrupts(enabled);
    return result;
}
