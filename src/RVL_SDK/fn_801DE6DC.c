#include <types.h>
#pragma force_active on

#define PASTE(x, y) x##y
#define BLOCK PASTE(a, sm)

BLOCK void fn_801DE6DC(void) {
    li r7, 0x0
    lis r4, 0x1000
    addi r4, r4, 0x2
    lis r3, 0x9000
    addi r3, r3, 0x7ff
    lis r6, 0x1000
    addi r6, r6, 0x2a
    lis r5, 0xd000
    addi r5, r5, 0x7ff
    isync
    mtspr 568, r7
    mtspr 569, r4
    mtspr 568, r3
    isync
    mtspr 560, r7
    mtspr 561, r4
    mtspr 560, r3
    isync
    mtspr 570, r7
    mtspr 571, r6
    mtspr 570, r5
    isync
    mtspr 562, r7
    mtspr 563, r7
    isync
    mtspr 564, r7
    mtspr 565, r7
    isync
    mtspr 566, r7
    mtspr 567, r7
    isync
    mtspr 572, r7
    mtspr 573, r7
    isync
    mtspr 574, r7
    mtspr 575, r7
    isync
    mfmsr r3
    ori r3, r3, 0x30
    mtsrr1 r3
    mflr r3
    mtsrr0 r3
    rfi
}
