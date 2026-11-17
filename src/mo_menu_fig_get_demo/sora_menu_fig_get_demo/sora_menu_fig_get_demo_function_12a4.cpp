#include <types.h>
#include <gf/gf_pad_system.h>
#include <gf/gf_pad_status.h>
#pragma force_active on

extern "C" {
extern const char lbl_26_data_164[];
extern const float lbl_26_rodata_28;
extern const float lbl_26_rodata_2C;
void changeAnimN__8MuObjectFPCc(void*, const char*);
void fn_800B753C(void*, float);
s32 fn_800B63B8(void*);
void setUpdateRate__16gfModelAnimationFf(void*, float);
}

union FigButtons {
    unsigned int bits;
    struct {
        unsigned int padding : 11;
        unsigned int confirm : 1;
        unsigned int remaining : 20;
    } fields;
};

inline unsigned int figPressed(unsigned int buttons) {
    FigButtons input;
    input.bits = buttons;
    if (buttons & 0x100)
        return 1;
    if (buttons & 0x200)
        return 1;
    if (buttons & 0x1000)
        return 1;
    return input.fields.confirm;
}

extern "C" s32 fn_26_12A4(unsigned char* self) {
    gfPadStatus status;
    g_gfPadSystem->getSysPadStatus(0xF0, &status);
    unsigned char* obj = *(unsigned char**)(self + 0x6d4);

    if (figPressed(status.m_buttonsPressedThisFrame.bits) == 1 && self[0x1370] == 0) {
        self[0x1370] = 1;
        changeAnimN__8MuObjectFPCc(obj, lbl_26_data_164);
        fn_800B753C(obj, lbl_26_rodata_28);
        setUpdateRate__16gfModelAnimationFf(*(void**)(obj + 0x14), lbl_26_rodata_2C);
    }

    if (fn_800B63B8(obj) != 0) {
        *(s32*)(self + 0x40) = 1;
    }
    return *(s32*)(self + 0x1368);
}
