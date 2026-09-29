# Runtime.PPCEABI.H/fn_803F5060.s (auto_03_803F5060_text)
#
# Reconstructed at assembly level from the Brawl target
# (build/RSBE01_02/asm/auto_03_803F5060_text.s), following the fn_803F1B64.s precedent.
# fn_803F5060 + __prep_buffer (MW stdio buffer preparation helper).

.include "macros.inc"

.text
.balign 4
.fn fn_803F5060, global
	srawi r4, r3, 31
	xor r0, r4, r3
	subf r3, r4, r0
	blr
.endfn fn_803F5060
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
