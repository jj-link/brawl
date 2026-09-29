# Runtime.PPCEABI.H/fn_803F1EC4.s (auto_fn_803F1EC4_text)
#
# Reconstructed at assembly level from the Brawl target
# (build/RSBE01_02/asm/auto_fn_803F1EC4_text.s), following the fn_803F1B64.s precedent.
# Calls _savegpr_27/_restgpr_27 (auto_03_803F11E0_text, resolved at link).

.include "macros.inc"

.section extab, "a"
.balign 4

.obj Letb, local
	.4byte 0x280A0000
	.4byte 0x00000000
.endobj Letb

.section extabindex, "a"
.balign 4

.obj Leti, local
	.4byte fn_803F1EC4
	.4byte 0x00000578
	.4byte Letb
.endobj Leti

.text
.balign 4

.fn fn_803F1EC4, global
	stwu r1, -0x20(r1)
	mflr r0
	stw r0, 0x24(r1)
	addi r11, r1, 0x20
	bl _savegpr_27
	lwz r5, 0x0(r4)
	lwz r6, 0x284(r3)
	lhz r0, 0x0(r5)
	lwz r7, 0x0(r6)
	extrwi. r6, r0, 1, 30
	extrwi r0, r0, 5, 21
	beq .L_803F1F00
	slwi r5, r0, 4
	subf r8, r5, r7
	b .L_803F1F08
.L_803F1F00:
	slwi r5, r0, 3
	subf r8, r5, r7
.L_803F1F08:
	cmpwi r6, 0x0
	beq .L_803F2130
	subfic r5, r0, 0x20
	li r6, 0x0
	cmpwi cr1, r5, 0x20
	li r9, 0x0
	bge cr1, .L_803F229C
	cmpwi r0, 0x8
	ble .L_803F20E8
	li r11, 0x0
	li r12, 0x0
	li r29, 0x0
	bgt cr1, .L_803F1F50
	lis r10, 0x8000
	subi r10, r10, 0x2
	cmpw r5, r10
	bgt .L_803F1F50
	li r29, 0x1
.L_803F1F50:
	cmpwi r29, 0x0
	beq .L_803F1F68
	addis r10, r5, 0x8000
	cmplwi r10, 0x0
	beq .L_803F1F68
	li r12, 0x1
.L_803F1F68:
	cmpwi r12, 0x0
	beq .L_803F1F98
	neg r10, r5
	li r12, 0x1
	clrrwi. r10, r10, 31
	bne .L_803F1F8C
	clrrwi. r0, r0, 31
	beq .L_803F1F8C
	li r12, 0x0
.L_803F1F8C:
	cmpwi r12, 0x0
	beq .L_803F1F98
	li r11, 0x1
.L_803F1F98:
	cmpwi r11, 0x0
	beq .L_803F20E8
	subfic r0, r5, 0x1f
	slwi r10, r5, 4
	srwi r0, r0, 3
	add r28, r3, r10
	mtctr r0
	cmpwi r5, 0x18
	bge .L_803F20E8
.L_803F1FBC:
	add r27, r8, r9
	addi r0, r6, 0x1
	lfs f0, 0x8(r27)
	slwi r31, r0, 4
	addi r10, r6, 0x2
	addi r0, r6, 0x3
	stfs f0, 0x8(r28)
	slwi r30, r10, 4
	slwi r29, r0, 4
	addi r0, r6, 0x4
	lfs f0, 0xc(r27)
	slwi r12, r0, 4
	addi r11, r6, 0x5
	addi r10, r6, 0x6
	stfs f0, 0xc(r28)
	addi r0, r6, 0x7
	slwi r11, r11, 4
	slwi r10, r10, 4
	lfdx f0, r8, r9
	add r27, r8, r31
	slwi r0, r0, 4
	add r30, r8, r30
	stfd f0, 0x0(r28)
	add r29, r8, r29
	add r12, r8, r12
	add r11, r8, r11
	lfs f0, 0x8(r27)
	add r10, r8, r10
	add r31, r8, r0
	addi r6, r6, 0x8
	stfs f0, 0x18(r28)
	addi r9, r9, 0x80
	addi r5, r5, 0x8
	lfs f0, 0xc(r27)
	stfs f0, 0x1c(r28)
	lfd f0, 0x0(r27)
	stfd f0, 0x10(r28)
	lfs f0, 0x8(r30)
	stfs f0, 0x28(r28)
	lfs f0, 0xc(r30)
	stfs f0, 0x2c(r28)
	lfd f0, 0x0(r30)
	stfd f0, 0x20(r28)
	lfs f0, 0x8(r29)
	stfs f0, 0x38(r28)
	lfs f0, 0xc(r29)
	stfs f0, 0x3c(r28)
	lfd f0, 0x0(r29)
	stfd f0, 0x30(r28)
	lfs f0, 0x8(r12)
	stfs f0, 0x48(r28)
	lfs f0, 0xc(r12)
	stfs f0, 0x4c(r28)
	lfd f0, 0x0(r12)
	stfd f0, 0x40(r28)
	lfs f0, 0x8(r11)
	stfs f0, 0x58(r28)
	lfs f0, 0xc(r11)
	stfs f0, 0x5c(r28)
	lfd f0, 0x0(r11)
	stfd f0, 0x50(r28)
	lfs f0, 0x8(r10)
	stfs f0, 0x68(r28)
	lfs f0, 0xc(r10)
	stfs f0, 0x6c(r28)
	lfd f0, 0x0(r10)
	stfd f0, 0x60(r28)
	lfs f0, 0x8(r31)
	stfs f0, 0x78(r28)
	lfs f0, 0xc(r31)
	stfs f0, 0x7c(r28)
	lfdx f0, r8, r0
	stfd f0, 0x70(r28)
	addi r28, r28, 0x80
	bdnz .L_803F1FBC
.L_803F20E8:
	slwi r9, r6, 4
	slwi r6, r5, 4
	subfic r0, r5, 0x20
	add r9, r8, r9
	add r6, r3, r6
	mtctr r0
	cmpwi r5, 0x20
	bge .L_803F229C
.L_803F2108:
	lfs f0, 0x8(r9)
	stfs f0, 0x8(r6)
	lfs f0, 0xc(r9)
	stfs f0, 0xc(r6)
	lfd f0, 0x0(r9)
	addi r9, r9, 0x10
	stfd f0, 0x0(r6)
	addi r6, r6, 0x10
	bdnz .L_803F2108
	b .L_803F229C
.L_803F2130:
	subfic r5, r0, 0x20
	li r6, 0x0
	cmpwi cr1, r5, 0x20
	li r9, 0x0
	bge cr1, .L_803F229C
	cmpwi r0, 0x8
	ble .L_803F2268
	li r11, 0x0
	li r12, 0x0
	li r29, 0x0
	bgt cr1, .L_803F2170
	lis r10, 0x8000
	subi r10, r10, 0x2
	cmpw r5, r10
	bgt .L_803F2170
	li r29, 0x1
.L_803F2170:
	cmpwi r29, 0x0
	beq .L_803F2188
	addis r10, r5, 0x8000
	cmplwi r10, 0x0
	beq .L_803F2188
	li r12, 0x1
.L_803F2188:
	cmpwi r12, 0x0
	beq .L_803F21B8
	neg r10, r5
	li r12, 0x1
	clrrwi. r10, r10, 31
	bne .L_803F21AC
	clrrwi. r0, r0, 31
	beq .L_803F21AC
	li r12, 0x0
.L_803F21AC:
	cmpwi r12, 0x0
	beq .L_803F21B8
	li r11, 0x1
.L_803F21B8:
	cmpwi r11, 0x0
	beq .L_803F2268
	subfic r0, r5, 0x1f
	slwi r10, r5, 4
	srwi r0, r0, 3
	add r31, r3, r10
	mtctr r0
	cmpwi r5, 0x18
	bge .L_803F2268
.L_803F21DC:
	lfdx f0, r8, r9
	addi r0, r6, 0x1
	addi r30, r6, 0x2
	addi r29, r6, 0x3
	stfd f0, 0x0(r31)
	slwi r0, r0, 3
	addi r12, r6, 0x4
	addi r11, r6, 0x5
	lfdx f0, r8, r0
	addi r10, r6, 0x6
	addi r0, r6, 0x7
	slwi r30, r30, 3
	stfd f0, 0x10(r31)
	slwi r29, r29, 3
	slwi r12, r12, 3
	slwi r11, r11, 3
	lfdx f0, r8, r30
	slwi r10, r10, 3
	slwi r0, r0, 3
	addi r6, r6, 0x8
	stfd f0, 0x20(r31)
	addi r9, r9, 0x40
	addi r5, r5, 0x8
	lfdx f0, r8, r29
	stfd f0, 0x30(r31)
	lfdx f0, r8, r12
	stfd f0, 0x40(r31)
	lfdx f0, r8, r11
	stfd f0, 0x50(r31)
	lfdx f0, r8, r10
	stfd f0, 0x60(r31)
	lfdx f0, r8, r0
	stfd f0, 0x70(r31)
	addi r31, r31, 0x80
	bdnz .L_803F21DC
.L_803F2268:
	slwi r9, r6, 3
	slwi r6, r5, 4
	subfic r0, r5, 0x20
	add r9, r8, r9
	add r6, r3, r6
	mtctr r0
	cmpwi r5, 0x20
	bge .L_803F229C
.L_803F2288:
	lfd f0, 0x0(r9)
	addi r9, r9, 0x8
	stfd f0, 0x0(r6)
	addi r6, r6, 0x10
	bdnz .L_803F2288
.L_803F229C:
	lwz r4, 0x0(r4)
	li r6, 0x0
	li r9, 0x0
	lhz r0, 0x0(r4)
	srawi r27, r0, 11
	subfic r5, r27, 0x20
	cmpwi cr1, r5, 0x20
	slwi r0, r27, 2
	subf r8, r0, r8
	bge cr1, .L_803F241C
	cmpwi r27, 0x8
	ble .L_803F23E8
	li r10, 0x0
	li r11, 0x0
	li r12, 0x0
	bgt cr1, .L_803F22F0
	lis r4, 0x8000
	subi r0, r4, 0x2
	cmpw r5, r0
	bgt .L_803F22F0
	li r12, 0x1
.L_803F22F0:
	cmpwi r12, 0x0
	beq .L_803F2308
	addis r0, r5, 0x8000
	cmplwi r0, 0x0
	beq .L_803F2308
	li r11, 0x1
.L_803F2308:
	cmpwi r11, 0x0
	beq .L_803F2338
	neg r0, r5
	li r4, 0x1
	clrrwi. r0, r0, 31
	bne .L_803F232C
	clrrwi. r0, r27, 31
	beq .L_803F232C
	li r4, 0x0
.L_803F232C:
	cmpwi r4, 0x0
	beq .L_803F2338
	li r10, 0x1
.L_803F2338:
	cmpwi r10, 0x0
	beq .L_803F23E8
	subfic r0, r5, 0x1f
	slwi r4, r5, 2
	srwi r0, r0, 3
	add r4, r3, r4
	mtctr r0
	cmpwi r5, 0x18
	bge .L_803F23E8
.L_803F235C:
	lwzx r10, r8, r9
	addi r0, r6, 0x1
	addi r30, r6, 0x2
	addi r31, r6, 0x3
	stw r10, 0x200(r4)
	slwi r0, r0, 2
	addi r12, r6, 0x4
	addi r11, r6, 0x5
	lwzx r29, r8, r0
	addi r10, r6, 0x6
	addi r0, r6, 0x7
	slwi r30, r30, 2
	stw r29, 0x204(r4)
	slwi r31, r31, 2
	slwi r12, r12, 2
	slwi r11, r11, 2
	lwzx r30, r8, r30
	slwi r10, r10, 2
	slwi r0, r0, 2
	addi r6, r6, 0x8
	stw r30, 0x208(r4)
	addi r9, r9, 0x20
	addi r5, r5, 0x8
	lwzx r31, r8, r31
	stw r31, 0x20c(r4)
	lwzx r12, r8, r12
	stw r12, 0x210(r4)
	lwzx r11, r8, r11
	stw r11, 0x214(r4)
	lwzx r10, r8, r10
	stw r10, 0x218(r4)
	lwzx r0, r8, r0
	stw r0, 0x21c(r4)
	addi r4, r4, 0x20
	bdnz .L_803F235C
.L_803F23E8:
	slwi r6, r6, 2
	slwi r4, r5, 2
	subfic r0, r5, 0x20
	add r6, r8, r6
	add r4, r3, r4
	mtctr r0
	cmpwi r5, 0x20
	bge .L_803F241C
.L_803F2408:
	lwz r0, 0x0(r6)
	addi r6, r6, 0x4
	stw r0, 0x200(r4)
	addi r4, r4, 0x4
	bdnz .L_803F2408
.L_803F241C:
	stw r7, 0x284(r3)
	addi r11, r1, 0x20
	lwz r3, 0x4(r7)
	bl _restgpr_27
	lwz r0, 0x24(r1)
	mtlr r0
	addi r1, r1, 0x20
	blr
