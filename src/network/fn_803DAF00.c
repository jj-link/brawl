#include <types.h>
#pragma force_active on
typedef struct { u32 unk0; u32 unk4; u8 unk8[0xC]; u32 unk14, unk18, unk1C; } Slot;
typedef struct { u8 unk0[0x15BC]; Slot slots[3]; } Object;
typedef struct { u8 unk0[4]; u16 ref_count; } Entry;
extern int lbl_8059FEB8, lbl_8059FEBC, lbl_8059FEC0, lbl_8059FEC4;
extern int fn_803D6A50(int, void *, int, int, int);
extern u16 fn_803D68CC(int, int);
extern void fn_803D674C(int, int);
extern int fn_803DD968(void *, void *);
extern void *fn_803DADEC(void *, void *);
extern int fn_803E9D60(void *, void *);
extern void fn_803E23C0(void *);
extern int PFENT_ITER_GetEntryOfPath(void *, void *, void *, int, int);
int fn_803DAF00(void *arg0, int arg1, void **arg2)
{
    unsigned char req[0x70];
    unsigned char obj[0x240];
    Object *self = (Object *)arg0;
    Entry *entry;
    Slot *slot;
    int i;
    Object *scan;
    int ret;
    if ((fn_803D6A50(arg1, &lbl_8059FEB8, 1, 0, 1) == 0 ||
         fn_803D6A50(arg1, &lbl_8059FEBC, 1, 0, 1) == 0) &&
        fn_803D6A50(arg1, &lbl_8059FEC0, 1, 1, 1) == 0) {
        ret = fn_803DD968(arg0, obj);
        if (ret != 0) return ret;
        goto create_slot;
    }
    if (fn_803D68CC(arg1, 1) == 2 &&
        fn_803D6A50(arg1, &lbl_8059FEC4, 1, 1, 1) == 0) {
        fn_803E9D60(arg0, obj);
        goto create_slot;
    }
    if (fn_803D68CC(arg1, 1) == 3 &&
        fn_803D6A50(arg1, &lbl_8059FEC4, 1, 1, 1) == 0 &&
        (fn_803D6A50(arg1, &lbl_8059FEB8, 1, 2, 1) == 0 ||
         fn_803D6A50(arg1, &lbl_8059FEBC, 1, 2, 1) == 0)) {
        ret = fn_803DD968(arg0, obj);
        if (ret != 0) return ret;
        goto create_slot;
    }
    if (fn_803D6A50(arg1, &lbl_8059FEC4, 1, 1, 1) == 0 &&
        (fn_803D6A50(arg1, &lbl_8059FEB8, 1, 2, 1) == 0 ||
         fn_803D6A50(arg1, &lbl_8059FEBC, 1, 2, 1) == 0))
        fn_803D674C(arg1, 2);
    ret = PFENT_ITER_GetEntryOfPath(req, obj, arg0, arg1, 0);
    if (ret != 0) return ret;
    if (!(obj[0x21C] & 0x10)) return 1;
create_slot:
    entry = (Entry *)fn_803DADEC(arg0, obj);
    if (entry == 0) return 0x15;
    scan = self;
    for (i = 0; i < 3; i++) {
        if (!(scan->slots[0].unk0 & 1)) {
            slot = &self->slots[i];
            goto found;
        }
        scan = (Object *)((char *)scan + 0x20);
    }
    slot = 0;
found:
    if (slot == 0) return 0x16;
    slot->unk4 = (u32)entry;
    slot->unk0 = 1;
    fn_803E23C0(&slot->unk8);
    slot->unk14 = 0;
    slot->unk18 = 0;
    slot->unk1C = 0;
    entry->ref_count++;
    *arg2 = slot;
    return 0;
}