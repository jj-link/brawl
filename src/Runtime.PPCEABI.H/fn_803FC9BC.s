# Runtime.PPCEABI.H/fn_803FC9BC.s (auto_fn_803FC9BC_text)
#
# Reconstructed at assembly level from the Brawl target
# (build/RSBE01_02/asm/auto_fn_803FC9BC_text.s), following the fn_803F36F0.s precedent.

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
	.4byte fn_803FC9BC
	.4byte 0x00000040
	.4byte Letb
.endobj Leti

.text
.balign 4

.fn fn_803FC9BC, global
	stwu r1, -0x20(r1)
	mflr r0
	stw r0, 0x24(r1)
	stw r31, 0x1c(r1)
	mr r31, r3
	addi r3, r1, 0x8
	bl fn_804006F0
	lwz r0, 0x8(r1)
	add r3, r0, r31
	stw r3, 0x8(r1)
	bl fn_80400778
	lwz r0, 0x24(r1)
	lwz r31, 0x1c(r1)
	mtlr r0
	addi r1, r1, 0x20
	blr
.endfn fn_803FC9BC
