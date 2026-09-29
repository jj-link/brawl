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
	.4byte fn_803F8C64
	.4byte 0x000006B4
	.4byte Letb
.endobj Leti

.text
.balign 4

.fn fn_803F8C64, global
	stwu r1, -0x40(r1)
	lis r6, lbl_8041FB18@ha
	lbzu r5, 0x1(r3)
	stw r31, 0x3c(r1)
	extsb r5, r5
	stw r30, 0x38(r1)
	cmpwi r5, 0x25
	lwzu r0, lbl_8041FB18@l(r6)
	lwz r30, 0x4(r6)
	lwz r31, 0x8(r6)
	lwz r12, 0xc(r6)
	lwz r11, 0x10(r6)
	lwz r10, 0x14(r6)
	lwz r9, 0x18(r6)
	lwz r8, 0x1c(r6)
	lwz r7, 0x20(r6)
	lwz r6, 0x24(r6)
	stw r0, 0x8(r1)
	stw r30, 0xc(r1)
	stw r31, 0x10(r1)
	stw r12, 0x14(r1)
	stw r11, 0x18(r1)
	stw r10, 0x1c(r1)
	stw r9, 0x20(r1)
	stw r8, 0x24(r1)
	stw r7, 0x28(r1)
	stw r6, 0x2c(r1)
	bne .L_803F8D0C
	stb r5, 0xb(r1)
	addi r3, r3, 0x1
	lwz r0, 0x8(r1)
	stw r0, 0x0(r4)
	stw r30, 0x4(r4)
	stw r31, 0x8(r4)
	stw r12, 0xc(r4)
	stw r11, 0x10(r4)
	stw r10, 0x14(r4)
	stw r9, 0x18(r4)
	stw r8, 0x1c(r4)
	stw r7, 0x20(r4)
	stw r6, 0x24(r4)
	b .L_803F9308
.L_803F8D0C:
	cmpwi r5, 0x2a
	bne .L_803F8D24
	lbzu r5, 0x1(r3)
	li r0, 0x1
	stb r0, 0x8(r1)
	extsb r5, r5
.L_803F8D24:
	cmpwi r5, 0x0
	li r0, 0x0
	blt .L_803F8D38
	cmpwi r5, 0x100
	blt .L_803F8D3C
.L_803F8D38:
	li r0, 0x1
.L_803F8D3C:
	cmpwi r0, 0x0
	beq .L_803F8D4C
	li r0, 0x0
	b .L_803F8D68
.L_803F8D4C:
	lis r6, lbl_804942B8@ha
	slwi r0, r5, 1
	addi r6, r6, lbl_804942B8@l
	lwz r6, 0x38(r6)
	lwz r6, 0x8(r6)
	lhzx r0, r6, r0
	rlwinm r0, r0, 0, 28, 28
.L_803F8D68:
	cmpwi r0, 0x0
	beq .L_803F8E4C
	lis r6, lbl_804942B8@ha
	li r0, 0x0
	addi r6, r6, lbl_804942B8@l
	stw r0, 0xc(r1)
	lwz r7, 0x38(r6)
.L_803F8D84:
	lwz r6, 0xc(r1)
	li r0, 0x0
	mulli r6, r6, 0xa
	add r6, r5, r6
	lbzu r5, 0x1(r3)
	subi r6, r6, 0x30
	extsb. r5, r5
	stw r6, 0xc(r1)
	blt .L_803F8DB0
	cmpwi r5, 0x100
	blt .L_803F8DB4
.L_803F8DB0:
	li r0, 0x1
.L_803F8DB4:
	cmpwi r0, 0x0
	beq .L_803F8DC4
	li r0, 0x0
	b .L_803F8DD4
.L_803F8DC4:
	lwz r6, 0x8(r7)
	slwi r0, r5, 1
	lhzx r0, r6, r0
	rlwinm r0, r0, 0, 28, 28
.L_803F8DD4:
	cmpwi r0, 0x0
	bne .L_803F8D84
	lwz r6, 0xc(r1)
	cmpwi r6, 0x0
	bne .L_803F8E44
	li r0, 0xff
	addi r3, r3, 0x1
	stb r0, 0xb(r1)
	lwz r0, 0x8(r1)
	stw r0, 0x0(r4)
	stw r6, 0x4(r4)
	lwz r5, 0x10(r1)
	lwz r0, 0x14(r1)
	stw r5, 0x8(r4)
	stw r0, 0xc(r4)
	lwz r5, 0x18(r1)
	lwz r0, 0x1c(r1)
	stw r5, 0x10(r4)
	stw r0, 0x14(r4)
	lwz r5, 0x20(r1)
	lwz r0, 0x24(r1)
	stw r5, 0x18(r4)
	stw r0, 0x1c(r4)
	lwz r5, 0x28(r1)
	lwz r0, 0x2c(r1)
	stw r5, 0x20(r4)
	stw r0, 0x24(r4)
	b .L_803F9308
.L_803F8E44:
	li r0, 0x1
	stb r0, 0x9(r1)
.L_803F8E4C:
	cmpwi r5, 0x6b
	li r7, 0x1
	beq .L_803F8F2C
	bge .L_803F8E80
	cmpwi r5, 0x68
	beq .L_803F8EA4
	bge .L_803F8E74
	cmpwi r5, 0x4c
	beq .L_803F8EFC
	b .L_803F8F2C
.L_803F8E74:
	cmpwi r5, 0x6a
	bge .L_803F8F08
	b .L_803F8F2C
.L_803F8E80:
	cmpwi r5, 0x74
	beq .L_803F8F20
	bge .L_803F8E98
	cmpwi r5, 0x6d
	bge .L_803F8F2C
	b .L_803F8ED0
.L_803F8E98:
	cmpwi r5, 0x7a
	beq .L_803F8F14
	b .L_803F8F2C
.L_803F8EA4:
	lbz r0, 0x1(r3)
	li r6, 0x2
	stb r6, 0xa(r1)
	extsb r6, r0
	cmpwi r6, 0x68
	bne .L_803F8F30
	li r0, 0x1
	mr r5, r6
	stb r0, 0xa(r1)
	addi r3, r3, 0x1
	b .L_803F8F30
.L_803F8ED0:
	lbz r0, 0x1(r3)
	li r6, 0x3
	stb r6, 0xa(r1)
	extsb r6, r0
	cmpwi r6, 0x6c
	bne .L_803F8F30
	li r0, 0x7
	mr r5, r6
	stb r0, 0xa(r1)
	addi r3, r3, 0x1
	b .L_803F8F30
.L_803F8EFC:
	li r0, 0x9
	stb r0, 0xa(r1)
	b .L_803F8F30
.L_803F8F08:
	li r0, 0x4
	stb r0, 0xa(r1)
	b .L_803F8F30
.L_803F8F14:
	li r0, 0x5
	stb r0, 0xa(r1)
	b .L_803F8F30
.L_803F8F20:
	li r0, 0x6
	stb r0, 0xa(r1)
	b .L_803F8F30
.L_803F8F2C:
	li r7, 0x0
.L_803F8F30:
	cmpwi r7, 0x0
	beq .L_803F8F40
	lbzu r5, 0x1(r3)
	extsb r5, r5
.L_803F8F40:
	subi r0, r5, 0x41
	stb r5, 0xb(r1)
	cmplwi r0, 0x37
	bgt .L_803F92AC
	lis r5, jumptable_80494550@ha
	slwi r0, r0, 2
	addi r5, r5, jumptable_80494550@l
	lwzx r5, r5, r0
	mtctr r5
	bctr
	lbz r0, 0xa(r1)
	cmplwi r0, 0x9
	bne .L_803F92B4
	li r0, 0xff
	stb r0, 0xb(r1)
	b .L_803F92B4
	lbz r5, 0xa(r1)
	cmplwi r5, 0x1
	beq .L_803F8FA4
	cmplwi r5, 0x2
	beq .L_803F8FA4
	addi r0, r5, 0xfc
	clrlwi r0, r0, 24
	cmplwi r0, 0x3
	bgt .L_803F8FB0
.L_803F8FA4:
	li r0, 0xff
	stb r0, 0xb(r1)
	b .L_803F92B4
.L_803F8FB0:
	cmplwi r5, 0x3
	bne .L_803F92B4
	li r0, 0x8
	stb r0, 0xa(r1)
	b .L_803F92B4
	li r5, 0x3
	li r0, 0x78
	stb r5, 0xa(r1)
	stb r0, 0xb(r1)
	b .L_803F92B4
	lbz r0, 0xa(r1)
	cmplwi r0, 0x3
	bne .L_803F8FF0
	li r0, 0xa
	stb r0, 0xa(r1)
	b .L_803F92B4
.L_803F8FF0:
	cmpwi r0, 0x0
	beq .L_803F92B4
	li r0, 0xff
	stb r0, 0xb(r1)
	b .L_803F92B4
	lbz r0, 0xa(r1)
	cmplwi r0, 0x3
	bne .L_803F901C
	li r0, 0xa
	stb r0, 0xa(r1)
	b .L_803F902C
.L_803F901C:
	cmpwi r0, 0x0
	beq .L_803F902C
	li r0, 0xff
	stb r0, 0xb(r1)
.L_803F902C:
	li r6, 0xff
	li r5, 0xc1
	li r0, 0xfe
	stb r6, 0x10(r1)
	stb r6, 0x12(r1)
	stb r6, 0x13(r1)
	stb r6, 0x15(r1)
	stb r6, 0x16(r1)
	stb r6, 0x17(r1)
	stb r6, 0x18(r1)
	stb r6, 0x19(r1)
	stb r6, 0x1a(r1)
	stb r6, 0x1b(r1)
	stb r6, 0x1c(r1)
	stb r6, 0x1d(r1)
	stb r6, 0x1e(r1)
	stb r6, 0x1f(r1)
	stb r6, 0x20(r1)
	stb r6, 0x21(r1)
	stb r6, 0x22(r1)
	stb r6, 0x23(r1)
	stb r6, 0x24(r1)
	stb r6, 0x25(r1)
	stb r6, 0x26(r1)
	stb r6, 0x27(r1)
	stb r6, 0x28(r1)
	stb r6, 0x29(r1)
	stb r6, 0x2a(r1)
	stb r6, 0x2b(r1)
	stb r6, 0x2c(r1)
	stb r6, 0x2d(r1)
	stb r6, 0x2e(r1)
	stb r6, 0x2f(r1)
	stb r5, 0x11(r1)
	stb r0, 0x14(r1)
	b .L_803F92B4
	lbz r0, 0xa(r1)
	cmplwi r0, 0x3
	bne .L_803F90D4
	li r0, 0xa
	stb r0, 0xa(r1)
	b .L_803F90E4
.L_803F90D4:
	cmpwi r0, 0x0
	beq .L_803F90E4
	li r0, 0xff
	stb r0, 0xb(r1)
.L_803F90E4:
	lbzu r10, 0x1(r3)
	li r11, 0x0
	extsb r10, r10
	cmpwi r10, 0x5e
	bne .L_803F9104
	lbzu r10, 0x1(r3)
	li r11, 0x1
	extsb r10, r10
.L_803F9104:
	cmpwi r10, 0x5d
	bne .L_803F9120
	lbz r0, 0x1b(r1)
	lbzu r10, 0x1(r3)
	ori r0, r0, 0x20
	stb r0, 0x1b(r1)
	extsb r10, r10
.L_803F9120:
	addi r8, r1, 0x8
	li r5, 0x1
	b .L_803F91A8
.L_803F912C:
	extrwi r6, r10, 5, 24
	lbz r0, 0x1(r3)
	add r9, r8, r6
	clrlwi r6, r10, 29
	lbz r7, 0x8(r9)
	slw r6, r5, r6
	cmpwi r0, 0x2d
	or r6, r7, r6
	stb r6, 0x8(r9)
	bne .L_803F91A0
	lbz r9, 0x2(r3)
	extsb. r9, r9
	beq .L_803F91A0
	cmpwi r9, 0x5d
	beq .L_803F91A0
	b .L_803F9188
.L_803F916C:
	extrwi r6, r10, 5, 24
	clrlwi r0, r10, 29
	add r7, r8, r6
	lbz r6, 0x8(r7)
	slw r0, r5, r0
	or r0, r6, r0
	stb r0, 0x8(r7)
.L_803F9188:
	addi r10, r10, 0x1
	cmpw r10, r9
	ble .L_803F916C
	lbzu r10, 0x3(r3)
	extsb r10, r10
	b .L_803F91A8
.L_803F91A0:
	lbzu r10, 0x1(r3)
	extsb r10, r10
.L_803F91A8:
	cmpwi r10, 0x0
	beq .L_803F91B8
	cmpwi r10, 0x5d
	bne .L_803F912C
.L_803F91B8:
	cmpwi r10, 0x0
	bne .L_803F91CC
	li r0, 0xff
	stb r0, 0xb(r1)
	b .L_803F92B4
.L_803F91CC:
	cmpwi r11, 0x0
	beq .L_803F92B4
	li r0, 0x2
	addi r5, r1, 0x10
	mtctr r0
.L_803F91E0:
	lbz r0, 0x0(r5)
	nor r0, r0, r0
	stb r0, 0x0(r5)
	lbz r0, 0x1(r5)
	nor r0, r0, r0
	stb r0, 0x1(r5)
	lbz r0, 0x2(r5)
	nor r0, r0, r0
	stb r0, 0x2(r5)
	lbz r0, 0x3(r5)
	nor r0, r0, r0
	stb r0, 0x3(r5)
	lbz r0, 0x4(r5)
	nor r0, r0, r0
	stb r0, 0x4(r5)
	lbz r0, 0x5(r5)
	nor r0, r0, r0
	stb r0, 0x5(r5)
	lbz r0, 0x6(r5)
	nor r0, r0, r0
	stb r0, 0x6(r5)
	lbz r0, 0x7(r5)
	nor r0, r0, r0
	stb r0, 0x7(r5)
	lbz r0, 0x8(r5)
	nor r0, r0, r0
	stb r0, 0x8(r5)
	lbz r0, 0x9(r5)
	nor r0, r0, r0
	stb r0, 0x9(r5)
	lbz r0, 0xa(r5)
	nor r0, r0, r0
	stb r0, 0xa(r5)
	lbz r0, 0xb(r5)
	nor r0, r0, r0
	stb r0, 0xb(r5)
	lbz r0, 0xc(r5)
	nor r0, r0, r0
	stb r0, 0xc(r5)
	lbz r0, 0xd(r5)
	nor r0, r0, r0
	stb r0, 0xd(r5)
	lbz r0, 0xe(r5)
	nor r0, r0, r0
	stb r0, 0xe(r5)
	lbz r0, 0xf(r5)
	nor r0, r0, r0
	stb r0, 0xf(r5)
	addi r5, r5, 0x10
	bdnz .L_803F91E0
	b .L_803F92B4
.L_803F92AC:
	li r0, 0xff
	stb r0, 0xb(r1)
.L_803F92B4:
	lwz r5, 0x8(r1)
	addi r3, r3, 0x1
	lwz r0, 0xc(r1)
	stw r5, 0x0(r4)
	stw r0, 0x4(r4)
	lwz r5, 0x10(r1)
	lwz r0, 0x14(r1)
	stw r5, 0x8(r4)
	stw r0, 0xc(r4)
	lwz r5, 0x18(r1)
	lwz r0, 0x1c(r1)
	stw r5, 0x10(r4)
	stw r0, 0x14(r4)
	lwz r5, 0x20(r1)
	lwz r0, 0x24(r1)
	stw r5, 0x18(r4)
	stw r0, 0x1c(r4)
	lwz r5, 0x28(r1)
	lwz r0, 0x2c(r1)
	stw r5, 0x20(r4)
	stw r0, 0x24(r4)
.L_803F9308:
	lwz r31, 0x3c(r1)
	lwz r30, 0x38(r1)
	addi r1, r1, 0x40
	blr
.endfn fn_803F8C64
