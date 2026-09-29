# Runtime.PPCEABI.H/fn_80401C54.s
.include "macros.inc"

.text
.balign 4

# .text:0x184 | 0x80401C54 | size: 0x88
.fn fn_80401C54, global
	stwu r1, -0x20(r1)
	mflr r0
	stw r0, 0x24(r1)
	stw r31, 0x1c(r1)
	li r31, 0x0
	stw r30, 0x18(r1)
	stw r29, 0x14(r1)
	mr r29, r3
	li r3, 0x0
	b .L_80401CA8
.L_80401C7C:
	bl fn_80402EF0
	stb r30, 0x8(r1)
	mr r30, r3
	li r3, 0x0
	stb r31, 0x9(r1)
	bl fn_80402EE4
	addi r3, r1, 0x8
	bl OSReport
	mr r3, r30
	bl fn_80402EE4
	li r3, 0x0
.L_80401CA8:
	cmpwi r3, 0x0
	bne .L_80401CC0
	lbz r0, 0x0(r29)
	addi r29, r29, 0x1
	extsb. r30, r0
	bne .L_80401C7C
.L_80401CC0:
	lwz r0, 0x24(r1)
	lwz r31, 0x1c(r1)
	lwz r30, 0x18(r1)
	lwz r29, 0x14(r1)
	mtlr r0
	addi r1, r1, 0x20
	blr
.endfn fn_80401C54

# .text:0x20C | 0x80401CDC | size: 0x140
.fn TRKDispatchMessage, global
	stwu r1, -0x10(r1)
	mflr r0
	li r4, 0x0
	stw r0, 0x14(r1)
	stw r31, 0xc(r1)
	li r31, 0x500
	stw r30, 0x8(r1)
	mr r30, r3
	bl fn_80401868
	lbz r0, 0x14(r30)
	cmplwi r0, 0x1a
	bgt .L_80401E00
	lis r3, jumptable_804946F8@ha
	slwi r0, r0, 2
	addi r3, r3, jumptable_804946F8@l
	lwzx r0, r3, r0
	mtctr r0
	bctr
	mr r3, r30
	bl fn_80402E5C
	mr r31, r3
	b .L_80401E00
	mr r3, r30
	bl fn_80402DC0
	mr r31, r3
	b .L_80401E00
	mr r3, r30
	bl fn_80402D44
	mr r31, r3
	b .L_80401E00
	mr r3, r30
	bl fn_80402CC8
	mr r31, r3
	b .L_80401E00
	mr r3, r30
	bl fn_80402CC0
	mr r31, r3
	b .L_80401E00
	mr r3, r30
	bl fn_80402CB8
	mr r31, r3
	b .L_80401E00
	mr r3, r30
	bl fn_80402A70
	mr r31, r3
	b .L_80401E00
	mr r3, r30
	bl fn_80402854
	mr r31, r3
	b .L_80401E00
	mr r3, r30
	bl fn_80402630
	mr r31, r3
	b .L_80401E00
	mr r3, r30
	bl fn_80402374
	mr r31, r3
	b .L_80401E00
	mr r3, r30
	bl fn_80402290
	mr r31, r3
	b .L_80401E00
	mr r3, r30
	bl fn_80401FBC
	mr r31, r3
	b .L_80401E00
	mr r3, r30
	bl fn_80401EF0
	mr r31, r3
	b .L_80401E00
	mr r3, r30
	bl fn_80401E24
	mr r31, r3
.L_80401E00:
	lwz r0, 0x14(r1)
	mr r3, r31
	lwz r31, 0xc(r1)
	lwz r30, 0x8(r1)
	mtlr r0
	addi r1, r1, 0x10
	blr
.endfn TRKDispatchMessage
