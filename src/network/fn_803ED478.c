#include <types.h>
#pragma force_active on
typedef struct Entry {
 u32 handle; u8 pad[0x54]; u8 file[0x8C]; u32 flags; u32 unkE8; s32 status;
} Entry;
extern Entry lbl_805980D8[];
extern int lbl_805A1280;
extern void fn_803EC3D4(int);
extern void fn_803EC418(int);
extern s32 fn_8020B16C(void *, s32 *);
extern s32 fn_8020BC3C(void *);
extern s32 fn_8020B9BC(void *, void *, s32);
extern s32 fn_8020AC38(void *, s32, s32);
static inline s32 set_status(u32 handle, s32 status) {
 u16 i;
 u32 value;
 for(i=0;i<23;i++) {
  value = lbl_805980D8[i].handle;
  if(value == handle) {
   lbl_805980D8[i].status=status; break;
  }
 }
 return i==23 ? -22 : 0;
}
static inline s32 get_entry(u32 handle, Entry **out) {
 u16 i; Entry *candidate;
 for(i=0;i<23;i++) {
  candidate=&lbl_805980D8[i];
  if(candidate->handle==handle) { *out=candidate; break; }
 }
 return i==23 ? -22 : 0;
}
s32 fn_803ED478(u32 handle) {
 Entry *entry=0;
 s32 result, position, r;
 u16 i;
 Entry *candidate;
 fn_803EC3D4(lbl_805A1280);
 if(handle==0) { fn_803EC418(lbl_805A1280); return -20; }
 result=set_status(handle,0);
 if(result==0) {
  for (i = 0; i < 23; ++i) {
   candidate = &lbl_805980D8[i];
   if (candidate->handle == handle) {
    entry = candidate;
    break;
   }
  }
  if(i == 23 ? -22 : 0) { fn_803EC418(lbl_805A1280); return -20; }
  entry->flags &= ~2;
  r=fn_8020B16C(entry->file,&position);
  if(r!=0) result=r;
  else {
   r=fn_8020BC3C(entry->file);
   if(r<0) result=r;
   else {
    r=fn_8020B9BC((u8 *)entry+4,entry->file,3);
    if(r<0) result=r;
    else {
     r=fn_8020AC38(entry->file,position,0);
     result=r & (r>>31);
    }
   }
  }
  if(result<0) {
   set_status(handle,result);
   fn_803EC418(lbl_805A1280); return result;
  }
 }
 fn_803EC418(lbl_805A1280); return result;
}
