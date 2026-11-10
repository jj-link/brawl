#include <types.h>
#pragma force_active on
typedef struct Entry {
 u8 id; u8 pad01[0x2F]; u8 pad30[8]; u16 cnt38; u8 pad3A[2]; u8 pad3C; u8 flag3D; u8 pad3E[2]; u32 pos40; u8 pad44[0xA]; u8 field4E; u8 pad4F[0x16]; u8 field65; u8 pad66[0x22]; u32 field88; void *fn8C; u8 pad90[4]; void *fn94; u8 pad98[8]; u16 lenA0;
} Entry;
typedef struct Pkt { u8 pad0[2]; u16 size; u16 off; } Pkt;
extern u8 lbl_8052D5A8[];
extern char lbl_804840E8[], lbl_8048410C[];
extern void fn_8022F0E0(void *);
extern void fn_8022F500(void *, void *);
extern void fn_802319E4(u32, const char *);
extern void fn_802319FC(u32, const char *, u16);
extern Entry *fn_80251AD0(void *, u16);
extern void fn_80251C84();
extern void fn_80254998(void *, u32, u32);
void fn_802512BC(void *arg0, u16 arg1, Pkt *arg2) {
 Entry *entry; u32 flags; u32 old; u8 *p; u8 c; s32 i; u32 cmp; s32 n;
 entry = fn_80251AD0(arg0, arg1);
 flags = 0;
 if (lbl_8052D5A8[0x414] >= 4U) fn_802319FC(0x90003, lbl_804840E8, arg2->size);
 if (entry == 0) { fn_8022F0E0(arg2); return; }
 if (entry->fn94 != 0) {
  fn_80251C84(entry, 1, 1);
  ((void (*)(u8, void *, u16))entry->fn94)(entry->id, (void *)((u32)arg2 + arg2->off + 8), arg2->size);
  fn_8022F0E0(arg2); return;
 }
 if (entry->pos40 + arg2->size > 0x2EE0U || (int)(entry->cnt38 + 1) > (int)entry->lenA0) {
  if (lbl_8052D5A8[0x414] >= 4U) fn_802319E4(0x90003, lbl_8048410C);
  fn_8022F0E0(arg2); fn_80254998(arg0, arg1, 2); return;
 }
 cmp = entry->field4E;
 if (cmp != 0 && (entry->field88 & 2)) {
  p = (u8 *)((u32)arg2 + arg2->off + 8);
  n = arg2->size;
  for (i = 0; i < n; i++) {
   c = *p; p++;
   if (c == cmp) { flags |= 2; break; }
  }
 }
 fn_8022F500((u8 *)entry + 0x30, arg2);
 old = entry->pos40;
 entry->pos40 = old + arg2->size;
 fn_80251C84(entry, 0, 0, old);
 if (entry->flag3D != 0) {
  if (flags & 2) entry->field65 = 1;
 } else {
  void (*fn)(u32, u8);
  flags |= 1; flags &= entry->field88;
  fn = (void (*)(u32, u8))entry->fn8C;
  if (fn != 0 && flags != 0) fn(flags, entry->id);
 }
}