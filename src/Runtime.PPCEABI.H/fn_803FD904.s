# Runtime.PPCEABI.H/fn_803FD904.s (auto_03_803FD320_text)

.include "macros.inc"

.text
.balign 4

.fn fn_803FD904, global
	stwu r1, -0x20(r1)
	mflr r0
	stw r0, 0x24(r1)
	stfd f31, 0x18(r1)
	stfd f1, 0x8(r1)
	lis r0, 0x10
	li r4, 0x0
	lwz r5, 0x8(r1)
	lwz r3, 0xc(r1)
	cmpw r5, r0
	bge .L_803FD988
	clrlwi r0, r5, 1
	or. r0, r0, r3
	bne .L_803FD954
	lfd f1, lbl_805A4DE8@sda21(r0)
	li r0, 0x21
	lfd f0, lbl_805A1300@sda21(r0)
	stw r0, lbl_805A12E0@sda21(r0)
	fdiv f1, f1, f0
	b .L_803FDA04
.L_803FD954:
	cmpwi r5, 0x0
	bge .L_803FD974
	fsub f1, f1, f1
	lfd f0, lbl_805A1300@sda21(r0)
	li r0, 0x21
	stw r0, lbl_805A12E0@sda21(r0)
	fdiv f1, f1, f0
	b .L_803FDA04
.L_803FD974:
	lfd f0, lbl_805A4DF0@sda21(r0)
	li r4, -0x36
	fmul f1, f1, f0
	stfd f1, 0x8(r1)
	lwz r5, 0x8(r1)
.L_803FD988:
	lis r0, 0x7ff0
	cmpw r5, r0
	blt .L_803FD99C
	fadd f1, f1, f1
	b .L_803FDA04
.L_803FD99C:
	srawi r3, r5, 20
	lis r0, 0x4330
	add r3, r4, r3
	stw r0, 0x10(r1)
	subi r4, r3, 0x3ff
	lfd f1, lbl_805A4E10@sda21(r0)
	srwi r3, r4, 31
	add r0, r4, r3
	xoris r0, r0, 0x8000
	subfic r3, r3, 0x3ff
	stw r0, 0x14(r1)
	slwi r0, r3, 20
	rlwimi r0, r5, 0, 12, 31
	lfd f0, 0x10(r1)
	stw r0, 0x8(r1)
	fsub f31, f0, f1
	lfd f1, 0x8(r1)
	bl fn_803FD650
	lfd f0, lbl_805A4E00@sda21(r0)
	lfd f2, lbl_805A4DF8@sda21(r0)
	fmul f3, f0, f1
	lfd f0, lbl_805A4E08@sda21(r0)
	fmul f1, f2, f31
	fmul f0, f0, f31
	fadd f1, f1, f3
	fadd f1, f1, f0
.L_803FDA04:
	lwz r0, 0x24(r1)
	lfd f31, 0x18(r1)
	mtlr r0
	addi r1, r1, 0x20
	blr
.endfn fn_803FD904

.fn fn_803FDA18, global
	stwu r1, -0xc0(r1)
	mflr r0
	stw r0, 0xc4(r1)
	stfd f31, 0xb0(r1)
	psq_st f31, 0xb8(r1), 0, qr0
	stfd f30, 0xa0(r1)
	psq_st f30, 0xa8(r1), 0, qr0
	stfd f29, 0x90(r1)
	psq_st f29, 0x98(r1), 0, qr0
	stfd f28, 0x80(r1)
	psq_st f28, 0x88(r1), 0, qr0
	stfd f27, 0x70(r1)
	psq_st f27, 0x78(r1), 0, qr0
	stfd f26, 0x60(r1)
	psq_st f26, 0x68(r1), 0, qr0
	stfd f2, 0x10(r1)
	lis r3, lbl_80420160@ha
	addi r3, r3, lbl_80420160@l
	lwz r5, 0x10(r1)
	stfd f1, 0x8(r1)
	lwz r11, 0x14(r1)
	clrlwi r7, r5, 1
	lwz r9, 0x8(r1)
	or. r0, r7, r11
	lwz r10, 0xc(r1)
	clrlwi r6, r9, 1
	bne .L_803FDA8C
	lfd f1, lbl_805A4E18@sda21(r0)
	b .L_803FE220
.L_803FDA8C:
	lis r0, 0x7ff0
	cmpw r6, r0
	bgt .L_803FDACC
	subis r0, r6, 0x7ff0
	cmplwi r0, 0x0
	bne .L_803FDAAC
	cmpwi r10, 0x0
	bne .L_803FDACC
.L_803FDAAC:
	lis r0, 0x7ff0
	cmpw r7, r0
	bgt .L_803FDACC
	subis r0, r7, 0x7ff0
	cmplwi r0, 0x0
	bne .L_803FDAD4
	cmpwi r11, 0x0
	beq .L_803FDAD4
.L_803FDACC:
	fadd f1, f1, f2
	b .L_803FE220
.L_803FDAD4:
	cmpwi r9, 0x0
	li r4, 0x0
	bge .L_803FDB54
	lis r0, 0x4340
	cmpw r7, r0
	blt .L_803FDAF4
	li r4, 0x2
	b .L_803FDB54
.L_803FDAF4:
	lis r0, 0x3ff0
	cmpw r7, r0
	blt .L_803FDB54
	srawi r8, r7, 20
	subi r0, r8, 0x3ff
	cmpwi r0, 0x14
	ble .L_803FDB30
	subfic r0, r0, 0x34
	srw r8, r11, r0
	slw r0, r8, r0
	cmplw r11, r0
	bne .L_803FDB54
	clrlwi r0, r8, 31
	subfic r4, r0, 0x2
	b .L_803FDB54
.L_803FDB30:
	cmpwi r11, 0x0
	bne .L_803FDB54
	subfic r0, r0, 0x14
	sraw r8, r7, r0
	slw r0, r8, r0
	cmpw r7, r0
	bne .L_803FDB54
	clrlwi r0, r8, 31
	subfic r4, r0, 0x2
.L_803FDB54:
	cmpwi r11, 0x0
	bne .L_803FDC08
	subis r0, r7, 0x7ff0
	cmplwi r0, 0x0
	bne .L_803FDBB8
	subis r0, r6, 0x3ff0
	or. r0, r0, r10
	bne .L_803FDB7C
	fsub f1, f2, f2
	b .L_803FE220
.L_803FDB7C:
	lis r0, 0x3ff0
	cmpw r6, r0
	blt .L_803FDBA0
	cmpwi r5, 0x0
	blt .L_803FDB98
	fmr f1, f2
	b .L_803FE220
.L_803FDB98:
	lfd f1, lbl_805A4E20@sda21(r0)
	b .L_803FE220
.L_803FDBA0:
	cmpwi r5, 0x0
	bge .L_803FDBB0
	fneg f1, f2
	b .L_803FE220
.L_803FDBB0:
	lfd f1, lbl_805A4E20@sda21(r0)
	b .L_803FE220
.L_803FDBB8:
	subis r0, r7, 0x3ff0
	cmplwi r0, 0x0
	bne .L_803FDBD8
	cmpwi r5, 0x0
	bge .L_803FE220
	lfd f0, lbl_805A4E18@sda21(r0)
	fdiv f1, f0, f1
	b .L_803FE220
.L_803FDBD8:
	subis r0, r5, 0x4000
	cmplwi r0, 0x0
	bne .L_803FDBEC
	fmul f1, f1, f1
	b .L_803FE220
.L_803FDBEC:
	subis r0, r5, 0x3fe0
	cmplwi r0, 0x0
	bne .L_803FDC08
	cmpwi r9, 0x0
	blt .L_803FDC08
	bl fn_80400D94
	b .L_803FE220
.L_803FDC08:
	fabs f0, f1
	cmpwi r10, 0x0
	stfd f0, 0x48(r1)
	bne .L_803FDC8C
	subis r0, r6, 0x7ff0
	cmplwi r0, 0x0
	beq .L_803FDC38
	cmpwi r6, 0x0
	beq .L_803FDC38
	subis r0, r6, 0x3ff0
	cmplwi r0, 0x0
	bne .L_803FDC8C
.L_803FDC38:
	cmpwi r5, 0x0
	stfd f0, 0x50(r1)
	bge .L_803FDC50
	lfd f1, lbl_805A4E18@sda21(r0)
	fdiv f0, f1, f0
	stfd f0, 0x50(r1)
.L_803FDC50:
	cmpwi r9, 0x0
	bge .L_803FDC84
	subis r0, r6, 0x3ff0
	or. r0, r0, r4
	bne .L_803FDC74
	fsub f0, f0, f0
	fdiv f0, f0, f0
	stfd f0, 0x50(r1)
	b .L_803FDC84
.L_803FDC74:
	cmpwi r4, 0x1
	bne .L_803FDC84
	fneg f0, f0
	stfd f0, 0x50(r1)
.L_803FDC84:
	fmr f1, f0
	b .L_803FE220
.L_803FDC8C:
	srawi r8, r9, 31
	addi r0, r8, 0x1
	or. r8, r0, r4
	bne .L_803FDCB0
	li r0, 0x21
	lis r3, lbl_8059FF68@ha
	stw r0, lbl_805A12E0@sda21(r0)
	lfs f1, lbl_8059FF68@l(r3)
	b .L_803FE220
.L_803FDCB0:
	lis r8, 0x41e0
	cmpw r7, r8
	ble .L_803FDDC4
	lis r3, 0x43f0
	cmpw r7, r3
	ble .L_803FDD10
	lis r3, 0x3ff0
	subi r7, r3, 0x1
	cmpw r6, r7
	bgt .L_803FDCF0
	cmpwi r5, 0x0
	bge .L_803FDCE8
	lfd f1, lbl_805A4E28@sda21(r0)
	b .L_803FE220
.L_803FDCE8:
	lfd f1, lbl_805A4E20@sda21(r0)
	b .L_803FE220
.L_803FDCF0:
	cmpw r6, r3
	blt .L_803FDD10
	cmpwi r5, 0x0
	ble .L_803FDD08
	lfd f1, lbl_805A4E28@sda21(r0)
	b .L_803FE220
.L_803FDD08:
	lfd f1, lbl_805A4E20@sda21(r0)
	b .L_803FE220
.L_803FDD10:
	lis r3, 0x3ff0
	subi r7, r3, 0x1
	cmpw r6, r7
	bge .L_803FDD38
	cmpwi r5, 0x0
	bge .L_803FDD30
	lfd f1, lbl_805A4E28@sda21(r0)
	b .L_803FE220
.L_803FDD30:
	lfd f1, lbl_805A4E20@sda21(r0)
	b .L_803FE220
.L_803FDD38:
	cmpw r6, r3
	ble .L_803FDD58
	cmpwi r5, 0x0
	ble .L_803FDD50
	lfd f1, lbl_805A4E28@sda21(r0)
	b .L_803FE220
.L_803FDD50:
	lfd f1, lbl_805A4E20@sda21(r0)
	b .L_803FE220
.L_803FDD58:
	lfd f3, lbl_805A4E18@sda21(r0)
	li r3, 0x0
	lfd f0, lbl_805A4E40@sda21(r0)
	fsub f8, f1, f3
	lfd f1, lbl_805A4E50@sda21(r0)
	lfd f5, lbl_805A4E38@sda21(r0)
	lfd f3, lbl_805A4E48@sda21(r0)
	fmul f6, f0, f8
	lfd f4, lbl_805A4E30@sda21(r0)
	lfd f0, lbl_805A4E58@sda21(r0)
	fmul f7, f8, f8
	stfd f8, 0x28(r1)
	fsub f5, f5, f6
	fmul f6, f3, f8
	fmul f5, f8, f5
	fmul f1, f1, f8
	fsub f3, f4, f5
	fmul f3, f7, f3
	fmul f0, f0, f3
	fsub f1, f1, f0
	fadd f0, f6, f1
	stfd f0, 0x30(r1)
	stw r3, 0x34(r1)
	lfd f0, 0x30(r1)
	fsub f0, f0, f6
	fsub f0, f1, f0
	b .L_803FDFD0
.L_803FDDC4:
	lis r5, 0x10
	li r11, 0x0
	cmpw r6, r5
	bge .L_803FDDE8
	lfd f1, lbl_805A4E60@sda21(r0)
	li r11, -0x35
	fmul f0, f0, f1
	stfd f0, 0x48(r1)
	lwz r6, 0x48(r1)
.L_803FDDE8:
	lis r5, 0x4
	clrlwi r8, r6, 12
	subi r5, r5, 0x6772
	srawi r6, r6, 20
	cmpw r8, r5
	oris r7, r8, 0x3ff0
	add r5, r11, r6
	subi r11, r5, 0x3ff
	bgt .L_803FDE14
	li r6, 0x0
	b .L_803FDE38
.L_803FDE14:
	lis r5, 0xc
	subi r5, r5, 0x4986
	cmpw r8, r5
	bge .L_803FDE2C
	li r6, 0x1
	b .L_803FDE38
.L_803FDE2C:
	subis r7, r7, 0x10
	li r6, 0x0
	addi r11, r11, 0x1
.L_803FDE38:
	stw r7, 0x48(r1)
	srawi r9, r7, 1
	slwi r10, r6, 3
	addi r5, r3, 0x0
	lfdx f7, r5, r10
	slwi r8, r6, 18
	lfd f10, 0x48(r1)
	xoris r6, r11, 0x8000
	lfd f4, lbl_805A4E20@sda21(r0)
	lis r5, 0x4330
	fadd f3, f10, f7
	lfd f1, lbl_805A4E18@sda21(r0)
	fsub f26, f10, f7
	stfd f4, 0x18(r1)
	oris r9, r9, 0x2000
	addis r8, r8, 0x8
	fdiv f1, f1, f3
	add r8, r9, r8
	stw r8, 0x18(r1)
	li r9, 0x0
	lfd f0, lbl_805A4E90@sda21(r0)
	addi r7, r3, 0x20
	fmul f4, f26, f1
	lfd f9, 0x18(r1)
	lfd f3, lbl_805A4E88@sda21(r0)
	fsub f8, f9, f7
	lfd f6, lbl_805A4E80@sda21(r0)
	stw r6, 0x5c(r1)
	fmul f5, f4, f4
	stfd f4, 0x20(r1)
	lfd f30, lbl_805A4E78@sda21(r0)
	fsub f11, f10, f8
	stw r5, 0x58(r1)
	lfd f31, lbl_805A4E70@sda21(r0)
	fmul f7, f0, f5
	stw r9, 0x24(r1)
	lfd f13, lbl_805A4E68@sda21(r0)
	lfd f0, 0x20(r1)
	lfd f12, lbl_805A4E98@sda21(r0)
	fadd f7, f3, f7
	fmul f27, f0, f9
	lfd f10, lbl_805A4EA8@sda21(r0)
	lfd f9, lbl_805A4EB0@sda21(r0)
	fmul f8, f5, f7
	lfd f7, lbl_805A4F20@sda21(r0)
	fmul f28, f0, f11
	lfd f11, lbl_805A4EA0@sda21(r0)
	fadd f29, f6, f8
	lfd f6, 0x58(r1)
	fsub f27, f26, f27
	lfdx f8, r7, r10
	fsub f6, f6, f7
	fmul f29, f5, f29
	fsub f28, f27, f28
	stfd f6, 0x28(r1)
	fmul f3, f0, f0
	fadd f7, f30, f29
	fmul f26, f1, f28
	fmul f7, f5, f7
	fmul f29, f5, f5
	fadd f31, f31, f7
	fadd f1, f0, f4
	fmul f5, f5, f31
	fmul f7, f26, f1
	fadd f5, f13, f5
	fadd f1, f12, f3
	fmul f13, f29, f5
	fadd f13, f13, f7
	fadd f1, f1, f13
	stfd f1, 0x18(r1)
	stw r9, 0x1c(r1)
	lfd f7, 0x18(r1)
	fsub f5, f7, f12
	fmul f1, f26, f7
	fsub f3, f5, f3
	fmul f5, f0, f7
	fsub f0, f13, f3
	fmul f0, f0, f4
	fadd f4, f1, f0
	fadd f3, f5, f4
	stfd f3, 0x40(r1)
	stw r9, 0x44(r1)
	lfd f3, 0x40(r1)
	fsub f0, f3, f5
	fmul f1, f10, f3
	fsub f0, f4, f0
	fmul f3, f11, f3
	fmul f0, f9, f0
	fadd f0, f1, f0
	fadd f4, f8, f0
	addi r3, r3, 0x10
	fadd f0, f3, f4
	lfdx f1, r3, r10
	fadd f0, f0, f1
	fadd f0, f6, f0
	stfd f0, 0x30(r1)
	stw r9, 0x34(r1)
	lfd f0, 0x30(r1)
	fsub f0, f0, f6
	fsub f0, f0, f1
	fsub f0, f0, f3
	fsub f0, f4, f0
.L_803FDFD0:
	subi r3, r4, 0x1
	lfd f31, lbl_805A4E18@sda21(r0)
	or. r0, r0, r3
	bne .L_803FDFE4
	lfd f31, lbl_805A4EB8@sda21(r0)
.L_803FDFE4:
	stfd f2, 0x38(r1)
	li r0, 0x0
	fmul f0, f2, f0
	lfd f1, 0x30(r1)
	stw r0, 0x3c(r1)
	lis r0, 0x4090
	lfd f3, 0x38(r1)
	fsub f2, f2, f3
	fmul f3, f3, f1
	fmul f1, f1, f2
	stfd f3, 0x40(r1)
	fadd f11, f1, f0
	fadd f0, f11, f3
	stfd f0, 0x50(r1)
	lwz r6, 0x50(r1)
	lwz r5, 0x54(r1)
	cmpw r6, r0
	blt .L_803FE06C
	subis r0, r6, 0x4090
	or. r0, r0, r5
	beq .L_803FE048
	lfd f1, lbl_805A4EC0@sda21(r0)
	fmul f0, f1, f31
	fmul f1, f1, f0
	b .L_803FE220
.L_803FE048:
	lfd f1, lbl_805A4EC8@sda21(r0)
	fsub f0, f0, f3
	fadd f1, f1, f11
	fcmpo cr0, f1, f0
	ble .L_803FE0C0
	lfd f1, lbl_805A4EC0@sda21(r0)
	fmul f0, f1, f31
	fmul f1, f1, f0
	b .L_803FE220
.L_803FE06C:
	lis r3, 0x4091
	clrlwi r4, r6, 1
	subi r0, r3, 0x3400
	cmpw r4, r0
	blt .L_803FE0C0
	addis r3, r6, 0x3f6f
	addi r0, r3, 0x3400
	or. r0, r0, r5
	beq .L_803FE0A0
	lfd f1, lbl_805A4ED0@sda21(r0)
	fmul f0, f1, f31
	fmul f1, f1, f0
	b .L_803FE220
.L_803FE0A0:
	fsub f0, f0, f3
	fcmpo cr0, f11, f0
	cror eq, lt, eq
	bne .L_803FE0C0
	lfd f1, lbl_805A4ED0@sda21(r0)
	fmul f0, f1, f31
	fmul f1, f1, f0
	b .L_803FE220
.L_803FE0C0:
	clrlwi r3, r6, 1
	lis r0, 0x3fe0
	cmpw r3, r0
	extrwi r4, r6, 11, 1
	li r3, 0x0
	ble .L_803FE134
	lis r3, 0x10
	subi r0, r4, 0x3fe
	sraw r0, r3, r0
	lfd f0, lbl_805A4E20@sda21(r0)
	add r7, r6, r0
	subi r3, r3, 0x1
	clrlwi r0, r7, 1
	stfd f0, 0x28(r1)
	srawi r4, r0, 20
	cmpwi r6, 0x0
	subi r5, r4, 0x3ff
	clrlwi r0, r7, 12
	sraw r4, r3, r5
	andc r4, r7, r4
	oris r3, r0, 0x10
	subfic r0, r5, 0x14
	stw r4, 0x28(r1)
	sraw r3, r3, r0
	bge .L_803FE128
	neg r3, r3
.L_803FE128:
	lfd f0, 0x28(r1)
	fsub f3, f3, f0
	stfd f3, 0x40(r1)
.L_803FE134:
	fadd f1, f11, f3
	li r0, 0x0
	lfd f0, lbl_805A4EE8@sda21(r0)
	slwi r4, r3, 20
	lfd f8, lbl_805A4EE0@sda21(r0)
	stfd f1, 0x28(r1)
	lfd f10, lbl_805A4ED8@sda21(r0)
	stw r0, 0x2c(r1)
	lfd f6, lbl_805A4F10@sda21(r0)
	lfd f9, 0x28(r1)
	lfd f1, lbl_805A4F08@sda21(r0)
	fsub f2, f9, f3
	lfd f5, lbl_805A4F00@sda21(r0)
	fmul f7, f0, f9
	lfd f4, lbl_805A4EF8@sda21(r0)
	lfd f3, lbl_805A4EF0@sda21(r0)
	fsub f0, f11, f2
	fmul f10, f10, f9
	lfd f2, lbl_805A4F18@sda21(r0)
	fmul f8, f8, f0
	lfd f0, lbl_805A4E18@sda21(r0)
	fadd f11, f8, f7
	fadd f9, f10, f11
	fmul f7, f9, f9
	fsub f8, f9, f10
	fmul f6, f6, f7
	stfd f7, 0x28(r1)
	fsub f8, f11, f8
	fadd f6, f1, f6
	fmul f1, f9, f8
	fmul f6, f7, f6
	fadd f1, f8, f1
	fadd f5, f5, f6
	fmul f5, f7, f5
	fadd f4, f4, f5
	fmul f4, f7, f4
	fadd f3, f3, f4
	fmul f3, f7, f3
	fsub f4, f9, f3
	fmul f3, f9, f4
	stfd f4, 0x30(r1)
	fsub f2, f4, f2
	fdiv f2, f3, f2
	fsub f1, f2, f1
	fsub f1, f1, f9
	fsub f1, f0, f1
	stfd f1, 0x50(r1)
	lwz r0, 0x50(r1)
	add r0, r0, r4
	srawi. r0, r0, 20
	bgt .L_803FE20C
	bl fn_803FC9BC
	stfd f1, 0x50(r1)
	b .L_803FE218
.L_803FE20C:
	lwz r0, 0x50(r1)
	add r0, r0, r4
	stw r0, 0x50(r1)
.L_803FE218:
	lfd f0, 0x50(r1)
	fmul f1, f31, f0
.L_803FE220:
	psq_l f31, 0xb8(r1), 0, qr0
	lfd f31, 0xb0(r1)
	psq_l f30, 0xa8(r1), 0, qr0
	lfd f30, 0xa0(r1)
	psq_l f29, 0x98(r1), 0, qr0
	lfd f29, 0x90(r1)
	psq_l f28, 0x88(r1), 0, qr0
	lfd f28, 0x80(r1)
	psq_l f27, 0x78(r1), 0, qr0
	lfd f27, 0x70(r1)
	psq_l f26, 0x68(r1), 0, qr0
	lwz r0, 0xc4(r1)
	lfd f26, 0x60(r1)
	mtlr r0
	addi r1, r1, 0xc0
	blr
.endfn fn_803FDA18

# .text:0xF40 | 0x803FE260 | size: 0x398
