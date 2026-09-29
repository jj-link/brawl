.include "macros.inc"
.text
.balign 4

.fn fn_8040369C, global
	cmplwi r5, 0x20
	clrlwi r4, r4, 24
	subi r6, r3, 0x1
	mr r7, r4
	blt .L_8040373C
	nor r0, r6, r6
	clrlwi. r3, r0, 30
	beq .L_804036CC
	subf r5, r3, r5
.L_804036C0:
	subic. r3, r3, 0x1
	stbu r7, 0x1(r6)
	bne .L_804036C0
.L_804036CC:
	cmplwi r7, 0x0
	beq .L_804036EC
	slwi r3, r7, 24
	slwi r0, r7, 16
	slwi r4, r7, 8
	or r0, r3, r0
	or r0, r4, r0
	or r7, r7, r0
.L_804036EC:
	srwi. r4, r5, 5
	subi r3, r6, 0x3
	beq .L_80403720
.L_804036F8:
	stw r7, 0x4(r3)
	subic. r4, r4, 0x1
	stw r7, 0x8(r3)
	stw r7, 0xc(r3)
	stw r7, 0x10(r3)
	stw r7, 0x14(r3)
	stw r7, 0x18(r3)
	stw r7, 0x1c(r3)
	stwu r7, 0x20(r3)
	bne .L_804036F8
.L_80403720:
	extrwi. r4, r5, 3, 27
	beq .L_80403734
.L_80403728:
	subic. r4, r4, 0x1
	stwu r7, 0x4(r3)
	bne .L_80403728
.L_80403734:
	addi r6, r3, 0x3
	clrlwi r5, r5, 30
.L_8040373C:
	cmplwi r5, 0x0
	beqlr
.L_80403744:
	subic. r5, r5, 0x1
	stbu r7, 0x1(r6)
	bne .L_80403744
	blr
.endfn fn_8040369C

.fn fn_80403754, global
	subi r4, r3, 0x1
	li r3, -0x1
.L_8040375C:
	lbzu r0, 0x1(r4)
	addi r3, r3, 0x1
	cmplwi r0, 0x0
	bne .L_8040375C
	blr
.endfn fn_80403754

.fn fn_80403770, global
	mfmsr r3
	blr
.endfn fn_80403770

.fn fn_80403778, global
	mtmsr r3
	blr
.endfn fn_80403778

.fn fn_80403780, global
	mfmsr r8
	li r10, 0x0
.L_80403788:
	cmpw r10, r5
	beq .L_804037B0
	mtmsr r7
	sync
	lbzx r9, r10, r4
	mtmsr r6
	sync
	stbx r9, r10, r3
	addi r10, r10, 0x1
	b .L_80403788
.L_804037B0:
	mtmsr r8
	sync
	blr
.endfn fn_80403780
