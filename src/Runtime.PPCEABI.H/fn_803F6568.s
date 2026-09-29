# Runtime.PPCEABI.H/fn_803F6568.s (auto_03_803F6568_text)

.include "macros.inc"

.text
.balign 4

.fn __stdio_atexit, global
	lis r3, __close_all@ha
	addi r3, r3, __close_all@l
	stw r3, __stdio_exit@sda21(r0)
	blr
.endfn __stdio_atexit
