# Runtime.PPCEABI.H/fn_803F5070.s (__prep_buffer residual assembly)

.include "macros.inc"

.text
.balign 4
.fn __prep_buffer, global
	lwz r4, 0x18(r3)
	lwz r0, 0x2c(r3)
	lwz r6, 0x1c(r3)
	lwz r5, 0x20(r3)
	and r0, r4, r0
	stw r6, 0x24(r3)
	subf r0, r0, r5
	stw r0, 0x28(r3)
	stw r4, 0x34(r3)
	blr
.endfn __prep_buffer
