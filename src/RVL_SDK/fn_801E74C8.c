#include <types.h>
#include <revolution/SI/SISamplingRate.h>
#include <revolution/VI/vihardware.h>
#pragma force_active on

extern s32 OSDisableInterrupts(void);
extern void OSRestoreInterrupts(s32 level);
extern void OSReport(const char* msg, ...);
extern u32 fn_801E9BDC(void);
extern u32 fn_801E6AE8(u32 lines, u32 times);
extern u32 lbl_805A0790;

typedef struct SIPollSetting {
    struct {
        u16 lines;
        u8 times;
    } params[SI_MAX_SAMPLE_RATE + 1];
} SIPollSetting;

static SIPollSetting lbl_80474EC0 = {
    {
        { 246, 2 }, { 14, 19 }, { 30, 9 }, { 44, 6 },
        { 52, 5 }, { 65, 4 }, { 87, 3 }, { 87, 3 },
        { 87, 3 }, { 131, 2 }, { 131, 2 }, { 131, 2 }
    }
};

static SIPollSetting lbl_80474EF0 = {
    {
        { 296, 2 }, { 15, 21 }, { 29, 11 }, { 45, 7 },
        { 52, 6 }, { 63, 5 }, { 78, 4 }, { 104, 3 },
        { 104, 3 }, { 104, 3 }, { 104, 3 }, { 156, 2 }
    }
};

static char lbl_80474F20[] = "SISetSamplingRate: unknown TV format. Use default.";

void fn_801E74C8(u32 msec) {
    SIPollSetting* xy;
    s32 enabled;
    s32 m;

    if (msec > SI_MAX_SAMPLE_RATE) {
        msec = SI_MAX_SAMPLE_RATE;
    }

    enabled = OSDisableInterrupts();

    lbl_805A0790 = msec;

    switch (fn_801E9BDC()) {
    case 0:
    case 2:
    case 5:
        xy = &lbl_80474EC0;
        break;
    case 1:
        xy = &lbl_80474EF0;
        break;
    default:
        OSReport(lbl_80474F20);
        msec = 0;
        xy = &lbl_80474EC0;
        break;
    }

    m = (VI_HW_REGS[VI_VICLK] & VI_VICLK_SPEED) != VI_VICLK_27MHZ ? 2 : 1;
    fn_801E6AE8(m * xy->params[msec].lines, xy->params[msec].times);

    OSRestoreInterrupts(enabled);
}