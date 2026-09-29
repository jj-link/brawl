.include "macros.inc"

.text
.balign 4

.fn fn_8040163C, global
	stwu r1, -0x30(r1)
	mflr r0
	lis r4, gTRKBigEndian@ha
	stw r0, 0x34(r1)
	stw r31, 0x2c(r1)
	mr r31, r3
	stw r30, 0x28(r1)
	stw r29, 0x24(r1)
	lwz r0, gTRKBigEndian@l(r4)
	stw r5, 0x8(r1)
	cmpwi r0, 0x0
	stw r6, 0xc(r1)
	beq .L_80401678
	addi r4, r1, 0x8
	b .L_804016BC
.L_80401678:
	lbz r10, 0xf(r1)
	addi r4, r1, 0x10
	lbz r9, 0xe(r1)
	lbz r8, 0xd(r1)
	lbz r7, 0xc(r1)
	lbz r6, 0xb(r1)
	lbz r5, 0xa(r1)
	lbz r3, 0x9(r1)
	lbz r0, 0x8(r1)
	stb r10, 0x10(r1)
	stb r9, 0x11(r1)
	stb r8, 0x12(r1)
	stb r7, 0x13(r1)
	stb r6, 0x14(r1)
	stb r5, 0x15(r1)
	stb r3, 0x16(r1)
	stb r0, 0x17(r1)
.L_804016BC:
	lwz r3, 0xc(r31)
	li r29, 0x8
	li r30, 0x0
	subfic r0, r3, 0x880
	cmplwi r0, 0x8
	bge .L_804016DC
	li r30, 0x301
	mr r29, r0
.L_804016DC:
	cmplwi r29, 0x1
	bne .L_804016F4
	lbz r0, 0x0(r4)
	add r3, r31, r3
	stb r0, 0x10(r3)
	b .L_80401704
.L_804016F4:
	addi r3, r3, 0x10
	mr r5, r29
	add r3, r31, r3
	bl fn_8000449C
.L_80401704:
	lwz r0, 0xc(r31)
	mr r3, r30
	add r0, r0, r29
	stw r0, 0xc(r31)
	lwz r0, 0xc(r31)
	stw r0, 0x8(r31)
	lwz r31, 0x2c(r1)
	lwz r30, 0x28(r1)
	lwz r29, 0x24(r1)
	lwz r0, 0x34(r1)
	mtlr r0
	addi r1, r1, 0x30
	blr
.endfn fn_8040163C

.fn fn_80401738, global
	stwu r1, -0x20(r1)
	mflr r0
	stw r0, 0x24(r1)
	stw r31, 0x1c(r1)
	li r31, 0x0
	stw r30, 0x18(r1)
	mr. r30, r5
	stw r29, 0x14(r1)
	mr r29, r3
	mr r3, r4
	bne .L_8040176C
	li r3, 0x0
	b .L_804017A8
.L_8040176C:
	lwz r4, 0xc(r29)
	lwz r0, 0x8(r29)
	subf r0, r4, r0
	cmplw r30, r0
	ble .L_80401788
	li r31, 0x302
	mr r30, r0
.L_80401788:
	addi r4, r4, 0x10
	mr r5, r30
	add r4, r29, r4
	bl fn_8000449C
	lwz r0, 0xc(r29)
	mr r3, r31
	add r0, r0, r30
	stw r0, 0xc(r29)
.L_804017A8:
	lwz r0, 0x24(r1)
	lwz r31, 0x1c(r1)
	lwz r30, 0x18(r1)
	lwz r29, 0x14(r1)
	mtlr r0
	addi r1, r1, 0x20
	blr
.endfn fn_80401738
