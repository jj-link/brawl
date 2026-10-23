#pragma force_active on
#define KASM a##s##m

KASM void fn_801D7974(void) {
    nofralloc
    rlwinm r6, r5, 30, 27, 31
    clrlwi r3, r3, 3
    or r6, r6, r3
    mtspr 922, r6
    rlwinm r6, r5, 2, 28, 29
    or r6, r6, r4
    ori r6, r6, 2
    mtspr 923, r6
    blr
}
