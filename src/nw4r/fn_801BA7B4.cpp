#include <nw4r/snd/snd_Types.h>
#include <revolution/OS/OSAddress.h>
#pragma force_active on

using nw4r::snd::detail::AdpcmParam;
extern "C" void* memcpy(void*, const void*, unsigned long);

extern "C" s16 fn_801D4FDC(AdpcmParam*, u8);

static inline u32 DspAddress(const void* data, u32 samples) {
    u32 base = (u32)data;
    if (data) base = (u32)OSCachedToPhysical(data);
    return samples % 14 + base * 2 + samples / 14 * 16 + 2;
}

extern "C" void fn_801BA7B4(u16* pred, u16* yn1, u16* yn2,
                            u32 offset, const void* data, const AdpcmParam& initial) {
    AdpcmParam state;
    memcpy(state.coef, initial.coef, 0x20);
    state.gain = initial.gain;
    state.pred_scale = initial.pred_scale;
    state.yn1 = initial.yn1;
    state.yn2 = initial.yn2;
    u32 current = DspAddress(data, 0);
    u32 end = DspAddress(data, offset);
    while (current < end) {
        if (!(current & 15)) {
            state.pred_scale = *(u8*)OSPhysicalToCached(current >> 1);
            current += 2;
        }
        u8 value = *(u8*)OSPhysicalToCached(current >> 1);
        fn_801D4FDC(&state, (u8)((current & 1) ? (value & 15) : (value >> 4)));
        ++current;
    }
    *pred = state.pred_scale;
    *yn1 = state.yn1;
    *yn2 = state.yn2;
}
