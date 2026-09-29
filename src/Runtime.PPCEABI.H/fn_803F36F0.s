# Runtime.PPCEABI.H/fn_803F36F0.s (auto_fn_803F36F0_text)
#
# Reconstructed at assembly level from the Brawl target
# (build/RSBE01_02/asm/auto_fn_803F36F0_text.s), following the fn_803F1B64.s precedent.

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
	.4byte fn_803F36F0
	.4byte 0x000000DC
	.4byte Letb
.endobj Leti

.text
.balign 4

.fn fn_803F36F0, global
	stwu r1, -0x20(r1)
	mflr r0
	stw r0, 0x24(r1)
	li r0, 0x0
	stw r31, 0x1c(r1)
	mr r31, r5
	stw r30, 0x18(r1)
	mr r30, r6
	stw r29, 0x14(r1)
	mr r29, r3
	stb r0, 0x0(r3)
	stb r0, 0x4(r3)
	b .L_803F3768
.L_803F3724:
	mr r3, r31
	mr r4, r30
	li r6, 0xa
	li r5, 0x0
	bl __mod2u
	lbz r8, 0x4(r29)
	mr r3, r31
	li r6, 0xa
	li r5, 0x0
	add r7, r29, r8
	addi r0, r8, 0x1
	stb r4, 0x5(r7)
	mr r4, r30
	stb r0, 0x4(r29)
	bl __div2u
	mr r30, r4
	mr r31, r3
.L_803F3768:
	or. r0, r30, r31
	bne .L_803F3724
	lbz r0, 0x4(r29)
	addi r4, r29, 0x5
	add r3, r29, r0
	addi r3, r3, 0x5
	b .L_803F3798
.L_803F3784:
	lbz r5, 0x0(r4)
	lbz r0, 0x0(r3)
	stb r0, 0x0(r4)
	addi r4, r4, 0x1
	stb r5, 0x0(r3)
.L_803F3798:
	subi r3, r3, 0x1
	cmplw r4, r3
	blt .L_803F3784
	lbz r3, 0x4(r29)
	subi r0, r3, 0x1
	sth r0, 0x2(r29)
	lwz r31, 0x1c(r1)
	lwz r30, 0x18(r1)
	lwz r29, 0x14(r1)
	lwz r0, 0x24(r1)
	mtlr r0
	addi r1, r1, 0x20
	blr
.endfn fn_803F36F0
