# Runtime.PPCEABI.H/fn_803F3A54.s (auto_03_803F3A54_text)
#
# Reconstructed at assembly level from the Brawl target
# (build/RSBE01_02/asm/auto_03_803F3A54_text.s), following the fn_803F1B64.s precedent.

.include "macros.inc"

.text
.balign 4

.fn fn_803F3A54, global
	li r0, 0x0
	sth r5, 0x2(r3)
	li r7, 0x0
	stb r0, 0x0(r3)
	b .L_803F3A80
.L_803F3A68:
	lbz r6, 0x0(r4)
	add r5, r3, r7
	addi r4, r4, 0x1
	addi r7, r7, 0x1
	subi r0, r6, 0x30
	stb r0, 0x5(r5)
.L_803F3A80:
	cmpwi r7, 0x24
	bge .L_803F3A94
	lbz r0, 0x0(r4)
	extsb. r0, r0
	bne .L_803F3A68
.L_803F3A94:
	lbz r0, 0x0(r4)
	stb r7, 0x4(r3)
	extsb. r0, r0
	beqlr
	cmpwi r0, 0x5
	bltlr
	bgt .L_803F3AE4
	addi r5, r4, 0x1
	b .L_803F3AC8
.L_803F3AB8:
	extsb r0, r4
	cmpwi r0, 0x30
	bne .L_803F3AE4
	addi r5, r5, 0x1
.L_803F3AC8:
	lbz r4, 0x0(r5)
	extsb. r0, r4
	bne .L_803F3AB8
	add r4, r7, r3
	lbz r0, 0x4(r4)
	clrlwi. r0, r0, 31
	beqlr
.L_803F3AE4:
	lbz r4, 0x4(r3)
	addi r6, r3, 0x5
	li r0, 0x0
	add r5, r6, r4
	subi r5, r5, 0x1
.L_803F3AF8:
	lbz r4, 0x0(r5)
	cmplwi r4, 0x9
	bge .L_803F3B10
	addi r0, r4, 0x1
	stb r0, 0x0(r5)
	blr
.L_803F3B10:
	cmplw r5, r6
	bne .L_803F3B30
	li r0, 0x1
	stb r0, 0x0(r5)
	lha r4, 0x2(r3)
	addi r0, r4, 0x1
	sth r0, 0x2(r3)
	blr
.L_803F3B30:
	stb r0, 0x0(r5)
	subi r5, r5, 0x1
	b .L_803F3AF8
	blr
.endfn fn_803F3A54
