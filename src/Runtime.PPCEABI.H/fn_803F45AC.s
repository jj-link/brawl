# Runtime.PPCEABI.H/fn_803F45AC.s (auto_fn_803F45AC_text)
#
# Reconstructed at assembly level from the Brawl target
# (build/RSBE01_02/asm/auto_fn_803F45AC_text.s), following the fn_803F1B64.s precedent.
# References lbl_805A4B68 (.sdata2) — external, link-resolved.

.include "macros.inc"

.section extab, "a"
.balign 4

.obj Letb, local
	.4byte 0x18480000
	.4byte 0x00000000
.endobj Letb

.section extabindex, "a"
.balign 4

.obj Leti, local
	.4byte fn_803F45AC
	.4byte 0x00000164
	.4byte Letb
.endobj Leti

.text
.balign 4

.fn fn_803F45AC, global
	stwu r1, -0x90(r1)
	mflr r0
	stw r0, 0x94(r1)
	stfd f31, 0x88(r1)
	fmr f31, f1
	stw r31, 0x84(r1)
	stw r30, 0x80(r1)
	mr r30, r3
	stw r29, 0x7c(r1)
	bl fn_803F64D0
	lfd f0, lbl_805A4B68@sda21(r0)
	neg r0, r3
	or r0, r0, r3
	fcmpu cr0, f0, f31
	srwi r0, r0, 31
	extsb r31, r0
	bne .L_803F460C
	li r3, 0x0
	li r0, 0x1
	stb r31, 0x0(r30)
	sth r3, 0x2(r30)
	stb r0, 0x4(r30)
	stb r3, 0x5(r30)
	b .L_803F46F0
.L_803F460C:
	fmr f1, f31
	bl fn_803F64E8
	cmpwi r3, 0x2
	bgt .L_803F4650
	li r3, 0x0
	li r0, 0x1
	fmr f1, f31
	stb r31, 0x0(r30)
	sth r3, 0x2(r30)
	stb r0, 0x4(r30)
	bl fn_803F64E8
	cmpwi r3, 0x1
	li r0, 0x49
	bne .L_803F4648
	li r0, 0x4e
.L_803F4648:
	stb r0, 0x5(r30)
	b .L_803F46F0
.L_803F4650:
	cmpwi r31, 0x0
	beq .L_803F465C
	fneg f31, f31
.L_803F465C:
	fmr f1, f31
	addi r3, r1, 0x8
	bl fn_804006F0
	stfd f1, 0x10(r1)
	fmr f31, f1
	lwz r4, 0x14(r1)
	lwz r3, 0x10(r1)
	subi r0, r4, 0x1
	cmpwi r4, 0x0
	andc r0, r0, r4
	oris r3, r3, 0x10
	cntlzw r0, r0
	subfic r4, r0, 0x20
	bne .L_803F46A8
	subi r0, r3, 0x1
	andc r0, r0, r3
	cntlzw r0, r0
	subfic r3, r0, 0x20
	addi r4, r3, 0x20
.L_803F46A8:
	lwz r0, 0x8(r1)
	subfic r29, r4, 0x35
	addi r3, r1, 0x18
	subf r4, r29, r0
	bl fn_803F3B40
	fmr f1, f31
	mr r3, r29
	bl fn_80400778
	bl fn_803F1960
	mr r5, r3
	mr r6, r4
	addi r3, r1, 0x44
	bl fn_803F36F0
	mr r3, r30
	addi r4, r1, 0x44
	addi r5, r1, 0x18
	bl fn_803F37CC
	stb r31, 0x0(r30)
.L_803F46F0:
	lwz r0, 0x94(r1)
	lfd f31, 0x88(r1)
	lwz r31, 0x84(r1)
	lwz r30, 0x80(r1)
	lwz r29, 0x7c(r1)
	mtlr r0
	addi r1, r1, 0x90
	blr
.endfn fn_803F45AC
