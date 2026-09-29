# Runtime.PPCEABI.H/fn_803F1B64.s (auto_fn_803F1B64_text)
#
# Reconstructed at assembly level from the Brawl target
# (build/RSBE01_02/asm/auto_fn_803F1B64_text.s). The C reconstruction of this MW runtime
# exception throw-helper reproduces the exact instruction sequence but not MWCC's register
# allocation/scheduling texture (verified across ~15 source-shape iterations), so the unit is
# transcribed directly, following the __init_cpp_exceptions.s precedent.
#
# Semantics (for reference; see PLAN.md): resolves a code address against the registered
# fragment's exception table via fn_803F1ADC, binary-searches the eti range table (12-byte
# entries), resolves the action-record table (inline vs TOC-relative via the entry size high
# bit), and walks word-keyed (stride 8) or halfword-keyed (stride 6) action records to find the
# handler offset for the throw site.

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
	.4byte fn_803F1B64
	.4byte 0x000001B0
	.4byte Letb
.endobj Leti

.text
.balign 4

.fn fn_803F1B64, global
	stwu r1, -0x30(r1)
	mflr r0
	stw r0, 0x34(r1)
	li r0, 0x0
	stw r31, 0x2c(r1)
	mr r31, r4
	stw r30, 0x28(r1)
	mr r30, r3
	stw r0, 0x0(r4)
	stw r0, 0x8(r4)
	addi r4, r1, 0x8
	bl fn_803F1ADC
	cmpwi r3, 0x0
	beq .L_803F1CFC
	lwz r0, 0x10(r1)
	lis r3, 0x2aab
	subi r3, r3, 0x5555
	li r7, 0x0
	stw r0, 0xc(r31)
	lwz r0, 0x18(r1)
	stw r0, 0x10(r31)
	lwz r0, 0x20(r1)
	stw r0, 0x14(r31)
	lwz r5, 0x8(r1)
	lwz r0, 0xc(r1)
	lwz r4, 0x10(r1)
	subf r0, r5, r0
	mulhw r3, r3, r0
	subf r0, r4, r30
	srawi r3, r3, 1
	srwi r4, r3, 31
	add r9, r3, r4
.L_803F1BE4:
	cmpw r7, r9
	bgt .L_803F1CFC
	add r4, r7, r9
	srwi r3, r4, 31
	add r3, r3, r4
	srawi r8, r3, 1
	mulli r3, r8, 0xc
	lwzx r4, r5, r3
	add r6, r5, r3
	cmplw r0, r4
	bge .L_803F1C18
	subi r9, r8, 0x1
	b .L_803F1BE4
.L_803F1C18:
	lwz r3, 0x4(r6)
	clrlwi r3, r3, 1
	add r3, r4, r3
	cmplw r0, r3
	ble .L_803F1C34
	addi r7, r8, 0x1
	b .L_803F1BE4
.L_803F1C34:
	lwz r3, 0x10(r1)
	add r3, r3, r4
	stw r3, 0x4(r31)
	lwz r3, 0x4(r6)
	srwi. r3, r3, 31
	beq .L_803F1C54
	addi r5, r6, 0x8
	b .L_803F1C60
.L_803F1C54:
	lwz r4, 0x18(r1)
	lwz r3, 0x8(r6)
	add r5, r4, r3
.L_803F1C60:
	stw r5, 0x0(r31)
	lhz r3, 0x0(r5)
	lwz r4, 0x0(r6)
	extrwi. r3, r3, 1, 28
	subf r0, r4, r0
	beq .L_803F1CC0
	addi r6, r5, 0x4
	b .L_803F1CB0
.L_803F1C80:
	lhz r3, 0x4(r6)
	cmplw r4, r0
	slwi r3, r3, 2
	add r3, r4, r3
	bgt .L_803F1CAC
	cmplw r3, r0
	blt .L_803F1CAC
	lhz r0, 0x6(r6)
	add r0, r5, r0
	stw r0, 0x8(r31)
	b .L_803F1CFC
.L_803F1CAC:
	addi r6, r6, 0x8
.L_803F1CB0:
	lwz r4, 0x0(r6)
	cmpwi r4, 0x0
	bne .L_803F1C80
	b .L_803F1CFC
.L_803F1CC0:
	addi r4, r5, 0x2
	b .L_803F1CF0
.L_803F1CC8:
	cmplw r3, r0
	bgt .L_803F1CEC
	lhz r3, 0x2(r4)
	cmplw r3, r0
	blt .L_803F1CEC
	lhz r0, 0x4(r4)
	add r0, r5, r0
	stw r0, 0x8(r31)
	b .L_803F1CFC
.L_803F1CEC:
	addi r4, r4, 0x6
.L_803F1CF0:
	lhz r3, 0x0(r4)
	cmpwi r3, 0x0
	bne .L_803F1CC8
.L_803F1CFC:
	lwz r0, 0x34(r1)
	lwz r31, 0x2c(r1)
	lwz r30, 0x28(r1)
	mtlr r0
	addi r1, r1, 0x30
	blr
.endfn fn_803F1B64
