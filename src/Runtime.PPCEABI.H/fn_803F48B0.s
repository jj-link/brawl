# Runtime.PPCEABI.H/fn_803F48B0.s (auto_fn_803F48B0_text)

.include "macros.inc"

.section extab, "a"
.balign 4

.obj Letb, local
	.4byte 0x684A0000
	.4byte 0x00000000
.endobj Letb

.section extabindex, "a"
.balign 4

.obj Leti, local
	.4byte fn_803F48B0
	.4byte 0x000007B0
	.4byte Letb
.endobj Leti

.text
.balign 4

.fn fn_803F48B0, global
	stwu r1, -0x180(r1)
	mflr r0
	stw r0, 0x184(r1)
	stfd f31, 0x170(r1)
	psq_st f31, 0x178(r1), 0, qr0
	addi r11, r1, 0x170
	bl _savegpr_19
	lbz r0, 0x4(r3)
	lis r4, 0x4330
	stw r4, 0x128(r1)
	mr r27, r3
	cmpwi r0, 0x0
	stw r4, 0x130(r1)
	bne .L_803F490C
	lbz r0, 0x0(r3)
	extsb. r0, r0
	bne .L_803F48FC
	lfd f2, lbl_805A4B70@sda21(r0)
	b .L_803F4900
.L_803F48FC:
	lfd f2, lbl_805A4B78@sda21(r0)
.L_803F4900:
	lfd f1, lbl_805A4B68@sda21(r0)
	bl fn_804004AC
	b .L_803F5040
.L_803F490C:
	lbz r0, 0x5(r3)
	cmpwi r0, 0x49
	beq .L_803F4958
	bge .L_803F4928
	cmpwi r0, 0x30
	beq .L_803F4934
	b .L_803F49C4
.L_803F4928:
	cmpwi r0, 0x4e
	beq .L_803F4980
	b .L_803F49C4
.L_803F4934:
	lbz r0, 0x0(r3)
	extsb. r0, r0
	bne .L_803F4948
	lfd f2, lbl_805A4B70@sda21(r0)
	b .L_803F494C
.L_803F4948:
	lfd f2, lbl_805A4B78@sda21(r0)
.L_803F494C:
	lfd f1, lbl_805A4B68@sda21(r0)
	bl fn_804004AC
	b .L_803F5040
.L_803F4958:
	lbz r0, 0x0(r3)
	extsb. r0, r0
	bne .L_803F496C
	lfd f2, lbl_805A4B70@sda21(r0)
	b .L_803F4970
.L_803F496C:
	lfd f2, lbl_805A4B78@sda21(r0)
.L_803F4970:
	lis r3, lbl_8059FF6C@ha
	lfs f1, lbl_8059FF6C@l(r3)
	bl fn_804004AC
	b .L_803F5040
.L_803F4980:
	lbz r0, 0x0(r3)
	li r4, 0x0
	lis r3, 0x7ff0
	stw r4, 0x1c(r1)
	extsb. r0, r0
	stw r3, 0x18(r1)
	beq .L_803F49B0
	lis r0, 0x8000
	li r3, 0x0
	oris r0, r0, 0x7ff0
	stw r3, 0x1c(r1)
	stw r0, 0x18(r1)
.L_803F49B0:
	lwz r0, 0x18(r1)
	oris r0, r0, 0x8
	stw r0, 0x18(r1)
	lfd f1, 0x18(r1)
	b .L_803F5040
.L_803F49C4:
	lhz r0, 0x4(r3)
	addi r4, r1, 0x101
	lhz r19, 0x0(r3)
	sth r0, 0x100(r1)
	lhz r20, 0x2(r3)
	lbz r0, 0x100(r1)
	lhz r31, 0x6(r3)
	add r28, r4, r0
	lhz r30, 0x8(r3)
	lhz r29, 0xa(r3)
	cmplw cr1, r4, r28
	lhz r26, 0xc(r3)
	lhz r25, 0xe(r3)
	lhz r24, 0x10(r3)
	lhz r23, 0x12(r3)
	lhz r22, 0x14(r3)
	lhz r21, 0x16(r3)
	lhz r12, 0x18(r3)
	lhz r11, 0x1a(r3)
	lhz r10, 0x1c(r3)
	lhz r9, 0x1e(r3)
	lhz r8, 0x20(r3)
	lhz r7, 0x22(r3)
	lhz r6, 0x24(r3)
	lhz r5, 0x26(r3)
	lhz r0, 0x28(r3)
	sth r19, 0xfc(r1)
	sth r20, 0xfe(r1)
	sth r31, 0x102(r1)
	sth r30, 0x104(r1)
	sth r29, 0x106(r1)
	sth r26, 0x108(r1)
	sth r25, 0x10a(r1)
	sth r24, 0x10c(r1)
	sth r23, 0x10e(r1)
	sth r22, 0x110(r1)
	sth r21, 0x112(r1)
	sth r12, 0x114(r1)
	sth r11, 0x116(r1)
	sth r10, 0x118(r1)
	sth r9, 0x11a(r1)
	sth r8, 0x11c(r1)
	sth r7, 0x11e(r1)
	sth r6, 0x120(r1)
	sth r5, 0x122(r1)
	sth r0, 0x124(r1)
	bge cr1, .L_803F4B38
	subf r0, r4, r28
	subi r3, r28, 0x8
	cmpwi r0, 0x8
	ble .L_803F4B14
	bgt cr1, .L_803F4B14
	addi r0, r3, 0x7
	subf r0, r4, r0
	srwi r0, r0, 3
	mtctr r0
	cmplw r4, r3
	bge .L_803F4B14
.L_803F4AAC:
	lbz r3, 0x0(r4)
	subi r0, r3, 0x30
	stb r0, 0x0(r4)
	lbz r3, 0x1(r4)
	subi r0, r3, 0x30
	stb r0, 0x1(r4)
	lbz r3, 0x2(r4)
	subi r0, r3, 0x30
	stb r0, 0x2(r4)
	lbz r3, 0x3(r4)
	subi r0, r3, 0x30
	stb r0, 0x3(r4)
	lbz r3, 0x4(r4)
	subi r0, r3, 0x30
	stb r0, 0x4(r4)
	lbz r3, 0x5(r4)
	subi r0, r3, 0x30
	stb r0, 0x5(r4)
	lbz r3, 0x6(r4)
	subi r0, r3, 0x30
	stb r0, 0x6(r4)
	lbz r3, 0x7(r4)
	subi r0, r3, 0x30
	stb r0, 0x7(r4)
	addi r4, r4, 0x8
	bdnz .L_803F4AAC
.L_803F4B14:
	subf r0, r4, r28
	mtctr r0
	cmplw r4, r28
	bge .L_803F4B38
.L_803F4B24:
	lbz r3, 0x0(r4)
	subi r0, r3, 0x30
	stb r0, 0x0(r4)
	addi r4, r4, 0x1
	bdnz .L_803F4B24
.L_803F4B38:
	lha r5, 0xfe(r1)
	lis r4, lbl_8041F500@ha
	lbz r0, 0x100(r1)
	addi r4, r4, lbl_8041F500@l
	addi r3, r1, 0xd0
	add r5, r0, r5
	addi r4, r4, 0xb8
	subi r0, r5, 0x1
	sth r0, 0xfe(r1)
	li r5, 0x134
	extsh r29, r0
	bl fn_803F3A54
	addi r3, r1, 0xd0
	addi r4, r1, 0xfc
	bl fn_803F3F90
	cmpwi r3, 0x0
	beq .L_803F4BA4
	lbz r0, 0x0(r27)
	extsb. r0, r0
	bne .L_803F4B90
	lfd f2, lbl_805A4B70@sda21(r0)
	b .L_803F4B94
.L_803F4B90:
	lfd f2, lbl_805A4B78@sda21(r0)
.L_803F4B94:
	lis r3, lbl_8059FF6C@ha
	lfs f1, lbl_8059FF6C@l(r3)
	bl fn_804004AC
	b .L_803F5040
.L_803F4BA4:
	lbz r0, 0x101(r1)
	lis r7, lbl_804940C8@ha
	lfd f2, lbl_805A4B90@sda21(r0)
	addi r4, r1, 0x102
	stw r0, 0x12c(r1)
	addi r7, r7, lbl_804940C8@l
	lis r3, 0x8000
	lfd f0, 0x128(r1)
	fsub f31, f0, f2
	b .L_803F4D08
.L_803F4BCC:
	subf r5, r4, r28
	li r10, 0x0
	slwi r0, r5, 29
	srwi r5, r5, 31
	subf r0, r5, r0
	rotlwi r0, r0, 3
	add. r6, r0, r5
	bne .L_803F4BF0
	li r6, 0x8
.L_803F4BF0:
	cmpwi cr1, r6, 0x0
	li r5, 0x0
	ble cr1, .L_803F4CD0
	cmpwi r6, 0x8
	subi r8, r6, 0x8
	ble .L_803F4CA8
	li r9, 0x0
	blt cr1, .L_803F4C20
	subi r0, r3, 0x2
	cmpw r6, r0
	bgt .L_803F4C20
	li r9, 0x1
.L_803F4C20:
	cmpwi r9, 0x0
	beq .L_803F4CA8
	addi r0, r8, 0x7
	srwi r0, r0, 3
	mtctr r0
	cmpwi r8, 0x0
	ble .L_803F4CA8
.L_803F4C3C:
	mulli r0, r10, 0xa
	lbz r9, 0x0(r4)
	lbz r8, 0x1(r4)
	addi r5, r5, 0x8
	lbz r21, 0x2(r4)
	add r0, r9, r0
	mulli r0, r0, 0xa
	lbz r12, 0x3(r4)
	lbz r11, 0x4(r4)
	lbz r10, 0x5(r4)
	add r0, r8, r0
	lbz r9, 0x6(r4)
	mulli r0, r0, 0xa
	lbz r8, 0x7(r4)
	addi r4, r4, 0x8
	add r0, r21, r0
	mulli r0, r0, 0xa
	add r0, r12, r0
	mulli r0, r0, 0xa
	add r0, r11, r0
	mulli r0, r0, 0xa
	add r0, r10, r0
	mulli r0, r0, 0xa
	add r0, r9, r0
	mulli r0, r0, 0xa
	add r10, r8, r0
	bdnz .L_803F4C3C
.L_803F4CA8:
	subf r0, r5, r6
	mtctr r0
	cmpw r5, r6
	bge .L_803F4CD0
.L_803F4CB8:
	mulli r0, r10, 0xa
	lbz r8, 0x0(r4)
	addi r5, r5, 0x1
	addi r4, r4, 0x1
	add r10, r8, r0
	bdnz .L_803F4CB8
.L_803F4CD0:
	slwi r0, r6, 3
	stw r10, 0x134(r1)
	add r5, r7, r0
	cmpwi r10, 0x0
	lfd f1, -0x8(r5)
	lfd f0, 0x130(r1)
	fmul f1, f31, f1
	fsub f0, f0, f2
	fadd f0, f1, f0
	beq .L_803F4D00
	fcmpu cr0, f1, f0
	beq .L_803F4D10
.L_803F4D00:
	fmr f31, f0
	subf r29, r6, r29
.L_803F4D08:
	cmplw r4, r28
	blt .L_803F4BCC
.L_803F4D10:
	cmpwi r29, 0x0
	bge .L_803F4D40
	neg r0, r29
	lfd f2, lbl_805A4B98@sda21(r0)
	xoris r0, r0, 0x8000
	lfd f1, lbl_805A4B80@sda21(r0)
	stw r0, 0x12c(r1)
	lfd f0, 0x128(r1)
	fsub f2, f0, f2
	bl fn_80400B44
	fdiv f31, f31, f1
	b .L_803F4D60
.L_803F4D40:
	xoris r0, r29, 0x8000
	lfd f2, lbl_805A4B98@sda21(r0)
	stw r0, 0x134(r1)
	lfd f1, lbl_805A4B80@sda21(r0)
	lfd f0, 0x130(r1)
	fsub f2, f0, f2
	bl fn_80400B44
	fmul f31, f31, f1
.L_803F4D60:
	fmr f1, f31
	mr r3, r29
	bl fn_80400778
	fmr f31, f1
	stfd f1, 0x10(r1)
	bl fn_803F64E8
	cmpwi r3, 0x2
	bne .L_803F4D88
	lfd f31, lbl_805A4B88@sda21(r0)
	stfd f31, 0x10(r1)
.L_803F4D88:
	fmr f1, f31
	addi r3, r1, 0xa4
	li r27, 0x0
	bl fn_803F45AC
	addi r3, r1, 0xa4
	addi r4, r1, 0xfc
	bl fn_803F3EAC
	cmpwi r3, 0x0
	bne .L_803F5028
	addi r3, r1, 0xa4
	addi r4, r1, 0xfc
	bl fn_803F3F90
	cmpwi r3, 0x0
	beq .L_803F4DC4
	li r27, 0x1
.L_803F4DC4:
	cntlzw r0, r27
	stfd f31, 0x8(r1)
	srwi r28, r0, 5
	li r29, 0x1
	li r30, 0x0
	li r31, -0x1
.L_803F4DDC:
	cmpwi r28, 0x0
	bne .L_803F4E10
	lwz r3, 0xc(r1)
	lwz r0, 0x8(r1)
	addc r3, r3, r29
	adde r0, r0, r30
	stw r3, 0xc(r1)
	stw r0, 0x8(r1)
	lfd f1, 0x8(r1)
	bl fn_803F64E8
	cmpwi r3, 0x2
	beq .L_803F5028
	b .L_803F4E28
.L_803F4E10:
	lwz r3, 0xc(r1)
	lwz r0, 0x8(r1)
	addc r3, r3, r31
	adde r0, r0, r31
	stw r3, 0xc(r1)
	stw r0, 0x8(r1)
.L_803F4E28:
	lfd f1, 0x8(r1)
	addi r3, r1, 0x78
	bl fn_803F45AC
	cmpwi r27, 0x0
	beq .L_803F4E50
	addi r3, r1, 0x78
	addi r4, r1, 0xfc
	bl fn_803F3F90
	cmpwi r3, 0x0
	beq .L_803F4FC0
.L_803F4E50:
	cmpwi r27, 0x0
	bne .L_803F4F5C
	addi r3, r1, 0xfc
	addi r4, r1, 0x78
	bl fn_803F3F90
	cmpwi r3, 0x0
	bne .L_803F4F5C
	fmr f0, f31
	lfd f31, 0x8(r1)
	lwz r21, 0xa4(r1)
	lwz r12, 0x78(r1)
	lwz r22, 0xa8(r1)
	lwz r11, 0x7c(r1)
	lwz r23, 0xac(r1)
	lwz r10, 0x80(r1)
	lwz r24, 0xb0(r1)
	lwz r9, 0x84(r1)
	lwz r25, 0xb4(r1)
	lwz r8, 0x88(r1)
	lwz r26, 0xb8(r1)
	lwz r7, 0x8c(r1)
	lwz r31, 0xbc(r1)
	lwz r6, 0x90(r1)
	lwz r30, 0xc0(r1)
	lwz r5, 0x94(r1)
	lwz r29, 0xc4(r1)
	lwz r4, 0x98(r1)
	lwz r28, 0xc8(r1)
	lwz r3, 0x9c(r1)
	lhz r27, 0xcc(r1)
	lhz r0, 0xa0(r1)
	stw r21, 0x4c(r1)
	stw r22, 0x50(r1)
	stw r23, 0x54(r1)
	stw r24, 0x58(r1)
	stw r25, 0x5c(r1)
	stw r26, 0x60(r1)
	stw r31, 0x64(r1)
	stw r30, 0x68(r1)
	stw r29, 0x6c(r1)
	stw r28, 0x70(r1)
	sth r27, 0x74(r1)
	stw r12, 0xa4(r1)
	stw r11, 0xa8(r1)
	stw r10, 0xac(r1)
	stw r9, 0xb0(r1)
	stw r8, 0xb4(r1)
	stw r7, 0xb8(r1)
	stw r6, 0xbc(r1)
	stw r5, 0xc0(r1)
	stw r4, 0xc4(r1)
	stw r3, 0xc8(r1)
	sth r0, 0xcc(r1)
	stw r21, 0x78(r1)
	stw r22, 0x7c(r1)
	stw r23, 0x80(r1)
	stw r24, 0x84(r1)
	stw r25, 0x88(r1)
	stw r26, 0x8c(r1)
	stw r31, 0x90(r1)
	stw r30, 0x94(r1)
	stw r29, 0x98(r1)
	stw r28, 0x9c(r1)
	sth r27, 0xa0(r1)
	stfd f31, 0x10(r1)
	stfd f0, 0x8(r1)
	b .L_803F4FC0
.L_803F4F5C:
	lwz r12, 0x78(r1)
	lwz r11, 0x7c(r1)
	lwz r10, 0x80(r1)
	lwz r9, 0x84(r1)
	lwz r8, 0x88(r1)
	lwz r7, 0x8c(r1)
	lwz r6, 0x90(r1)
	lwz r5, 0x94(r1)
	lwz r4, 0x98(r1)
	lwz r3, 0x9c(r1)
	lhz r0, 0xa0(r1)
	lfd f31, 0x8(r1)
	stw r12, 0xa4(r1)
	stw r11, 0xa8(r1)
	stw r10, 0xac(r1)
	stw r9, 0xb0(r1)
	stw r8, 0xb4(r1)
	stw r7, 0xb8(r1)
	stw r6, 0xbc(r1)
	stw r5, 0xc0(r1)
	stw r4, 0xc4(r1)
	stw r3, 0xc8(r1)
	sth r0, 0xcc(r1)
	stfd f31, 0x10(r1)
	b .L_803F4DDC
.L_803F4FC0:
	addi r3, r1, 0x4c
	addi r4, r1, 0xfc
	addi r5, r1, 0xa4
	bl fn_803F4090
	addi r3, r1, 0x20
	addi r4, r1, 0x78
	addi r5, r1, 0xfc
	bl fn_803F4090
	addi r3, r1, 0x4c
	addi r4, r1, 0x20
	bl fn_803F3EAC
	cmpwi r3, 0x0
	beq .L_803F500C
	lwz r0, 0x14(r1)
	clrlwi. r0, r0, 31
	beq .L_803F5028
	lfd f31, 0x8(r1)
	stfd f31, 0x10(r1)
	b .L_803F5028
.L_803F500C:
	addi r3, r1, 0x4c
	addi r4, r1, 0x20
	bl fn_803F3F90
	cmpwi r3, 0x0
	bne .L_803F5028
	lfd f31, 0x8(r1)
	stfd f31, 0x10(r1)
.L_803F5028:
	lbz r0, 0xfc(r1)
	extsb. r0, r0
	beq .L_803F503C
	fneg f31, f31
	stfd f31, 0x10(r1)
.L_803F503C:
	fmr f1, f31
.L_803F5040:
	psq_l f31, 0x178(r1), 0, qr0
	addi r11, r1, 0x170
	lfd f31, 0x170(r1)
	bl _restgpr_19
	lwz r0, 0x184(r1)
	mtlr r0
	addi r1, r1, 0x180
	blr
.endfn fn_803F48B0
