# Runtime.PPCEABI.H/TRK_flush_cache.s

.include "macros.inc"

.text
.balign 4

# .text:0xB0 | 0x80403664 | size: 0x38
.fn TRK_flush_cache, global
/* 80403664 003F93E4  3C A0 FF FF */	lis r5, 0xffff
/* 80403668 003F93E8  60 A5 FF F1 */	ori r5, r5, 0xfff1
/* 8040366C 003F93EC  7C A5 18 38 */	and r5, r5, r3
/* 80403670 003F93F0  7C 65 18 50 */	subf r3, r5, r3
/* 80403674 003F93F4  7C 84 1A 14 */	add r4, r4, r3
.L_80403678:
/* 80403678 003F93F8  7C 00 28 6C */	dcbst r0, r5
/* 8040367C 003F93FC  7C 00 28 AC */	dcbf r0, r5
/* 80403680 003F9400  7C 00 04 AC */	sync
/* 80403684 003F9404  7C 00 2F AC */	icbi r0, r5
/* 80403688 003F9408  30 A5 00 08 */	addic r5, r5, 0x8
/* 8040368C 003F940C  34 84 FF F8 */	subic. r4, r4, 0x8
/* 80403690 003F9410  40 80 FF E8 */	bge .L_80403678
/* 80403694 003F9414  4C 00 01 2C */	isync
/* 80403698 003F9418  4E 80 00 20 */	blr
.endfn TRK_flush_cache
