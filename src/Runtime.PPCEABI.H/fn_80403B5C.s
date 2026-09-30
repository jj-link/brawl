.include "macros.inc"
.file "fn_80403B28"
.text
.balign 4

# .text:0x34 | 0x80403B5C | size: 0x18
.fn fn_80403B5C, global
/* 80403B5C 003F98DC  3C 60 80 5A */	lis r3, gTRKState@ha
/* 80403B60 003F98E0  38 00 00 01 */	li r0, 0x1
/* 80403B64 003F98E4  38 83 B9 4C */	addi r4, r3, gTRKState@l
/* 80403B68 003F98E8  38 60 00 00 */	li r3, 0x0
/* 80403B6C 003F98EC  90 04 00 98 */	stw r0, 0x98(r4)
/* 80403B70 003F98F0  4E 80 00 20 */	blr
.endfn fn_80403B5C
