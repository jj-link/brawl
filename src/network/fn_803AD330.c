#pragma force_active on
typedef unsigned int u32;
typedef unsigned short u16;
typedef signed int s32;
typedef unsigned char u8;
typedef struct Node { u32 first; s32 handle; u32 generation; u8 rest[0x20]; } Node;
typedef struct Entry { u32 generation; Node* node; } Entry;
typedef struct State { u8 first[0xD4]; Entry entries[26]; u8 pad[0x6EC-0xD4-26*8]; Node nodes[26]; } State;
extern State lbl_8053A6E0;
extern s32 fn_803AC72C(s32,s32);
extern s32 fn_803AC2C8(s32,s32);
static inline s32 invalid(u32 a) {
 Node* node;
 u16 i;
 u32 index = a & 0xFF;
 u32 type = a & 0xFF00;
 u32 generation = a >> 16;
 if (index >= 26 || type != 0x400 ||
     generation > lbl_8053A6E0.nodes[index].generation) {
  return 1;
 }
 node = &lbl_8053A6E0.nodes[index];
 for (i = 0; i < 26; i++) {
  if (lbl_8053A6E0.entries[i].node == node &&
      (a >> 16) == lbl_8053A6E0.entries[i].generation) {
   break;
  }
 }
 return i >= 26;
}
s32 fn_803AD330(s32 arg0,s32 arg1) {
 u32 index; s32 result; s32 r;
 if(arg0==0)return 1;
 index=(u32)arg0 & 0xFF;
 result=invalid(arg0);
 if(result)return result;
 result=fn_803AC72C(lbl_8053A6E0.nodes[index].handle,arg0);
 if(result)return result;
 r=fn_803AC2C8(lbl_8053A6E0.nodes[index].handle,arg1);
 return r&((s32)(-r|r)>>31);
}
