# Runtime.PPCEABI.H/fn_80401968.s (auto_03_80401898_text)

.include "macros.inc"

.text
.balign 4

.fn fn_80401968, global
	stwu r1, -0x20(r1)
	mflr r0
	stw r0, 0x24(r1)
	li r0, 0x0
	stmw r27, 0xc(r1)
	mr r28, r4
	mr r27, r3
	li r30, 0x300
	li r29, 0x0
	stw r0, 0x0(r4)
	b .L_804019FC
.L_80401994:
	cmpwi r29, 0x0
	li r31, 0x0
	blt .L_804019B8
	cmpwi r29, 0x3
	bge .L_804019B8
	mulli r4, r29, 0x890
	lis r3, lbl_80599F78@ha
	addi r0, r3, lbl_80599F78@l
	add r31, r0, r4
.L_804019B8:
	mr r3, r31
	bl fn_804035BC
	lwz r0, 0x4(r31)
	cmpwi r0, 0x0
	bne .L_804019F0
	li r3, 0x0
	li r0, 0x1
	stw r3, 0x8(r31)
	li r30, 0x0
	stw r3, 0xc(r31)
	stw r0, 0x4(r31)
	stw r31, 0x0(r28)
	stw r29, 0x0(r27)
	li r29, 0x3
.L_804019F0:
	mr r3, r31
	bl fn_804035B4
	addi r29, r29, 0x1
.L_804019FC:
	cmpwi r29, 0x3
	blt .L_80401994
	cmpwi r30, 0x300
	bne .L_80401A18
	lis r3, lbl_80420488@ha
	addi r3, r3, lbl_80420488@l
	bl fn_80401C54
.L_80401A18:
	mr r3, r30
	lmw r27, 0xc(r1)
	lwz r0, 0x24(r1)
	mtlr r0
	addi r1, r1, 0x20
	blr
.endfn fn_80401968

# .text:0x198 | 0x80401A30 | size: 0x74
.fn TRKInitializeMessageBuffers, global
	stwu r1, -0x20(r1)
	mflr r0
	lis r3, lbl_80599F78@ha
	stw r0, 0x24(r1)
	stw r31, 0x1c(r1)
	li r31, 0x0
	stw r30, 0x18(r1)
	addi r30, r3, lbl_80599F78@l
	stw r29, 0x14(r1)
	li r29, 0x0
.L_80401A58:
	mr r3, r30
	bl fn_804035C4
	mr r3, r30
	bl fn_804035BC
	stw r31, 0x4(r30)
	mr r3, r30
	bl fn_804035B4
	addi r29, r29, 0x1
	addi r30, r30, 0x890
	cmpwi r29, 0x3
	blt .L_80401A58
	lwz r0, 0x24(r1)
	li r3, 0x0
	lwz r31, 0x1c(r1)
	lwz r30, 0x18(r1)
	lwz r29, 0x14(r1)
	mtlr r0
	addi r1, r1, 0x20
	blr
.endfn TRKInitializeMessageBuffers

# .text:0x20C | 0x80401AA4 | size: 0x8
.fn fn_80401AA4, global
	li r3, 0x0
	blr
.endfn fn_80401AA4

# .text:0x214 | 0x80401AAC | size: 0x24
.fn TRKInitializeSerialHandler, global
	lis r3, lbl_8059B928@ha
	li r5, -0x1
	addi r4, r3, lbl_8059B928@l
	li r0, 0x0
	stw r5, 0x0(r4)
	li r3, 0x0
	stw r0, 0x8(r4)
	stw r0, 0xc(r4)
	blr
.endfn TRKInitializeSerialHandler
