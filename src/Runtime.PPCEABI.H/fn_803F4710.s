# Runtime.PPCEABI.H/fn_803F4710.s (auto_fn_803F4710_text)
#
# Reconstructed at assembly level from the Brawl target
# (build/RSBE01_02/asm/auto_fn_803F4710_text.s), following the fn_803F1B64.s precedent.

.include "macros.inc"

.section extab, "a"
.balign 4

.obj Letb, local
	.4byte 0x10080000
	.4byte 0x00000000
.endobj Letb

.section extabindex, "a"
.balign 4

.obj Leti, local
	.4byte fn_803F4710
	.4byte 0x000001A0
	.4byte Letb
.endobj Leti

.text
.balign 4

.fn fn_803F4710, global
	stwu r1, -0x10(r1)
	mflr r0
	stw r0, 0x14(r1)
	stw r31, 0xc(r1)
	lha r31, 0x2(r3)
	stw r30, 0x8(r1)
	mr r30, r4
	mr r3, r30
	bl fn_803F45AC
	lbz r0, 0x5(r30)
	cmplwi r0, 0x9
	bgt .L_803F4898
	cmpwi r31, 0x24
	ble .L_803F474C
	li r31, 0x24
.L_803F474C:
	cmpwi r31, 0x0
	ble .L_803F4838
	lbz r0, 0x4(r30)
	cmpw r31, r0
	bge .L_803F4838
	addi r4, r30, 0x5
	lbzx r0, r4, r31
	add r3, r4, r31
	cmplwi r0, 0x5
	ble .L_803F477C
	li r4, 0x1
	b .L_803F47D8
.L_803F477C:
	bge .L_803F4788
	li r4, -0x1
	b .L_803F47D8
.L_803F4788:
	lbz r0, 0x4(r30)
	addi r3, r3, 0x1
	add r4, r4, r0
	subf r0, r3, r4
	mtctr r0
	cmplw r3, r4
	bge .L_803F47C0
.L_803F47A4:
	lbz r0, 0x0(r3)
	cmpwi r0, 0x0
	beq .L_803F47B8
	li r4, 0x1
	b .L_803F47D8
.L_803F47B8:
	addi r3, r3, 0x1
	bdnz .L_803F47A4
.L_803F47C0:
	add r3, r31, r30
	li r4, -0x1
	lbz r0, 0x4(r3)
	clrlwi. r0, r0, 31
	beq .L_803F47D8
	li r4, 0x1
.L_803F47D8:
	cmpwi r4, 0x0
	stb r31, 0x4(r30)
	blt .L_803F4838
	addi r4, r30, 0x5
	li r0, 0x0
	add r5, r4, r31
	subi r5, r5, 0x1
.L_803F47F4:
	lbz r3, 0x0(r5)
	cmplwi r3, 0x9
	bge .L_803F480C
	addi r0, r3, 0x1
	stb r0, 0x0(r5)
	b .L_803F4838
.L_803F480C:
	cmplw r5, r4
	bne .L_803F482C
	li r0, 0x1
	stb r0, 0x0(r5)
	lha r3, 0x2(r30)
	addi r0, r3, 0x1
	sth r0, 0x2(r30)
	b .L_803F4838
.L_803F482C:
	stb r0, 0x0(r5)
	subi r5, r5, 0x1
	b .L_803F47F4
.L_803F4838:
	li r5, 0x0
	b .L_803F4854
.L_803F4840:
	lbz r4, 0x4(r30)
	add r3, r30, r4
	addi r0, r4, 0x1
	stb r5, 0x5(r3)
	stb r0, 0x4(r30)
.L_803F4854:
	lbz r3, 0x4(r30)
	cmpw r3, r31
	blt .L_803F4840
	lha r0, 0x2(r30)
	subi r3, r3, 0x1
	li r5, 0x0
	subf r0, r3, r0
	sth r0, 0x2(r30)
	b .L_803F488C
.L_803F4878:
	add r4, r30, r5
	addi r5, r5, 0x1
	lbz r3, 0x5(r4)
	addi r0, r3, 0x30
	stb r0, 0x5(r4)
.L_803F488C:
	lbz r0, 0x4(r30)
	cmpw r5, r0
	blt .L_803F4878
.L_803F4898:
	lwz r0, 0x14(r1)
	lwz r31, 0xc(r1)
	lwz r30, 0x8(r1)
	mtlr r0
	addi r1, r1, 0x10
	blr
.endfn fn_803F4710
