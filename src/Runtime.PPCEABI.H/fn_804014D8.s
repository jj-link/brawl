# Runtime.PPCEABI.H/fn_804014D8.s (auto_03_80401358_text)

.include "macros.inc"

.text
.balign 4

.fn fn_804014D8, global
	stwu r1, -0x30(r1)
	mflr r0
	lis r6, gTRKBigEndian@ha
	stw r0, 0x34(r1)
	stmw r25, 0x14(r1)
	mr r27, r3
	mr r28, r5
	mr r30, r4
	addi r31, r6, gTRKBigEndian@l
	li r29, 0x0
	li r3, 0x0
	b .L_804015B0
.L_80401508:
	lwz r0, 0x0(r31)
	lwz r3, 0x0(r30)
	cmpwi r0, 0x0
	stw r3, 0x8(r1)
	beq .L_80401524
	addi r4, r1, 0x8
	b .L_80401548
.L_80401524:
	lbz r6, 0xb(r1)
	addi r4, r1, 0xc
	lbz r5, 0xa(r1)
	lbz r3, 0x9(r1)
	lbz r0, 0x8(r1)
	stb r6, 0xc(r1)
	stb r5, 0xd(r1)
	stb r3, 0xe(r1)
	stb r0, 0xf(r1)
.L_80401548:
	lwz r5, 0xc(r27)
	li r25, 0x4
	li r26, 0x0
	subfic r0, r5, 0x880
	cmplwi r0, 0x4
	bge .L_80401568
	li r26, 0x301
	mr r25, r0
.L_80401568:
	cmplwi r25, 0x1
	bne .L_80401580
	lbz r3, 0x0(r4)
	addi r0, r5, 0x10
	stbx r3, r27, r0
	b .L_80401590
.L_80401580:
	addi r3, r5, 0x10
	mr r5, r25
	add r3, r27, r3
	bl fn_8000449C
.L_80401590:
	lwz r0, 0xc(r27)
	mr r3, r26
	addi r30, r30, 0x4
	addi r29, r29, 0x1
	add r0, r0, r25
	stw r0, 0xc(r27)
	lwz r0, 0xc(r27)
	stw r0, 0x8(r27)
.L_804015B0:
	cmpwi r3, 0x0
	bne .L_804015C0
	cmpw r29, r28
	blt .L_80401508
.L_804015C0:
	lmw r25, 0x14(r1)
	lwz r0, 0x34(r1)
	mtlr r0
	addi r1, r1, 0x30
	blr
.endfn fn_804014D8

.fn fn_804015D4, global
	li r9, 0x0
	li r0, 0x0
	b .L_80401624
.L_804015E0:
	lwz r7, 0xc(r3)
	lbz r8, 0x0(r4)
	cmplwi r7, 0x880
	blt .L_804015F8
	li r7, 0x301
	b .L_80401618
.L_804015F8:
	addi r6, r7, 0x1
	addi r0, r7, 0x10
	stw r6, 0xc(r3)
	li r7, 0x0
	stbx r8, r3, r0
	lwz r6, 0x8(r3)
	addi r0, r6, 0x1
	stw r0, 0x8(r3)
.L_80401618:
	mr r0, r7
	addi r9, r9, 0x1
	addi r4, r4, 0x1
.L_80401624:
	cmpwi r0, 0x0
	bne .L_80401634
	cmpw r9, r5
	blt .L_804015E0
.L_80401634:
	mr r3, r0
	blr
.endfn fn_804015D4
