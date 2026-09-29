.include "macros.inc"

.section extab, "a"
.balign 4

.obj Letb, local
	.4byte 0x00080000
	.4byte 0x00000000
.endobj Letb

.section extabindex, "a"
.balign 4

.obj Leti, local
	.4byte fn_803FC984
	.4byte 0x00000034
	.4byte Letb
.endobj Leti

.text
.balign 4

.fn fn_803FC984, global
	stwu r1, -0x10(r1)
	mflr r0
	li r3, 0x1
	stw r0, 0x14(r1)
	bl fn_803FA1D0
	li r0, 0x1
	li r3, 0x1
	stw r0, lbl_805A12F0@sda21(r0)
	bl exit
	lwz r0, 0x14(r1)
	mtlr r0
	addi r1, r1, 0x10
	blr
.endfn fn_803FC984
