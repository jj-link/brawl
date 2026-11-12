#include <types.h>
#pragma force_active on
extern "C" void fn_41_34690(void*, const void*, u32, const s16*, s16);
extern "C" void* fn_41_346B4(void*, short);
class Elem { public: char pad0[8]; s32 key; char pad1[2]; s16 w; };
class List {
public:
 virtual void v0(); virtual void v1(); virtual Elem* v2(s32); virtual s32 v3();
 virtual void v4(); virtual void v5(); virtual void v6(s32); virtual void v7();
 virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(s32, void*);
 virtual void v12(); virtual void v13(); virtual u32 v14();
};
class Self {
public:
 virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
 virtual s32 v4(); virtual u32 v5(); virtual u32 v6(s32);
 char pad0[12]; List m_list; char pad1[0x78]; u8 m_8C;
 inline s32 findKey() {
   s32 temp;
   if (m_list.v14() == 1U) return 0x7fff;
   if (v5() == 1U) return 0;
   s32 n = m_list.v3()-1;
   if (m_list.v2(n)->key < 0x7fff) {
     n = m_list.v3()-1;
     return m_list.v2(n)->key+1;
   }
   for (s32 k = m_list.v3()-1; k >= 0; k--) {
     if (k == 0) {
       if (m_list.v2(k)->key == 0) return -1;
       return m_list.v2(k)->key-1;
     }
     temp = m_list.v2(k-1)->key;
     if (m_list.v2(k)->key-1 > temp) return m_list.v2(k)->key-1;
   }
   return -1;
 }
 inline s32 findPos(s16 lim) {
   if (lim <= -1) return v4();
   s32 i;
   s32 count = v4();
   for (i = 0; i < count; i++) {
     s16 w = m_list.v2(i)->w;
     if (w <= -1) return i;
     if (w > lim) return i;
   }
   return count;
 }
};
extern "C" s32 fn_41_33EF8(Self* self, const void* src, s32 idx, const s16* p, s16 lim) {
 s32 temp; s32 k; s32 spC[4]; s16 sp8;
 if (self->m_list.v14() == 1U) return -1;
 if ((self->m_8C == 0 || idx > -1) && self->v6(idx) == 1U) return -1;
 if (self->m_8C == 0 && idx <= -1) {
   idx = self->findKey();
   if (idx <= -1) return -1;
 }
 k = self->findPos(lim);
 if (k < 0) return -1;
 sp8 = *p;
 fn_41_34690(spC, src, idx, &sp8, lim);
 self->m_list.v11(k, spC);
 fn_41_346B4(spC, -1);
 return idx;
}