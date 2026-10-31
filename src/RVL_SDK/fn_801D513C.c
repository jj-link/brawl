#pragma force_active on
#define PASTE(x, y) x##y
#define BLOCK PASTE(a, sm)
#define RG PASTE(r, egister)

void PPCMthid2(RG unsigned int val) {
    BLOCK { mtspr 0x398, val }
}
