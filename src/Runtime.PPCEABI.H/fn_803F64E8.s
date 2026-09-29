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
	.4byte fn_803F64E8
	.4byte 0x00000080
	.4byte Letb
.endobj Leti

.text
.balign 4

.fn fn_803F64E8, global
	stwu r1, -0x10(r1)
	lis r0, 0x7ff0
	stfd f1, 0x8(r1)
	lwz r4, 0x8(r1)
	rlwinm r3, r4, 0, 1, 11
	cmpw r3, r0
	beq .L_803F6514
	bge .L_803F655C
	cmpwi r3, 0x0
	beq .L_803F6538
	b .L_803F655C
.L_803F6514:
	clrlwi. r0, r4, 12
	bne .L_803F6528
	lwz r0, 0xc(r1)
	cmpwi r0, 0x0
	beq .L_803F6530
.L_803F6528:
	li r3, 0x1
	b .L_803F6560
.L_803F6530:
	li r3, 0x2
	b .L_803F6560
.L_803F6538:
	clrlwi. r0, r4, 12
	bne .L_803F654C
	lwz r0, 0xc(r1)
	cmpwi r0, 0x0
	beq .L_803F6554
.L_803F654C:
	li r3, 0x5
	b .L_803F6560
.L_803F6554:
	li r3, 0x3
	b .L_803F6560
.L_803F655C:
	li r3, 0x4
.L_803F6560:
	addi r1, r1, 0x10
	blr
.endfn fn_803F64E8
