#pragma force_active on
#define KASM a##s##m

KASM void fn_801D7950(void) {
    nofralloc
    rlwinm r6, r5, 30, 27, 31
    clrlwi r4, r4, 3
    or r6, r6, r4
    mtspr 922, r6
    rlwinm r6, r5, 2, 28, 29
    or r6, r6, r3
    ori r6, r6, 0x12
    mtspr 923, r6
    blr
}
