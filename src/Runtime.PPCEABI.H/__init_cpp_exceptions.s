# Runtime.PPCEABI.H/__init_cpp_exceptions.s
#
# Reconstructed at assembly level: the original unit was compiled by MWCC 4.x (see .comment of the
# extracted object) whose section emission order (.text, .ctors$10, .dtors$10, .dtors$15, .sdata)
# cannot be reproduced by the project's MWCC 3.0a5.2 — and mwldeppc drops the .ctors$10/.dtors$15
# fragments when .sdata precedes them. The code itself matches the C reconstruction
# (see doldecomp/melee src/Runtime/__init_cpp_exceptions.c for provenance).

.include "macros.inc"

.text

.global __init_cpp_exceptions
__init_cpp_exceptions:
	stwu r1, -0x10(r1)
	mflr r0
	stw r0, 0x14(r1)
	lwz r0, fragmentID@sda21(r13)
	cmpwi r0, -2
	bne .Lskip_init
	lis r3, _eti_init_info@ha
	mr r4, r2
	addi r3, r3, _eti_init_info@l
	bl __register_fragment
	stw r3, fragmentID@sda21(r13)
.Lskip_init:
	lwz r0, 0x14(r1)
	mtlr r0
	addi r1, r1, 0x10
	blr

.global __fini_cpp_exceptions
__fini_cpp_exceptions:
	stwu r1, -0x10(r1)
	mflr r0
	stw r0, 0x14(r1)
	lwz r3, fragmentID@sda21(r13)
	cmpwi r3, -2
	beq .Lskip_fini
	bl __unregister_fragment
	li r0, -2
	stw r0, fragmentID@sda21(r13)
.Lskip_fini:
	lwz r0, 0x14(r1)
	mtlr r0
	addi r1, r1, 0x10
	blr

.section .ctors$10, "a"
.globl __init_cpp_exceptions_reference
__init_cpp_exceptions_reference:
	.4byte __init_cpp_exceptions

.section .dtors$10, "a"
.globl __destroy_global_chain_reference
__destroy_global_chain_reference:
	.4byte __destroy_global_chain

.section .dtors$15, "a"
.globl __fini_cpp_exceptions_reference
__fini_cpp_exceptions_reference:
	.4byte __fini_cpp_exceptions

.section .sdata, "wa"
	.balign 8
fragmentID:
	.4byte 0xFFFFFFFE
