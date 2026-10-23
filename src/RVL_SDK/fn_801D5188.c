#include <types.h>
#pragma force_active on

extern void OSReport(const char*, ...);
extern char lbl_80466E30[];

#define PASTE(x, y) x##y
#define BLOCK PASTE(a, sm)
#define RG PASTE(r, egister)

void fn_801D5188(RG u32 val) {
    if ((val & 0x80000000) != 0) {
        BLOCK { mtspr 0x3F3, val }
        return;
    }
    OSReport(lbl_80466E30);
    val |= 0x80000000;
    BLOCK { mtspr 0x3F3, val }
}
