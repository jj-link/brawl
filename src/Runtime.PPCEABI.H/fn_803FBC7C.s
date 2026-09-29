# Runtime.PPCEABI.H/fn_803FBC7C.s (auto_fn_803FBC7C_text)

.include "macros.inc"

.section extab, "a"
.balign 4

.obj Letb, local
	.4byte 0x80080000
	.4byte 0x00000000
.endobj Letb

.section extabindex, "a"
.balign 4

.obj Leti, local
	.4byte fn_803FBC7C
	.4byte 0x00000430
	.4byte Letb
.endobj Leti

.text
.balign 4

.fn fn_803FBC7C, global
stwu r1, -0x50(r1)
mflr r0
cmpwi r3, 0x0
stw r0, 0x54(r1)
stmw r16, 0x10(r1)
li r26, 0x0
mr r16, r3
mr r17, r4
mr r18, r5
mr r19, r6
mr r20, r7
mr r21, r8
mr r22, r9
li r27, 0x1
li r25, 0x0
li r24, 0x0
li r23, 0x0
stw r26, 0x0(r9)
stw r26, 0x0(r8)
blt .L_803FBCE4
cmpwi r3, 0x1
beq .L_803FBCE4
cmpwi r3, 0x24
bgt .L_803FBCE4
cmpwi r4, 0x1
bge .L_803FBCEC
.L_803FBCE4:
li r27, 0x40
b .L_803FBD0C
.L_803FBCEC:
mr r12, r18
mr r3, r19
li r4, 0x0
li r5, 0x0
mtctr r12
li r26, 0x1
bctrl
mr r4, r3
.L_803FBD0C:
cmpwi r16, 0x0
beq .L_803FBD1C
li r0, -0x1
divwu r23, r0, r16
.L_803FBD1C:
lis r3, lbl_804942B8@ha
li r30, 0x1
li r31, -0x1
lis r28, jumptable_80494670@ha
addi r29, r3, lbl_804942B8@l
b .L_803FC048
.L_803FBD34:
cmplwi r27, 0x10
bgt .L_803FC048
addi r3, r28, jumptable_80494670@l
slwi r0, r27, 2
lwzx r3, r3, r0
mtctr r3
bctr
cmpwi r4, 0x0
li r0, 0x0
blt .L_803FBD64
cmpwi r4, 0x100
blt .L_803FBD68
.L_803FBD64:
li r0, 0x1
.L_803FBD68:
cmpwi r0, 0x0
beq .L_803FBD78
li r0, 0x0
b .L_803FBD8C
.L_803FBD78:
lwz r3, 0x38(r29)
slwi r0, r4, 1
lwz r3, 0x8(r3)
lhzx r0, r3, r0
rlwinm r0, r0, 0, 23, 23
.L_803FBD8C:
cmpwi r0, 0x0
beq .L_803FBDB8
mr r12, r18
mr r3, r19
li r4, 0x0
li r5, 0x0
mtctr r12
bctrl
mr r4, r3
addi r25, r25, 0x1
b .L_803FC048
.L_803FBDB8:
cmpwi r4, 0x2b
bne .L_803FBDE4
mr r12, r18
mr r3, r19
li r4, 0x0
li r5, 0x0
mtctr r12
addi r26, r26, 0x1
bctrl
mr r4, r3
b .L_803FBE10
.L_803FBDE4:
cmpwi r4, 0x2d
bne .L_803FBE10
mr r12, r18
mr r3, r19
li r4, 0x0
li r5, 0x0
mtctr r12
addi r26, r26, 0x1
bctrl
mr r4, r3
stw r30, 0x0(r21)
.L_803FBE10:
li r27, 0x2
b .L_803FC048
cmpwi r16, 0x0
beq .L_803FBE28
cmpwi r16, 0x10
bne .L_803FBE58
.L_803FBE28:
cmpwi r4, 0x30
bne .L_803FBE58
mr r12, r18
mr r3, r19
li r27, 0x4
li r4, 0x0
li r5, 0x0
mtctr r12
addi r26, r26, 0x1
bctrl
mr r4, r3
b .L_803FC048
.L_803FBE58:
li r27, 0x8
b .L_803FC048
cmpwi r4, 0x58
beq .L_803FBE70
cmpwi r4, 0x78
bne .L_803FBE9C
.L_803FBE70:
mr r12, r18
mr r3, r19
li r16, 0x10
li r27, 0x8
li r4, 0x0
li r5, 0x0
mtctr r12
addi r26, r26, 0x1
bctrl
mr r4, r3
b .L_803FC048
.L_803FBE9C:
cmpwi r16, 0x0
bne .L_803FBEA8
li r16, 0x8
.L_803FBEA8:
li r27, 0x10
b .L_803FC048
cmpwi r16, 0x0
bne .L_803FBEBC
li r16, 0xa
.L_803FBEBC:
cmpwi r23, 0x0
bne .L_803FBEC8
divwu r23, r31, r16
.L_803FBEC8:
cmpwi r4, 0x0
li r0, 0x0
blt .L_803FBEDC
cmpwi r4, 0x100
blt .L_803FBEE0
.L_803FBEDC:
li r0, 0x1
.L_803FBEE0:
cmpwi r0, 0x0
beq .L_803FBEF0
li r0, 0x0
b .L_803FBF04
.L_803FBEF0:
lwz r3, 0x38(r29)
slwi r0, r4, 1
lwz r3, 0x8(r3)
lhzx r0, r3, r0
rlwinm r0, r0, 0, 28, 28
.L_803FBF04:
cmpwi r0, 0x0
beq .L_803FBF30
subi r4, r4, 0x30
cmpw r4, r16
blt .L_803FC000
cmpwi r27, 0x10
li r27, 0x40
bne .L_803FBF28
li r27, 0x20
.L_803FBF28:
addi r4, r4, 0x30
b .L_803FC048
.L_803FBF30:
cmpwi r4, 0x0
li r0, 0x0
blt .L_803FBF44
cmpwi r4, 0x100
blt .L_803FBF48
.L_803FBF44:
li r0, 0x1
.L_803FBF48:
cmpwi r0, 0x0
beq .L_803FBF58
li r0, 0x0
b .L_803FBF6C
.L_803FBF58:
lwz r3, 0x38(r29)
slwi r0, r4, 1
lwz r3, 0x8(r3)
lhzx r0, r3, r0
clrlwi r0, r0, 31
.L_803FBF6C:
cmpwi r0, 0x0
beq .L_803FBFB4
cmpwi r4, 0x0
li r0, 0x0
blt .L_803FBF88
cmpwi r4, 0x100
blt .L_803FBF8C
.L_803FBF88:
li r0, 0x1
.L_803FBF8C:
cmpwi r0, 0x0
beq .L_803FBF9C
mr r3, r4
b .L_803FBFA8
.L_803FBF9C:
lwz r3, 0x38(r29)
lwz r3, 0xc(r3)
lbzx r3, r3, r4
.L_803FBFA8:
subi r0, r3, 0x37
cmpw r0, r16
blt .L_803FBFCC
.L_803FBFB4:
cmpwi r27, 0x10
bne .L_803FBFC4
li r27, 0x20
b .L_803FC048
.L_803FBFC4:
li r27, 0x40
b .L_803FC048
.L_803FBFCC:
cmpwi r4, 0x0
li r0, 0x0
blt .L_803FBFE0
cmpwi r4, 0x100
blt .L_803FBFE4
.L_803FBFE0:
li r0, 0x1
.L_803FBFE4:
cmpwi r0, 0x0
beq .L_803FBFF0
b .L_803FBFFC
.L_803FBFF0:
lwz r3, 0x38(r29)
lwz r3, 0xc(r3)
lbzx r4, r3, r4
.L_803FBFFC:
subi r4, r4, 0x37
.L_803FC000:
cmplw r24, r23
ble .L_803FC00C
stw r30, 0x0(r22)
.L_803FC00C:
mullw r24, r24, r16
subfic r0, r24, -0x1
cmplw r4, r0
ble .L_803FC020
stw r30, 0x0(r22)
.L_803FC020:
mr r12, r18
add r24, r24, r4
mr r3, r19
li r27, 0x10
li r4, 0x0
li r5, 0x0
mtctr r12
addi r26, r26, 0x1
bctrl
mr r4, r3
.L_803FC048:
cmpw r26, r17
bgt .L_803FC060
cmpwi r4, -0x1
beq .L_803FC060
rlwinm. r0, r27, 0, 25, 26
beq .L_803FBD34
.L_803FC060:
andi. r0, r27, 0x34
bne .L_803FC074
li r24, 0x0
stw r24, 0x0(r20)
b .L_803FC080
.L_803FC074:
add r3, r26, r25
subi r0, r3, 0x1
stw r0, 0x0(r20)
.L_803FC080:
mr r12, r18
mr r3, r19
li r5, 0x1
mtctr r12
bctrl
mr r3, r24
lmw r16, 0x10(r1)
lwz r0, 0x54(r1)
mtlr r0
addi r1, r1, 0x50
blr
.endfn fn_803FBC7C
