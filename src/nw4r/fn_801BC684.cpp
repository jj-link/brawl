#include <types.h>
#pragma force_active on

extern float lbl_805A34A8;
extern double lbl_805A34B0;

#define PASTE(x,y) x##y
#define BLOCK PASTE(a,sm)
#define REG_ PASTE(regist,er)

extern "C" BLOCK void fn_801BC684(REG_ void* self, REG_ int arg) {
stwu r1,-0x30(r1)
mflr r0
stw r0,0x34(r1)
lis r0,0x4330
stw r31,0x2c(r1)
stw r30,0x28(r1)
mr r30,r4
stw r29,0x24(r1)
mr r29,r3
lwz r12,0x0(r3)
stw r0,0x8(r1)
lwz r12,0x68(r12)
stw r0,0x10(r1)
mtctr r12
bctrl
cmpwi r30,0x0
mr r31,r3
beq L_71C
lwz r12,0x0(r3)
lwz r12,0x18(r12)
mtctr r12
bctrl
cmpwi r3,0x0
beq L_71C
lwz r12,0x0(r31)
mr r3,r31
lwz r12,0x1c(r12)
mtctr r12
bctrl
cmpwi r3,0x0
beq L_71C
lwz r12,0x0(r31)
mr r3,r31
lwz r12,0x20(r12)
mtctr r12
bctrl
cmpwi r3,0x0
beq L_734
L_71C:
lwz r12,0x0(r29)
mr r3,r29
lwz r12,0x28(r12)
mtctr r12
bctrl
b L_838
L_734:
lwz r5,0x4c(r29)
lwz r4,0x50(r29)
cmpw r4,r5
blt L_74C
lfs f1,0x48(r29)
b L_788
L_74C:
xoris r3,r4,0x8000
xoris r0,r5,0x8000
stw r3,0xc(r1)
lfd f4,lbl_805A34B0
lfd f0,0x8(r1)
lfs f1,0x48(r29)
lfs f2,0x44(r29)
fsubs f3,f0,f4
stw r0,0x14(r1)
fsubs f1,f1,f2
lfd f0,0x10(r1)
fsubs f0,f0,f4
fmuls f1,f3,f1
fdivs f0,f1,f0
fadds f1,f2,f0
L_788:
xoris r0,r30,0x8000
lfd f4,lbl_805A34B0
stw r0,0xc(r1)
cmpw r4,r5
lfd f0,0x8(r1)
fsubs f0,f0,f4
fmuls f0,f0,f1
fctiwz f0,f0
stfd f0,0x18(r1)
lwz r6,0x1c(r1)
blt L_7BC
lfs f1,0x48(r29)
b L_7F4
L_7BC:
xoris r3,r4,0x8000
xoris r0,r5,0x8000
stw r3,0x14(r1)
lfs f0,0x48(r29)
lfd f1,0x10(r1)
lfs f2,0x44(r29)
fsubs f3,f1,f4
stw r0,0xc(r1)
fsubs f1,f0,f2
lfd f0,0x8(r1)
fmuls f1,f3,f1
fsubs f0,f0,f4
fdivs f0,f1,f0
fadds f1,f2,f0
L_7F4:
lfs f0,lbl_805A34A8
li r31,0x0
stfs f1,0x44(r29)
mr r3,r29
li r4,0x0
stfs f0,0x48(r29)
stw r6,0x4c(r29)
stw r31,0x50(r29)
lwz r12,0x0(r29)
lwz r12,0x4c(r12)
mtctr r12
bctrl
li r0,0x1
stb r31,0x66(r29)
stb r31,0x67(r29)
stb r31,0x68(r29)
stb r0,0x69(r29)
L_838:
lwz r0,0x34(r1)
lwz r31,0x2c(r1)
lwz r30,0x28(r1)
lwz r29,0x24(r1)
mtlr r0
addi r1,r1,0x30
blr
}