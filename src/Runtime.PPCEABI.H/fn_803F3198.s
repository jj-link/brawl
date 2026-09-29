# Runtime.PPCEABI.H/fn_803F3198.s (auto_03_803F3198_text)
#
# Reconstructed at assembly level from the Brawl target
# (build/RSBE01_02/asm/auto_03_803F3198_text.s), following the fn_803F1B64.s precedent.

.include "macros.inc"

.text
.balign 4

.fn fn_803F3198, global
	lwz r5, 0x0(r3)
	clrrwi r7, r5, 3
	lwzx r6, r3, r7
	add r8, r3, r7
	rlwinm. r0, r6, 0, 30, 30
	bnelr
	clrrwi r0, r6, 3
	clrlwi r5, r5, 29
	add r6, r7, r0
	rlwimi r5, r6, 0, 0, 28
	rlwinm. r0, r5, 0, 30, 30
	stw r5, 0x0(r3)
	bne .L_803F31D4
	add r5, r3, r6
	stw r6, -0x4(r5)
.L_803F31D4:
	lwz r0, 0x0(r3)
	rlwinm. r0, r0, 0, 30, 30
	bne .L_803F31F0
	lwzx r0, r3, r6
	rlwinm r0, r0, 0, 30, 28
	stwx r0, r3, r6
	b .L_803F31FC
.L_803F31F0:
	lwzx r0, r3, r6
	ori r0, r0, 0x4
	stwx r0, r3, r6
.L_803F31FC:
	lwz r3, 0x0(r4)
	cmplw r3, r8
	bne .L_803F3210
	lwz r0, 0xc(r3)
	stw r0, 0x0(r4)
.L_803F3210:
	lwz r0, 0x0(r4)
	cmplw r0, r8
	bne .L_803F3224
	li r0, 0x0
	stw r0, 0x0(r4)
.L_803F3224:
	lwz r0, 0x8(r8)
	lwz r3, 0xc(r8)
	stw r0, 0x8(r3)
	lwz r0, 0xc(r8)
	lwz r3, 0x8(r8)
	stw r0, 0xc(r3)
	blr
.endfn fn_803F3198
