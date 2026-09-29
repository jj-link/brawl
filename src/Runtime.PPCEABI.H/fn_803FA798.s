# Runtime.PPCEABI.H/fn_803FA798.s (auto_03_803FA798_text)

.include "macros.inc"

.text
.balign 4

.fn strstr, global
	cmpwi r4, 0x0
	subi r5, r3, 0x1
	beqlr
	lbz r6, 0x0(r4)
	cmpwi r6, 0x0
	bne .L_803FA7F0
	blr
	b .L_803FA7F0
.L_803FA7B8:
	cmplw r0, r6
	bne .L_803FA7F0
	subi r7, r5, 0x1
	subi r8, r4, 0x1
.L_803FA7C8:
	lbzu r0, 0x1(r7)
	lbzu r3, 0x1(r8)
	cmplw r0, r3
	bne .L_803FA7E0
	cmpwi r0, 0x0
	bne .L_803FA7C8
.L_803FA7E0:
	cmpwi r3, 0x0
	bne .L_803FA7F0
	mr r3, r5
	blr
.L_803FA7F0:
	lbzu r0, 0x1(r5)
	cmpwi r0, 0x0
	bne .L_803FA7B8
	li r3, 0x0
	blr
.endfn strstr
