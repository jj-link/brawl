# Runtime.PPCEABI.H/fn_803FA078.s (auto_03_803FA078_text)

.include "macros.inc"

.text
.balign 4

.fn fn_803FA078, global
	cmpwi r5, 0x1
	beq .L_803FA0CC
	bge .L_803FA090
	cmpwi r5, 0x0
	bge .L_803FA09C
	b .L_803FA100
.L_803FA090:
	cmpwi r5, 0x3
	bge .L_803FA100
	b .L_803FA0F8
.L_803FA09C:
	lwz r4, 0x0(r3)
	lbz r5, 0x0(r4)
	extsb. r0, r5
	bne .L_803FA0BC
	li r0, 0x1
	stw r0, 0x4(r3)
	li r3, -0x1
	blr
.L_803FA0BC:
	addi r0, r4, 0x1
	stw r0, 0x0(r3)
	mr r3, r5
	blr
.L_803FA0CC:
	lwz r0, 0x4(r3)
	cmpwi r0, 0x0
	bne .L_803FA0E8
	lwz r5, 0x0(r3)
	subi r0, r5, 0x1
	stw r0, 0x0(r3)
	b .L_803FA0F0
.L_803FA0E8:
	li r0, 0x0
	stw r0, 0x4(r3)
.L_803FA0F0:
	mr r3, r4
	blr
.L_803FA0F8:
	lwz r3, 0x4(r3)
	blr
.L_803FA100:
	li r3, 0x0
	blr
.endfn fn_803FA078
