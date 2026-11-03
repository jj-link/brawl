#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed short s16;
typedef signed char s8;
typedef int s32;
typedef void (*Callback)(u8 *, void *, u8);
typedef struct Ent {
    u8 pad[12];
    u16 id;
    u8 flags;
    u8 rest[45];
} Ent;
typedef struct Obj {
    Ent *ent;
    Callback cb;
    void *result;
    u8 pad0[4];
    s32 unk10;
    s32 unk14;
    u16 unk18;
    u8 pad1[0x5c];
    u8 unk76;
    u8 pad2[8];
    u8 unk7f;
    u8 unk80;
    u8 unk81;
} Obj;
extern Obj *fn_8023A0F0(u8 *);
extern Obj *fn_80239F18(u8 *);
extern void fn_802319FC(s32, void *, u32);
extern void fn_80231A5C(s32, void *, u32, s16, u8, u8, u8);
extern void fn_80231A2C(s32, void *, s32, s32, u8);
extern u8 fn_80241D40(Obj *);
extern u8 lbl_804814C8[];
extern u8 lbl_80529CF8[];

static inline Ent *find_ent(u32 id)
{
    Ent *p = (Ent *)(lbl_80529CF8 + 0x1990);
    int i;
    for (i = 0; i < 24; i++, p++) {
        if ((p->flags & 0x80) && p->id == id)
            return p;
    }
    return 0;
}

static inline Ent *find_next(Ent *ent)
{
    Ent *p = (Ent *)(lbl_80529CF8 + 0x1990);
    int found = 0;
    int i;
    for (i = 0; i < 24; i++, p++) {
        if ((p->flags & 0x80) && p->id == ent->id) {
            if (found == 0) {
                if (ent == p)
                    found = 1;
            } else {
                return p;
            }
        }
    }
    return 0;
}

u8 fn_8023FDEC(u8 *arg0, u32 arg1, s16 arg2, u8 arg3, Callback arg4)
{
    u8 *base = lbl_804814C8;
    Obj *obj;
    Ent *ent;
    Ent *p;
    int i;
    int found;
    u8 flags;
    u8 result;

    obj = fn_8023A0F0(arg0);
    if (obj == 0) {
        obj = fn_80239F18(arg0);
        if (obj == 0) {
            if (lbl_80529CF8[0x27c0] >= 2)
                fn_802319FC(0xd0001, base + 0x410, arg1);
            if (arg4)
                arg4(arg0, 0, 3);
            return 3;
        }
    }
    obj->unk18 = arg2;
    ent = find_ent(arg1);
    if (ent == 0) {
        if (lbl_80529CF8[0x27c0] >= 2)
            fn_802319FC(0xd0001, base + 0x448, arg1);
        if (arg4)
            arg4(arg0, 0, 4);
        return 4;
    }
    if (arg3 == 0 || (arg3 != 0 && obj->ent == 0))
        obj->ent = ent;
    flags = ent->flags;
    p = find_next(ent);
    if (p) {
        if (lbl_80529CF8[0x27c0] >= 4)
            fn_802319FC(0xd0003, base + 0x48c, arg1);
        if (arg4)
            arg4(arg0, 0, 0);
        return 0;
    }
    obj->cb = arg4;
    obj->result = 0;
    obj->unk81 = flags;
    obj->unk80 = arg3;
    if (lbl_80529CF8[0x27c0] >= 4)
        fn_80231A5C(0xd0003, base + 0x4d0, arg1, arg2, obj->unk7f, obj->unk76, flags);
    if (arg3 == 0 && (flags & 1)) {
        obj->unk76 &= ~1;
        if (lbl_80529CF8[0x27c0] >= 4)
            fn_80231A2C(0xd0003, base + 0x528, obj->unk14, obj->unk10, obj->unk76);
    }
    result = fn_80241D40(obj);
    if (result != 1 && arg4) {
        arg4(arg0, obj->result, result);
        obj->cb = 0;
    }
    return result;
}