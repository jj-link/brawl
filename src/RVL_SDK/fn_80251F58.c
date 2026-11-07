typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef int s32;
typedef unsigned int u32;
typedef struct Entry { u8 pad[0x68]; u16 id; } Entry;
extern u8 lbl_8052D5A8[];
extern void fn_802319FC(u32, const char *, u32);
extern void fn_80231A14(u32, const char *, u32, u32);
extern void fn_80252784(void *, int, void *);
extern void fn_8024AB20(u32);
extern void fn_8022F0E0(void *);
extern void *fn_80251AD0(void *, u8);
extern void *fn_80251B24(u8);
extern void fn_802533C8(void *, s32, void *);
extern void fn_80254BF4(void *, u8, u8);
extern u8 fn_80255544(void *, void *, void *);
extern void fn_80255AB8(void *, void *);
extern void fn_80256790(void *, u8);
extern void fn_8025443C(void *, int);
#pragma force_active on
#pragma push
#pragma opt_propagation off
void fn_80251F58(u16 arg0, s16 arg1) {
 s16 sp8; s32 index; Entry *entry;
 index = arg0 - 0x40; sp8 = arg1;
 if (index >= 10) {
  if (lbl_8052D5A8[0x414] >= 1U) fn_802319FC(0x90000, "rfc_find_lcid_mcb LCID:0x%x", arg0);
  entry = 0;
 } else {
  entry = ((Entry **)(lbl_8052D5A8 + 0x3C))[index];
  if (entry != 0 && entry->id != arg0) {
   if (lbl_8052D5A8[0x414] >= 2U) fn_80231A14(0x90001, "rfc_find_lcid_mcb LCID reused LCID:0x%x current:0x%x", arg0, entry->id);
   entry = 0;
  }
 }
 if (entry == 0) {
  if (lbl_8052D5A8[0x414] >= 1U) fn_802319FC(0x90000, "RFCOMM_ConnectCnf LCID:0x%x", arg0);
 } else { entry->id = arg0; fn_80252784(entry, 9, &sp8); }
}
void fn_8025205C(u32 arg0, s32 arg1) {
 s32 index = arg0 - 0x40; void *ptr;
 if (index >= 10) {
  if (lbl_8052D5A8[0x414] >= 1U) fn_802319FC(0x90000, "rfc_find_lcid_mcb LCID:0x%x", arg0);
  ptr = 0;
 } else {
  ptr = ((void **)(lbl_8052D5A8 + 0x3C))[index];
  if (ptr != 0 && *(u16 *)((u8 *)ptr + 0x68) != arg0) {
   if (lbl_8052D5A8[0x414] >= 2U) fn_80231A14(0x90001, "rfc_find_lcid_mcb LCID reused LCID:0x%x current:0x%x", arg0, *(u16 *)((u8 *)ptr + 0x68));
   ptr = 0;
  }
 }
 if (ptr == 0) {
  if (lbl_8052D5A8[0x414] >= 1U) fn_802319FC(0x90000, "RFCOMM_ConfigInd LCID:0x%x", arg0);
 } else fn_80252784(ptr, 0xC, (void *)arg1);
}
void fn_80252164(u32 arg0, void *arg1) {
 void *p; int idx = arg0 - 0x40;
 if (idx >= 10) {
  if (lbl_8052D5A8[0x414] >= 1U) fn_802319FC(0x90000, "rfc_find_lcid_mcb LCID:0x%x", arg0);
  p = 0;
 } else {
  p = ((void **)(lbl_8052D5A8 + 0x3C))[idx];
  if (p != 0 && *(u16 *)((u8 *)p + 0x68) != arg0) {
   if (lbl_8052D5A8[0x414] >= 2U) fn_80231A14(0x90001, "rfc_find_lcid_mcb LCID reused LCID:0x%x current:0x%x", arg0, *(u16 *)((u8 *)p + 0x68));
   p = 0;
  }
 }
 if (p == 0) {
  if (lbl_8052D5A8[0x414] >= 1U) fn_802319FC(0x90000, "RFCOMM_ConfigCnf LCID:0x%x", arg0);
 } else fn_80252784(p, 0xB, arg1);
}
#pragma pop
void fn_8025226C(void) {}
void fn_80252270(u32 arg0, int arg1) {
 s32 temp; void *obj;
 temp = arg0 - 0x40;
 if (temp >= 10) {
  if (lbl_8052D5A8[0x414] >= 1U) fn_802319FC(0x90000, "rfc_find_lcid_mcb LCID:0x%x", arg0);
  obj = 0;
 } else {
  obj = *(void **)(lbl_8052D5A8 + temp * 4 + 0x3C);
  if (obj != 0 && *(u16 *)((u8 *)obj + 0x68) != arg0) {
   if (lbl_8052D5A8[0x414] >= 2U) fn_80231A14(0x90001, "rfc_find_lcid_mcb LCID reused LCID:0x%x current:0x%x", arg0, *(u16 *)((u8 *)obj + 0x68));
   obj = 0;
  }
 }
 if (arg1 != 0) fn_8024AB20(arg0);
 if (obj == 0) {
  if (lbl_8052D5A8[0x414] >= 2U) fn_802319FC(0x90001, "RFCOMM_DisconnectInd LCID:0x%x", arg0);
 } else fn_80252784(obj, 0xE, 0);
}
static inline u8 *find_entry(s32 arg0) {
 u8 *ent;
 if (arg0 - 0x40 >= 0xA) {
  if (lbl_8052D5A8[0x414] >= 1) fn_802319FC(0x90000, "rfc_find_lcid_mcb LCID:0x%x", arg0);
  ent = 0;
 } else {
  ent = *(u8 **)(lbl_8052D5A8 + (arg0 - 0x40) * 4 + 0x3c);
  if (ent != 0 && (u32)*(u16 *)(ent + 0x68) != (u32)arg0) {
   if (lbl_8052D5A8[0x414] >= 2) fn_80231A14(0x90001, "rfc_find_lcid_mcb LCID reused LCID:0x%x current:0x%x", arg0, *(u16 *)(ent + 0x68));
   ent = 0;
  }
 }
 return ent;
}
void fn_80252394(s32 arg0, u8 *arg1) {
 u8 *ent; u8 *r27; u8 kind; u8 r4v;
 ent = find_entry(arg0);
 if (ent == 0) {
  if (lbl_8052D5A8[0x414] >= 2) fn_802319FC(0x90001, "RFCOMM_BufDataInd LCID:0x%x", arg0);
  fn_8022F0E0(arg1); return;
 }
 kind = fn_80255544(ent, lbl_8052D5A8, arg1);
 if (kind == 0x32) { fn_8022F0E0(arg1); return; }
 if (lbl_8052D5A8[0] == 0) {
  if (kind == 4) { fn_80255AB8(ent, arg1); return; }
  fn_80252784(ent, kind, 0); fn_8022F0E0(arg1); return;
 }
 r27 = fn_80251AD0(ent, lbl_8052D5A8[0]);
 if (r27 == 0 || *(u32 *)(r27 + 0x6c) == 0) {
  if (kind != 0) {
   r4v = ent[0x6d];
   if ((r4v != 0 && lbl_8052D5A8[2] == 0) || (r4v == 0 && lbl_8052D5A8[2] != 0))
    fn_80254BF4(ent, lbl_8052D5A8[0], lbl_8052D5A8[4]);
   fn_8022F0E0(arg1); return;
  }
  r27 = fn_80251B24(lbl_8052D5A8[0]);
  if (r27 == 0) { fn_80254BF4(ent, lbl_8052D5A8[0], 1); fn_8022F0E0(arg1); return; }
  (ent + lbl_8052D5A8[0])[0x24] = r27[0];
  *(u8 **)(r27 + 0x6c) = ent;
 }
 if (kind == 4) {
  if (*(u16 *)(arg1 + 2) != 0) fn_802533C8(r27, kind, arg1);
  else fn_8022F0E0(arg1);
  if (lbl_8052D5A8[5] != 0) fn_80256790(r27, lbl_8052D5A8[5]);
 } else { fn_802533C8(r27, kind, 0); fn_8022F0E0(arg1); }
}
void fn_80252634(unsigned int arg0, int arg1) {
 int index = arg0 - 0x40; u8 *p;
 if (index >= 10) {
  if (lbl_8052D5A8[0x414] >= 1) fn_802319FC(0x90000, "rfc_find_lcid_mcb LCID:0x%x", arg0);
  p = 0;
 } else {
  p = *(u8 **)(lbl_8052D5A8 + 0x3c + index * 4);
  if (p != 0 && *(u16 *)(p + 0x68) != arg0) {
   if (lbl_8052D5A8[0x414] >= 2) fn_80231A14(0x90001, "rfc_find_lcid_mcb LCID reused LCID:0x%x current:0x%x", arg0, *(u16 *)(p + 0x68));
   p = 0;
  }
 }
 if (p == 0) {
  if (lbl_8052D5A8[0x414] >= 1) fn_802319FC(0x90000, "RFCOMM_CongestionStatusInd dropped LCID:0x%x", arg0);
 } else {
  if (lbl_8052D5A8[0x414] >= 4) fn_802319FC(0x90003, "RFCOMM_CongestionStatusInd LCID:0x%x\0\0\0\0\0\0\0", arg0);
  fn_8025443C(p, arg1);
 }
}