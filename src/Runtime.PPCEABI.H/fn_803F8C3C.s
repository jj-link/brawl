.include "macros.inc"

.text
.balign 4

.fn rand, global
	lis r3, 0x41c6
	lwz r4, lbl_8059FF58@sda21(r0)
	addi r0, r3, 0x4e6d
	mullw r3, r4, r0
	addi r0, r3, 0x3039
	stw r0, lbl_8059FF58@sda21(r0)
	extrwi r3, r0, 15, 1
	blr
.endfn rand

.fn fn_803F8C5C, global
	stw r3, lbl_8059FF58@sda21(r0)
	blr
.endfn fn_803F8C5C
