# Runtime.PPCEABI.H/fn_803F5C38.s (auto_03_803F5C38_text)
# Reconstructed at assembly level from the Brawl target.

.include "macros.inc"

.text
.balign 4

.fn fn_803F5C38, global
	lwz r0, 0x4(r3)
	li r6, 0x0
	extrwi r4, r0, 3, 7
	addi r0, r4, 0xff
	clrlwi r0, r0, 24
	cmplwi r0, 0x1
	bgt .L_803F5C60
	lbz r0, 0xa(r3)
	cmpwi r0, 0x0
	beq .L_803F5C70
.L_803F5C60:
	li r0, 0x28
	li r3, -0x1
	stw r0, lbl_805A12E0@sda21(r0)
	blr
.L_803F5C70:
	lwz r0, 0x8(r3)
	srwi. r5, r0, 29
	bne .L_803F5C84
	lwz r3, 0x18(r3)
	blr
.L_803F5C84:
	lwz r8, 0x1c(r3)
	cmplwi r5, 0x3
	lwz r4, 0x24(r3)
	lwz r0, 0x34(r3)
	subf r4, r8, r4
	add r7, r0, r4
	blt .L_803F5CA8
	subi r6, r5, 0x2
	subf r7, r6, r7
.L_803F5CA8:
	lwz r0, 0x4(r3)
	extrwi. r0, r0, 1, 12
	bne .L_803F5CD8
	subf. r0, r6, r4
	mtctr r0
	beq .L_803F5CD8
.L_803F5CC0:
	lbz r0, 0x0(r8)
	addi r8, r8, 0x1
	cmplwi r0, 0xa
	bne .L_803F5CD4
	addi r7, r7, 0x1
.L_803F5CD4:
	bdnz .L_803F5CC0
.L_803F5CD8:
	mr r3, r7
	blr
.endfn fn_803F5C38

.fn fn_803F5CE0, global
	b fn_803F5C38
.endfn fn_803F5CE0
