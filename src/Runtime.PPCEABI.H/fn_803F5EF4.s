# Runtime.PPCEABI.H/fn_803F5EF4.s (auto_03_803F5EF4_text)
#
# Reconstructed at assembly level from the Brawl target
# (build/RSBE01_02/asm/auto_03_803F5EF4_text.s).

.include "macros.inc"

.text
.balign 4

.fn fn_803F5EF4, global
	lis r6, lbl_804942B8@ha
	addi r6, r6, lbl_804942B8@l
	lwz r6, 0x38(r6)
	lwz r12, 0x20(r6)
	mtctr r12
	bctr
.endfn fn_803F5EF4

.fn fn_803F5F0C, global
	cmpwi r4, 0x0
	bne .L_803F5F1C
	li r3, 0x0
	blr
.L_803F5F1C:
	cmpwi r5, 0x0
	bne .L_803F5F2C
	li r3, -0x1
	blr
.L_803F5F2C:
	cmpwi r3, 0x0
	beq .L_803F5F3C
	lbz r0, 0x0(r4)
	sth r0, 0x0(r3)
.L_803F5F3C:
	lbz r0, 0x0(r4)
	extsb. r0, r0
	bne .L_803F5F50
	li r3, 0x0
	blr
.L_803F5F50:
	li r3, 0x1
	blr
.endfn fn_803F5F0C

.fn fn_803F5F58, global
	cmpwi r3, 0x0
	bne .L_803F5F68
	li r3, 0x0
	blr
.L_803F5F68:
	stb r4, 0x0(r3)
	li r3, 0x1
	blr
.endfn fn_803F5F58
