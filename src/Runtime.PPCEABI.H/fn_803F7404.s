.include "macros.inc"

.text
.balign 4

.obj fn_803F7404, local
.fn fn_803F7404, global
	cmpwi r4, 0x0
	bge .L_803F7428
.L_803F740C:
	li r5, 0x0
	li r4, 0x1
	li r0, 0x30
	sth r5, 0x2(r3)
	stb r4, 0x4(r3)
	stb r0, 0x5(r3)
	blr
.L_803F7428:
	lbz r7, 0x4(r3)
	cmpw r4, r7
	bgelr
	add r6, r3, r4
	lbz r5, 0x5(r6)
	addi r8, r6, 0x5
	subi r0, r5, 0x30
	extsb r6, r0
	cmpwi r6, 0x5
	bne .L_803F748C
	add r5, r3, r7
	addi r5, r5, 0x5
.L_803F7458:
	subi r5, r5, 0x1
	cmplw r5, r8
	ble .L_803F7470
	lbz r0, 0x0(r5)
	cmpwi r0, 0x30
	beq .L_803F7458
.L_803F7470:
	cmplw r5, r8
	bne .L_803F7484
	lbz r0, -0x1(r8)
	clrlwi r5, r0, 31
	b .L_803F74A0
.L_803F7484:
	li r5, 0x1
	b .L_803F74A0
.L_803F748C:
	xori r0, r6, 0x5
	srawi r5, r0, 1
	and r0, r0, r6
	subf r0, r0, r5
	srwi r5, r0, 31
.L_803F74A0:
	mtctr r4
	cmpwi r4, 0x0
	beq .L_803F74F4
.L_803F74AC:
	lbzu r0, -0x1(r8)
	add r5, r0, r5
	subi r0, r5, 0x30
	extsb r6, r0
	xori r0, r6, 0x9
	srawi r5, r0, 1
	and r0, r0, r6
	subf r0, r0, r5
	srwi. r5, r0, 31
	bne .L_803F74DC
	cmpwi r6, 0x0
	bne .L_803F74E4
.L_803F74DC:
	subi r4, r4, 0x1
	b .L_803F74F0
.L_803F74E4:
	addi r0, r6, 0x30
	stb r0, 0x0(r8)
	b .L_803F74F4
.L_803F74F0:
	bdnz .L_803F74AC
.L_803F74F4:
	cmpwi r5, 0x0
	beq .L_803F751C
	lha r5, 0x2(r3)
	li r4, 0x1
	li r0, 0x31
	stb r4, 0x4(r3)
	addi r4, r5, 0x1
	sth r4, 0x2(r3)
	stb r0, 0x5(r3)
	blr
.L_803F751C:
	cmpwi r4, 0x0
	beq .L_803F740C
	stb r4, 0x4(r3)
	blr
.endfn fn_803F7404
.endobj fn_803F7404
