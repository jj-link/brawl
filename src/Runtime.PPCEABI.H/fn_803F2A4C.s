# Runtime.PPCEABI.H/fn_803F2A4C.s (auto_fn_803F2A4C_text)
#
# Reconstructed at assembly level from the Brawl target
# (build/RSBE01_02/asm/auto_fn_803F2A4C_text.s), following the fn_803F1B64.s precedent.
# References jumptable_80493E18 (external data, resolved at link).

.include "macros.inc"

.section extab, "a"
.balign 4

.obj Letb, local
	.4byte 0x30080000
	.4byte 0x0000026C
	.4byte 0x000F0010
	.4byte 0x00000000
	.4byte 0x8E000000
.endobj Letb

.section extabindex, "a"
.balign 4

.obj Leti, local
	.4byte fn_803F2A4C
	.4byte 0x00000400
	.4byte Letb
.endobj Leti

.text
.balign 4

.fn fn_803F2A4C, global
	stwu r1, -0x70(r1)
	mflr r0
	stw r0, 0x74(r1)
	addi r4, r1, 0x10
	stmw r26, 0x58(r1)
	mr r30, r3
	lwz r3, 0x290(r3)
	bl fn_803F1B64
	lwz r0, 0x10(r1)
	cmpwi r0, 0x0
	bne .L_803F2A7C
	bl fn_803F07D4
.L_803F2A7C:
	lwz r3, 0x10(r1)
	lhz r0, 0x0(r3)
	extrwi. r0, r0, 1, 27
	beq .L_803F2A94
	lwz r3, 0x27c(r30)
	b .L_803F2A98
.L_803F2A94:
	lwz r3, 0x284(r30)
.L_803F2A98:
	lwz r0, 0x294(r30)
	stw r3, 0x288(r30)
	cmpwi r0, 0x0
	bne .L_803F2B84
	lwz r5, 0x18(r1)
	lwz r7, 0x10(r1)
	lwz r6, 0x14(r1)
	cmpwi r5, 0x0
	lwz r4, 0x1c(r1)
	lwz r3, 0x20(r1)
	lwz r0, 0x24(r1)
	stw r7, 0x28(r1)
	stw r6, 0x2c(r1)
	stw r5, 0x30(r1)
	stw r4, 0x34(r1)
	stw r3, 0x38(r1)
	stw r0, 0x3c(r1)
	lwz r0, 0x284(r30)
	stw r0, 0x40(r1)
	lwz r0, 0x288(r30)
	stw r0, 0x44(r1)
	lwz r0, 0x27c(r30)
	stw r0, 0x48(r1)
	bne .L_803F2B00
	li r3, 0x0
	b .L_803F2B08
.L_803F2B00:
	lbz r0, 0x0(r5)
	clrlwi r3, r0, 25
.L_803F2B08:
	clrlwi r0, r3, 24
	cmpwi r0, 0xd
	beq .L_803F2B54
	bge .L_803F2B30
	cmpwi r0, 0x1
	beq .L_803F2B40
	bge .L_803F2B48
	cmpwi r0, 0x0
	bge .L_803F2B48
	b .L_803F2B40
.L_803F2B30:
	cmpwi r0, 0x11
	bge .L_803F2B40
	cmpwi r0, 0xf
	bge .L_803F2B48
.L_803F2B40:
	bl fn_803F07D4
	b .L_803F2B54
.L_803F2B48:
	addi r3, r1, 0x28
	bl fn_803F1D14
	b .L_803F2B08
.L_803F2B54:
	lwz r3, 0x30(r1)
	li r0, 0x0
	lwz r4, 0x44(r1)
	lha r3, 0x2(r3)
	add r4, r4, r3
	lwz r3, 0x4(r4)
	stw r3, 0x294(r30)
	lwz r3, 0x0(r4)
	stw r3, 0x298(r30)
	stw r0, 0x29c(r30)
	stw r4, 0x2a0(r30)
	b .L_803F2B8C
.L_803F2B84:
	li r0, 0x0
	stw r0, 0x2a0(r30)
.L_803F2B8C:
	lwz r5, 0x18(r1)
	lwz r7, 0x10(r1)
	lwz r6, 0x14(r1)
	cmpwi r5, 0x0
	lwz r4, 0x1c(r1)
	lwz r3, 0x20(r1)
	lwz r0, 0x24(r1)
	stw r7, 0x28(r1)
	stw r6, 0x2c(r1)
	stw r5, 0x30(r1)
	stw r4, 0x34(r1)
	stw r3, 0x38(r1)
	stw r0, 0x3c(r1)
	lwz r0, 0x284(r30)
	stw r0, 0x40(r1)
	lwz r0, 0x288(r30)
	stw r0, 0x44(r1)
	lwz r0, 0x27c(r30)
	stw r0, 0x48(r1)
	bne .L_803F2BE4
	li r26, 0x0
	b .L_803F2BEC
.L_803F2BE4:
	lbz r0, 0x0(r5)
	clrlwi r26, r0, 25
.L_803F2BEC:
	lis r31, jumptable_80493E18@ha
.L_803F2BF0:
	clrlwi r0, r26, 24
	cmplwi r0, 0x10
	bgt .L_803F2CF8
	addi r3, r31, jumptable_80493E18@l
	slwi r0, r0, 2
	lwzx r3, r3, r0
	mtctr r3
	bctr
	lwz r4, 0x30(r1)
	addi r5, r1, 0xc
	lwz r3, 0x294(r30)
	lwz r4, 0x4(r4)
	bl fn_803F07E0
	extsb. r0, r3
	bne .L_803F2D10
	b .L_803F2D00
	lwz r4, 0x30(r1)
	addi r5, r1, 0xc
	lwz r3, 0x294(r30)
	lwz r4, 0x4(r4)
	bl fn_803F07E0
	extsb. r0, r3
	bne .L_803F2D10
	b .L_803F2D00
	lwz r28, 0x30(r1)
	li r27, 0x0
	lwz r29, 0x294(r30)
	mr r26, r28
	b .L_803F2C8C
.L_803F2C64:
	lwz r4, 0xc(r26)
	mr r3, r29
	addi r5, r1, 0x8
	bl fn_803F07E0
	extsb. r0, r3
	beq .L_803F2C84
	li r0, 0x1
	b .L_803F2C9C
.L_803F2C84:
	addi r26, r26, 0x4
	addi r27, r27, 0x1
.L_803F2C8C:
	lhz r0, 0x2(r28)
	cmpw r27, r0
	blt .L_803F2C64
	li r0, 0x0
.L_803F2C9C:
	cmpwi r0, 0x0
	bne .L_803F2D00
	lwz r27, 0x30(r1)
	mr r3, r30
	addi r4, r1, 0x10
	mr r5, r27
	bl fn_803F243C
	lwz r5, 0x288(r30)
	mr r3, r30
	lwz r4, 0x8(r27)
	lwz r0, 0x298(r30)
	stwux r0, r4, r5
	lwz r0, 0x294(r30)
	stw r0, 0x4(r4)
	lwz r0, 0x29c(r30)
	stw r0, 0x8(r4)
	stw r27, 0x14(r4)
	lwz r5, 0x14(r1)
	lwz r0, 0x4(r27)
	lwz r4, 0x24(r1)
	add r5, r5, r0
	bl fn_803F2948
	b .L_803F2D00
.L_803F2CF8:
	bl fn_803F07D4
	b .L_803F2D10
.L_803F2D00:
	addi r3, r1, 0x28
	bl fn_803F1D14
	mr r26, r3
	b .L_803F2BF0
.L_803F2D10:
	clrlwi r0, r26, 24
	cmplwi r0, 0x10
	bne .L_803F2DAC
	lwz r31, 0x30(r1)
	mr r3, r30
	addi r4, r1, 0x10
	mr r5, r31
	bl fn_803F243C
	lwz r4, 0x288(r30)
	lwz r3, 0xc(r31)
	lwz r0, 0x298(r30)
	stwux r0, r4, r3
	lwz r0, 0x294(r30)
	stw r0, 0x4(r4)
	lwz r0, 0x29c(r30)
	stw r0, 0x8(r4)
	lwz r3, 0x294(r30)
	lbz r0, 0x0(r3)
	cmpwi r0, 0x2a
	bne .L_803F2D80
	addi r0, r4, 0x10
	stw r0, 0xc(r4)
	lwz r3, 0x298(r30)
	lwz r0, 0xc(r1)
	lwz r3, 0x0(r3)
	add r0, r3, r0
	stw r0, 0x10(r4)
	b .L_803F2D90
.L_803F2D80:
	lwz r3, 0x298(r30)
	lwz r0, 0xc(r1)
	add r0, r3, r0
	stw r0, 0xc(r4)
.L_803F2D90:
	lwz r5, 0x14(r1)
	mr r3, r30
	lwz r0, 0x8(r31)
	lwz r4, 0x24(r1)
	add r5, r5, r0
	bl fn_803F2948
	b .L_803F2E38
.L_803F2DAC:
	lwz r31, 0x30(r1)
	mr r3, r30
	addi r4, r1, 0x10
	mr r5, r31
	bl fn_803F243C
	lwz r4, 0x288(r30)
	lha r3, 0xa(r31)
	lwz r0, 0x298(r30)
	stwux r0, r4, r3
	lwz r0, 0x294(r30)
	stw r0, 0x4(r4)
	lwz r0, 0x29c(r30)
	stw r0, 0x8(r4)
	lwz r3, 0x294(r30)
	lbz r0, 0x0(r3)
	cmpwi r0, 0x2a
	bne .L_803F2E10
	addi r0, r4, 0x10
	stw r0, 0xc(r4)
	lwz r3, 0x298(r30)
	lwz r0, 0xc(r1)
	lwz r3, 0x0(r3)
	add r0, r3, r0
	stw r0, 0x10(r4)
	b .L_803F2E20
.L_803F2E10:
	lwz r3, 0x298(r30)
	lwz r0, 0xc(r1)
	add r0, r3, r0
	stw r0, 0xc(r4)
.L_803F2E20:
	lwz r5, 0x14(r1)
	mr r3, r30
	lhz r0, 0x8(r31)
	lwz r4, 0x24(r1)
	add r5, r5, r0
	bl fn_803F2948
.L_803F2E38:
	lmw r26, 0x58(r1)
	lwz r0, 0x74(r1)
	mtlr r0
	addi r1, r1, 0x70
	blr
