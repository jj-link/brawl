# Runtime.PPCEABI.H/fn_804006F0.s (auto_03_804004AC_text)

.include "macros.inc"

.text
.balign 4

# .text:0x244 | 0x804006F0 | size: 0x88
.fn fn_804006F0, global
	stwu r1, -0x10(r1)
	li r4, 0x0
	lis r0, 0x7ff0
	stfd f1, 0x8(r1)
	lwz r5, 0x8(r1)
	stw r4, 0x0(r3)
	clrlwi r4, r5, 1
	lwz r6, 0xc(r1)
	cmpw r4, r0
	bge .L_80400770
	or. r0, r4, r6
	bne .L_80400724
	b .L_80400770
.L_80400724:
	lis r0, 0x10
	cmpw r4, r0
	bge .L_8040074C
	lfd f0, lbl_805A50C8@sda21(r0)
	li r0, -0x36
	stw r0, 0x0(r3)
	fmul f1, f1, f0
	stfd f1, 0x8(r1)
	lwz r5, 0x8(r1)
	clrlwi r4, r5, 1
.L_8040074C:
	rlwinm r0, r5, 0, 12, 0
	lwz r5, 0x0(r3)
	srawi r4, r4, 20
	oris r0, r0, 0x3fe0
	stw r0, 0x8(r1)
	add r4, r4, r5
	subi r0, r4, 0x3fe
	stw r0, 0x0(r3)
	lfd f1, 0x8(r1)
.L_80400770:
	addi r1, r1, 0x10
	blr
.endfn fn_804006F0

# .text:0x2CC | 0x80400778 | size: 0x16C
.fn fn_80400778, global
	stwu r1, -0x20(r1)
	mflr r0
	stw r0, 0x24(r1)
	stfd f31, 0x18(r1)
	fmr f31, f1
	stw r31, 0x14(r1)
	mr r31, r3
	stfd f1, 0x8(r1)
	bl fn_803F64E8
	cmpwi r3, 0x2
	ble .L_804007B0
	lfd f0, lbl_805A50D0@sda21(r0)
	fcmpu cr0, f0, f31
	bne .L_804007B8
.L_804007B0:
	fmr f1, f31
	b .L_804008CC
.L_804007B8:
	lwz r5, 0x8(r1)
	lwz r3, 0xc(r1)
	extrwi. r4, r5, 11, 1
	bne .L_80400810
	clrlwi r0, r5, 1
	or. r0, r3, r0
	bne .L_804007DC
	fmr f1, f31
	b .L_804008CC
.L_804007DC:
	lfd f0, lbl_805A50D8@sda21(r0)
	lis r3, 0xffff
	addi r0, r3, 0x3cb0
	fmul f31, f31, f0
	cmpw r31, r0
	stfd f31, 0x8(r1)
	lwz r5, 0x8(r1)
	extrwi r3, r5, 11, 1
	subi r4, r3, 0x36
	bge .L_80400810
	lfd f0, lbl_805A50E0@sda21(r0)
	fmul f1, f0, f31
	b .L_804008CC
.L_80400810:
	cmpwi r4, 0x7ff
	bne .L_80400820
	fadd f1, f31, f31
	b .L_804008CC
.L_80400820:
	add r4, r4, r31
	cmpwi r4, 0x7fe
	ble .L_80400844
	fmr f2, f31
	lfd f1, lbl_805A50E8@sda21(r0)
	bl fn_804004AC
	lfd f0, lbl_805A50E8@sda21(r0)
	fmul f1, f0, f1
	b .L_804008CC
.L_80400844:
	cmpwi r4, 0x0
	ble .L_80400864
	rlwinm r3, r5, 0, 12, 0
	slwi r0, r4, 20
	or r0, r3, r0
	stw r0, 0x8(r1)
	lfd f1, 0x8(r1)
	b .L_804008CC
.L_80400864:
	cmpwi r4, -0x36
	bgt .L_804008AC
	lis r3, 0x1
	subi r0, r3, 0x3cb0
	cmpw r31, r0
	ble .L_80400894
	fmr f2, f31
	lfd f1, lbl_805A50E8@sda21(r0)
	bl fn_804004AC
	lfd f0, lbl_805A50E8@sda21(r0)
	fmul f1, f0, f1
	b .L_804008CC
.L_80400894:
	fmr f2, f31
	lfd f1, lbl_805A50E0@sda21(r0)
	bl fn_804004AC
	lfd f0, lbl_805A50E0@sda21(r0)
	fmul f1, f0, f1
	b .L_804008CC
.L_804008AC:
	addi r0, r4, 0x36
	rlwinm r3, r5, 0, 12, 0
	slwi r0, r0, 20
	lfd f1, lbl_805A50F0@sda21(r0)
	or r0, r3, r0
	stw r0, 0x8(r1)
	lfd f0, 0x8(r1)
	fmul f1, f1, f0
.L_804008CC:
	lwz r0, 0x24(r1)
	lfd f31, 0x18(r1)
	lwz r31, 0x14(r1)
	mtlr r0
	addi r1, r1, 0x20
	blr
.endfn fn_80400778

