# Runtime.PPCEABI.H/fn_8040012C.s (auto_03_803FFE14_text)

.include "macros.inc"

.text
.balign 4

.fn fn_8040012C, global
	stwu r1, -0x10(r1)
	lis r5, lbl_804203D0@ha
	lis r0, 0x4410
	stfd f1, 0x8(r1)
	addi r5, r5, lbl_804203D0@l
	lwz r6, 0x8(r1)
	clrlwi r4, r6, 1
	cmpw r4, r0
	blt .L_804001B8
	lis r0, 0x7ff0
	cmpw r4, r0
	bgt .L_80400174
	subis r0, r4, 0x7ff0
	cmplwi r0, 0x0
	bne .L_8040017C
	lwz r0, 0xc(r1)
	cmpwi r0, 0x0
	beq .L_8040017C
.L_80400174:
	fadd f1, f1, f1
	b .L_80400364
.L_8040017C:
	cmpwi r6, 0x0
	ble .L_8040019C
	addi r4, r5, 0x0
	addi r3, r5, 0x20
	lfd f1, 0x18(r4)
	lfd f0, 0x18(r3)
	fadd f1, f1, f0
	b .L_80400364
.L_8040019C:
	addi r4, r5, 0x0
	addi r3, r5, 0x20
	lfd f1, 0x18(r4)
	lfd f0, 0x18(r3)
	fneg f1, f1
	fsub f1, f1, f0
	b .L_80400364
.L_804001B8:
	lis r0, 0x3fdc
	cmpw r4, r0
	bge .L_804001F0
	lis r0, 0x3e20
	cmpw r4, r0
	bge .L_804001E8
	lfd f2, lbl_805A5078@sda21(r0)
	lfd f0, lbl_805A5080@sda21(r0)
	fadd f2, f2, f1
	fcmpo cr0, f2, f0
	ble .L_804001E8
	b .L_80400364
.L_804001E8:
	li r0, -0x1
	b .L_80400290
.L_804001F0:
	lis r0, 0x3ff3
	fabs f3, f1
	cmpw r4, r0
	bge .L_8040024C
	lis r0, 0x3fe6
	cmpw r4, r0
	bge .L_80400230
	lfd f0, lbl_805A5088@sda21(r0)
	li r0, 0x0
	lfd f1, lbl_805A5080@sda21(r0)
	fmul f2, f0, f3
	fadd f0, f0, f3
	fsub f1, f2, f1
	fdiv f1, f1, f0
	stfd f1, 0x8(r1)
	b .L_80400290
.L_80400230:
	lfd f0, lbl_805A5080@sda21(r0)
	li r0, 0x1
	fsub f1, f3, f0
	fadd f0, f0, f3
	fdiv f1, f1, f0
	stfd f1, 0x8(r1)
	b .L_80400290
.L_8040024C:
	lis r3, 0x4004
	addi r0, r3, -0x8000
	cmpw r4, r0
	bge .L_80400280
	lfd f2, lbl_805A5090@sda21(r0)
	li r0, 0x2
	lfd f0, lbl_805A5080@sda21(r0)
	fmul f1, f2, f3
	fsub f2, f3, f2
	fadd f0, f0, f1
	fdiv f1, f2, f0
	stfd f1, 0x8(r1)
	b .L_80400290
.L_80400280:
	lfd f0, lbl_805A5098@sda21(r0)
	li r0, 0x3
	fdiv f1, f0, f3
	stfd f1, 0x8(r1)
.L_80400290:
	fmul f0, f1, f1
	addi r3, r5, 0x40
	lfd f3, 0x50(r3)
	cmpwi r0, 0x0
	lfd f2, 0x48(r3)
	lfd f11, 0x40(r3)
	fmul f13, f0, f0
	lfd f5, 0x38(r3)
	lfd f10, 0x30(r3)
	lfd f4, 0x28(r3)
	lfd f9, 0x20(r3)
	fmul f12, f13, f3
	lfd f3, 0x18(r3)
	fmul f6, f13, f2
	lfd f8, 0x10(r3)
	lfd f2, 0x8(r3)
	fadd f11, f11, f12
	lfd f7, 0x40(r5)
	fadd f5, f5, f6
	fmul f6, f13, f11
	fmul f5, f13, f5
	fadd f6, f10, f6
	fadd f4, f4, f5
	fmul f5, f13, f6
	fmul f4, f13, f4
	fadd f5, f9, f5
	fadd f3, f3, f4
	fmul f4, f13, f5
	fmul f3, f13, f3
	fadd f4, f8, f4
	fadd f2, f2, f3
	fmul f3, f13, f4
	fmul f4, f13, f2
	fadd f2, f7, f3
	fmul f0, f0, f2
	bge .L_80400330
	fadd f0, f0, f4
	fmul f0, f1, f0
	fsub f1, f1, f0
	b .L_80400364
.L_80400330:
	fadd f0, f0, f4
	slwi r0, r0, 3
	addi r3, r5, 0x20
	addi r4, r5, 0x0
	lfdx f2, r3, r0
	cmpwi r6, 0x0
	fmul f3, f1, f0
	lfdx f0, r4, r0
	fsub f2, f3, f2
	fsub f1, f2, f1
	fsub f1, f0, f1
	bge .L_80400364
	fneg f1, f1
.L_80400364:
	addi r1, r1, 0x10
	blr
.endfn fn_8040012C

.fn fn_8040036C, global
	stwu r1, -0x10(r1)
	stfd f1, 0x8(r1)
	lwz r5, 0x8(r1)
	lwz r6, 0xc(r1)
	extrwi r3, r5, 11, 1
	subi r7, r3, 0x3ff
	cmpwi cr1, r7, 0x14
	bge cr1, .L_8040041C
	cmpwi r7, 0x0
	bge .L_804003D0
	lfd f2, lbl_805A50A0@sda21(r0)
	lfd f0, lbl_805A50A8@sda21(r0)
	fadd f1, f2, f1
	fcmpo cr0, f1, f0
	ble .L_80400498
	cmpwi r5, 0x0
	bge .L_804003BC
	lis r5, 0x8000
	li r6, 0x0
	b .L_80400498
.L_804003BC:
	or. r0, r5, r6
	beq .L_80400498
	lis r5, 0x3ff0
	li r6, 0x0
	b .L_80400498
.L_804003D0:
	lis r3, 0x10
	subi r0, r3, 0x1
	sraw r4, r0, r7
	and r0, r5, r4
	or. r0, r6, r0
	bne .L_804003EC
	b .L_804004A4
.L_804003EC:
	lfd f2, lbl_805A50A0@sda21(r0)
	lfd f0, lbl_805A50A8@sda21(r0)
	fadd f1, f2, f1
	fcmpo cr0, f1, f0
	ble .L_80400498
	cmpwi r5, 0x0
	ble .L_80400410
	sraw r0, r3, r7
	add r5, r5, r0
.L_80400410:
	andc r5, r5, r4
	li r6, 0x0
	b .L_80400498
.L_8040041C:
	cmpwi r7, 0x33
	ble .L_80400434
	cmpwi r7, 0x400
	bne .L_804004A4
	fadd f1, f1, f1
	b .L_804004A4
.L_80400434:
	subi r0, r7, 0x14
	li r3, -0x1
	srw r4, r3, r0
	and. r0, r6, r4
	bne .L_8040044C
	b .L_804004A4
.L_8040044C:
	lfd f2, lbl_805A50A0@sda21(r0)
	lfd f0, lbl_805A50A8@sda21(r0)
	fadd f1, f2, f1
	fcmpo cr0, f1, f0
	ble .L_80400498
	cmpwi r5, 0x0
	ble .L_80400494
	bne cr1, .L_80400474
	addi r5, r5, 0x1
	b .L_80400494
.L_80400474:
	subfic r0, r7, 0x34
	li r3, 0x1
	slw r0, r3, r0
	add r0, r6, r0
	cmplw r0, r6
	bge .L_80400490
	addi r5, r5, 0x1
.L_80400490:
	mr r6, r0
.L_80400494:
	andc r6, r6, r4
.L_80400498:
	stw r5, 0x8(r1)
	stw r6, 0xc(r1)
	lfd f1, 0x8(r1)
.L_804004A4:
	addi r1, r1, 0x10
	blr
.endfn fn_8040036C
