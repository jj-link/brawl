.include "macros.inc"

.section extab, "a"
.balign 4

.obj Letb, local
	.4byte 0x08080000
	.4byte 0x00000000
.endobj Letb

.section extabindex, "a"
.balign 4

.obj Leti, local
	.4byte fn_803F0F04
	.4byte 0x00000040
	.4byte Letb
.endobj Leti

.text
.balign 4

.fn fn_803F0F04, global
	stwu r1, -0x10(r1)
	mflr r0
	cmpwi r3, 0x0
	stw r0, 0x14(r1)
	stw r31, 0xc(r1)
	mr r31, r3
	beq .L_803F0F2C
	cmpwi r4, 0x0
	ble .L_803F0F2C
	bl __dl__FPv
.L_803F0F2C:
	mr r3, r31
	lwz r31, 0xc(r1)
	lwz r0, 0x14(r1)
	mtlr r0
	addi r1, r1, 0x10
	blr
.endfn fn_803F0F04
