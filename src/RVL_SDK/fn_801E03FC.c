typedef unsigned int u32;

#pragma force_active on

asm void fn_801E03FC(void) {
    nofralloc
    mfspr r9, HID0
    ori r10, r9, 0x8
    mtspr HID0, r10
    isync
    sync
    mtspr HID0, r9
    rfi
    nop
}
