.include "macros.inc"

.section extab, "a"
.balign 4

.obj Letb, local
.4byte 0x38080000
	.4byte 0x00000000
.endobj Letb

.section extabindex, "a"
.balign 4

.obj Leti, local
	.4byte fn_803F5250
	.4byte 0x00000340
	.4byte Letb
.endobj Leti

.text
.balign 4

.fn fn_803F5250, global
	stwu r1, -0x30(r1)
	mflr r0
	stw r0, 0x34(r1)
	stmw r25, 0x14(r1)
	mr r27, r4
	mr r28, r6
	mr r26, r3
	mr r25, r5
	li r4, 0x0
	mr r3, r28
	bl fwide
	cmpwi r3, 0x0
	bne .L_803F5290
	mr r3, r28
	li r4, -0x1
	bl fwide
.L_803F5290:
	mullw. r30, r27, r25
	beq .L_803F52B0
	lbz r0, 0xa(r28)
	cmpwi r0, 0x0
	bne .L_803F52B0
	lwz r3, 0x4(r28)
	extrwi. r0, r3, 3, 7
	bne .L_803F52B8
.L_803F52B0:
	li r3, 0x0
	b .L_803F557C
.L_803F52B8:
	extrwi. r0, r3, 1, 12
	li r31, 0x1
	beq .L_803F52D4
	extrwi r0, r3, 2, 5
	cmplwi r0, 0x2
	beq .L_803F52D4
	li r31, 0x0
.L_803F52D4:
	lwz r3, 0x8(r28)
	srwi. r0, r3, 29
	bne .L_803F5300
	lwz r0, 0x4(r28)
	extrwi. r0, r0, 1, 4
	beq .L_803F5300
	li r0, 0x2
	rlwimi r3, r0, 29, 0, 2
	li r0, 0x0
	stw r3, 0x8(r28)
	stw r0, 0x28(r28)
.L_803F5300:
	lwz r0, 0x8(r28)
	srwi r0, r0, 29
	cmplwi r0, 0x2
	bge .L_803F5328
	li r3, 0x1
	li r0, 0x0
	stb r3, 0xa(r28)
	li r3, 0x0
	stw r0, 0x28(r28)
	b .L_803F557C
.L_803F5328:
	lwz r0, 0x4(r28)
	extrwi. r0, r0, 1, 6
	beq .L_803F5358
	bl fn_803F3600
	cmpwi r3, 0x0
	beq .L_803F5358
	li r3, 0x1
	li r0, 0x0
	stb r3, 0xa(r28)
	li r3, 0x0
	stw r0, 0x28(r28)
	b .L_803F557C
.L_803F5358:
	cmpwi r30, 0x0
	li r29, 0x0
	beq .L_803F540C
	lwz r0, 0x8(r28)
	srwi r0, r0, 29
	cmplwi r0, 0x3
	blt .L_803F540C
.L_803F5374:
	mr r3, r28
	li r4, 0x0
	bl fwide
	cmpwi r3, 0x1
	bne .L_803F53AC
	lwz r0, 0x8(r28)
	addi r29, r29, 0x2
	subi r30, r30, 0x2
	rlwinm r0, r0, 4, 28, 30
	add r3, r28, r0
	lhz r0, 0xc(r3)
	sth r0, 0x0(r26)
	addi r26, r26, 0x2
	b .L_803F53CC
.L_803F53AC:
	lwz r0, 0x8(r28)
	addi r29, r29, 0x1
	subi r30, r30, 0x1
	srwi r0, r0, 29
	add r3, r28, r0
	lbz r0, 0xc(r3)
	stb r0, 0x0(r26)
	addi r26, r26, 0x1
.L_803F53CC:
	lwz r4, 0x8(r28)
	cmpwi r30, 0x0
	srwi r3, r4, 29
	subi r0, r3, 0x1
	rlwimi r4, r0, 29, 0, 2
	stw r4, 0x8(r28)
	beq .L_803F53F4
	srwi r0, r4, 29
	cmplwi r0, 0x3
	bge .L_803F5374
.L_803F53F4:
	lwz r0, 0x8(r28)
	srwi r0, r0, 29
	cmplwi r0, 0x2
	bne .L_803F540C
	lwz r0, 0x30(r28)
	stw r0, 0x28(r28)
.L_803F540C:
	cmpwi r30, 0x0
	beq .L_803F54E8
	lwz r0, 0x28(r28)
	cmpwi r0, 0x0
	bne .L_803F5428
	cmpwi r31, 0x0
	beq .L_803F54E8
.L_803F5428:
	lwz r0, 0x28(r28)
	cmpwi r0, 0x0
	bne .L_803F548C
	mr r3, r28
	li r4, 0x0
	li r5, 0x0
	bl fn_803F5098
	cmpwi r3, 0x0
	beq .L_803F548C
	cmpwi r3, 0x1
	bne .L_803F5468
	li r3, 0x1
	li r0, 0x0
	stb r3, 0xa(r28)
	stw r0, 0x28(r28)
	b .L_803F5484
.L_803F5468:
	lwz r3, 0x8(r28)
	li r4, 0x0
	li r0, 0x1
	stw r4, 0x28(r28)
	clrlwi r3, r3, 3
	stw r3, 0x8(r28)
	stb r0, 0x9(r28)
.L_803F5484:
	li r30, 0x0
	b .L_803F54E8
.L_803F548C:
	lwz r5, 0x28(r28)
	cmplw r5, r30
	stw r5, 0x8(r1)
	ble .L_803F54A4
	mr r5, r30
	stw r30, 0x8(r1)
.L_803F54A4:
	lwz r4, 0x24(r28)
	mr r3, r26
	bl memcpy
	lwz r4, 0x8(r1)
	lwz r3, 0x24(r28)
	lwz r0, 0x28(r28)
	subf. r30, r4, r30
	add r3, r3, r4
	add r26, r26, r4
	stw r3, 0x24(r28)
	add r29, r29, r4
	lwz r3, 0x8(r1)
	subf r0, r3, r0
	stw r0, 0x28(r28)
	beq .L_803F54E8
	cmpwi r31, 0x0
	bne .L_803F5428
.L_803F54E8:
	cmpwi r30, 0x0
	beq .L_803F5578
	cmpwi r31, 0x0
	bne .L_803F5578
	lwz r31, 0x1c(r28)
	mr r3, r28
	lwz r25, 0x20(r28)
	addi r4, r1, 0x8
	stw r26, 0x1c(r28)
	li r5, 0x1
	stw r30, 0x20(r28)
	bl fn_803F5098
	cmpwi r3, 0x0
	beq .L_803F5558
	cmpwi r3, 0x1
	bne .L_803F553C
	li r3, 0x1
	li r0, 0x0
	stb r3, 0xa(r28)
	stw r0, 0x28(r28)
	b .L_803F5558
.L_803F553C:
	lwz r3, 0x8(r28)
	li r4, 0x0
	li r0, 0x1
	stw r4, 0x28(r28)
	clrlwi r3, r3, 3
	stw r3, 0x8(r28)
	stb r0, 0x9(r28)
.L_803F5558:
	lwz r0, 0x8(r1)
	mr r3, r28
	stw r31, 0x1c(r28)
	add r29, r29, r0
	stw r25, 0x20(r28)
	bl __prep_buffer
	li r0, 0x0
	stw r0, 0x28(r28)
.L_803F5578:
	divwu r3, r29, r27
.L_803F557C:
	lmw r25, 0x14(r1)
	lwz r0, 0x34(r1)
	mtlr r0
	addi r1, r1, 0x30
	blr
.endfn fn_803F5250
