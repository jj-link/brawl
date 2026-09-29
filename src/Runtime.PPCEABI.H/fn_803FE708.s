# Runtime.PPCEABI.H/fn_803FE708.s
.include "macros.inc"

.text
.balign 4

.fn fn_803FE708, global
	stwu r1, -0x370(r1)
	mflr r0
	stw r0, 0x374(r1)
	addi r11, r1, 0x370
	bl _savefpr_23
	stmw r14, 0x2e0(r1)
	lis r9, 0x2aab
	lis r12, 0x4330
	subi r0, r5, 0x3
	lis r10, lbl_80420318@ha
	subi r9, r9, 0x5555
	slwi r11, r7, 2
	mulhw r0, r9, r0
	addi r10, r10, lbl_80420318@l
	mr r17, r4
	lwzx r21, r10, r11
	stw r12, 0x240(r1)
	mr r16, r3
	srawi r0, r0, 2
	stw r12, 0x248(r1)
	srwi r4, r0, 31
	subi r22, r6, 0x1
	add. r10, r0, r4
	stw r7, 0x8(r1)
	bge .L_803FE770
	li r10, 0x0
.L_803FE770:
	addi r0, r10, 0x1
	add. r9, r22, r21
	mulli r6, r0, 0x18
	subf r7, r22, r10
	lfd f1, lbl_805A5000@sda21(r0)
	slwi r4, r7, 2
	subf r19, r6, r5
	addi r0, r9, 0x1
	add r4, r8, r4
	addi r5, r1, 0x1a0
	mtctr r0
	blt .L_803FE7D8
.L_803FE7A0:
	cmpwi r7, 0x0
	bge .L_803FE7B0
	lfd f0, lbl_805A4FC8@sda21(r0)
	b .L_803FE7C4
.L_803FE7B0:
	lwz r0, 0x0(r4)
	xoris r0, r0, 0x8000
	stw r0, 0x244(r1)
	lfd f0, 0x240(r1)
	fsub f0, f0, f1
.L_803FE7C4:
	stfd f0, 0x0(r5)
	addi r5, r5, 0x8
	addi r4, r4, 0x4
	addi r7, r7, 0x1
	bdnz .L_803FE7A0
.L_803FE7D8:
	addi r0, r22, 0x1
	addi r5, r1, 0x60
	clrrwi r25, r22, 31
	addi r12, r1, 0x1a0
	clrrwi r24, r0, 31
	li r9, 0x0
	lis r4, 0x8000
	b .L_803FE9BC
.L_803FE7F8:
	cmpwi cr1, r22, 0x0
	lfd f6, lbl_805A4FC8@sda21(r0)
	li r7, 0x0
	blt cr1, .L_803FE9B0
	addi r0, r22, 0x1
	subi r14, r22, 0x8
	cmpwi r0, 0x8
	ble .L_803FE96C
	li r6, 0x0
	li r11, 0x0
	blt cr1, .L_803FE834
	subi r0, r4, 0x2
	cmpw r22, r0
	bgt .L_803FE834
	li r11, 0x1
.L_803FE834:
	cmpwi r11, 0x0
	beq .L_803FE860
	cmpwi r25, 0x0
	li r0, 0x1
	bne .L_803FE854
	cmpwi r24, 0x0
	beq .L_803FE854
	li r0, 0x0
.L_803FE854:
	cmpwi r0, 0x0
	beq .L_803FE860
	li r6, 0x1
.L_803FE860:
	cmpwi r6, 0x0
	beq .L_803FE96C
	addi r11, r14, 0x8
	mr r6, r16
	srwi r11, r11, 3
	add r0, r22, r9
	mtctr r11
	cmpwi r14, 0x0
	blt .L_803FE96C
.L_803FE884:
	subf r11, r7, r0
	addi r14, r7, 0x1
	slwi r15, r11, 3
	lfd f1, 0x0(r6)
	lfdx f0, r12, r15
	subf r14, r14, r0
	slwi r15, r14, 3
	addi r11, r7, 0x2
	fmul f2, f1, f0
	subf r14, r11, r0
	lfdx f0, r12, r15
	slwi r15, r14, 3
	lfd f1, 0x8(r6)
	addi r11, r7, 0x3
	fmul f3, f1, f0
	subf r14, r11, r0
	lfd f1, 0x10(r6)
	slwi r14, r14, 3
	fadd f6, f6, f2
	lfdx f0, r12, r15
	fmul f2, f1, f0
	addi r11, r7, 0x4
	lfdx f0, r12, r14
	subf r11, r11, r0
	fadd f6, f6, f3
	lfd f1, 0x18(r6)
	slwi r18, r11, 3
	fmul f1, f1, f0
	addi r11, r7, 0x5
	addi r14, r7, 0x6
	fadd f6, f6, f2
	subf r11, r11, r0
	slwi r15, r11, 3
	addi r11, r7, 0x7
	fadd f6, f6, f1
	subf r14, r14, r0
	lfd f2, 0x20(r6)
	lfdx f0, r12, r18
	subf r11, r11, r0
	lfd f1, 0x28(r6)
	fmul f5, f2, f0
	lfdx f0, r12, r15
	slwi r14, r14, 3
	lfd f3, 0x30(r6)
	fmul f4, f1, f0
	lfdx f2, r12, r14
	fadd f6, f6, f5
	slwi r11, r11, 3
	lfd f1, 0x38(r6)
	fmul f2, f3, f2
	lfdx f0, r12, r11
	addi r7, r7, 0x8
	fadd f6, f6, f4
	addi r6, r6, 0x40
	fmul f0, f1, f0
	fadd f6, f6, f2
	fadd f6, f6, f0
	bdnz .L_803FE884
.L_803FE96C:
	addi r0, r22, 0x1
	slwi r6, r7, 3
	subf r0, r7, r0
	add r11, r22, r9
	add r6, r3, r6
	mtctr r0
	cmpw r7, r22
	bgt .L_803FE9B0
.L_803FE98C:
	subf r0, r7, r11
	lfd f1, 0x0(r6)
	slwi r0, r0, 3
	addi r6, r6, 0x8
	lfdx f0, r12, r0
	addi r7, r7, 0x1
	fmul f0, f1, f0
	fadd f6, f6, f0
	bdnz .L_803FE98C
.L_803FE9B0:
	stfd f6, 0x0(r5)
	addi r5, r5, 0x8
	addi r9, r9, 0x1
.L_803FE9BC:
	cmpw r9, r21
	ble .L_803FE7F8
	subfic r28, r19, 0x18
	neg r5, r21
	subfic r0, r19, 0x17
	slwi r4, r10, 2
	slwi r3, r22, 3
	addi r26, r1, 0x1a0
	lfd f24, lbl_805A4FD0@sda21(r0)
	mr r23, r21
	lfd f25, lbl_805A5000@sda21(r0)
	clrrwi r14, r5, 31
	lfd f26, lbl_805A4FD8@sda21(r0)
	add r27, r8, r4
	stw r0, 0x2d0(r1)
	add r26, r26, r3
	lfd f27, lbl_805A4FE8@sda21(r0)
	addi r29, r1, 0x10
	lfd f28, lbl_805A4FE0@sda21(r0)
	addi r15, r1, 0x1a0
	lfd f29, lbl_805A4FF0@sda21(r0)
	lis r30, 0x100
	lfd f30, lbl_805A4FF8@sda21(r0)
	lis r31, 0x8000
	lfd f31, lbl_805A4FC8@sda21(r0)
.L_803FEA20:
	slwi r0, r23, 3
	cmpwi cr1, r23, 0x0
	addi r3, r1, 0x60
	lfdux f1, r3, r0
	mr r4, r23
	li r5, 0x0
	li r6, 0x0
	ble cr1, .L_803FED34
	cmpwi r23, 0x8
	ble .L_803FECC4
	li r7, 0x0
	blt cr1, .L_803FEA60
	addi r0, r31, 0x1
	cmpw r23, r0
	blt .L_803FEA60
	li r7, 0x1
.L_803FEA60:
	cmpwi r7, 0x0
	beq .L_803FECC4
	subi r0, r23, 0x1
	srwi r0, r0, 3
	mtctr r0
	cmpwi r23, 0x8
	ble .L_803FECC4
.L_803FEA7C:
	fmul f0, f24, f1
	addi r0, r5, 0x1
	addi r9, r5, 0x2
	addi r8, r5, 0x3
	addi r7, r5, 0x4
	lfd f4, -0x8(r3)
	fctiwz f5, f0
	lfd f3, -0x10(r3)
	lfd f2, -0x18(r3)
	slwi r0, r0, 2
	lfd f0, -0x20(r3)
	slwi r9, r9, 2
	stfd f5, 0x250(r1)
	slwi r8, r8, 2
	slwi r7, r7, 2
	lwz r10, 0x254(r1)
	xoris r10, r10, 0x8000
	stw r10, 0x24c(r1)
	lfd f5, 0x248(r1)
	fsub f5, f5, f25
	fadd f6, f5, f4
	fmul f5, f26, f5
	fmul f4, f24, f6
	fsub f5, f1, f5
	fctiwz f1, f4
	fctiwz f4, f5
	stfd f1, 0x260(r1)
	lwz r10, 0x264(r1)
	stfd f4, 0x258(r1)
	xoris r10, r10, 0x8000
	stw r10, 0x244(r1)
	lwz r10, 0x25c(r1)
	lfd f1, 0x240(r1)
	stwx r10, r29, r6
	fsub f1, f1, f25
	fadd f4, f1, f3
	fmul f3, f26, f1
	fmul f1, f24, f4
	fsub f3, f6, f3
	fctiwz f1, f1
	fctiwz f3, f3
	stfd f1, 0x270(r1)
	lwz r10, 0x274(r1)
	stfd f3, 0x268(r1)
	xoris r10, r10, 0x8000
	stw r10, 0x24c(r1)
	lwz r10, 0x26c(r1)
	lfd f1, 0x248(r1)
	stwx r10, r29, r0
	fsub f1, f1, f25
	fadd f3, f1, f2
	fmul f2, f26, f1
	fmul f1, f24, f3
	fsub f2, f4, f2
	fctiwz f1, f1
	fctiwz f2, f2
	stfd f1, 0x280(r1)
	lwz r0, 0x284(r1)
	stfd f2, 0x278(r1)
	xoris r0, r0, 0x8000
	stw r0, 0x244(r1)
	lwz r0, 0x27c(r1)
	lfd f1, 0x240(r1)
	stwx r0, r29, r9
	fsub f1, f1, f25
	fadd f2, f1, f0
	fmul f1, f26, f1
	fmul f0, f24, f2
	fsub f1, f3, f1
	fctiwz f0, f0
	fctiwz f1, f1
	stfd f0, 0x290(r1)
	lwz r0, 0x294(r1)
	stfd f1, 0x288(r1)
	xoris r0, r0, 0x8000
	stw r0, 0x24c(r1)
	lwz r0, 0x28c(r1)
	lfd f0, 0x248(r1)
	stwx r0, r29, r8
	fsub f1, f0, f25
	fmul f0, f26, f1
	fsub f0, f2, f0
	fctiwz f0, f0
	stfd f0, 0x298(r1)
	lwz r0, 0x29c(r1)
	stwx r0, r29, r7
	lfd f0, -0x28(r3)
	addi r8, r5, 0x5
	addi r0, r5, 0x7
	addi r7, r5, 0x6
	fadd f5, f1, f0
	slwi r9, r8, 2
	slwi r8, r7, 2
	lfd f2, -0x30(r3)
	lfd f1, -0x38(r3)
	slwi r0, r0, 2
	fmul f3, f24, f5
	lfdu f0, -0x40(r3)
	addi r5, r5, 0x8
	addi r6, r6, 0x20
	subi r4, r4, 0x8
	fctiwz f3, f3
	stfd f3, 0x2a0(r1)
	lwz r7, 0x2a4(r1)
	xoris r7, r7, 0x8000
	stw r7, 0x244(r1)
	lfd f3, 0x240(r1)
	fsub f3, f3, f25
	fadd f4, f3, f2
	fmul f3, f26, f3
	fmul f2, f24, f4
	fsub f3, f5, f3
	fctiwz f2, f2
	fctiwz f3, f3
	stfd f2, 0x2b0(r1)
	lwz r7, 0x2b4(r1)
	stfd f3, 0x2a8(r1)
	xoris r7, r7, 0x8000
	stw r7, 0x24c(r1)
	lwz r7, 0x2ac(r1)
	lfd f2, 0x248(r1)
	stwx r7, r29, r9
	fsub f2, f2, f25
	fadd f3, f2, f1
	fmul f2, f26, f2
	fmul f1, f24, f3
	fsub f2, f4, f2
	fctiwz f1, f1
	fctiwz f2, f2
	stfd f1, 0x2c0(r1)
	lwz r7, 0x2c4(r1)
	stfd f2, 0x2b8(r1)
	xoris r7, r7, 0x8000
	stw r7, 0x244(r1)
	lwz r7, 0x2bc(r1)
	lfd f1, 0x240(r1)
	stwx r7, r29, r8
	fsub f1, f1, f25
	fmul f2, f26, f1
	fadd f1, f1, f0
	fsub f0, f3, f2
	fctiwz f0, f0
	stfd f0, 0x2c8(r1)
	lwz r7, 0x2cc(r1)
	stwx r7, r29, r0
	bdnz .L_803FEA7C
.L_803FECC4:
	slwi r3, r5, 2
	addi r5, r1, 0x10
	slwi r0, r4, 3
	addi r6, r1, 0x60
	add r5, r5, r3
	add r6, r6, r0
	mtctr r4
	cmpwi r4, 0x0
	ble .L_803FED34
.L_803FECE8:
	fmul f2, f24, f1
	lfdu f0, -0x8(r6)
	subi r4, r4, 0x1
	fctiwz f2, f2
	stfd f2, 0x2c8(r1)
	lwz r0, 0x2cc(r1)
	xoris r0, r0, 0x8000
	stw r0, 0x24c(r1)
	lfd f2, 0x248(r1)
	fsub f3, f2, f25
	fmul f2, f26, f3
	fsub f2, f1, f2
	fadd f1, f3, f0
	fctiwz f0, f2
	stfd f0, 0x2c0(r1)
	lwz r0, 0x2c4(r1)
	stw r0, 0x0(r5)
	addi r5, r5, 0x4
	bdnz .L_803FECE8
.L_803FED34:
	mr r3, r19
	bl fn_803FC9BC
	fmr f23, f1
	fmul f1, f27, f1
	bl fn_804005AC
	fmul f0, f28, f1
	cmpwi r19, 0x0
	li r18, 0x0
	fsub f23, f23, f0
	fctiwz f0, f23
	stfd f0, 0x2c8(r1)
	lwz r20, 0x2cc(r1)
	xoris r0, r20, 0x8000
	stw r0, 0x244(r1)
	lfd f0, 0x240(r1)
	fsub f0, f0, f25
	fsub f23, f23, f0
	ble .L_803FEDA8
	slwi r0, r23, 2
	add r4, r29, r0
	lwz r3, -0x4(r4)
	sraw r5, r3, r28
	slw r0, r5, r28
	subf r3, r0, r3
	lwz r0, 0x2d0(r1)
	stw r3, -0x4(r4)
	add r20, r20, r5
	sraw r18, r3, r0
	b .L_803FEDD0
.L_803FEDA8:
	bne .L_803FEDC0
	slwi r0, r23, 2
	add r3, r29, r0
	lwz r0, -0x4(r3)
	srawi r18, r0, 23
	b .L_803FEDD0
.L_803FEDC0:
	fcmpo cr0, f23, f29
	cror eq, gt, eq
	bne .L_803FEDD0
	li r18, 0x2
.L_803FEDD0:
	cmpwi r18, 0x0
	ble .L_803FEE98
	addi r5, r1, 0x10
	subi r4, r30, 0x1
	li r0, 0x0
	mtctr r23
	cmpwi r23, 0x0
	addi r20, r20, 0x1
	ble .L_803FEE28
.L_803FEDF4:
	cmpwi r0, 0x0
	lwz r3, 0x0(r5)
	bne .L_803FEE18
	cmpwi r3, 0x0
	beq .L_803FEE20
	subf r3, r3, r30
	li r0, 0x1
	stw r3, 0x0(r5)
	b .L_803FEE20
.L_803FEE18:
	subf r3, r3, r4
	stw r3, 0x0(r5)
.L_803FEE20:
	addi r5, r5, 0x4
	bdnz .L_803FEDF4
.L_803FEE28:
	cmpwi r19, 0x0
	ble .L_803FEE74
	cmpwi r19, 0x2
	beq .L_803FEE60
	bge .L_803FEE74
	cmpwi r19, 0x1
	bge .L_803FEE48
	b .L_803FEE74
.L_803FEE48:
	slwi r3, r23, 2
	add r4, r29, r3
	lwz r3, -0x4(r4)
	clrlwi r3, r3, 9
	stw r3, -0x4(r4)
	b .L_803FEE74
.L_803FEE60:
	slwi r3, r23, 2
	add r4, r29, r3
	lwz r3, -0x4(r4)
	clrlwi r3, r3, 10
	stw r3, -0x4(r4)
.L_803FEE74:
	cmpwi r18, 0x2
	bne .L_803FEE98
	cmpwi r0, 0x0
	fsub f23, f30, f23
	beq .L_803FEE98
	fmr f1, f30
	mr r3, r19
	bl fn_803FC9BC
	fsub f23, f23, f1
.L_803FEE98:
	fcmpu cr0, f31, f23
	bne .L_803FF270
	subi r10, r23, 0x1
	li r9, 0x0
	cmpw cr1, r10, r21
	blt cr1, .L_803FF030
	subf r7, r21, r10
	addi r0, r21, 0x8
	addi r8, r7, 0x1
	cmpwi r8, 0x8
	ble .L_803FEFFC
	li r3, 0x0
	li r4, 0x0
	li r5, 0x0
	li r6, 0x0
	li r12, 0x0
	blt cr1, .L_803FEEEC
	addi r11, r31, 0x1
	cmpw r21, r11
	blt .L_803FEEEC
	li r12, 0x1
.L_803FEEEC:
	cmpwi r12, 0x0
	beq .L_803FEF08
	subi r12, r23, 0x1
	addi r11, r31, 0x1
	cmpw r12, r11
	blt .L_803FEF08
	li r6, 0x1
.L_803FEF08:
	cmpwi r6, 0x0
	beq .L_803FEF20
	addis r6, r21, 0x8000
	cmplwi r6, 0x0
	beq .L_803FEF20
	li r5, 0x1
.L_803FEF20:
	cmpwi r5, 0x0
	beq .L_803FEF58
	subi r5, r23, 0x1
	li r6, 0x1
	clrrwi r11, r5, 31
	cmpw r11, r14
	bne .L_803FEF4C
	clrrwi r5, r7, 31
	cmpw r11, r5
	beq .L_803FEF4C
	li r6, 0x0
.L_803FEF4C:
	cmpwi r6, 0x0
	beq .L_803FEF58
	li r4, 0x1
.L_803FEF58:
	cmpwi r4, 0x0
	beq .L_803FEF84
	clrrwi. r4, r7, 31
	li r5, 0x1
	bne .L_803FEF78
	clrrwi. r4, r8, 31
	beq .L_803FEF78
	li r5, 0x0
.L_803FEF78:
	cmpwi r5, 0x0
	beq .L_803FEF84
	li r3, 0x1
.L_803FEF84:
	cmpwi r3, 0x0
	beq .L_803FEFFC
	addi r4, r10, 0x8
	slwi r5, r10, 2
	subf r4, r0, r4
	addi r3, r1, 0x10
	srwi r4, r4, 3
	add r3, r3, r5
	mtctr r4
	cmpw r10, r0
	blt .L_803FEFFC
.L_803FEFB0:
	lwz r4, 0x0(r3)
	subi r10, r10, 0x8
	lwz r0, -0x4(r3)
	or r9, r9, r4
	lwz r4, -0x8(r3)
	or r9, r9, r0
	lwz r0, -0xc(r3)
	or r9, r9, r4
	lwz r4, -0x10(r3)
	or r9, r9, r0
	lwz r0, -0x14(r3)
	or r9, r9, r4
	lwz r4, -0x18(r3)
	or r9, r9, r0
	lwz r0, -0x1c(r3)
	or r9, r9, r4
	subi r3, r3, 0x20
	or r9, r9, r0
	bdnz .L_803FEFB0
.L_803FEFFC:
	addi r0, r10, 0x1
	slwi r3, r10, 2
	addi r4, r1, 0x10
	subf r0, r21, r0
	add r4, r4, r3
	mtctr r0
	cmpw r10, r21
	blt .L_803FF030
.L_803FF01C:
	lwz r0, 0x0(r4)
	subi r4, r4, 0x4
	subi r10, r10, 0x1
	or r9, r9, r0
	bdnz .L_803FF01C
.L_803FF030:
	cmpwi r9, 0x0
	bne .L_803FF270
	li r18, 0x1
	b .L_803FF044
.L_803FF040:
	addi r18, r18, 0x1
.L_803FF044:
	subf r0, r18, r21
	slwi r0, r0, 2
	lwzx r0, r29, r0
	cmpwi r0, 0x0
	beq .L_803FF040
	addi r12, r23, 0x1
	addi r7, r1, 0x60
	slwi r3, r12, 3
	add r8, r23, r18
	slwi r0, r12, 2
	add r5, r27, r0
	add r6, r26, r3
	add r7, r7, r3
	b .L_803FF260
.L_803FF07C:
	lwz r0, 0x0(r5)
	cmpwi cr1, r22, 0x0
	lfd f0, lbl_805A4FC8@sda21(r0)
	li r11, 0x0
	xoris r0, r0, 0x8000
	stw r0, 0x24c(r1)
	lfd f1, 0x248(r1)
	fsub f1, f1, f25
	stfd f1, 0x0(r6)
	blt cr1, .L_803FF24C
	addi r0, r22, 0x1
	subi r3, r22, 0x8
	cmpwi r0, 0x8
	ble .L_803FF208
	li r4, 0x0
	li r9, 0x0
	blt cr1, .L_803FF0D0
	subi r0, r31, 0x2
	cmpw r22, r0
	bgt .L_803FF0D0
	li r9, 0x1
.L_803FF0D0:
	cmpwi r9, 0x0
	beq .L_803FF0FC
	cmpwi r25, 0x0
	li r0, 0x1
	bne .L_803FF0F0
	cmpwi r24, 0x0
	beq .L_803FF0F0
	li r0, 0x0
.L_803FF0F0:
	cmpwi r0, 0x0
	beq .L_803FF0FC
	li r4, 0x1
.L_803FF0FC:
	cmpwi r4, 0x0
	beq .L_803FF208
	addi r0, r3, 0x8
	mr r9, r16
	srwi r0, r0, 3
	add r10, r22, r12
	mtctr r0
	cmpwi r3, 0x0
	blt .L_803FF208
.L_803FF120:
	subf r0, r11, r10
	addi r4, r11, 0x1
	slwi r0, r0, 3
	addi r3, r11, 0x2
	lfd f2, 0x0(r9)
	subf r3, r3, r10
	lfdx f1, r15, r0
	subf r4, r4, r10
	slwi r0, r4, 3
	addi r20, r11, 0x7
	fmul f3, f2, f1
	lfd f2, 0x8(r9)
	lfdx f1, r15, r0
	addi r4, r11, 0x3
	slwi r3, r3, 3
	subf r20, r20, r10
	fmul f4, f2, f1
	subf r0, r4, r10
	lfdx f1, r15, r3
	addi r4, r11, 0x4
	fadd f0, f0, f3
	lfd f2, 0x10(r9)
	fmul f3, f2, f1
	slwi r0, r0, 3
	lfdx f1, r15, r0
	subf r4, r4, r10
	fadd f0, f0, f4
	lfd f2, 0x18(r9)
	addi r3, r11, 0x5
	addi r0, r11, 0x6
	fadd f0, f0, f3
	subf r3, r3, r10
	fmul f2, f2, f1
	slwi r4, r4, 3
	subf r0, r0, r10
	lfd f3, 0x20(r9)
	lfdx f1, r15, r4
	slwi r3, r3, 3
	fmul f6, f3, f1
	slwi r0, r0, 3
	lfdx f1, r15, r3
	slwi r20, r20, 3
	fadd f0, f0, f2
	lfd f2, 0x28(r9)
	fmul f5, f2, f1
	lfd f4, 0x30(r9)
	lfdx f3, r15, r0
	addi r11, r11, 0x8
	fadd f0, f0, f6
	lfd f2, 0x38(r9)
	lfdx f1, r15, r20
	fmul f3, f4, f3
	addi r9, r9, 0x40
	fadd f0, f0, f5
	fmul f1, f2, f1
	fadd f0, f0, f3
	fadd f0, f0, f1
	bdnz .L_803FF120
.L_803FF208:
	addi r4, r22, 0x1
	slwi r3, r11, 3
	subf r4, r11, r4
	add r0, r22, r12
	add r3, r16, r3
	mtctr r4
	cmpw r11, r22
	bgt .L_803FF24C
.L_803FF228:
	subf r4, r11, r0
	lfd f2, 0x0(r3)
	slwi r4, r4, 3
	addi r3, r3, 0x8
	lfdx f1, r15, r4
	addi r11, r11, 0x1
	fmul f1, f2, f1
	fadd f0, f0, f1
	bdnz .L_803FF228
.L_803FF24C:
	stfd f0, 0x0(r7)
	addi r5, r5, 0x4
	addi r6, r6, 0x8
	addi r7, r7, 0x8
	addi r12, r12, 0x1
.L_803FF260:
	cmpw r12, r8
	ble .L_803FF07C
	add r23, r23, r18
	b .L_803FEA20
.L_803FF270:
	lfd f0, lbl_805A4FC8@sda21(r0)
	fcmpu cr0, f0, f23
	bne .L_803FF2B0
	subi r23, r23, 0x1
	addi r3, r1, 0x10
	slwi r0, r23, 2
	subi r19, r19, 0x18
	add r3, r3, r0
	b .L_803FF2A0
.L_803FF294:
	subi r3, r3, 0x4
	subi r23, r23, 0x1
	subi r19, r19, 0x18
.L_803FF2A0:
	lwz r0, 0x0(r3)
	cmpwi r0, 0x0
	beq .L_803FF294
	b .L_803FF34C
.L_803FF2B0:
	fmr f1, f23
	neg r3, r19
	bl fn_803FC9BC
	lfd f3, lbl_805A4FD8@sda21(r0)
	fcmpo cr0, f1, f3
	cror eq, gt, eq
	bne .L_803FF334
	lfd f0, lbl_805A4FD0@sda21(r0)
	slwi r5, r23, 2
	addi r23, r23, 0x1
	lfd f2, lbl_805A5000@sda21(r0)
	fmul f0, f0, f1
	addi r4, r1, 0x10
	slwi r0, r23, 2
	addi r19, r19, 0x18
	fctiwz f0, f0
	stfd f0, 0x2c8(r1)
	lwz r3, 0x2cc(r1)
	xoris r3, r3, 0x8000
	stw r3, 0x244(r1)
	lfd f0, 0x240(r1)
	fsub f0, f0, f2
	fmul f2, f3, f0
	fctiwz f0, f0
	fsub f1, f1, f2
	stfd f0, 0x2b8(r1)
	fctiwz f0, f1
	lwz r3, 0x2bc(r1)
	stfd f0, 0x2c0(r1)
	lwz r6, 0x2c4(r1)
	stwx r6, r4, r5
	stwx r3, r4, r0
	b .L_803FF34C
.L_803FF334:
	fctiwz f0, f1
	slwi r0, r23, 2
	addi r3, r1, 0x10
	stfd f0, 0x2c8(r1)
	lwz r4, 0x2cc(r1)
	stwx r4, r3, r0
.L_803FF34C:
	lfd f1, lbl_805A4FF8@sda21(r0)
	mr r3, r19
	bl fn_803FC9BC
	cmpwi cr1, r23, 0x0
	mr r3, r23
	blt cr1, .L_803FF564
	addi r0, r23, 0x1
	cmpwi r0, 0x8
	ble .L_803FF508
	li r5, 0x0
	li r6, 0x0
	blt cr1, .L_803FF390
	lis r4, 0x8000
	addi r0, r4, 0x1
	cmpw r23, r0
	blt .L_803FF390
	li r6, 0x1
.L_803FF390:
	cmpwi r6, 0x0
	beq .L_803FF3C0
	clrrwi. r0, r23, 31
	li r4, 0x1
	bne .L_803FF3B4
	addi r0, r23, 0x1
	clrrwi. r0, r0, 31
	beq .L_803FF3B4
	li r4, 0x0
.L_803FF3B4:
	cmpwi r4, 0x0
	beq .L_803FF3C0
	li r5, 0x1
.L_803FF3C0:
	cmpwi r5, 0x0
	beq .L_803FF508
	slwi r5, r23, 2
	addi r6, r1, 0x10
	slwi r4, r23, 3
	addi r7, r1, 0x60
	srwi r0, r23, 3
	add r6, r6, r5
	add r7, r7, r4
	lfd f10, lbl_805A5000@sda21(r0)
	lfd f8, lbl_805A4FD0@sda21(r0)
	mtctr r0
	cmpwi r23, 0x8
	blt .L_803FF508
.L_803FF3F8:
	lwz r4, 0x0(r6)
	subi r3, r3, 0x8
	lwz r0, -0x4(r6)
	xoris r5, r4, 0x8000
	lwz r4, -0x8(r6)
	stw r5, 0x24c(r1)
	xoris r5, r0, 0x8000
	xoris r4, r4, 0x8000
	lwz r0, -0xc(r6)
	lfd f0, 0x248(r1)
	stw r5, 0x244(r1)
	xoris r5, r0, 0x8000
	fsub f0, f0, f10
	lwz r0, -0x10(r6)
	lfd f2, 0x240(r1)
	stw r4, 0x24c(r1)
	xoris r4, r0, 0x8000
	fmul f9, f1, f0
	lfd f0, 0x248(r1)
	fmul f1, f1, f8
	stw r5, 0x244(r1)
	lwz r0, -0x14(r6)
	fsub f2, f2, f10
	fsub f3, f0, f10
	lfd f0, 0x240(r1)
	fmul f7, f1, f2
	stw r4, 0x24c(r1)
	xoris r5, r0, 0x8000
	lwz r4, -0x18(r6)
	fmul f1, f1, f8
	lwz r0, -0x1c(r6)
	lfd f2, 0x248(r1)
	fsub f5, f0, f10
	fmul f6, f1, f3
	stw r5, 0x244(r1)
	xoris r4, r4, 0x8000
	xoris r0, r0, 0x8000
	lfd f0, 0x240(r1)
	fmul f1, f1, f8
	stfd f9, 0x0(r7)
	fsub f4, f2, f10
	fsub f3, f0, f10
	subi r6, r6, 0x20
	fmul f5, f1, f5
	stw r4, 0x24c(r1)
	fmul f1, f1, f8
	lfd f0, 0x248(r1)
	stfd f7, -0x8(r7)
	fsub f2, f0, f10
	fmul f4, f1, f4
	stw r0, 0x244(r1)
	fmul f1, f1, f8
	stfd f6, -0x10(r7)
	lfd f0, 0x240(r1)
	stfd f5, -0x18(r7)
	fsub f0, f0, f10
	fmul f3, f1, f3
	stfd f4, -0x20(r7)
	fmul f1, f1, f8
	stfd f3, -0x28(r7)
	fmul f2, f1, f2
	fmul f1, f1, f8
	stfd f2, -0x30(r7)
	fmul f0, f1, f0
	fmul f1, f1, f8
	stfd f0, -0x38(r7)
	subi r7, r7, 0x40
	bdnz .L_803FF3F8
.L_803FF508:
	slwi r5, r3, 2
	addi r6, r1, 0x10
	slwi r4, r3, 3
	addi r7, r1, 0x60
	addi r0, r3, 0x1
	add r6, r6, r5
	add r7, r7, r4
	lfd f3, lbl_805A5000@sda21(r0)
	lfd f0, lbl_805A4FD0@sda21(r0)
	mtctr r0
	cmpwi r3, 0x0
	blt .L_803FF564
.L_803FF538:
	lwz r0, 0x0(r6)
	subi r6, r6, 0x4
	xoris r0, r0, 0x8000
	stw r0, 0x24c(r1)
	lfd f2, 0x248(r1)
	fsub f2, f2, f3
	fmul f2, f1, f2
	fmul f1, f1, f0
	stfd f2, 0x0(r7)
	subi r7, r7, 0x8
	bdnz .L_803FF538
.L_803FF564:
	addi r0, r23, 0x1
	mr r8, r23
	addi r4, r1, 0x100
	slwi r3, r23, 3
	lis r5, lbl_80420328@ha
	mtctr r0
	cmpwi r23, 0x0
	blt .L_803FF5E0
.L_803FF584:
	addi r6, r1, 0x60
	lfd f2, lbl_805A4FC8@sda21(r0)
	add r6, r6, r3
	addi r7, r5, lbl_80420328@l
	subf r0, r8, r23
	li r9, 0x0
	b .L_803FF5BC
.L_803FF5A0:
	lfd f1, 0x0(r7)
	addi r7, r7, 0x8
	lfd f0, 0x0(r6)
	addi r6, r6, 0x8
	addi r9, r9, 0x1
	fmul f0, f1, f0
	fadd f2, f2, f0
.L_803FF5BC:
	cmpw r9, r21
	bgt .L_803FF5CC
	cmpw r9, r0
	ble .L_803FF5A0
.L_803FF5CC:
	slwi r0, r0, 3
	subi r3, r3, 0x8
	stfdx f2, r4, r0
	subi r8, r8, 0x1
	bdnz .L_803FF584
.L_803FF5E0:
	lwz r0, 0x8(r1)
	cmpwi r0, 0x3
	beq .L_803FF9A0
	bge .L_803FFDF4
	cmpwi r0, 0x0
	beq .L_803FF600
	bge .L_803FF71C
	b .L_803FFDF4
.L_803FF600:
	cmpwi cr1, r23, 0x0
	lfd f6, lbl_805A4FC8@sda21(r0)
	blt cr1, .L_803FF704
	addi r0, r23, 0x1
	cmpwi r0, 0x8
	ble .L_803FF6D8
	li r4, 0x0
	li r5, 0x0
	blt cr1, .L_803FF638
	lis r3, 0x8000
	addi r0, r3, 0x1
	cmpw r23, r0
	blt .L_803FF638
	li r5, 0x1
.L_803FF638:
	cmpwi r5, 0x0
	beq .L_803FF668
	clrrwi. r0, r23, 31
	li r3, 0x1
	bne .L_803FF65C
	addi r0, r23, 0x1
	clrrwi. r0, r0, 31
	beq .L_803FF65C
	li r3, 0x0
.L_803FF65C:
	cmpwi r3, 0x0
	beq .L_803FF668
	li r4, 0x1
.L_803FF668:
	cmpwi r4, 0x0
	beq .L_803FF6D8
	slwi r3, r23, 3
	addi r4, r1, 0x100
	srwi r0, r23, 3
	add r4, r4, r3
	mtctr r0
	cmpwi r23, 0x8
	blt .L_803FF6D8
.L_803FF68C:
	lfd f1, 0x0(r4)
	subi r23, r23, 0x8
	lfd f0, -0x8(r4)
	fadd f6, f6, f1
	lfd f5, -0x10(r4)
	lfd f4, -0x18(r4)
	lfd f3, -0x20(r4)
	fadd f6, f6, f0
	lfd f2, -0x28(r4)
	lfd f1, -0x30(r4)
	lfd f0, -0x38(r4)
	subi r4, r4, 0x40
	fadd f6, f6, f5
	fadd f6, f6, f4
	fadd f6, f6, f3
	fadd f6, f6, f2
	fadd f6, f6, f1
	fadd f6, f6, f0
	bdnz .L_803FF68C
.L_803FF6D8:
	slwi r3, r23, 3
	addi r4, r1, 0x100
	addi r0, r23, 0x1
	add r4, r4, r3
	mtctr r0
	cmpwi r23, 0x0
	blt .L_803FF704
.L_803FF6F4:
	lfd f0, 0x0(r4)
	subi r4, r4, 0x8
	fadd f6, f6, f0
	bdnz .L_803FF6F4
.L_803FF704:
	cmpwi r18, 0x0
	bne .L_803FF710
	b .L_803FF714
.L_803FF710:
	fneg f6, f6
.L_803FF714:
	stfd f6, 0x0(r17)
	b .L_803FFDF4
.L_803FF71C:
	cmpwi cr1, r23, 0x0
	lfd f6, lbl_805A4FC8@sda21(r0)
	mr r6, r23
	blt cr1, .L_803FF824
	addi r0, r23, 0x1
	cmpwi r0, 0x8
	ble .L_803FF7F8
	li r4, 0x0
	li r5, 0x0
	blt cr1, .L_803FF758
	lis r3, 0x8000
	addi r0, r3, 0x1
	cmpw r23, r0
	blt .L_803FF758
	li r5, 0x1
.L_803FF758:
	cmpwi r5, 0x0
	beq .L_803FF788
	clrrwi. r0, r23, 31
	li r3, 0x1
	bne .L_803FF77C
	addi r0, r23, 0x1
	clrrwi. r0, r0, 31
	beq .L_803FF77C
	li r3, 0x0
.L_803FF77C:
	cmpwi r3, 0x0
	beq .L_803FF788
	li r4, 0x1
.L_803FF788:
	cmpwi r4, 0x0
	beq .L_803FF7F8
	slwi r3, r23, 3
	addi r4, r1, 0x100
	srwi r0, r23, 3
	add r4, r4, r3
	mtctr r0
	cmpwi r23, 0x8
	blt .L_803FF7F8
.L_803FF7AC:
	lfd f1, 0x0(r4)
	subi r6, r6, 0x8
	lfd f0, -0x8(r4)
	fadd f6, f6, f1
	lfd f5, -0x10(r4)
	lfd f4, -0x18(r4)
	lfd f3, -0x20(r4)
	fadd f6, f6, f0
	lfd f2, -0x28(r4)
	lfd f1, -0x30(r4)
	lfd f0, -0x38(r4)
	subi r4, r4, 0x40
	fadd f6, f6, f5
	fadd f6, f6, f4
	fadd f6, f6, f3
	fadd f6, f6, f2
	fadd f6, f6, f1
	fadd f6, f6, f0
	bdnz .L_803FF7AC
.L_803FF7F8:
	slwi r3, r6, 3
	addi r4, r1, 0x100
	addi r0, r6, 0x1
	add r4, r4, r3
	mtctr r0
	cmpwi r6, 0x0
	blt .L_803FF824
.L_803FF814:
	lfd f0, 0x0(r4)
	subi r4, r4, 0x8
	fadd f6, f6, f0
	bdnz .L_803FF814
.L_803FF824:
	cmpwi r18, 0x0
	bne .L_803FF834
	fmr f1, f6
	b .L_803FF838
.L_803FF834:
	fneg f1, f6
.L_803FF838:
	lfd f0, 0x100(r1)
	cmpwi cr1, r23, 0x1
	stfd f1, 0x0(r17)
	li r8, 0x1
	fsub f6, f0, f6
	blt cr1, .L_803FF988
	cmpwi r23, 0x8
	subi r4, r23, 0x8
	ble .L_803FF958
	li r5, 0x0
	li r6, 0x0
	li r7, 0x0
	blt cr1, .L_803FF880
	lis r3, 0x8000
	subi r0, r3, 0x2
	cmpw r23, r0
	bgt .L_803FF880
	li r7, 0x1
.L_803FF880:
	cmpwi r7, 0x0
	beq .L_803FF8BC
	clrrwi r7, r23, 31
	li r3, 0x1
	addis r0, r7, 0x8000
	cmplwi r0, 0x0
	bne .L_803FF8B0
	subi r0, r23, 0x1
	clrrwi r0, r0, 31
	cmpw r7, r0
	beq .L_803FF8B0
	li r3, 0x0
.L_803FF8B0:
	cmpwi r3, 0x0
	beq .L_803FF8BC
	li r6, 0x1
.L_803FF8BC:
	cmpwi r6, 0x0
	beq .L_803FF8EC
	subi r0, r23, 0x1
	li r3, 0x1
	clrrwi. r0, r0, 31
	bne .L_803FF8E0
	clrrwi. r0, r23, 31
	beq .L_803FF8E0
	li r3, 0x0
.L_803FF8E0:
	cmpwi r3, 0x0
	beq .L_803FF8EC
	li r5, 0x1
.L_803FF8EC:
	cmpwi r5, 0x0
	beq .L_803FF958
	addi r0, r4, 0x7
	addi r3, r1, 0x108
	srwi r0, r0, 3
	mtctr r0
	cmpwi r4, 0x1
	blt .L_803FF958
.L_803FF90C:
	lfd f1, 0x0(r3)
	addi r8, r8, 0x8
	lfd f0, 0x8(r3)
	fadd f6, f6, f1
	lfd f5, 0x10(r3)
	lfd f4, 0x18(r3)
	lfd f3, 0x20(r3)
	fadd f6, f6, f0
	lfd f2, 0x28(r3)
	lfd f1, 0x30(r3)
	lfd f0, 0x38(r3)
	addi r3, r3, 0x40
	fadd f6, f6, f5
	fadd f6, f6, f4
	fadd f6, f6, f3
	fadd f6, f6, f2
	fadd f6, f6, f1
	fadd f6, f6, f0
	bdnz .L_803FF90C
.L_803FF958:
	addi r0, r23, 0x1
	slwi r3, r8, 3
	addi r4, r1, 0x100
	subf r0, r8, r0
	add r4, r4, r3
	mtctr r0
	cmpw r8, r23
	bgt .L_803FF988
.L_803FF978:
	lfd f0, 0x0(r4)
	addi r4, r4, 0x8
	fadd f6, f6, f0
	bdnz .L_803FF978
.L_803FF988:
	cmpwi r18, 0x0
	bne .L_803FF994
	b .L_803FF998
.L_803FF994:
	fneg f6, f6
.L_803FF998:
	stfd f6, 0x8(r17)
	b .L_803FFDF4
.L_803FF9A0:
	cmpwi cr1, r23, 0x0
	mr r5, r23
	ble cr1, .L_803FFAE0
	cmpwi r23, 0x8
	ble .L_803FFAA8
	li r4, 0x0
	blt cr1, .L_803FF9D0
	lis r3, 0x8000
	addi r0, r3, 0x1
	cmpw r23, r0
	blt .L_803FF9D0
	li r4, 0x1
.L_803FF9D0:
	cmpwi r4, 0x0
	beq .L_803FFAA8
	subi r0, r23, 0x1
	slwi r3, r23, 3
	addi r4, r1, 0x100
	srwi r0, r0, 3
	add r4, r4, r3
	mtctr r0
	cmpwi r23, 0x8
	ble .L_803FFAA8
.L_803FF9F8:
	lfd f0, -0x8(r4)
	subi r5, r5, 0x8
	lfd f1, 0x0(r4)
	fadd f2, f0, f1
	fsub f0, f0, f2
	fadd f0, f1, f0
	stfd f0, 0x0(r4)
	lfd f0, -0x10(r4)
	fadd f1, f0, f2
	fsub f0, f0, f1
	fadd f0, f2, f0
	stfd f0, -0x8(r4)
	lfd f0, -0x18(r4)
	fadd f2, f0, f1
	fsub f0, f0, f2
	fadd f0, f1, f0
	stfd f0, -0x10(r4)
	lfd f0, -0x20(r4)
	fadd f1, f0, f2
	fsub f0, f0, f1
	fadd f0, f2, f0
	stfd f0, -0x18(r4)
	lfd f0, -0x28(r4)
	fadd f2, f0, f1
	fsub f0, f0, f2
	fadd f0, f1, f0
	stfd f0, -0x20(r4)
	lfd f0, -0x30(r4)
	fadd f1, f0, f2
	fsub f0, f0, f1
	fadd f0, f2, f0
	stfd f0, -0x28(r4)
	lfd f0, -0x38(r4)
	fadd f2, f0, f1
	fsub f0, f0, f2
	fadd f0, f1, f0
	stfd f0, -0x30(r4)
	lfd f0, -0x40(r4)
	fadd f1, f0, f2
	fsub f0, f0, f1
	fadd f0, f2, f0
	stfd f0, -0x38(r4)
	stfdu f1, -0x40(r4)
	bdnz .L_803FF9F8
.L_803FFAA8:
	slwi r0, r5, 3
	addi r3, r1, 0x100
	add r3, r3, r0
	mtctr r5
	cmpwi r5, 0x0
	ble .L_803FFAE0
.L_803FFAC0:
	lfd f0, -0x8(r3)
	lfd f1, 0x0(r3)
	fadd f2, f0, f1
	fsub f0, f0, f2
	fadd f0, f1, f0
	stfd f0, 0x0(r3)
	stfdu f2, -0x8(r3)
	bdnz .L_803FFAC0
.L_803FFAE0:
	cmpwi cr1, r23, 0x1
	mr r6, r23
	ble cr1, .L_803FFC68
	subi r0, r23, 0x1
	cmpwi r0, 0x8
	ble .L_803FFC2C
	li r4, 0x0
	li r5, 0x0
	blt cr1, .L_803FFB18
	lis r3, 0x8000
	addi r0, r3, 0x1
	cmpw r23, r0
	blt .L_803FFB18
	li r5, 0x1
.L_803FFB18:
	cmpwi r5, 0x0
	beq .L_803FFB54
	clrrwi r5, r23, 31
	li r3, 0x1
	addis r0, r5, 0x8000
	cmplwi r0, 0x0
	bne .L_803FFB48
	subi r0, r23, 0x1
	clrrwi r0, r0, 31
	cmpw r5, r0
	beq .L_803FFB48
	li r3, 0x0
.L_803FFB48:
	cmpwi r3, 0x0
	beq .L_803FFB54
	li r4, 0x1
.L_803FFB54:
	cmpwi r4, 0x0
	beq .L_803FFC2C
	subi r0, r23, 0x2
	slwi r3, r23, 3
	addi r4, r1, 0x100
	srwi r0, r0, 3
	add r4, r4, r3
	mtctr r0
	cmpwi r23, 0x9
	ble .L_803FFC2C
.L_803FFB7C:
	lfd f0, -0x8(r4)
	subi r6, r6, 0x8
	lfd f1, 0x0(r4)
	fadd f2, f0, f1
	fsub f0, f0, f2
	fadd f0, f1, f0
	stfd f0, 0x0(r4)
	lfd f0, -0x10(r4)
	fadd f1, f0, f2
	fsub f0, f0, f1
	fadd f0, f2, f0
	stfd f0, -0x8(r4)
	lfd f0, -0x18(r4)
	fadd f2, f0, f1
	fsub f0, f0, f2
	fadd f0, f1, f0
	stfd f0, -0x10(r4)
	lfd f0, -0x20(r4)
	fadd f1, f0, f2
	fsub f0, f0, f1
	fadd f0, f2, f0
	stfd f0, -0x18(r4)
	lfd f0, -0x28(r4)
	fadd f2, f0, f1
	fsub f0, f0, f2
	fadd f0, f1, f0
	stfd f0, -0x20(r4)
	lfd f0, -0x30(r4)
	fadd f1, f0, f2
	fsub f0, f0, f1
	fadd f0, f2, f0
	stfd f0, -0x28(r4)
	lfd f0, -0x38(r4)
	fadd f2, f0, f1
	fsub f0, f0, f2
	fadd f0, f1, f0
	stfd f0, -0x30(r4)
	lfd f0, -0x40(r4)
	fadd f1, f0, f2
	fsub f0, f0, f1
	fadd f0, f2, f0
	stfd f0, -0x38(r4)
	stfdu f1, -0x40(r4)
	bdnz .L_803FFB7C
.L_803FFC2C:
	slwi r3, r6, 3
	addi r4, r1, 0x100
	subi r0, r6, 0x1
	add r4, r4, r3
	mtctr r0
	cmpwi r6, 0x1
	ble .L_803FFC68
.L_803FFC48:
	lfd f0, -0x8(r4)
	lfd f1, 0x0(r4)
	fadd f2, f0, f1
	fsub f0, f0, f2
	fadd f0, f1, f0
	stfd f0, 0x0(r4)
	stfdu f2, -0x8(r4)
	bdnz .L_803FFC48
.L_803FFC68:
	cmpwi cr1, r23, 0x2
	lfd f6, lbl_805A4FC8@sda21(r0)
	blt cr1, .L_803FFDB4
	subi r0, r23, 0x1
	cmpwi r0, 0x8
	ble .L_803FFD88
	li r4, 0x0
	li r5, 0x0
	li r6, 0x0
	blt cr1, .L_803FFCA4
	lis r3, 0x8000
	addi r0, r3, 0x1
	cmpw r23, r0
	blt .L_803FFCA4
	li r6, 0x1
.L_803FFCA4:
	cmpwi r6, 0x0
	beq .L_803FFCE0
	clrrwi r6, r23, 31
	li r3, 0x1
	addis r0, r6, 0x8000
	cmplwi r0, 0x0
	bne .L_803FFCD4
	subi r0, r23, 0x2
	clrrwi r0, r0, 31
	cmpw r6, r0
	beq .L_803FFCD4
	li r3, 0x0
.L_803FFCD4:
	cmpwi r3, 0x0
	beq .L_803FFCE0
	li r5, 0x1
.L_803FFCE0:
	cmpwi r5, 0x0
	beq .L_803FFD14
	subi r0, r23, 0x2
	li r3, 0x1
	clrrwi. r0, r0, 31
	bne .L_803FFD08
	subi r0, r23, 0x1
	clrrwi. r0, r0, 31
	beq .L_803FFD08
	li r3, 0x0
.L_803FFD08:
	cmpwi r3, 0x0
	beq .L_803FFD14
	li r4, 0x1
.L_803FFD14:
	cmpwi r4, 0x0
	beq .L_803FFD88
	subi r0, r23, 0x2
	slwi r3, r23, 3
	addi r4, r1, 0x100
	srwi r0, r0, 3
	add r4, r4, r3
	mtctr r0
	cmpwi r23, 0xa
	blt .L_803FFD88
.L_803FFD3C:
	lfd f1, 0x0(r4)
	subi r23, r23, 0x8
	lfd f0, -0x8(r4)
	fadd f6, f6, f1
	lfd f5, -0x10(r4)
	lfd f4, -0x18(r4)
	lfd f3, -0x20(r4)
	fadd f6, f6, f0
	lfd f2, -0x28(r4)
	lfd f1, -0x30(r4)
	lfd f0, -0x38(r4)
	subi r4, r4, 0x40
	fadd f6, f6, f5
	fadd f6, f6, f4
	fadd f6, f6, f3
	fadd f6, f6, f2
	fadd f6, f6, f1
	fadd f6, f6, f0
	bdnz .L_803FFD3C
.L_803FFD88:
	slwi r3, r23, 3
	addi r4, r1, 0x100
	subi r0, r23, 0x1
	add r4, r4, r3
	mtctr r0
	cmpwi r23, 0x2
	blt .L_803FFDB4
.L_803FFDA4:
	lfd f0, 0x0(r4)
	subi r4, r4, 0x8
	fadd f6, f6, f0
	bdnz .L_803FFDA4
.L_803FFDB4:
	cmpwi r18, 0x0
	bne .L_803FFDD4
	lfd f1, 0x100(r1)
	lfd f0, 0x108(r1)
	stfd f1, 0x0(r17)
	stfd f0, 0x8(r17)
	stfd f6, 0x10(r17)
	b .L_803FFDF4
.L_803FFDD4:
	lfd f2, 0x100(r1)
	fneg f0, f6
	lfd f1, 0x108(r1)
	fneg f2, f2
	fneg f1, f1
	stfd f0, 0x10(r17)
	stfd f2, 0x0(r17)
	stfd f1, 0x8(r17)
.L_803FFDF4:
	addi r11, r1, 0x370
	clrlwi r3, r20, 29
	bl _restfpr_23
	lmw r14, 0x2e0(r1)
	lwz r0, 0x374(r1)
	mtlr r0
	addi r1, r1, 0x370
	blr
.endfn fn_803FE708
