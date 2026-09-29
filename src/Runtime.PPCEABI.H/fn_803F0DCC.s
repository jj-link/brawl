.include "macros.inc"

.text
.balign 4

.fn __ptmf_test, global
	lwz r5, 0x0(r3)
	lwz r6, 0x4(r3)
	lwz r7, 0x8(r3)
	li r3, 0x1
	cmpwi r5, 0x0
	cmpwi cr6, r6, 0x0
	cmpwi cr7, r7, 0x0
	bnelr
	bnelr cr6
	bnelr cr7
	li r3, 0x0
	blr
.endfn __ptmf_test

.fn fn_803F0DFC, global
	lwz r5, 0x0(r3)
	lwz r6, 0x0(r4)
	lwz r7, 0x4(r3)
	lwz r8, 0x4(r4)
	lwz r9, 0x8(r3)
	lwz r10, 0x8(r4)
	li r3, 0x1
	cmpw r5, r6
	cmpw cr6, r7, r8
	cmpw cr7, r9, r10
	bnelr
	bnelr cr6
	bnelr cr7
	li r3, 0x0
	blr
.endfn fn_803F0DFC

.fn __ptmf_scall, global
	lwz r0, 0x0(r12)
	lwz r11, 0x4(r12)
	lwz r12, 0x8(r12)
	add r3, r3, r0
	cmpwi r11, 0x0
	blt .L_803F0E58
	lwzx r12, r3, r12
	lwzx r12, r12, r11
.L_803F0E58:
	mtctr r12
	bctr
.endfn __ptmf_scall

.fn fn_803F0E60, global
	lwz r0, 0x0(r4)
	lwz r6, 0x4(r4)
	add r3, r0, r3
	lwz r0, 0x8(r4)
	stw r3, 0x0(r5)
	mr r3, r5
	stw r6, 0x4(r5)
	stw r0, 0x8(r5)
	blr
.endfn fn_803F0E60
