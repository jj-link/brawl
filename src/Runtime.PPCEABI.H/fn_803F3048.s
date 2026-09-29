# Runtime.PPCEABI.H/fn_803F3048.s (auto_fn_803F3048_text)
#
# Reconstructed at assembly level from the Brawl target
# (build/RSBE01_02/asm/auto_fn_803F3048_text.s), following the fn_803F1B64.s precedent.

.include "macros.inc"

.section extab, "a"
.balign 4

.obj Letb, local
	.4byte 0x10080000
	.4byte 0x00000000
.endobj Letb

.section extabindex, "a"
.balign 4

.obj Leti, local
	.4byte fn_803F3048
	.4byte 0x00000150
	.4byte Letb
.endobj Leti

.text
.balign 4

.fn fn_803F3048, global
	stwu r1, -0x10(r1)
	mflr r0
	stw r0, 0x14(r1)
	stw r31, 0xc(r1)
	stw r30, 0x8(r1)
	mr r30, r3
	lwz r5, 0x0(r4)
	rlwinm r0, r5, 0, 31, 29
	clrrwi r6, r5, 3
	stw r0, 0x0(r4)
	add r5, r4, r6
	lwzx r0, r4, r6
	rlwinm r0, r0, 0, 30, 28
	stwx r0, r4, r6
	stw r6, -0x4(r5)
	lwz r0, 0xc(r3)
	clrrwi r0, r0, 3
	add r31, r3, r0
	lwzu r3, -0x4(r31)
	cmpwi r3, 0x0
	beq .L_803F3158
	lwz r5, 0x8(r3)
	mr r3, r4
	stw r5, 0x8(r4)
	stw r4, 0xc(r5)
	lwz r0, 0x0(r31)
	stw r0, 0xc(r4)
	lwz r5, 0x0(r31)
	stw r4, 0x8(r5)
	stw r4, 0x0(r31)
	lwz r0, 0x0(r4)
	rlwinm. r0, r0, 0, 29, 29
	bne .L_803F3148
	lwz r6, -0x4(r4)
	rlwinm. r0, r6, 0, 30, 30
	beq .L_803F30DC
	b .L_803F3148
.L_803F30DC:
	subf r3, r6, r4
	lwz r0, 0x0(r3)
	clrlwi r5, r0, 29
	stw r5, 0x0(r3)
	lwz r0, 0x0(r4)
	clrrwi r0, r0, 3
	add r0, r6, r0
	rlwimi r5, r0, 0, 0, 28
	rlwinm. r0, r5, 0, 30, 30
	stw r5, 0x0(r3)
	bne .L_803F311C
	lwz r0, 0x0(r4)
	clrrwi r0, r0, 3
	add r0, r6, r0
	add r5, r3, r0
	stw r0, -0x4(r5)
.L_803F311C:
	lwz r5, 0x0(r31)
	cmplw r5, r4
	bne .L_803F3130
	lwz r0, 0xc(r5)
	stw r0, 0x0(r31)
.L_803F3130:
	lwz r0, 0x8(r4)
	lwz r5, 0xc(r4)
	stw r0, 0x8(r5)
	lwz r5, 0xc(r4)
	lwz r4, 0x8(r5)
	stw r5, 0xc(r4)
.L_803F3148:
	stw r3, 0x0(r31)
	mr r4, r31
	bl fn_803F3198
	b .L_803F3164
.L_803F3158:
	stw r4, 0x0(r31)
	stw r4, 0x8(r4)
	stw r4, 0xc(r4)
.L_803F3164:
	lwz r3, 0x0(r31)
	lwz r0, 0x8(r30)
	lwz r3, 0x0(r3)
	clrrwi r3, r3, 3
	cmplw r0, r3
	bge .L_803F3180
	stw r3, 0x8(r30)
.L_803F3180:
	lwz r0, 0x14(r1)
	lwz r31, 0xc(r1)
	lwz r30, 0x8(r1)
	mtlr r0
	addi r1, r1, 0x10
	blr
.endfn fn_803F3048
