.include "macros.inc"

.text
.balign 4

.fn fn_803FC7C8, global
	subi r4, r3, 0x2
	li r3, -0x1
.L_803FC7D0:
	lhzu r0, 0x2(r4)
	addi r3, r3, 0x1
	cmpwi r0, 0x0
	bne .L_803FC7D0
	blr
.endfn fn_803FC7C8

.fn fn_803FC7E4, global
	subi r4, r4, 0x2
	subi r6, r3, 0x2
	addi r5, r5, 0x1
	b .L_803FC81C
.L_803FC7F4:
	lhzu r0, 0x2(r4)
	cmpwi r0, 0x0
	sthu r0, 0x2(r6)
	bne .L_803FC81C
	li r0, 0x0
	b .L_803FC810
.L_803FC80C:
	sthu r0, 0x2(r6)
.L_803FC810:
	subic. r5, r5, 0x1
	bne .L_803FC80C
	blr
.L_803FC81C:
	subic. r5, r5, 0x1
	bne .L_803FC7F4
	blr
.endfn fn_803FC7E4

.fn fwide, global
	cmpwi r3, 0x0
	beq .L_803FC83C
	lwz r5, 0x4(r3)
	extrwi. r0, r5, 3, 7
	bne .L_803FC844
.L_803FC83C:
	li r3, 0x0
	blr
.L_803FC844:
	extrwi r0, r5, 2, 10
	cmpwi r0, 0x1
	beq .L_803FC8A0
	bge .L_803FC860
	cmpwi r0, 0x0
	bge .L_803FC86C
	b .L_803FC8A4
.L_803FC860:
	cmpwi r0, 0x3
	bge .L_803FC8A4
	b .L_803FC898
.L_803FC86C:
	cmpwi r4, 0x0
	ble .L_803FC884
	li r0, 0x2
	rlwimi r5, r0, 20, 10, 11
	stw r5, 0x4(r3)
	b .L_803FC8A4
.L_803FC884:
	bge .L_803FC8A4
	li r0, 0x1
	rlwimi r5, r0, 20, 10, 11
	stw r5, 0x4(r3)
	b .L_803FC8A4
.L_803FC898:
	li r4, 0x1
	b .L_803FC8A4
.L_803FC8A0:
	li r4, -0x1
.L_803FC8A4:
	mr r3, r4
	blr
.endfn fwide
