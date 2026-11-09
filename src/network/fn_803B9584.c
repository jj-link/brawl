#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef int s32;
typedef struct Input {
u16 size;
u8 pad02[10];
u32 increment;
u8 pad10[8];
u16 flags;
u8 pad1a[6];
u8 shift;
u8 pad21;
u8 mode;
u8 pad23[5];
u32 base;
u8 pad2c[8];
u32 count;
u8 pad38[0x1870 - 0x38];
void *callback_arg;
u8 pad1874[0x1c];
s32 (*callback)(void *);
} Input;
extern s32 fn_803BFFC8(void *, void *, u32, u16, s32);
s32 fn_803B9584(Input *input, u32 index, s32 *result)
{
u32 word;
u32 offset;
u32 block;
u16 remainder;
s32 callback_result;
s32 status;
u32 tries;
if (input == 0) { *result = -1; return 10; }
if ((index < 2 || index >= input->count + 2) && index != 0 && index != 1) {
*result = -1; return 14;
}
offset = index * 4;
block = (u16)(input->base + (offset >> input->shift));
remainder = (u16)(offset & (input->size - 1));
tries = 1;
if (input->flags & 0x80) { tries = input->flags & 7; }
do {
status = fn_803BFFC8(input, &word, block, remainder, 4);
if (status == 0x1000 && input->callback != 0) {
callback_result = input->callback(input->callback_arg);
if (callback_result == 0) { goto retry; }
if (callback_result == 1 && input->mode >= 2 && tries < input->mode) {
tries++; block += input->increment; goto retry;
}
}
if (status != 0) { *result = -1; return status; }
retry: ;
} while (status != 0);
*result = (((word << 24) | ((word << 8) & 0x00FF0000)) |
((word >> 24) | ((word >> 8) & 0x0000FF00))) & 0x0FFFFFFF;
return 0;
}