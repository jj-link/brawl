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
	.4byte fn_803F5898
	.4byte 0x000000BC
	.4byte Letb
.endobj Leti

.text
.balign 4

.fn fn_803F5898, global
	stwu r1, -0x20(r1)
	mflr r0
	cmpwi r3, 0x0
	stw r0, 0x24(r1)
	stw r31, 0x1c(r1)
	stw r30, 0x18(r1)
	stw r29, 0x14(r1)
	mr r29, r3
	bne .L_803F58C4
	li r3, -0x1
	b .L_803F5938
.L_803F58C4:
	lwz r0, 0x4(r3)
	extrwi. r0, r0, 3, 7
	bne .L_803F58D8
	li r3, 0x0
	b .L_803F5938
.L_803F58D8:
	bl fn_803F5954
	lwz r12, 0x44(r29)
	mr r30, r3
	lwz r3, 0x0(r29)
	mtctr r12
	bctrl
	lwz r0, 0x8(r29)
	li r5, 0x0
	lwz r4, 0x4(r29)
	mr r31, r3
	extrwi. r0, r0, 1, 3
	stw r5, 0x0(r29)
	rlwinm r4, r4, 0, 10, 6
	stw r4, 0x4(r29)
	beq .L_803F591C
	lwz r3, 0x1c(r29)
	bl fn_803F342C
.L_803F591C:
	cmpwi r30, 0x0
	li r0, 0x0
	bne .L_803F5930
	cmpwi r31, 0x0
	beq .L_803F5934
.L_803F5930:
	li r0, 0x1
.L_803F5934:
	neg r3, r0
.L_803F5938:
	lwz r0, 0x24(r1)
	lwz r31, 0x1c(r1)
	lwz r30, 0x18(r1)
	lwz r29, 0x14(r1)
	mtlr r0
	addi r1, r1, 0x20
	blr
.endfn fn_803F5898
