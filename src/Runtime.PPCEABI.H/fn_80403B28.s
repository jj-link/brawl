.include "macros.inc"
.file "fn_80403B28"
.text
.balign 4

# .text:0x0 | 0x80403B28 | size: 0x24
.fn fn_80403B28, global
/* 80403B28 003F98A8  94 21 FF C0 */	stwu r1, -0x40(r1)
/* 80403B2C 003F98AC  DB E1 00 10 */	stfd f31, 0x10(r1)
/* 80403B30 003F98B0  F3 E1 00 20 */	psq_st f31, 0x20(r1), 0, qr0
/* 80403B34 003F98B4  CB E3 00 00 */	lfd f31, 0x0(r3)
/* 80403B38 003F98B8  FD FE FD 8E */	mtfsf 255, f31
/* 80403B3C 003F98BC  E3 E1 00 20 */	psq_l f31, 0x20(r1), 0, qr0
/* 80403B40 003F98C0  CB E1 00 10 */	lfd f31, 0x10(r1)
/* 80403B44 003F98C4  38 21 00 40 */	addi r1, r1, 0x40
/* 80403B48 003F98C8  4E 80 00 20 */	blr
.endfn fn_80403B28
