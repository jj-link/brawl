.include "macros.inc"
.text
.balign 4

.fn fn_80402CC8, global
stwu r1, -0x50(r1)
mflr r0
li r4, 0x0
li r5, 0x40
stw r0, 0x54(r1)
addi r3, r1, 0x8
bl fn_8000446C
lis r3, lbl_8059B940@ha
li r0, 0x80
addi r9, r3, lbl_8059B940@l
li r6, 0x40
lwz r8, 0x0(r9)
li r5, 0x0
stb r0, 0xc(r1)
addi r3, r1, 0x8
addi r7, r8, 0x1
li r4, 0x40
stw r8, 0x14(r1)
addi r0, r7, 0x1
stw r7, 0x0(r9)
stw r6, 0x8(r1)
stb r5, 0x10(r1)
stw r0, 0x0(r9)
stw r7, 0x14(r1)
bl fn_80405B6C
bl fn_80405810
lwz r0, 0x54(r1)
li r3, 0x0
mtlr r0
addi r1, r1, 0x50
blr
.endfn fn_80402CC8

# .text:0x7C | 0x80402D44 | size: 0x7C
.fn fn_80402D44, global
stwu r1, -0x50(r1)
mflr r0
li r4, 0x0
li r5, 0x40
stw r0, 0x54(r1)
addi r3, r1, 0x8
bl fn_8000446C
lis r3, lbl_8059B940@ha
li r0, 0x80
addi r9, r3, lbl_8059B940@l
li r6, 0x40
lwz r8, 0x0(r9)
li r5, 0x0
stb r0, 0xc(r1)
addi r3, r1, 0x8
addi r7, r8, 0x1
li r4, 0x40
stw r8, 0x14(r1)
addi r0, r7, 0x1
stw r7, 0x0(r9)
stw r6, 0x8(r1)
stb r5, 0x10(r1)
stw r0, 0x0(r9)
stw r7, 0x14(r1)
bl fn_80405B6C
bl fn_800063F4
lwz r0, 0x54(r1)
li r3, 0x0
mtlr r0
addi r1, r1, 0x50
blr
.endfn fn_80402D44

# .text:0xF8 | 0x80402DC0 | size: 0x9C
.fn fn_80402DC0, global
stwu r1, -0x60(r1)
mflr r0
lis r3, lbl_8059B944@ha
li r5, 0x40
stw r0, 0x64(r1)
addi r4, r3, lbl_8059B944@l
li r0, 0x0
addi r3, r1, 0x14
stw r0, 0x0(r4)
li r4, 0x0
bl fn_8000446C
lis r3, lbl_8059B940@ha
li r0, 0x80
addi r9, r3, lbl_8059B940@l
li r6, 0x40
lwz r8, 0x0(r9)
li r5, 0x0
stb r0, 0x18(r1)
addi r3, r1, 0x14
addi r7, r8, 0x1
li r4, 0x40
stw r8, 0x20(r1)
addi r0, r7, 0x1
stw r7, 0x0(r9)
stw r6, 0x14(r1)
stb r5, 0x1c(r1)
stw r0, 0x0(r9)
stw r7, 0x20(r1)
bl fn_80405B6C
addi r3, r1, 0x8
li r4, 0x1
bl fn_80400EB4
addi r3, r1, 0x8
bl fn_80400ECC
lwz r0, 0x64(r1)
li r3, 0x0
mtlr r0
addi r1, r1, 0x60
blr
.endfn fn_80402DC0

# .text:0x194 | 0x80402E5C | size: 0x88
.fn fn_80402E5C, global
stwu r1, -0x50(r1)
mflr r0
lis r3, lbl_8059B944@ha
li r5, 0x40
stw r0, 0x54(r1)
addi r4, r3, lbl_8059B944@l
li r0, 0x1
addi r3, r1, 0x8
stw r0, 0x0(r4)
li r4, 0x0
bl fn_8000446C
lis r3, lbl_8059B940@ha
li r0, 0x80
addi r9, r3, lbl_8059B940@l
li r6, 0x40
lwz r8, 0x0(r9)
li r5, 0x0
stb r0, 0xc(r1)
addi r3, r1, 0x8
addi r7, r8, 0x1
li r4, 0x40
stw r8, 0x14(r1)
addi r0, r7, 0x1
stw r7, 0x0(r9)
stw r6, 0x8(r1)
stb r5, 0x10(r1)
stw r0, 0x0(r9)
stw r7, 0x14(r1)
bl fn_80405B6C
lwz r0, 0x54(r1)
li r3, 0x0
mtlr r0
addi r1, r1, 0x50
blr
.endfn fn_80402E5C

# .text:0x21C | 0x80402EE4 | size: 0xC
.fn fn_80402EE4, global
lis r4, lbl_8059B944@ha
stw r3, lbl_8059B944@l(r4)
blr
.endfn fn_80402EE4
