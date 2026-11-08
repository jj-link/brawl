#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef int s32;
typedef struct InitFunc { void (*func)(void *, u32); u32 arg; } InitFunc;
typedef struct Callback { int (*func)(u32); } Callback;
typedef struct Node { u32 flags; Callback *callback; u32 pad; u32 generation; u16 count; char rest[0x22]; } Node;
typedef struct Entry { u32 generation; Node *node; } Entry;
typedef struct State { u16 first; u16 alloc_count; Entry entries[26]; char pad[0xDC]; Node nodes[26]; } State;
extern State lbl_8053A6E0;
extern s32 fn_803AB508(InitFunc *, Node **, u16 *, u16 *);
s32 fn_803AB8C4(InitFunc *arg0, u32 *arg1) {
 Node *node;
 u16 index, slot;
 s32 result;
 if (arg1 == 0 || arg0 == 0 || arg0->func == 0) return 1;
 result = fn_803AB508(arg0, &node, &index, &slot);
 if (result != 0) return result;
 node->generation++;
 node->generation = (u16)node->generation;
 node->count++;
 lbl_8053A6E0.entries[slot].generation = node->generation;
 lbl_8053A6E0.entries[slot].node = node;
 *arg1 = (u8)index | 0x300 | (lbl_8053A6E0.nodes[index].flags << 16);
 if (node->count == 1 && node->callback->func(*arg1) != 0) {
  if (node->count == 1) {
   node->flags &= ~1;
   lbl_8053A6E0.alloc_count--;
  }
  node->count--;
  lbl_8053A6E0.entries[slot].node = 0;
  return 0x15;
 }
 return 0;
}