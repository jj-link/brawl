.include "macros.inc"

.text
.balign 4

.fn fn_80400B30, global
	b fn_803FCB54
.endfn fn_80400B30

# .text:0x250 | 0x80400B34 | size: 0x4
.fn fn_80400B34, global
	b fn_803FCE18
.endfn fn_80400B34

# .text:0x254 | 0x80400B38 | size: 0x4
.fn atan2, global
	b fn_803FD0B0
.endfn atan2

# .text:0x258 | 0x80400B3C | size: 0x4
.fn fn_80400B3C, global
	b fn_803FD320
.endfn fn_80400B3C

# .text:0x25C | 0x80400B40 | size: 0x4
.fn fn_80400B40, global
	b fn_803FD904
.endfn fn_80400B40

# .text:0x260 | 0x80400B44 | size: 0x4
.fn fn_80400B44, global
	b fn_803FDA18
.endfn fn_80400B44

# .text:0x264 | 0x80400B48 | size: 0x248
.fn fn_80400B48, global
	stwu r1, -0x20(r1)
	stfd f1, 0x8(r1)
	lwz r6, 0x8(r1)
	lwz r0, 0xc(r1)
	rlwinm r3, r6, 0, 1, 11
	subis r3, r3, 0x7ff0
	cmplwi r3, 0x0
	bne .L_80400B7C
	fmul f0, f1, f1
	li r0, 0x21
	stw r0, lbl_805A12E0@sda21(r0)
	fadd f1, f1, f0
	b .L_80400D88
.L_80400B7C:
	cmpwi cr1, r6, 0x0
	bgt cr1, .L_80400BAC
	clrlwi r3, r6, 1
	or. r3, r0, r3
	bne .L_80400B94
	b .L_80400D88
.L_80400B94:
	bge cr1, .L_80400BAC
	li r0, 0x21
	lis r3, lbl_8059FF68@ha
	stw r0, lbl_805A12E0@sda21(r0)
	lfs f1, lbl_8059FF68@l(r3)
	b .L_80400D88
.L_80400BAC:
	srawi. r3, r6, 20
	bne .L_80400C00
	b .L_80400BC8
.L_80400BB8:
	srwi r4, r0, 11
	slwi r0, r0, 21
	or r6, r6, r4
	subi r3, r3, 0x15
.L_80400BC8:
	cmpwi r6, 0x0
	beq .L_80400BB8
	li r7, 0x0
	b .L_80400BE0
.L_80400BD8:
	slwi r6, r6, 1
	addi r7, r7, 0x1
.L_80400BE0:
	rlwinm. r4, r6, 0, 11, 11
	beq .L_80400BD8
	subfic r4, r7, 0x20
	subi r5, r7, 0x1
	srw r4, r0, r4
	slw r0, r0, r7
	subf r3, r5, r3
	or r6, r6, r4
.L_80400C00:
	subi r4, r3, 0x3ff
	clrlwi r5, r6, 12
	clrlwi. r4, r4, 31
	oris r6, r5, 0x10
	beq .L_80400C24
	srwi r5, r0, 31
	add r4, r6, r6
	add r6, r5, r4
	add r0, r0, r0
.L_80400C24:
	srwi r5, r0, 31
	add r4, r6, r6
	add r6, r5, r4
	add r0, r0, r0
	li r9, 0x0
	li r11, 0x0
	li r10, 0x0
	li r12, 0x0
	lis r7, 0x20
	b .L_80400C78
.L_80400C4C:
	add r4, r11, r7
	cmpw r4, r6
	bgt .L_80400C64
	add r11, r4, r7
	subf r6, r4, r6
	add r12, r12, r7
.L_80400C64:
	srwi r5, r0, 31
	add r4, r6, r6
	add r6, r5, r4
	add r0, r0, r0
	srwi r7, r7, 1
.L_80400C78:
	cmpwi r7, 0x0
	bne .L_80400C4C
	lis r7, 0x8000
	b .L_80400CF0
.L_80400C88:
	cmpw r11, r6
	mr r5, r11
	add r8, r9, r7
	blt .L_80400CA4
	bne .L_80400CDC
	cmplw r8, r0
	bgt .L_80400CDC
.L_80400CA4:
	clrrwi r4, r8, 31
	add r9, r8, r7
	addis r4, r4, 0x8000
	cmplwi r4, 0x0
	bne .L_80400CC4
	clrrwi. r4, r9, 31
	bne .L_80400CC4
	addi r11, r11, 0x1
.L_80400CC4:
	cmplw r0, r8
	subf r6, r5, r6
	bge .L_80400CD4
	subi r6, r6, 0x1
.L_80400CD4:
	subf r0, r8, r0
	add r10, r10, r7
.L_80400CDC:
	srwi r5, r0, 31
	add r4, r6, r6
	add r6, r5, r4
	add r0, r0, r0
	srwi r7, r7, 1
.L_80400CF0:
	cmpwi r7, 0x0
	bne .L_80400C88
	or. r0, r6, r0
	beq .L_80400D54
	lfd f0, lbl_805A5108@sda21(r0)
	fcmpo cr0, f0, f0
	stfd f0, 0x10(r1)
	cror eq, gt, eq
	bne .L_80400D54
	addis r0, r10, 0x1
	stfd f0, 0x10(r1)
	cmplwi r0, 0xffff
	bne .L_80400D30
	li r10, 0x0
	addi r12, r12, 0x1
	b .L_80400D54
.L_80400D30:
	fcmpo cr0, f0, f0
	ble .L_80400D4C
	cmplwi r0, 0xfffe
	bne .L_80400D44
	addi r12, r12, 0x1
.L_80400D44:
	addi r10, r10, 0x2
	b .L_80400D54
.L_80400D4C:
	clrlwi r0, r10, 31
	add r10, r10, r0
.L_80400D54:
	clrlwi r0, r12, 31
	srawi r4, r12, 1
	cmpwi r0, 0x1
	srwi r5, r10, 1
	addis r4, r4, 0x3fe0
	bne .L_80400D70
	oris r5, r5, 0x8000
.L_80400D70:
	subi r0, r3, 0x3ff
	stw r5, 0x14(r1)
	extlwi r0, r0, 12, 19
	add r4, r4, r0
	stw r4, 0x10(r1)
	lfd f1, 0x10(r1)
.L_80400D88:
	addi r1, r1, 0x20
	blr
.endfn fn_80400B48
