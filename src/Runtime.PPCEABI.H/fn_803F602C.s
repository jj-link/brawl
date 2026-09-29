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
	.4byte fn_803F602C
	.4byte 0x000000CC
	.4byte Letb
.endobj Leti

.text
.balign 4

.fn fn_803F602C, global
	stwu r1, -0x10(r1)
	mflr r0
	xor r6, r3, r4
	cmplwi r5, 0x20
	stw r0, 0x14(r1)
	cntlzw r0, r6
	slw r0, r3, r0
	stw r31, 0xc(r1)
	mr r31, r3
	srwi r7, r0, 31
	blt .L_803F6094
	clrlwi. r0, r6, 30
	beq .L_803F6078
	cmpwi r7, 0x0
	bne .L_803F6070
	bl fn_803F6300
	b .L_803F608C
.L_803F6070:
	bl fn_803F63C0
	b .L_803F608C
.L_803F6078:
	cmpwi r7, 0x0
	bne .L_803F6088
	bl fn_803F619C
	b .L_803F608C
.L_803F6088:
	bl fn_803F6258
.L_803F608C:
	mr r3, r31
	b .L_803F60E4
.L_803F6094:
	cmpwi r7, 0x0
	bne .L_803F60C0
	subi r4, r4, 0x1
	subi r3, r3, 0x1
	addi r5, r5, 0x1
	b .L_803F60B4
.L_803F60AC:
	lbzu r0, 0x1(r4)
	stbu r0, 0x1(r3)
.L_803F60B4:
	subic. r5, r5, 0x1
	bne .L_803F60AC
	b .L_803F60E0
.L_803F60C0:
	add r4, r4, r5
	add r3, r3, r5
	addi r5, r5, 0x1
	b .L_803F60D8
.L_803F60D0:
	lbzu r0, -0x1(r4)
	stbu r0, -0x1(r3)
.L_803F60D8:
	subic. r5, r5, 0x1
	bne .L_803F60D0
.L_803F60E0:
	mr r3, r31
.L_803F60E4:
	lwz r0, 0x14(r1)
	lwz r31, 0xc(r1)
	mtlr r0
	addi r1, r1, 0x10
	blr
.endfn fn_803F602C
