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
	.4byte dtor_803F0B20
	.4byte 0x000000BC
	.4byte Letb
.endobj Leti

.text
.balign 4

.fn dtor_803F0B20, global
	stwu r1, -0x20(r1)
	mflr r0
	cmpwi r3, 0x0
	stw r0, 0x24(r1)
	stw r31, 0x1c(r1)
	stw r30, 0x18(r1)
	mr r30, r4
	stw r29, 0x14(r1)
	mr r29, r3
	beq .L_803F0BBC
	lwz r4, 0x10(r3)
	lwz r0, 0x8(r3)
	cmplw r4, r0
	bge .L_803F0BAC
	lwz r0, 0xc(r3)
	cmpwi r0, 0x0
	beq .L_803F0BAC
	lwz r0, 0x4(r3)
	lwz r3, 0x0(r3)
	mullw r0, r0, r4
	add r31, r3, r0
	b .L_803F0BA0
.L_803F0B78:
	lwz r0, 0x4(r29)
	li r4, -0x1
	lwz r12, 0xc(r29)
	subf r31, r0, r31
	mr r3, r31
	mtctr r12
	bctrl
	lwz r3, 0x10(r29)
	subi r0, r3, 0x1
	stw r0, 0x10(r29)
.L_803F0BA0:
	lwz r0, 0x10(r29)
	cmpwi r0, 0x0
	bne .L_803F0B78
.L_803F0BAC:
	cmpwi r30, 0x0
	ble .L_803F0BBC
	mr r3, r29
	bl __dl__FPv
.L_803F0BBC:
	lwz r31, 0x1c(r1)
	mr r3, r29
	lwz r30, 0x18(r1)
	lwz r29, 0x14(r1)
	lwz r0, 0x24(r1)
	mtlr r0
	addi r1, r1, 0x20
	blr
.endfn dtor_803F0B20
