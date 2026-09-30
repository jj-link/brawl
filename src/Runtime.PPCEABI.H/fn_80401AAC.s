.include "macros.inc"

.text
.balign 4

.fn TRKInitializeSerialHandler, global
	lis r3, lbl_8059B928@ha
	li r5, -0x1
	addi r4, r3, lbl_8059B928@l
	li r0, 0x0
	stw r5, 0x0(r4)
	li r3, 0x0
	stw r0, 0x8(r4)
	stw r0, 0xc(r4)
	blr
.endfn TRKInitializeSerialHandler
