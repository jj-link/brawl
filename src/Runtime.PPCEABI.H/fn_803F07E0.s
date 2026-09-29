.include "macros.inc"

.text
.balign 4

# .text:0x0 | 0x803F07E0 | size: 0x23C
.fn fn_803F07E0, global
li r0, 0x0
cmpwi r4, 0x0
stw r0, 0x0(r5)
mr r7, r4
bne .L_803F07FC
li r3, 0x1
blr
.L_803F07FC:
lbz r0, 0x0(r4)
mr r6, r3
cmpwi r0, 0x50
bne .L_803F0860
lbz r0, 0x1(r4)
addi r7, r4, 0x1
cmpwi r0, 0x43
bne .L_803F0820
addi r7, r7, 0x1
.L_803F0820:
lbz r0, 0x0(r7)
cmpwi r0, 0x56
bne .L_803F0830
addi r7, r7, 0x1
.L_803F0830:
lbz r0, 0x0(r7)
cmpwi r0, 0x76
bne .L_803F085C
lbz r0, 0x0(r3)
extsb r0, r0
cmpwi r0, 0x50
beq .L_803F0854
cmpwi r0, 0x2a
bne .L_803F085C
.L_803F0854:
li r3, 0x1
blr
.L_803F085C:
mr r7, r4
.L_803F0860:
lbz r0, 0x0(r3)
extsb r0, r0
cmpwi r0, 0x2a
beq .L_803F0880
bge .L_803F09B4
cmpwi r0, 0x21
beq .L_803F0880
b .L_803F09B4
.L_803F0880:
lbz r0, 0x0(r7)
addi r6, r3, 0x1
lbz r3, 0x0(r3)
addi r7, r7, 0x1
extsb r0, r0
extsb r3, r3
cmpw r3, r0
beq .L_803F08A8
li r3, 0x0
blr
.L_803F08A8:
lbz r0, 0x0(r7)
addi r7, r7, 0x1
lbz r3, 0x0(r6)
extsb r0, r0
extsb r3, r3
cmpw r3, r0
bne .L_803F0908
cmpwi r3, 0x21
addi r6, r6, 0x1
bne .L_803F08A8
li r4, 0x0
b .L_803F08F0
.L_803F08D8:
lbz r3, 0x0(r6)
mulli r0, r4, 0xa
addi r6, r6, 0x1
extsb r3, r3
add r4, r3, r0
subi r4, r4, 0x30
.L_803F08F0:
lbz r0, 0x0(r6)
cmpwi r0, 0x21
bne .L_803F08D8
stw r4, 0x0(r5)
li r3, 0x1
blr
.L_803F0908:
lbz r0, 0x0(r6)
addi r6, r6, 0x1
cmpwi r0, 0x21
bne .L_803F0908
.L_803F0918:
lbz r0, 0x0(r6)
addi r6, r6, 0x1
cmpwi r0, 0x21
bne .L_803F0918
lbz r0, 0x0(r6)
extsb. r0, r0
bne .L_803F093C
li r3, 0x0
blr
.L_803F093C:
addi r7, r4, 0x1
b .L_803F08A8
b .L_803F09B4
.L_803F0948:
lbzu r0, 0x1(r7)
addi r6, r6, 0x1
cmpwi r0, 0x43
bne .L_803F096C
lbz r0, 0x0(r6)
cmpwi r0, 0x43
bne .L_803F0968
addi r6, r6, 0x1
.L_803F0968:
addi r7, r7, 0x1
.L_803F096C:
lbz r0, 0x0(r6)
extsb r3, r0
cmpwi r3, 0x43
bne .L_803F0984
li r3, 0x0
blr
.L_803F0984:
lbz r0, 0x0(r7)
cmpwi r0, 0x56
bne .L_803F09A0
cmpwi r3, 0x56
bne .L_803F099C
addi r6, r6, 0x1
.L_803F099C:
addi r7, r7, 0x1
.L_803F09A0:
lbz r0, 0x0(r6)
cmpwi r0, 0x56
bne .L_803F09B4
li r3, 0x0
blr
.L_803F09B4:
lbz r3, 0x0(r6)
extsb r0, r3
cmpwi r0, 0x50
beq .L_803F09CC
cmpwi r0, 0x52
bne .L_803F09FC
.L_803F09CC:
lbz r0, 0x0(r7)
extsb r3, r3
extsb r0, r0
cmpw r3, r0
beq .L_803F0948
b .L_803F09FC
.L_803F09E4:
extsb. r0, r4
bne .L_803F09F4
li r3, 0x1
blr
.L_803F09F4:
addi r6, r6, 0x1
addi r7, r7, 0x1
.L_803F09FC:
lbz r4, 0x0(r6)
lbz r0, 0x0(r7)
extsb r3, r4
extsb r0, r0
cmpw r3, r0
beq .L_803F09E4
li r3, 0x0
blr
.endfn fn_803F07E0
