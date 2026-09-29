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
	.4byte fn_803F88A4
	.4byte 0x00000080
	.4byte Letb
.endobj Leti

.text
.balign 4

.fn fn_803F88A4, global
	stwu r1, -0x30(r1)
	mflr r0
	mr r6, r5
	mr r5, r4
	stw r0, 0x34(r1)
	lis r7, __StringWrite@ha
	addi r4, r1, 0x8
	stw r31, 0x2c(r1)
	li r31, 0x0
	stw r30, 0x28(r1)
	li r30, -0x1
	stw r29, 0x24(r1)
	mr r29, r3
	stw r3, 0x8(r1)
	addi r3, r7, __StringWrite@l
	stw r30, 0xc(r1)
	stw r31, 0x10(r1)
	bl __pformatter_803F7CFC
	cmpwi r29, 0x0
	beq .L_803F8908
	cmplw r3, r30
	bge .L_803F8904
	stbx r31, r29, r3
	b .L_803F8908
.L_803F8904:
	stb r31, -0x2(r29)
.L_803F8908:
	lwz r0, 0x34(r1)
	lwz r31, 0x2c(r1)
	lwz r30, 0x28(r1)
	lwz r29, 0x24(r1)
	mtlr r0
	addi r1, r1, 0x30
	blr
.endfn fn_803F88A4
