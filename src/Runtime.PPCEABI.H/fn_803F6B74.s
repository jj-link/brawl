.include "macros.inc"
.text
.balign 4

.fn long2str_803F6B74, global
	li r8, 0x0
	cmpwi r3, 0x0
	stb r8, -0x1(r4)
	subi r6, r4, 0x1
	li r7, 0x0
	bne .L_803F6BB8
	lwz r0, 0xc(r5)
	cmpwi r0, 0x0
	bne .L_803F6BB8
	lbz r0, 0x3(r5)
	cmpwi r0, 0x0
	beq .L_803F6BB0
	lbz r0, 0x5(r5)
	cmplwi r0, 0x6f
	beq .L_803F6BB8
.L_803F6BB0:
	mr r3, r6
	blr
.L_803F6BB8:
	lbz r9, 0x5(r5)
	subi r10, r9, 0x58
	cmplwi r10, 0x20
	bgt .L_803F6C30
	lis r9, jumptable_80494424@ha
	slwi r10, r10, 2
	addi r9, r9, jumptable_80494424@l
	lwzx r9, r9, r10
	mtctr r9
	bctr
	cmpwi r3, 0x0
	li r0, 0xa
	bge .L_803F6C30
	addis r8, r3, 0x8000
	cmplwi r8, 0x0
	beq .L_803F6BFC
	neg r3, r3
.L_803F6BFC:
	li r8, 0x1
	b .L_803F6C30
	li r9, 0x0
	li r0, 0x8
	stb r9, 0x1(r5)
	b .L_803F6C30
	li r9, 0x0
	li r0, 0xa
	stb r9, 0x1(r5)
	b .L_803F6C30
	li r9, 0x0
	li r0, 0x10
	stb r9, 0x1(r5)
.L_803F6C30:
	divwu r9, r3, r0
	mullw r9, r9, r0
	subf r11, r9, r3
	divwu r3, r3, r0
	cmpwi r11, 0xa
	bge .L_803F6C50
	addi r11, r11, 0x30
	b .L_803F6C68
.L_803F6C50:
	lbz r9, 0x5(r5)
	addi r10, r11, 0x37
	cmplwi r9, 0x78
	bne .L_803F6C64
	addi r10, r11, 0x57
.L_803F6C64:
	mr r11, r10
.L_803F6C68:
	cmpwi r3, 0x0
	stb r11, -0x1(r6)
	subi r6, r6, 0x1
	addi r7, r7, 0x1
	bne .L_803F6C30
	cmplwi r0, 0x8
	bne .L_803F6CA8
	lbz r3, 0x3(r5)
	cmpwi r3, 0x0
	beq .L_803F6CA8
	lbz r3, 0x0(r6)
	cmpwi r3, 0x30
	beq .L_803F6CA8
	li r3, 0x30
	addi r7, r7, 0x1
	stbu r3, -0x1(r6)
.L_803F6CA8:
	lbz r3, 0x0(r5)
	cmplwi r3, 0x2
	bne .L_803F6CFC
	lwz r3, 0x8(r5)
	cmpwi r8, 0x0
	stw r3, 0xc(r5)
	bne .L_803F6CD0
	lbz r3, 0x1(r5)
	cmpwi r3, 0x0
	beq .L_803F6CDC
.L_803F6CD0:
	lwz r3, 0xc(r5)
	subi r3, r3, 0x1
	stw r3, 0xc(r5)
.L_803F6CDC:
	cmplwi r0, 0x10
	bne .L_803F6CFC
	lbz r3, 0x3(r5)
	cmpwi r3, 0x0
	beq .L_803F6CFC
	lwz r3, 0xc(r5)
	subi r3, r3, 0x2
	stw r3, 0xc(r5)
.L_803F6CFC:
	lwz r9, 0xc(r5)
	subf r3, r6, r4
	add r3, r9, r3
	cmpwi r3, 0x1fd
	ble .L_803F6D18
	li r3, 0x0
	blr
.L_803F6D18:
	li r4, 0x30
	b .L_803F6D28
.L_803F6D20:
	stbu r4, -0x1(r6)
	addi r7, r7, 0x1
.L_803F6D28:
	lwz r3, 0xc(r5)
	cmpw r7, r3
	blt .L_803F6D20
	cmplwi r0, 0x10
	bne .L_803F6D58
	lbz r0, 0x3(r5)
	cmpwi r0, 0x0
	beq .L_803F6D58
	lbz r3, 0x5(r5)
	li r0, 0x30
	stb r3, -0x1(r6)
	stbu r0, -0x2(r6)
.L_803F6D58:
	cmpwi r8, 0x0
	beq .L_803F6D6C
	li r0, 0x2d
	stbu r0, -0x1(r6)
	b .L_803F6D94
.L_803F6D6C:
	lbz r0, 0x1(r5)
	cmplwi r0, 0x1
	bne .L_803F6D84
	li r0, 0x2b
	stbu r0, -0x1(r6)
	b .L_803F6D94
.L_803F6D84:
	cmplwi r0, 0x2
	bne .L_803F6D94
	li r0, 0x20
	stbu r0, -0x1(r6)
.L_803F6D94:
	mr r3, r6
	blr
.endfn long2str_803F6B74
