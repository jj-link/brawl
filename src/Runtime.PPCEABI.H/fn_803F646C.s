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
	.4byte fn_803F646C
	.4byte 0x00000064
	.4byte Letb
.endobj Leti

.text
.balign 4

.fn fn_803F646C, global
	stwu r1, -0x10(r1)
	lis r0, 0x7f80
	stfs f1, 0x8(r1)
	lwz r4, 0x8(r1)
	rlwinm r3, r4, 0, 1, 8
	cmpw r3, r0
	beq .L_803F6498
	bge .L_803F64C4
	cmpwi r3, 0x0
	beq .L_803F64B0
	b .L_803F64C4
.L_803F6498:
	clrlwi r3, r4, 9
	neg r0, r3
	or r0, r0, r3
	srawi r3, r0, 31
	addi r3, r3, 0x2
	b .L_803F64C8
.L_803F64B0:
	clrlwi. r0, r4, 9
	li r3, 0x3
	beq .L_803F64C8
	li r3, 0x5
	b .L_803F64C8
.L_803F64C4:
	li r3, 0x4
.L_803F64C8:
	addi r1, r1, 0x10
	blr
.endfn fn_803F646C
