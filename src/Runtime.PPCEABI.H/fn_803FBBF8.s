.include "macros.inc"
.section extab, "a"
.balign 4
.obj Letb, local
	.4byte 0x000A0000
	.4byte 0x00000000
.endobj Letb
.section extabindex, "a"
.balign 4
.obj Leti, local
	.4byte fn_803FBBF8
	.4byte 0x00000084
	.4byte Letb
.endobj Leti
.text
.balign 4
.fn fn_803FBBF8, global
	stwu r1, -0x20(r1)
	mflr r0
	lis r4, fn_803FA078@ha
	stw r0, 0x24(r1)
	li r0, 0x0
	addi r4, r4, fn_803FA078@l
	addi r5, r1, 0x10
	stw r3, 0x10(r1)
	lis r3, 0x8000
	subi r3, r3, 0x1
	addi r6, r1, 0x8
	stw r0, 0x14(r1)
	addi r7, r1, 0xc
	bl fn_803FA804
	lwz r0, 0xc(r1)
	fabs f2, f1
	cmpwi r0, 0x0
	bne .L_803FBC64
	lfd f0, lbl_805A4BE8@sda21(r0)
	fcmpu cr0, f0, f1
	beq .L_803FBC6C
	lfd f0, lbl_805A4BF0@sda21(r0)
	fcmpo cr0, f2, f0
	blt .L_803FBC64
	lfd f0, lbl_805A4BF8@sda21(r0)
	fcmpo cr0, f2, f0
	ble .L_803FBC6C
.L_803FBC64:
	li r0, 0x22
	stw r0, lbl_805A12E0@sda21(r0)
.L_803FBC6C:
	lwz r0, 0x24(r1)
	mtlr r0
	addi r1, r1, 0x20
	blr
.endfn fn_803FBBF8
