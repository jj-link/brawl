# Runtime.PPCEABI.H/fn_803F5EAC.s (auto_fn_803F5EAC_text)

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
	.4byte fn_803F5EAC
	.4byte 0x00000048
	.4byte Letb
.endobj Leti

.text
.balign 4

.fn fn_803F5EAC, global
	stwu r1, -0x10(r1)
	mflr r0
	li r4, 0x0
	li r5, 0x0
	stw r0, 0x14(r1)
	stw r31, 0xc(r1)
	li r31, 0x0
	stw r30, 0x8(r1)
	mr r30, r3
	stb r31, 0xa(r3)
	bl _fseek
	stb r31, 0xa(r30)
	lwz r31, 0xc(r1)
	lwz r30, 0x8(r1)
	lwz r0, 0x14(r1)
	mtlr r0
	addi r1, r1, 0x10
	blr
.endfn fn_803F5EAC
