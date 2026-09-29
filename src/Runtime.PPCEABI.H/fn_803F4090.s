# Runtime.PPCEABI.H/fn_803F4090.s (auto_fn_803F4090_text)
#
# Reconstructed at assembly level from the Brawl target
# (build/RSBE01_02/asm/auto_fn_803F4090_text.s), following the fn_803F1B64.s precedent.

.include "macros.inc"

.section extab, "a"
.balign 4

.obj Letb, local
	.4byte 0x68080000
	.4byte 0x00000000
.endobj Letb

.section extabindex, "a"
.balign 4

.obj Leti, local
	.4byte fn_803F4090
	.4byte 0x0000051C
	.4byte Letb
.endobj Leti

.text
.balign 4

.fn fn_803F4090, global
	stwu r1, -0x40(r1)
	lhz r12, 0x1a(r4)
	stmw r19, 0xc(r1)
	lhz r19, 0x0(r4)
	lhz r20, 0x2(r4)
	lhz r21, 0x4(r4)
	lhz r22, 0x6(r4)
	lhz r23, 0x8(r4)
	lhz r24, 0xa(r4)
	lhz r25, 0xc(r4)
	lhz r26, 0xe(r4)
	lhz r27, 0x10(r4)
	lhz r28, 0x12(r4)
	lhz r29, 0x14(r4)
	lhz r30, 0x16(r4)
	lhz r31, 0x18(r4)
	lhz r11, 0x1c(r4)
	lhz r10, 0x1e(r4)
	lhz r9, 0x20(r4)
	lhz r8, 0x22(r4)
	lhz r7, 0x24(r4)
	lhz r6, 0x26(r4)
	lhz r0, 0x28(r4)
	sth r19, 0x0(r3)
	sth r20, 0x2(r3)
	sth r21, 0x4(r3)
	sth r22, 0x6(r3)
	sth r23, 0x8(r3)
	sth r24, 0xa(r3)
	sth r25, 0xc(r3)
	sth r26, 0xe(r3)
	sth r27, 0x10(r3)
	sth r28, 0x12(r3)
	sth r29, 0x14(r3)
	sth r30, 0x16(r3)
	sth r31, 0x18(r3)
	sth r12, 0x1a(r3)
	sth r11, 0x1c(r3)
	sth r10, 0x1e(r3)
	sth r9, 0x20(r3)
	sth r8, 0x22(r3)
	sth r7, 0x24(r3)
	sth r6, 0x26(r3)
	sth r0, 0x28(r3)
	lbz r0, 0x5(r5)
	cmpwi r0, 0x0
	beq .L_803F45A0
	lbz r8, 0x4(r3)
	lbz r0, 0x4(r5)
	cmpw r8, r0
	bge .L_803F4160
	mr r8, r0
.L_803F4160:
	lha r4, 0x2(r5)
	lha r0, 0x2(r3)
	subf r0, r4, r0
	add r8, r8, r0
	cmpwi r8, 0x24
	ble .L_803F417C
	li r8, 0x24
.L_803F417C:
	li r7, 0x0
	b .L_803F4198
.L_803F4184:
	lbz r6, 0x4(r3)
	add r4, r3, r6
	addi r6, r6, 0x1
	stb r7, 0x5(r4)
	stb r6, 0x4(r3)
.L_803F4198:
	lbz r4, 0x4(r3)
	cmpw r4, r8
	blt .L_803F4184
	lbz r7, 0x4(r5)
	addi r4, r3, 0x5
	add r6, r4, r8
	add r7, r7, r0
	cmpw r7, r8
	bge .L_803F41C0
	add r6, r4, r7
.L_803F41C0:
	subf r7, r4, r6
	addi r9, r5, 0x5
	subf r7, r0, r7
	add r10, r9, r7
	mr r11, r10
	b .L_803F42F8
.L_803F41D8:
	lbzu r8, -0x1(r6)
	lbzu r7, -0x1(r10)
	cmplw r8, r7
	bge .L_803F42E8
	subi r12, r6, 0x1
	b .L_803F41F4
.L_803F41F0:
	subi r12, r12, 0x1
.L_803F41F4:
	lbz r7, 0x0(r12)
	cmpwi r7, 0x0
	beq .L_803F41F0
	cmplw r12, r6
	subf r8, r12, r6
	beq .L_803F42E8
	srwi. r7, r8, 3
	mtctr r7
	beq .L_803F42C8
.L_803F4218:
	lbz r7, 0x0(r12)
	subi r7, r7, 0x1
	stb r7, 0x0(r12)
	lbz r7, 0x1(r12)
	addi r7, r7, 0xa
	clrlwi r7, r7, 24
	subi r7, r7, 0x1
	stb r7, 0x1(r12)
	lbz r7, 0x2(r12)
	addi r7, r7, 0xa
	clrlwi r7, r7, 24
	subi r7, r7, 0x1
	stb r7, 0x2(r12)
	lbz r7, 0x3(r12)
	addi r7, r7, 0xa
	clrlwi r7, r7, 24
	subi r7, r7, 0x1
	stb r7, 0x3(r12)
	lbz r7, 0x4(r12)
	addi r7, r7, 0xa
	clrlwi r7, r7, 24
	subi r7, r7, 0x1
	stb r7, 0x4(r12)
	lbz r7, 0x5(r12)
	addi r7, r7, 0xa
	clrlwi r7, r7, 24
	subi r7, r7, 0x1
	stb r7, 0x5(r12)
	lbz r7, 0x6(r12)
	addi r7, r7, 0xa
	clrlwi r7, r7, 24
	subi r7, r7, 0x1
	stb r7, 0x6(r12)
	lbz r7, 0x7(r12)
	addi r7, r7, 0xa
	clrlwi r7, r7, 24
	subi r7, r7, 0x1
	stb r7, 0x7(r12)
	lbz r7, 0x8(r12)
	addi r7, r7, 0xa
	stbu r7, 0x8(r12)
	bdnz .L_803F4218
	andi. r8, r8, 0x7
	beq .L_803F42E8
.L_803F42C8:
	mtctr r8
.L_803F42CC:
	lbz r7, 0x0(r12)
	subi r7, r7, 0x1
	stb r7, 0x0(r12)
	lbz r7, 0x1(r12)
	addi r7, r7, 0xa
	stbu r7, 0x1(r12)
	bdnz .L_803F42CC
.L_803F42E8:
	lbz r8, 0x0(r10)
	lbz r7, 0x0(r6)
	subf r7, r8, r7
	stb r7, 0x0(r6)
.L_803F42F8:
	cmplw r6, r4
	ble .L_803F4308
	cmplw r10, r9
	bgt .L_803F41D8
.L_803F4308:
	lbz r8, 0x4(r5)
	subf r9, r9, r11
	cmpw r9, r8
	bge .L_803F449C
	lbz r7, 0x0(r11)
	li r10, 0x0
	cmplwi r7, 0x5
	bge .L_803F4330
	li r10, 0x1
	b .L_803F437C
.L_803F4330:
	bne .L_803F437C
	add r5, r5, r8
	addi r6, r11, 0x1
	addi r7, r5, 0x5
	subf r5, r6, r7
	mtctr r5
	cmplw r6, r7
	bge .L_803F4364
.L_803F4350:
	lbz r5, 0x0(r6)
	cmpwi r5, 0x0
	bne .L_803F449C
	addi r6, r6, 0x1
	bdnz .L_803F4350
.L_803F4364:
	add r5, r4, r9
	add r6, r0, r5
	lbzu r0, -0x1(r6)
	clrlwi. r0, r0, 31
	beq .L_803F437C
	li r10, 0x1
.L_803F437C:
	cmpwi r10, 0x0
	beq .L_803F449C
	lbz r0, 0x0(r6)
	cmplwi r0, 0x1
	bge .L_803F4490
	subi r8, r6, 0x1
	b .L_803F439C
.L_803F4398:
	subi r8, r8, 0x1
.L_803F439C:
	lbz r0, 0x0(r8)
	cmpwi r0, 0x0
	beq .L_803F4398
	cmplw r8, r6
	subf r5, r8, r6
	beq .L_803F4490
	srwi. r0, r5, 3
	mtctr r0
	beq .L_803F4470
.L_803F43C0:
	lbz r7, 0x0(r8)
	subi r0, r7, 0x1
	stb r0, 0x0(r8)
	lbz r7, 0x1(r8)
	addi r0, r7, 0xa
	clrlwi r7, r0, 24
	subi r0, r7, 0x1
	stb r0, 0x1(r8)
	lbz r7, 0x2(r8)
	addi r0, r7, 0xa
	clrlwi r7, r0, 24
	subi r0, r7, 0x1
	stb r0, 0x2(r8)
	lbz r7, 0x3(r8)
	addi r0, r7, 0xa
	clrlwi r7, r0, 24
	subi r0, r7, 0x1
	stb r0, 0x3(r8)
	lbz r7, 0x4(r8)
	addi r0, r7, 0xa
	clrlwi r7, r0, 24
	subi r0, r7, 0x1
	stb r0, 0x4(r8)
	lbz r7, 0x5(r8)
	addi r0, r7, 0xa
	clrlwi r7, r0, 24
	subi r0, r7, 0x1
	stb r0, 0x5(r8)
	lbz r7, 0x6(r8)
	addi r0, r7, 0xa
	clrlwi r7, r0, 24
	subi r0, r7, 0x1
	stb r0, 0x6(r8)
	lbz r7, 0x7(r8)
	addi r0, r7, 0xa
	clrlwi r7, r0, 24
	subi r0, r7, 0x1
	stb r0, 0x7(r8)
	lbz r7, 0x8(r8)
	addi r0, r7, 0xa
	stbu r0, 0x8(r8)
	bdnz .L_803F43C0
	andi. r5, r5, 0x7
	beq .L_803F4490
.L_803F4470:
	mtctr r5
.L_803F4474:
	lbz r7, 0x0(r8)
	subi r0, r7, 0x1
	stb r0, 0x0(r8)
	lbz r7, 0x1(r8)
	addi r0, r7, 0xa
	stbu r0, 0x1(r8)
	bdnz .L_803F4474
.L_803F4490:
	lbz r5, 0x0(r6)
	subi r0, r5, 0x1
	stb r0, 0x0(r6)
.L_803F449C:
	mr r7, r4
	b .L_803F44A8
.L_803F44A4:
	addi r7, r7, 0x1
.L_803F44A8:
	lbz r0, 0x0(r7)
	cmpwi r0, 0x0
	beq .L_803F44A4
	cmplw r7, r4
	ble .L_803F4568
	lbz r0, 0x4(r3)
	subf r6, r4, r7
	lha r5, 0x2(r3)
	clrlwi r8, r6, 24
	add r6, r4, r0
	subf r0, r8, r5
	cmplw r7, r6
	sth r0, 0x2(r3)
	subf r5, r7, r6
	bge .L_803F455C
	srwi. r0, r5, 3
	mtctr r0
	beq .L_803F4544
.L_803F44F0:
	lbz r0, 0x0(r7)
	stb r0, 0x0(r4)
	lbz r0, 0x1(r7)
	stb r0, 0x1(r4)
	lbz r0, 0x2(r7)
	stb r0, 0x2(r4)
	lbz r0, 0x3(r7)
	stb r0, 0x3(r4)
	lbz r0, 0x4(r7)
	stb r0, 0x4(r4)
	lbz r0, 0x5(r7)
	stb r0, 0x5(r4)
	lbz r0, 0x6(r7)
	stb r0, 0x6(r4)
	lbz r0, 0x7(r7)
	addi r7, r7, 0x8
	stb r0, 0x7(r4)
	addi r4, r4, 0x8
	bdnz .L_803F44F0
	andi. r5, r5, 0x7
	beq .L_803F455C
.L_803F4544:
	mtctr r5
.L_803F4548:
	lbz r0, 0x0(r7)
	addi r7, r7, 0x1
	stb r0, 0x0(r4)
	addi r4, r4, 0x1
	bdnz .L_803F4548
.L_803F455C:
	lbz r0, 0x4(r3)
	subf r0, r8, r0
	stb r0, 0x4(r3)
.L_803F4568:
	lbz r0, 0x4(r3)
	addi r4, r3, 0x5
	add r5, r4, r0
	subf r0, r4, r5
	mtctr r0
	cmplw r5, r4
	ble .L_803F4594
.L_803F4584:
	lbzu r0, -0x1(r5)
	cmpwi r0, 0x0
	bne .L_803F4594
	bdnz .L_803F4584
.L_803F4594:
	subf r4, r4, r5
	addi r0, r4, 0x1
	stb r0, 0x4(r3)
.L_803F45A0:
	lmw r19, 0xc(r1)
	addi r1, r1, 0x40
	blr
.endfn fn_803F4090
