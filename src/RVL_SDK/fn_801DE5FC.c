#include <types.h>
#pragma force_active on

#define PASTE(x, y) x##y
#define BLOCK PASTE(a, sm)

BLOCK void fn_801DE5FC(void) {
    li r7, 0x0
    lis r4, 0x1000
    addi r4, r4, 0x2
    lis r3, 0x9000
    addi r3, r3, 0x3ff
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
    lis r4, 0x1200
    addi r4, r4, 0x2
    lis r3, 0x9200
    addi r3, r3, 0x1ff
    lis r6, 0x1300
    addi r6, r6, 0x2
    lis r5, 0x9300
    addi r5, r5, 0xff
    isync
    mtspr 572, r7
    mtspr 573, r4
    mtspr 572, r3
    isync
    mtspr 564, r7
    mtspr 565, r4
    mtspr 564, r3
    isync
    mtspr 574, r7
    mtspr 575, r6
    mtspr 574, r5
    isync
    mtspr 566, r7
    mtspr 567, r6
    mtspr 566, r5
    isync
    mfmsr r3
    ori r3, r3, 0x30
    mtsrr1 r3
    mflr r3
    mtsrr0 r3
    rfi
}
