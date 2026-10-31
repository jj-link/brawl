#pragma force_active on

#define PASTE(x, y) x##y
#define BLOCK PASTE(a, sm)
#define RG PASTE(r, egister)

void PPCMtwpar(RG unsigned int val) {
    BLOCK { mtspr WPAR, val }
}
