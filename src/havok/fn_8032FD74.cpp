#pragma force_active on
#include <types.h>
class Class_80488EE0 {
public:
 virtual void fn_8032FA40();
 virtual void fn_80080A64();
 virtual void fn_8032FCB4();
 virtual void fn_80330928();
 virtual void fn_8033259C();
 virtual void fn_803315A4();
 virtual void fn_80330698();
 virtual void fn_8032FF60();
 virtual void fn_803309D0();
 virtual void fn_8032FCAC();
 virtual s32 fn_8032FD74(void*);
 virtual void fn_80331408();
 virtual void* fn_80331494(s32, s32);
};
extern "C" {
void fn_80281D64(s32*, s32, s32);
void fn_8032F714(void*, s32);
void fn_8027CD94(void*, s32, s32);
s32 fn_8027C83C(void*);
s32 fn_803310D0(void*);
s32 fn_8032FD74(void* arg0, void* arg1) {
 s32 local[16];
 u8* dst = (u8*)arg0;
 u8* src = (u8*)arg1;
 fn_80281D64(&local[0], -1, 0x40);
 s32* data = 0;
 local[0] = 0x57E0E057;
 local[1] = 0x10C0C010;
 *(u8*)&local[10] = (u8)(u32)data;
 if (*(s32*)(src + 0) == local[0] && *(s32*)(src + 4) == local[1])
   *(void**)(dst + 0x0C) = arg1;
 else
   return 1;
 if (*(s32*)(src + 0x14) > 0)
   data = (s32*)(src + 0x40);
 *(s32**)(dst + 0x10) = data;
 if (*(s32*)(*(u8**)(dst + 0x0C) + 0x0C) < 4)
   fn_8032F714(data, *(s32*)(*(u8**)(dst + 0x0C) + 0x14));
 s32 count = *(s32*)(*(u8**)(dst + 0x0C) + 0x14);
 s32 capacity = *(s32*)(dst + 0x1C) & 0x3FFFFFFF;
 if (capacity < count) {
   s32 doubled = capacity * 2;
   fn_8027CD94(dst + 0x14, count < doubled ? doubled : count, 4);
 }
 *(s32*)(dst + 0x18) = count;
 s32 blockOffset;
 s32 tableOffset;
 u8* entry;
 s32 i = 0;
 blockOffset = 0;
 tableOffset = 0;
 while (i < *(s32*)(*(u8**)(dst + 0x0C) + 0x14)) {
   u8* block = (u8*)*(s32**)(dst + 0x10) + blockOffset;
   s32 baseOffset = *(s32*)(block + 0x14);
   s32 entriesOffset = *(s32*)(block + 0x18);
   u8* base = src + baseOffset;
   entry = base + entriesOffset;
   s32 entryIndex = 0;
   while (entryIndex < (*(s32*)(block + 0x1C) - *(s32*)(block + 0x18)) / 4) {
     s32 index = *(s32*)entry;
     if (index != -1) {
       s32 offset = *(s32*)(entry + 4);
       *(u8**)(base + index) = base + offset;
     }
     entry += 8;
     entryIndex += 2;
   }
   *(u8**)(*(u8**)(dst + 0x14) + tableOffset) = base;
   blockOffset += 0x30;
   ++i;
   tableOffset += 4;
 }
 u8* resource = *(u8**)(dst + 0x0C);
 s32 callbackArg = *(s32*)(resource + 0x20);
 s32 callbackCheck = *(s32*)(resource + 0x24);
 if (callbackArg >= 0 && callbackCheck >= 0 && *(s32*)(resource + 0x0C) < 3) {
   void* p = ((Class_80488EE0*)arg0)->fn_80331494(callbackArg, callbackCheck);
   s32 result = fn_8027C83C(p);
   *(s32*)(*(u8**)(dst + 0x0C) + 0x24) = result - *(s32*)(*(s32**)(dst + 0x14) + callbackArg);
 }
 return fn_803310D0(arg0);
}
}