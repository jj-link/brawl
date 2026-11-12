#include <types.h>
#pragma force_active on
typedef struct {
void *unk0; void *unk4; u32 unk8; u32 unkC; void *unk10;
u8 pad14[0x28]; void *unk3C; u32 unk40; u32 unk44;
u16 unk48; u16 unk4A; u8 unk4C[0x20]; u8 unk6C;
} State;
typedef struct {
u8 pad0[0x20E]; u8 unk20E; u8 unk20F; u8 pad210[0x0C];
u8 unk21C; u8 pad21D[0x13]; u32 unk230; u32 unk234;
} Info;
extern s32 fn_803D6A50(void *, void *, s32, s32, s32);
extern void fn_803D674C(void *, s16);
extern u16 fn_803D68CC(void *, s32);
extern u16 fn_803D68B8(void *);
extern s32 fn_803D6724(void *, s32);
extern s32 fn_803D66F4(void *);
extern s32 fn_803DD968(void *, void *);
extern s32 fn_803E9D60(void *, void *);
extern void fn_803E2414(void *, void *, void *, void *);
extern void fn_803E23D4(void *, void *);
extern void fn_803E6E90(void *, s32, s32);
extern s32 fn_803E6EA0(void *, s32);
extern s32 fn_803DDF18(void *, s32);
extern s32 PFSEC_ReadData(void *, void *, u32, u16, u32, u32 *, s32);
extern s32 fn_803DE0C8(void *, void *, void *, s32, s32, s32 *);
extern s32 fn_803DF2A8(void *, void *, u32, s32 *);
extern s32 fn_803E7BB4(void *);
extern s32 fn_803E7B4C(void *);
extern char lbl_8059FED0[2];
extern char lbl_8059FED4[2];
extern char lbl_8059FED8[2];
extern char lbl_8059FEDC[4];
s32 fn_803DE800(State *arg0, Info *arg1, void *a2, s32 *p3, s32 a4, s32 a5)
{
s32 result;
u32 temp14;
s32 temp10;
u32 readCount;
u32 readCount2;
u32 pathInfo;
struct { u32 pad[2]; u32 buffer[4]; } workspace;
u8 tempBuf[0x238];
u32 mask;
void *oldPos;
s32 result1;
s32 result2;
s32 readResult;
s32 readReturn;
u32 neg1 = 0xFFFFFFFFU;
s32 one = 1;
void *zero = 0;
s32 three = 3;
s32 ctx;
if (fn_803D6A50(p3, lbl_8059FED0, 1, 1, 1) == 0) fn_803D674C(p3, 2);
if (fn_803D6A50(p3, lbl_8059FED4, 1, 0, 1) == 0 ||
fn_803D6A50(p3, lbl_8059FED8, 1, 0, 1) == 0) {
result = fn_803DD968(a2, arg1);
if (result != 0) return result;
if (fn_803D68CC(p3, 1) == 1 &&
fn_803D6A50(p3, lbl_8059FEDC, 2, 0, 1) == 0) return 0;
} else {
result = fn_803E9D60(a2, arg1);
if (result != 0) return result;
}
ctx = fn_803D6724(p3, 1);
fn_803E2414(&arg0->unk8, &temp14, a2, &arg0->unkC);
arg0->unkC = arg1->unk234;
fn_803E6E90(workspace.buffer, ctx, fn_803D66F4(p3));
result = fn_803E6EA0(workspace.buffer, a4);
while (workspace.buffer[0] != 0) {
if (result != 0) return result;
if (a5 != 0 && fn_803D6A50(workspace.buffer, lbl_8059FEDC, 2, 0, 1) == 0) break;
if ((arg1->unk21C & 0x10) == 0) return 2;
if (fn_803D68B8(workspace.buffer) == 0) return 2;
arg0->unkC = arg1->unk234;
fn_803E23D4(&arg0->unk8, &arg0->unkC);
arg0->unk4 = arg0->unk3C;
pathInfo = (u32)arg0->unk0;
arg0->unk6C = ((u8 *)arg0->unk3C)[0x20] - 5;
arg0->unk40 = (u32)zero;
arg0->unk40 = one;
arg0->unk40 = neg1;
mask = 1U << arg0->unk6C;
arg0->unk4A = (u16)(mask - 1);
arg0->unk0 = zero;
result1 = fn_803DDF18(arg0, 0);
if (result1 != 0) {
arg0->unk0 = (void *)pathInfo;
fn_803DDF18(arg0, 0);
} else {
if (arg0->unk44 == 0xFFFFFFFFU) readResult = 0x10;
else {
readReturn = PFSEC_ReadData(arg0->unk4, arg0->unk4C, arg0->unk44, arg0->unk48, 0x20, &readCount, 0);
readResult = 0x11;
if (readCount == 0x20) readResult = readReturn;
}
result1 = readResult & ((-readResult | readResult) >> 31);
}
if (result1 != 0) return result1;
pathInfo = *(u32 *)arg0->unk10;
result = fn_803DE0C8(arg0, arg1, workspace.buffer, 0x7F, 0, &temp10);
if (result != 0) return result;
if (temp10 == 0) {
result = fn_803E6EA0(workspace.buffer, a4);
if (result != 0) return result;
return (workspace.buffer[0] == 0) + 2;
}
if (a4 == 0) {
if ((arg1->unk21C & 0x10) != 0 && arg1->unk234 == one) arg1->unk230 = three;
else if ((arg1->unk21C & 0x10) != 0 && (s32)arg1->unk20E == 0x2E && (s32)arg1->unk20F == 0x2E) {
fn_803E23D4(&arg0->unk8, &arg1->unk234);
arg0->unk4 = arg0->unk3C;
oldPos = arg0->unk0;
arg0->unk6C = ((u8 *)arg0->unk3C)[0x20] - 5;
arg0->unk40 = (u32)zero;
arg0->unk40 = one;
arg0->unk40 = neg1;
mask = 1U << arg0->unk6C;
arg0->unk4A = (u16)(mask - 1);
arg0->unk0 = zero;
result2 = fn_803DDF18(arg0, 0);
if (result2 != 0) {
arg0->unk0 = oldPos;
fn_803DDF18(arg0, 0);
} else {
if (arg0->unk44 == 0xFFFFFFFFU) readResult = 0x10;
else {
readReturn = PFSEC_ReadData(arg0->unk4, arg0->unk4C, arg0->unk44, arg0->unk48, 0x20, &readCount2, 0);
readResult = 0x11;
if (readCount2 == 0x20) readResult = readReturn;
}
result2 = readResult & ((-readResult | readResult) >> 31);
}
if (result2 != 0) return result2;
tempBuf[0x21C] = arg1->unk21C;
*(u32 *)(tempBuf + 0x234) = arg1->unk234;
result = fn_803DF2A8(arg0, tempBuf, pathInfo, &temp10);
if (result != 0) return result;
if (temp10 == 0) return 2;
if (tempBuf[0x20A] != 0) arg1->unk230 -= fn_803E7BB4(tempBuf);
else arg1->unk230 -= fn_803E7B4C(tempBuf + 0x20E);
arg1->unk230 -= one;
} else if ((arg1->unk21C & 0x10) == 0 || (s32)arg1->unk20E != 0x2E) {
arg1->unk230 += fn_803D68CC(workspace.buffer, one) + 1;
if (fn_803D6A50(workspace.buffer, lbl_8059FEDC, 2, 0, 1) != 0)
arg1->unk230 -= fn_803D68CC(workspace.buffer, 2);
}
}
result = fn_803E6EA0(workspace.buffer, a4);
}
return 0;
}
