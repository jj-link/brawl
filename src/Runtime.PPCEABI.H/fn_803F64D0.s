# Runtime.PPCEABI.H/fn_803F64D0.s (auto_fn_803F64D0_text)

.include "macros.inc"

.section extab, "a"
.balign 4

.obj Letb, local
	.4byte 0x00080000
	.4byte 0x00000000
.endobj Letb

.section extabindex, "a"
.balign 4

.obj Leti, local
	.4byte fn_803F64D0
	.4byte 0x00000018
	.4byte Letb
.endobj Leti

.text
.balign 4

.fn fn_803F64D0, global
	stwu r1, -0x10(r1)
	stfd f1, 0x8(r1)
	lwz r0, 0x8(r1)
	clrrwi r3, r0, 31
	addi r1, r1, 0x10
	blr
.endfn fn_803F64D0
