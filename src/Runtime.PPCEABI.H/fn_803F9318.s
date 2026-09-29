.include "macros.inc"

.section extab, "a"
.balign 4

.obj Letb, local
	.4byte 0x880A0000
	.4byte 0x00000000
.endobj Letb

.section extabindex, "a"
.balign 4

.obj Leti, local
	.4byte fn_803F9318
	.4byte 0x00000D60
	.4byte Letb
.endobj Leti

.text
.balign 4

.fn fn_803F9318, global
	stwu r1, -0xb0(r1)
	mflr r0
	stw r0, 0xb4(r1)
	addi r11, r1, 0xb0
	bl _savegpr_15
	li r0, 0x0
	lis r8, lbl_804942B8@ha
	stw r0, 0x5c(r1)
	li r0, 0x0
	mr r26, r3
	mr r27, r4
	stw r6, 0x8(r1)
	mr r17, r5
	mr r28, r7
	addi r25, r1, 0x20
	stw r0, 0x58(r1)
	addi r23, r8, lbl_804942B8@l
	li r29, 0x0
	li r21, 0x0
	li r20, 0x0
	li r19, 0x0
	li r24, 0x1
	b .L_803FA020
.L_803F9374:
	cmpwi r22, 0x0
	li r0, 0x0
	blt .L_803F9388
	cmpwi r22, 0x100
	blt .L_803F938C
.L_803F9388:
	li r0, 0x1
.L_803F938C:
	cmpwi r0, 0x0
	beq .L_803F939C
	li r0, 0x0
	b .L_803F93B0
.L_803F939C:
	lwz r3, 0x38(r23)
	slwi r0, r22, 1
	lwz r3, 0x8(r3)
	lhzx r0, r3, r0
	rlwinm r0, r0, 0, 23, 23
.L_803F93B0:
	cmpwi r0, 0x0
	beq .L_803F9490
	lwz r4, 0x38(r23)
.L_803F93BC:
	lbzu r3, 0x1(r17)
	li r0, 0x0
	extsb. r5, r3
	blt .L_803F93D4
	cmpwi r5, 0x100
	blt .L_803F93D8
.L_803F93D4:
	li r0, 0x1
.L_803F93D8:
	cmpwi r0, 0x0
	beq .L_803F93E8
	li r0, 0x0
	b .L_803F93F8
.L_803F93E8:
	lwz r3, 0x8(r4)
	slwi r0, r5, 1
	lhzx r0, r3, r0
	rlwinm r0, r0, 0, 23, 23
.L_803F93F8:
	cmpwi r0, 0x0
	bne .L_803F93BC
	cmpwi r29, 0x0
	bne .L_803FA020
	b .L_803F9410
.L_803F940C:
	addi r21, r21, 0x1
.L_803F9410:
	mr r12, r26
	mr r3, r27
	li r4, 0x0
	li r5, 0x0
	mtctr r12
	bctrl
	extsb. r5, r3
	stb r3, 0xc(r1)
	li r0, 0x0
	blt .L_803F9440
	cmpwi r5, 0x100
	blt .L_803F9444
.L_803F9440:
	li r0, 0x1
.L_803F9444:
	cmpwi r0, 0x0
	beq .L_803F9454
	li r0, 0x0
	b .L_803F9468
.L_803F9454:
	lwz r4, 0x38(r23)
	slwi r0, r5, 1
	lwz r4, 0x8(r4)
	lhzx r0, r4, r0
	rlwinm r0, r0, 0, 23, 23
.L_803F9468:
	cmpwi r0, 0x0
	bne .L_803F940C
	clrlwi r4, r3, 24
	mr r12, r26
	mr r3, r27
	li r5, 0x1
	extsb r4, r4
	mtctr r12
	bctrl
	b .L_803FA020
.L_803F9490:
	cmpwi r22, 0x25
	beq .L_803F9508
	cmpwi r29, 0x0
	bne .L_803F9508
	mr r12, r26
	mr r3, r27
	li r4, 0x0
	li r5, 0x0
	mtctr r12
	bctrl
	extsb r4, r3
	clrlwi r0, r22, 24
	cmpw r0, r4
	stb r3, 0xc(r1)
	beq .L_803F94FC
	clrlwi r4, r3, 24
	mr r12, r26
	mr r3, r27
	li r5, 0x1
	extsb r4, r4
	mtctr r12
	bctrl
	cmpwi r28, 0x0
	beq .L_803FA02C
	li r29, 0x1
	addi r17, r17, 0x1
	b .L_803FA020
.L_803F94FC:
	addi r21, r21, 0x1
	addi r17, r17, 0x1
	b .L_803FA020
.L_803F9508:
	mr r3, r17
	addi r4, r1, 0x20
	bl fn_803F8C64
	lbz r0, 0x20(r1)
	mr r17, r3
	cmpwi r0, 0x0
	bne .L_803F9544
	lbz r0, 0x23(r1)
	cmplwi r0, 0x25
	beq .L_803F9544
	lwz r3, 0x8(r1)
	li r4, 0x1
	bl __va_arg
	lwz r22, 0x0(r3)
	b .L_803F9548
.L_803F9544:
	li r22, 0x0
.L_803F9548:
	lbz r0, 0x23(r1)
	cmplwi r0, 0x6e
	beq .L_803F9588
	cmpwi r29, 0x0
	bne .L_803F9588
	mr r12, r26
	mr r3, r27
	li r4, 0x0
	li r5, 0x2
	mtctr r12
	bctrl
	cmpwi r3, 0x0
	beq .L_803F9588
	cmpwi r28, 0x0
	beq .L_803FA02C
	li r29, 0x1
.L_803F9588:
	lbz r0, 0x23(r1)
	cmpwi r0, 0x64
	beq .L_803F9654
	bge .L_803F95F4
	cmpwi r0, 0x58
	beq .L_803F9818
	bge .L_803F95D0
	cmpwi r0, 0x41
	beq .L_803F99A0
	bge .L_803F95BC
	cmpwi r0, 0x25
	beq .L_803F9BFC
	b .L_803FA02C
.L_803F95BC:
	cmpwi r0, 0x48
	bge .L_803FA02C
	cmpwi r0, 0x45
	bge .L_803F99A0
	b .L_803FA02C
.L_803F95D0:
	cmpwi r0, 0x61
	beq .L_803F99A0
	bge .L_803F95E8
	cmpwi r0, 0x5b
	beq .L_803F9D50
	b .L_803FA02C
.L_803F95E8:
	cmpwi r0, 0x63
	bge .L_803F9A50
	b .L_803FA02C
.L_803F95F4:
	cmpwi r0, 0x73
	beq .L_803F9CA8
	bge .L_803F9630
	cmpwi r0, 0x6e
	beq .L_803F9FB8
	bge .L_803F9624
	cmpwi r0, 0x69
	beq .L_803F965C
	bge .L_803FA02C
	cmpwi r0, 0x68
	bge .L_803FA02C
	b .L_803F99A0
.L_803F9624:
	cmpwi r0, 0x70
	bge .L_803FA02C
	b .L_803F9808
.L_803F9630:
	cmpwi r0, 0x78
	beq .L_803F9818
	bge .L_803F9648
	cmpwi r0, 0x75
	beq .L_803F9810
	b .L_803FA02C
.L_803F9648:
	cmpwi r0, 0xff
	beq .L_803FA02C
	b .L_803FA02C
.L_803F9654:
	li r3, 0xa
	b .L_803F9660
.L_803F965C:
	li r3, 0x0
.L_803F9660:
	cmpwi r29, 0x0
	beq .L_803F9680
	li r0, 0x0
	li r16, 0x0
	stw r0, 0x5c(r1)
	li r0, 0x0
	stw r0, 0x58(r1)
	b .L_803F9774
.L_803F9680:
	lbz r0, 0x22(r1)
	cmplwi r0, 0x7
	beq .L_803F9694
	cmplwi r0, 0x4
	bne .L_803F96BC
.L_803F9694:
	lwz r4, 0x24(r1)
	mr r5, r26
	mr r6, r27
	addi r7, r1, 0x18
	addi r8, r1, 0x14
	addi r9, r1, 0x10
	bl fn_803FC0AC
	stw r4, 0x54(r1)
	stw r3, 0x50(r1)
	b .L_803F96DC
.L_803F96BC:
	lwz r4, 0x24(r1)
	mr r5, r26
	mr r6, r27
	addi r7, r1, 0x18
	addi r8, r1, 0x14
	addi r9, r1, 0x10
	bl fn_803FBC7C
	mr r15, r3
.L_803F96DC:
	lwz r3, 0x18(r1)
	cmpwi r3, 0x0
	bne .L_803F970C
	cmpwi r28, 0x0
	beq .L_803FA02C
	li r0, 0x0
	li r29, 0x1
	stw r0, 0x5c(r1)
	li r0, 0x0
	li r16, 0x0
	stw r0, 0x58(r1)
	b .L_803F9774
.L_803F970C:
	lbz r0, 0x22(r1)
	add r21, r21, r3
	cmplwi r0, 0x7
	beq .L_803F9724
	cmplwi r0, 0x4
	bne .L_803F9760
.L_803F9724:
	lwz r0, 0x14(r1)
	cmpwi r0, 0x0
	beq .L_803F974C
	lwz r0, 0x54(r1)
	subfic r0, r0, 0x0
	stw r0, 0x5c(r1)
	lwz r0, 0x50(r1)
	subfze r0, r0
	stw r0, 0x58(r1)
	b .L_803F9774
.L_803F974C:
	lwz r0, 0x54(r1)
	stw r0, 0x5c(r1)
	lwz r0, 0x50(r1)
	stw r0, 0x58(r1)
	b .L_803F9774
.L_803F9760:
	lwz r0, 0x14(r1)
	mr r16, r15
	cmpwi r0, 0x0
	beq .L_803F9774
	neg r16, r15
.L_803F9774:
	cmpwi r22, 0x0
	beq .L_803F9800
	lbz r0, 0x22(r1)
	cmplwi r0, 0x7
	bgt .L_803F97F4
	lis r3, jumptable_80494650@ha
	slwi r0, r0, 2
	addi r3, r3, jumptable_80494650@l
	lwzx r3, r3, r0
	mtctr r3
	bctr
	stw r16, 0x0(r22)
	b .L_803F97F4
	stb r16, 0x0(r22)
	b .L_803F97F4
	sth r16, 0x0(r22)
	b .L_803F97F4
	stw r16, 0x0(r22)
	b .L_803F97F4
	lwz r0, 0x5c(r1)
	stw r0, 0x4(r22)
	lwz r0, 0x58(r1)
	stw r0, 0x0(r22)
	b .L_803F97F4
	stw r16, 0x0(r22)
	b .L_803F97F4
	stw r16, 0x0(r22)
	b .L_803F97F4
	lwz r0, 0x5c(r1)
	stw r0, 0x4(r22)
	lwz r0, 0x58(r1)
	stw r0, 0x0(r22)
.L_803F97F4:
	cmpwi r29, 0x0
	bne .L_803F9800
	addi r20, r20, 0x1
.L_803F9800:
	addi r19, r19, 0x1
	b .L_803FA020
.L_803F9808:
	li r3, 0x8
	b .L_803F981C
.L_803F9810:
	li r3, 0xa
	b .L_803F981C
.L_803F9818:
	li r3, 0x10
.L_803F981C:
	cmpwi r29, 0x0
	beq .L_803F983C
	li r0, 0x0
	li r15, 0x0
	stw r0, 0x54(r1)
	li r0, 0x0
	stw r0, 0x50(r1)
	b .L_803F990C
.L_803F983C:
	lbz r0, 0x22(r1)
	cmplwi r0, 0x7
	beq .L_803F9850
	cmplwi r0, 0x4
	bne .L_803F9878
.L_803F9850:
	lwz r4, 0x24(r1)
	mr r5, r26
	mr r6, r27
	addi r7, r1, 0x18
	addi r8, r1, 0x14
	addi r9, r1, 0x10
	bl fn_803FC0AC
	stw r4, 0x54(r1)
	stw r3, 0x50(r1)
	b .L_803F9898
.L_803F9878:
	lwz r4, 0x24(r1)
	mr r5, r26
	mr r6, r27
	addi r7, r1, 0x18
	addi r8, r1, 0x14
	addi r9, r1, 0x10
	bl fn_803FBC7C
	mr r15, r3
.L_803F9898:
	lwz r3, 0x18(r1)
	cmpwi r3, 0x0
	bne .L_803F98C8
	cmpwi r28, 0x0
	beq .L_803FA02C
	li r0, 0x0
	li r29, 0x1
	stw r0, 0x54(r1)
	li r0, 0x0
	li r15, 0x0
	stw r0, 0x50(r1)
	b .L_803F990C
.L_803F98C8:
	lwz r0, 0x14(r1)
	add r21, r21, r3
	cmpwi r0, 0x0
	beq .L_803F990C
	lbz r0, 0x22(r1)
	cmplwi r0, 0x7
	bne .L_803F98FC
	lwz r0, 0x54(r1)
	subfic r0, r0, 0x0
	stw r0, 0x54(r1)
	lwz r0, 0x50(r1)
	subfze r0, r0
	stw r0, 0x50(r1)
.L_803F98FC:
	lbz r0, 0x22(r1)
	cmplwi r0, 0x7
	beq .L_803F990C
	neg r15, r15
.L_803F990C:
	cmpwi r22, 0x0
	beq .L_803F9998
	lbz r0, 0x22(r1)
	cmplwi r0, 0x7
	bgt .L_803F998C
	lis r3, jumptable_80494630@ha
	slwi r0, r0, 2
	addi r3, r3, jumptable_80494630@l
	lwzx r3, r3, r0
	mtctr r3
	bctr
	stw r15, 0x0(r22)
	b .L_803F998C
	stb r15, 0x0(r22)
	b .L_803F998C
	sth r15, 0x0(r22)
	b .L_803F998C
	stw r15, 0x0(r22)
	b .L_803F998C
	lwz r0, 0x54(r1)
	stw r0, 0x4(r22)
	lwz r0, 0x50(r1)
	stw r0, 0x0(r22)
	b .L_803F998C
	stw r15, 0x0(r22)
	b .L_803F998C
	stw r15, 0x0(r22)
	b .L_803F998C
	lwz r0, 0x54(r1)
	stw r0, 0x4(r22)
	lwz r0, 0x50(r1)
	stw r0, 0x0(r22)
.L_803F998C:
	cmpwi r29, 0x0
	bne .L_803F9998
	addi r20, r20, 0x1
.L_803F9998:
	addi r19, r19, 0x1
	b .L_803FA020
.L_803F99A0:
	cmpwi r29, 0x0
	beq .L_803F99B4
	lis r3, lbl_8059FF68@ha
	lfs f1, lbl_8059FF68@l(r3)
	b .L_803F99F4
.L_803F99B4:
	lwz r3, 0x24(r1)
	mr r4, r26
	mr r5, r27
	addi r6, r1, 0x18
	addi r7, r1, 0x10
	bl fn_803FA804
	lwz r0, 0x18(r1)
	cmpwi r0, 0x0
	bne .L_803F99F0
	cmpwi r28, 0x0
	beq .L_803FA02C
	lis r3, lbl_8059FF68@ha
	li r29, 0x1
	lfs f1, lbl_8059FF68@l(r3)
	b .L_803F99F4
.L_803F99F0:
	add r21, r21, r0
.L_803F99F4:
	cmpwi r22, 0x0
	beq .L_803F9A48
	lbz r0, 0x22(r1)
	cmpwi r0, 0x8
	beq .L_803F9A30
	bge .L_803F9A18
	cmpwi r0, 0x0
	beq .L_803F9A24
	b .L_803F9A3C
.L_803F9A18:
	cmpwi r0, 0xa
	bge .L_803F9A3C
	b .L_803F9A38
.L_803F9A24:
	frsp f0, f1
	stfs f0, 0x0(r22)
	b .L_803F9A3C
.L_803F9A30:
	stfd f1, 0x0(r22)
	b .L_803F9A3C
.L_803F9A38:
	stfd f1, 0x0(r22)
.L_803F9A3C:
	cmpwi r29, 0x0
	bne .L_803F9A48
	addi r20, r20, 0x1
.L_803F9A48:
	addi r19, r19, 0x1
	b .L_803FA020
.L_803F9A50:
	lbz r0, 0x21(r1)
	cmpwi r0, 0x0
	bne .L_803F9A60
	stw r24, 0x24(r1)
.L_803F9A60:
	cmpwi r22, 0x0
	beq .L_803F9B90
	cmpwi r28, 0x0
	beq .L_803F9A84
	lwz r3, 0x8(r1)
	li r31, 0x1
	li r4, 0x1
	bl __va_arg
	lwz r30, 0x0(r3)
.L_803F9A84:
	li r0, 0x0
	cmpwi r29, 0x0
	stw r0, 0x18(r1)
	beq .L_803F9AA8
	cmpwi r30, 0x0
	beq .L_803FA020
	li r0, 0x0
	stb r0, 0x0(r22)
	b .L_803FA020
.L_803F9AA8:
	stw r22, 0x4c(r1)
	b .L_803F9AEC
.L_803F9AB0:
	lbz r0, 0x22(r1)
	stb r3, 0xc(r1)
	cmplwi r0, 0xa
	bne .L_803F9AD8
	mr r3, r22
	addi r4, r1, 0xc
	li r5, 0x1
	bl fn_803F5EF4
	addi r22, r22, 0x1
	b .L_803F9AE0
.L_803F9AD8:
	stb r3, 0x0(r22)
	addi r22, r22, 0x1
.L_803F9AE0:
	lwz r3, 0x18(r1)
	addi r0, r3, 0x1
	stw r0, 0x18(r1)
.L_803F9AEC:
	lwz r4, 0x24(r1)
	subi r3, r4, 0x1
	cmpwi r4, 0x0
	stw r3, 0x24(r1)
	beq .L_803F9B40
	cmpwi r28, 0x0
	beq .L_803F9B1C
	xor r0, r30, r0
	cntlzw r0, r0
	slw r0, r30, r0
	srwi. r31, r0, 31
	beq .L_803F9B40
.L_803F9B1C:
	mr r12, r26
	mr r3, r27
	li r4, 0x0
	li r5, 0x0
	mtctr r12
	bctrl
	cmpwi r3, -0x1
	mr r18, r3
	bne .L_803F9AB0
.L_803F9B40:
	lwz r0, 0x18(r1)
	stb r18, 0xc(r1)
	cmpwi r0, 0x0
	beq .L_803F9B60
	cmpwi r28, 0x0
	beq .L_803F9B84
	cmpwi r31, 0x0
	bne .L_803F9B84
.L_803F9B60:
	cmpwi r28, 0x0
	beq .L_803FA02C
	cmpwi r30, 0x0
	li r29, 0x1
	beq .L_803FA020
	lwz r3, 0x4c(r1)
	li r0, 0x0
	stb r0, 0x0(r3)
	b .L_803FA020
.L_803F9B84:
	add r21, r21, r0
	addi r20, r20, 0x1
	b .L_803F9BF4
.L_803F9B90:
	li r0, 0x0
	stw r0, 0x18(r1)
	b .L_803F9BAC
.L_803F9B9C:
	lwz r4, 0x18(r1)
	stb r3, 0xc(r1)
	addi r0, r4, 0x1
	stw r0, 0x18(r1)
.L_803F9BAC:
	lwz r3, 0x24(r1)
	subi r0, r3, 0x1
	cmpwi r3, 0x0
	stw r0, 0x24(r1)
	beq .L_803F9BE4
	mr r12, r26
	mr r3, r27
	li r4, 0x0
	li r5, 0x0
	mtctr r12
	bctrl
	cmpwi r3, -0x1
	mr r18, r3
	bne .L_803F9B9C
.L_803F9BE4:
	lwz r0, 0x18(r1)
	stb r18, 0xc(r1)
	cmpwi r0, 0x0
	beq .L_803FA02C
.L_803F9BF4:
	addi r19, r19, 0x1
	b .L_803FA020
.L_803F9BFC:
	cmpwi r29, 0x0
	bne .L_803FA020
	b .L_803F9C0C
.L_803F9C08:
	addi r21, r21, 0x1
.L_803F9C0C:
	mr r12, r26
	mr r3, r27
	li r4, 0x0
	li r5, 0x0
	mtctr r12
	bctrl
	extsb. r5, r3
	stb r3, 0xc(r1)
	li r0, 0x0
	blt .L_803F9C3C
	cmpwi r5, 0x100
	blt .L_803F9C40
.L_803F9C3C:
	li r0, 0x1
.L_803F9C40:
	cmpwi r0, 0x0
	beq .L_803F9C50
	li r0, 0x0
	b .L_803F9C64
.L_803F9C50:
	lwz r4, 0x38(r23)
	slwi r0, r5, 1
	lwz r4, 0x8(r4)
	lhzx r0, r4, r0
	rlwinm r0, r0, 0, 23, 23
.L_803F9C64:
	cmpwi r0, 0x0
	bne .L_803F9C08
	clrlwi r0, r3, 24
	extsb r4, r0
	cmpwi r4, 0x25
	beq .L_803F9CA0
	mr r12, r26
	mr r3, r27
	li r5, 0x1
	mtctr r12
	bctrl
	cmpwi r28, 0x0
	beq .L_803FA02C
	li r29, 0x1
	b .L_803FA020
.L_803F9CA0:
	addi r21, r21, 0x1
	b .L_803FA020
.L_803F9CA8:
	cmpwi r29, 0x0
	bne .L_803F9D50
	mr r12, r26
	mr r3, r27
	li r4, 0x0
	li r5, 0x0
	mtctr r12
	bctrl
	stb r3, 0xc(r1)
	b .L_803F9CF0
.L_803F9CD0:
	mr r12, r26
	mr r3, r27
	li r4, 0x0
	li r5, 0x0
	mtctr r12
	addi r21, r21, 0x1
	bctrl
	stb r3, 0xc(r1)
.L_803F9CF0:
	clrlwi r5, r3, 24
	li r0, 0x0
	extsb. r4, r5
	blt .L_803F9D08
	cmpwi r4, 0x100
	blt .L_803F9D0C
.L_803F9D08:
	li r0, 0x1
.L_803F9D0C:
	cmpwi r0, 0x0
	beq .L_803F9D1C
	li r0, 0x0
	b .L_803F9D30
.L_803F9D1C:
	lwz r3, 0x38(r23)
	slwi r0, r4, 1
	lwz r3, 0x8(r3)
	lhzx r0, r3, r0
	rlwinm r0, r0, 0, 23, 23
.L_803F9D30:
	cmpwi r0, 0x0
	bne .L_803F9CD0
	mr r12, r26
	extsb r4, r5
	mr r3, r27
	li r5, 0x1
	mtctr r12
	bctrl
.L_803F9D50:
	cmpwi r22, 0x0
	beq .L_803F9EE4
	cmpwi r28, 0x0
	beq .L_803F9D78
	lwz r3, 0x8(r1)
	li r31, 0x1
	li r4, 0x1
	bl __va_arg
	lwz r3, 0x0(r3)
	subi r30, r3, 0x1
.L_803F9D78:
	li r0, 0x0
	cmpwi r29, 0x0
	stw r0, 0x18(r1)
	beq .L_803F9D9C
	cmpwi r30, 0x0
	beq .L_803FA020
	li r0, 0x0
	stb r0, 0x0(r22)
	b .L_803FA020
.L_803F9D9C:
	stw r22, 0x48(r1)
	b .L_803F9E00
.L_803F9DA4:
	extrwi r0, r3, 5, 24
	clrlwi r5, r3, 29
	add r4, r25, r0
	stb r3, 0xc(r1)
	lbz r0, 0x8(r4)
	slw r4, r24, r5
	clrlwi r3, r3, 24
	and. r0, r4, r0
	beq .L_803F9E58
	lbz r0, 0x22(r1)
	cmplwi r0, 0xa
	bne .L_803F9DEC
	mr r3, r22
	addi r4, r1, 0xc
	li r5, 0x1
	bl fn_803F5EF4
	addi r22, r22, 0x2
	b .L_803F9DF4
.L_803F9DEC:
	stb r3, 0x0(r22)
	addi r22, r22, 0x1
.L_803F9DF4:
	lwz r3, 0x18(r1)
	addi r0, r3, 0x1
	stw r0, 0x18(r1)
.L_803F9E00:
	lwz r4, 0x24(r1)
	subi r3, r4, 0x1
	cmpwi r4, 0x0
	stw r3, 0x24(r1)
	beq .L_803F9E58
	cmpwi r28, 0x0
	beq .L_803F9E34
	subf r4, r0, r30
	orc r3, r30, r0
	srwi r0, r4, 1
	subf r0, r0, r3
	srwi. r31, r0, 31
	beq .L_803F9E58
.L_803F9E34:
	mr r12, r26
	mr r3, r27
	li r4, 0x0
	li r5, 0x0
	mtctr r12
	bctrl
	cmpwi r3, -0x1
	mr r18, r3
	bne .L_803F9DA4
.L_803F9E58:
	lwz r3, 0x18(r1)
	stb r18, 0xc(r1)
	cmpwi r3, 0x0
	beq .L_803F9E78
	cmpwi r28, 0x0
	beq .L_803F9EB8
	cmpwi r31, 0x0
	bne .L_803F9EB8
.L_803F9E78:
	clrlwi r4, r18, 24
	mr r12, r26
	mr r3, r27
	li r5, 0x1
	extsb r4, r4
	mtctr r12
	bctrl
	cmpwi r28, 0x0
	beq .L_803FA02C
	cmpwi r30, 0x0
	li r29, 0x1
	beq .L_803FA020
	lwz r3, 0x48(r1)
	li r0, 0x0
	stb r0, 0x0(r3)
	b .L_803FA020
.L_803F9EB8:
	lbz r0, 0x22(r1)
	add r21, r21, r3
	cmplwi r0, 0xa
	bne .L_803F9ED4
	li r0, 0x0
	sth r0, 0x0(r22)
	b .L_803F9EDC
.L_803F9ED4:
	li r0, 0x0
	stb r0, 0x0(r22)
.L_803F9EDC:
	addi r20, r20, 0x1
	b .L_803F9F88
.L_803F9EE4:
	li r0, 0x0
	stw r0, 0x18(r1)
	b .L_803F9F1C
.L_803F9EF0:
	extrwi r0, r3, 5, 24
	clrlwi r5, r3, 29
	add r4, r25, r0
	stb r3, 0xc(r1)
	lbz r0, 0x8(r4)
	slw r3, r24, r5
	and. r0, r3, r0
	beq .L_803F9F54
	lwz r3, 0x18(r1)
	addi r0, r3, 0x1
	stw r0, 0x18(r1)
.L_803F9F1C:
	lwz r3, 0x24(r1)
	subi r0, r3, 0x1
	cmpwi r3, 0x0
	stw r0, 0x24(r1)
	beq .L_803F9F54
	mr r12, r26
	mr r3, r27
	li r4, 0x0
	li r5, 0x0
	mtctr r12
	bctrl
	cmpwi r3, -0x1
	mr r18, r3
	bne .L_803F9EF0
.L_803F9F54:
	lwz r0, 0x18(r1)
	stb r18, 0xc(r1)
	cmpwi r0, 0x0
	bne .L_803F9F84
	clrlwi r4, r18, 24
	mr r12, r26
	mr r3, r27
	li r5, 0x1
	extsb r4, r4
	mtctr r12
	bctrl
	b .L_803FA020
.L_803F9F84:
	add r21, r21, r0
.L_803F9F88:
	lwz r0, 0x24(r1)
	cmpwi r0, 0x0
	blt .L_803F9FB0
	lbz r4, 0xc(r1)
	mr r12, r26
	mr r3, r27
	li r5, 0x1
	extsb r4, r4
	mtctr r12
	bctrl
.L_803F9FB0:
	addi r19, r19, 0x1
	b .L_803FA020
.L_803F9FB8:
	cmpwi r22, 0x0
	beq .L_803FA020
	lbz r0, 0x22(r1)
	cmpwi r0, 0x3
	beq .L_803FA004
	bge .L_803F9FE8
	cmpwi r0, 0x1
	beq .L_803FA00C
	bge .L_803F9FFC
	cmpwi r0, 0x0
	bge .L_803F9FF4
	b .L_803FA020
.L_803F9FE8:
	cmpwi r0, 0x7
	beq .L_803FA014
	b .L_803FA020
.L_803F9FF4:
	stw r21, 0x0(r22)
	b .L_803FA020
.L_803F9FFC:
	sth r21, 0x0(r22)
	b .L_803FA020
.L_803FA004:
	stw r21, 0x0(r22)
	b .L_803FA020
.L_803FA00C:
	stb r21, 0x0(r22)
	b .L_803FA020
.L_803FA014:
	stw r21, 0x4(r22)
	srawi r0, r21, 31
	stw r0, 0x0(r22)
.L_803FA020:
	lbz r0, 0x0(r17)
	extsb. r22, r0
	bne .L_803F9374
.L_803FA02C:
	mr r12, r26
	mr r3, r27
	li r4, 0x0
	li r5, 0x2
	mtctr r12
	bctrl
	cmpwi r3, 0x0
	beq .L_803FA05C
	cmpwi r19, 0x0
	bne .L_803FA05C
	li r3, -0x1
	b .L_803FA060
.L_803FA05C:
	mr r3, r20
.L_803FA060:
	addi r11, r1, 0xb0
	bl _restgpr_15
	lwz r0, 0xb4(r1)
	mtlr r0
	addi r1, r1, 0xb0
	blr
.endfn fn_803F9318
