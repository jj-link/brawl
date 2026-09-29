# Runtime.PPCEABI.H/fn_803F3EAC.s (auto_03_803F3EAC_text)
#
# Reconstructed at assembly level from the Brawl target
# (build/RSBE01_02/asm/auto_03_803F3EAC_text.s), following the fn_803F1B64.s precedent.

.include "macros.inc"

.text
.balign 4
.fn fn_803F3EAC, global
	lbz r5, 0x5(r3)
	cmpwi r5, 0x0
	bne .L_803F3EC8
	lbz r0, 0x5(r4)
	cntlzw r0, r0
	srwi r3, r0, 5
	blr
.L_803F3EC8:
	lbz r0, 0x5(r4)
	cmpwi r0, 0x0
	bne .L_803F3EE0
	cntlzw r0, r5
	srwi r3, r0, 5
	blr
.L_803F3EE0:
	lha r5, 0x2(r3)
	lha r0, 0x2(r4)
	cmpw r5, r0
	bne .L_803F3F88
	lbz r7, 0x4(r3)
	lbz r0, 0x4(r4)
	mr r9, r7
	cmpw r7, r0
	ble .L_803F3F08
	mr r9, r0
.L_803F3F08:
	li r8, 0x0
	mtctr r9
	cmpwi r9, 0x0
	ble .L_803F3F40
.L_803F3F18:
	add r6, r3, r8
	add r5, r4, r8
	lbz r6, 0x5(r6)
	lbz r0, 0x5(r5)
	cmplw r6, r0
	beq .L_803F3F38
	li r3, 0x0
	blr
.L_803F3F38:
	addi r8, r8, 0x1
	bdnz .L_803F3F18
.L_803F3F40:
	cmpw r9, r7
	bne .L_803F3F4C
	mr r3, r4
.L_803F3F4C:
	lbz r4, 0x4(r3)
	subf r0, r8, r4
	mtctr r0
	cmpw r8, r4
	bge .L_803F3F80
.L_803F3F60:
	add r4, r3, r8
	lbz r0, 0x5(r4)
	cmpwi r0, 0x0
	beq .L_803F3F78
	li r3, 0x0
	blr
.L_803F3F78:
	addi r8, r8, 0x1
	bdnz .L_803F3F60
.L_803F3F80:
	li r3, 0x1
	blr
.L_803F3F88:
	li r3, 0x0
	blr
.endfn fn_803F3EAC
.fn fn_803F3F90, global
	lbz r0, 0x5(r3)
	cmpwi r0, 0x0
	bne .L_803F3FB0
	lbz r3, 0x5(r4)
	neg r0, r3
	or r0, r0, r3
	srwi r3, r0, 31
	blr
.L_803F3FB0:
	lbz r0, 0x5(r4)
	cmpwi r0, 0x0
	bne .L_803F3FC4
	li r3, 0x0
	blr
.L_803F3FC4:
	lha r5, 0x2(r4)
	lha r0, 0x2(r3)
	cmpw r0, r5
	bne .L_803F4078
	lbz r7, 0x4(r3)
	lbz r0, 0x4(r4)
	mr r9, r7
	cmpw r7, r0
	ble .L_803F3FEC
	mr r9, r0
.L_803F3FEC:
	li r8, 0x0
	mtctr r9
	cmpwi r9, 0x0
	ble .L_803F4034
.L_803F3FFC:
	add r6, r4, r8
	add r5, r3, r8
	lbz r6, 0x5(r6)
	lbz r0, 0x5(r5)
	cmplw r0, r6
	bge .L_803F401C
	li r3, 0x1
	blr
.L_803F401C:
	cmplw r6, r0
	bge .L_803F402C
	li r3, 0x0
	blr
.L_803F402C:
	addi r8, r8, 0x1
	bdnz .L_803F3FFC
.L_803F4034:
	cmpw r9, r7
	bne .L_803F4070
	lbz r3, 0x4(r4)
	subf r0, r8, r3
	mtctr r0
	cmpw r8, r3
	bge .L_803F4070
.L_803F4050:
	add r3, r4, r8
	lbz r0, 0x5(r3)
	cmpwi r0, 0x0
	beq .L_803F4068
	li r3, 0x1
	blr
.L_803F4068:
	addi r8, r8, 0x1
	bdnz .L_803F4050
.L_803F4070:
	li r3, 0x0
	blr
.L_803F4078:
	xor r0, r5, r0
	srawi r3, r0, 1
	and r0, r0, r5
	subf r0, r0, r3
	srwi r3, r0, 31
	blr
.endfn fn_803F3F90
