#pragma force_active on
typedef unsigned int u32;
typedef unsigned short u16;
typedef signed int s32;
typedef unsigned char u8;
typedef struct Node { u32 first; s32 handle; u32 generation; u32 len_pad[3]; u32 size; u8 rest[0x10]; } Node;
typedef struct Entry { u32 generation; Node* node; } Entry;
typedef struct State { u8 first[0xD4]; Entry entries[26]; u8 pad[0x6EC-0xD4-26*8]; Node nodes[26]; } State;
extern State lbl_8053A6E0;
extern s32 fn_803AC72C(s32,s32);
extern u32 fn_803ACA68(Node*, u32, u32);
extern s32 fn_803ABF18(s32, s32, s32, s32, u32, u32*);
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
s32 fn_803AD47C(u32 a, s32 b, u32 off, u32 len, u32 e, u32* f) {
 Node* n;
 s32 r;
 u32 size;
 u32 index;
 if (a == 0 || b == 0 || len == 0 || e == 0 || f == 0) return 1;
 index = a & 0xFF;
 r = invalid(a);
 if (r) return r;
 n = &lbl_8053A6E0.nodes[index];
 r = fn_803AC72C(n->handle, a);
 if (r) return r;
 if (n->size <= off) return 0x12;
 if (n->size < off + len) len -= off + len - n->size;
 r = fn_803ABF18(n->handle, b, fn_803ACA68(n, off, e), len, e, f);
 if (r) return r;
 return 0;
}
