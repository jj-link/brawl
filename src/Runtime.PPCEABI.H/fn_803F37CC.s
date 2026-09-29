# Runtime.PPCEABI.H/fn_803F37CC.s (auto_fn_803F37CC_text)
#
# Reconstructed at assembly level from the Brawl target
# (build/RSBE01_02/asm/auto_fn_803F37CC_text.s), following the fn_803F1B64.s precedent.

.include "macros.inc"

.section extab, "a"
.balign 4

.obj Letb, local
	.4byte 0x18080000
	.4byte 0x00000000
.endobj Letb

.section extabindex, "a"
.balign 4

.obj Leti, local
	.4byte fn_803F37CC
	.4byte 0x00000288
	.4byte Letb
.endobj Leti

.text
.balign 4

.fn fn_803F37CC, global
	stwu r1, -0x60(r1)
	lis r6, 0xcccd
	lbz r8, 0x4(r4)
	li r11, 0x0
	stw r31, 0x5c(r1)
	addi r0, r1, 0x8
	lbz r7, 0x4(r5)
	subi r9, r6, 0x3333
	stw r30, 0x58(r1)
	add r12, r8, r7
	stw r29, 0x54(r1)
	subi r12, r12, 0x1
	add r6, r0, r12
	addi r6, r6, 0x1
	stb r11, 0x0(r3)
	mr r0, r6
	b .L_803F393C
.L_803F3810:
	lbz r7, 0x4(r5)
	subi r31, r7, 0x1
	subf r7, r31, r12
	subic. r30, r7, 0x1
	bge .L_803F382C
	li r30, 0x0
	subi r31, r12, 0x1
.L_803F382C:
	lbz r7, 0x4(r4)
	add r8, r5, r31
	addi r31, r31, 0x1
	add r10, r4, r30
	subf r7, r30, r7
	addi r29, r8, 0x5
	cmpw r31, r7
	addi r30, r10, 0x5
	ble .L_803F3854
	mr r31, r7
.L_803F3854:
	cmpwi r31, 0x0
	ble .L_803F391C
	srwi. r7, r31, 3
	mtctr r7
	beq .L_803F38FC
.L_803F3868:
	lbz r10, 0x0(r30)
	lbz r8, 0x0(r29)
	mullw r7, r10, r8
	lbz r10, 0x1(r30)
	lbz r8, -0x1(r29)
	add r11, r11, r7
	mullw r7, r10, r8
	lbz r10, 0x2(r30)
	lbz r8, -0x2(r29)
	add r11, r11, r7
	mullw r7, r10, r8
	lbz r10, 0x3(r30)
	lbz r8, -0x3(r29)
	add r11, r11, r7
	mullw r7, r10, r8
	lbz r10, 0x4(r30)
	lbz r8, -0x4(r29)
	add r11, r11, r7
	mullw r7, r10, r8
	lbz r10, 0x5(r30)
	lbz r8, -0x5(r29)
	add r11, r11, r7
	mullw r7, r10, r8
	lbz r10, 0x6(r30)
	lbz r8, -0x6(r29)
	add r11, r11, r7
	mullw r7, r10, r8
	lbz r10, 0x7(r30)
	lbz r8, -0x7(r29)
	addi r30, r30, 0x8
	subi r29, r29, 0x8
	add r11, r11, r7
	mullw r7, r10, r8
	add r11, r11, r7
	bdnz .L_803F3868
	andi. r31, r31, 0x7
	beq .L_803F391C
.L_803F38FC:
	mtctr r31
.L_803F3900:
	lbz r10, 0x0(r30)
	addi r30, r30, 0x1
	lbz r8, 0x0(r29)
	subi r29, r29, 0x1
	mullw r7, r10, r8
	add r11, r11, r7
	bdnz .L_803F3900
.L_803F391C:
	mulhwu r8, r9, r11
	subi r12, r12, 0x1
	mr r7, r8
	srwi r8, r8, 3
	mulli r8, r8, 0xa
	subf r8, r8, r11
	srwi r11, r7, 3
	stbu r8, -0x1(r6)
.L_803F393C:
	cmpwi r12, 0x0
	bgt .L_803F3810
	lha r7, 0x2(r4)
	cmpwi r11, 0x0
	lha r4, 0x2(r5)
	add r4, r7, r4
	sth r4, 0x2(r3)
	beq .L_803F396C
	stbu r11, -0x1(r6)
	lha r4, 0x2(r3)
	addi r4, r4, 0x1
	sth r4, 0x2(r3)
.L_803F396C:
	li r7, 0x0
	b .L_803F3988
.L_803F3974:
	lbz r5, 0x0(r6)
	add r4, r3, r7
	addi r7, r7, 0x1
	addi r6, r6, 0x1
	stb r5, 0x5(r4)
.L_803F3988:
	cmpwi r7, 0x24
	bge .L_803F3998
	cmplw r6, r0
	blt .L_803F3974
.L_803F3998:
	cmplw r6, r0
	stb r7, 0x4(r3)
	bge .L_803F3A40
	lbz r4, 0x0(r6)
	cmplwi r4, 0x5
	blt .L_803F3A40
	bne .L_803F39E8
	addi r5, r6, 0x1
	subf r4, r5, r0
	mtctr r4
	cmplw r5, r0
	bge .L_803F39DC
.L_803F39C8:
	lbz r0, 0x0(r5)
	cmpwi r0, 0x0
	bne .L_803F39E8
	addi r5, r5, 0x1
	bdnz .L_803F39C8
.L_803F39DC:
	lbz r0, -0x1(r6)
	clrlwi. r0, r0, 31
	beq .L_803F3A40
.L_803F39E8:
	lbz r4, 0x4(r3)
	addi r6, r3, 0x5
	li r0, 0x0
	add r5, r6, r4
	subi r5, r5, 0x1
.L_803F39FC:
	lbz r4, 0x0(r5)
	cmplwi r4, 0x9
	bge .L_803F3A14
	addi r0, r4, 0x1
	stb r0, 0x0(r5)
	b .L_803F3A40
.L_803F3A14:
	cmplw r5, r6
	bne .L_803F3A34
	li r0, 0x1
	stb r0, 0x0(r5)
	lha r4, 0x2(r3)
	addi r0, r4, 0x1
	sth r0, 0x2(r3)
	b .L_803F3A40
.L_803F3A34:
	stb r0, 0x0(r5)
	subi r5, r5, 0x1
	b .L_803F39FC
.L_803F3A40:
	lwz r31, 0x5c(r1)
	lwz r30, 0x58(r1)
	lwz r29, 0x54(r1)
	addi r1, r1, 0x60
	blr
.endfn fn_803F37CC
