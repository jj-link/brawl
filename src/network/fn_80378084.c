#include <types.h>
#pragma force_active on

typedef struct Key {
    s32 id;
    s16 type;
    u8 pad[0x9A];
} Key;

typedef struct Arg {
    u8 pad00[0x0C];
    void *unkC;
    u8 pad10[0x38 - 0x10];
    s32 unk38;
    s32 unk3C;
} Arg;

typedef struct Obj {
    s32 unk00;
    s16 unk04;
    u8 pad06[0x08 - 0x06];
    void *unk08;
    u8 pad0C[0x1C - 0x0C];
    s32 unk1C;
    u8 pad20[0x44 - 0x20];
    void *unk44;
    u8 pad48[0x50 - 0x48];
    void *unk50;
    u8 pad54[0x5C - 0x54];
    void *unk5C;
    void *unk60;
    s16 unk64;
    s16 unk66;
    u8 pad68[0x88 - 0x68];
    s32 unk88;
    u8 pad8C[0x98 - 0x8C];
    void *unk98;
    void *unk9C;
} Obj;

extern void *fn_8035A460(s32, s32, s32);
extern void fn_8035A4FC(void *p);
extern void fn_8035B078(void *obj, void *arg);
extern s32 *fn_8035B1C4(void *obj, Key **key);
extern u32 fn_8035D728(void);
extern void *fn_8035DFE8(s32 size);
extern void fn_8035E00C(void *p);
extern s32 fn_80373780(void *self, s32 arg);

s32 fn_80378084(Arg *arg0, s32 *arg1, s32 arg2, s16 arg3) {
    u8 buf[0xA0];
    Key key1;
    Key key2;
    Obj *obj;
    Key *kp;
    Key *kp2;
    s32 *p;
    s32 r = 0;

    obj = NULL;
    key1.id = arg2;
    key1.type = arg3;
    kp = &key1;
    p = fn_8035B1C4(arg0->unkC, &kp);
    if (p != NULL) {
        r = *p;
    }
    if (r != 0) {
        return 5;
    }
    obj = fn_8035DFE8(0xA0);
    if (obj != NULL) {
        memset(obj, 0, 0xA0);
        obj->unk00 = arg2;
        obj->unk04 = arg3;
        obj->unk08 = arg0;
        obj->unk1C = fn_8035D728();
        r = 0;
        obj->unk88 = obj->unk1C;
        obj->unk64 = 0;
        obj->unk66 = 0;
        if (fn_80373780(&obj->unk44, arg0->unk3C) != 0 && fn_80373780(&obj->unk50, arg0->unk38) != 0) {
            obj->unk5C = fn_8035A460(0x10, 0x40, 0);
            if (obj->unk5C != NULL) {
                obj->unk60 = fn_8035A460(0x10, 0x40, 0);
                if (obj->unk60 != NULL) {
                    obj->unk98 = fn_8035A460(4, 2, 0);
                    if (obj->unk98 != NULL) {
                        obj->unk9C = fn_8035A460(4, 2, 0);
                        if (obj->unk9C != NULL) {
                            fn_8035B078(arg0->unkC, &obj);
                            key2.id = arg2;
                            key2.type = arg3;
                            kp2 = &key2;
                            p = fn_8035B1C4(arg0->unkC, &kp2);
                            if (p != NULL) {
                                r = *p;
                            }
                            *arg1 = r;
                            if (r != 0) {
                                return 0;
                            }
                            goto block_15;
                        }
                    }
                }
            }
        }
    }
block_15:
    if (obj != NULL) {
        fn_8035E00C(obj->unk44);
        fn_8035E00C(obj->unk50);
        if (obj->unk5C != NULL) {
            fn_8035A4FC(obj->unk5C);
        }
        if (obj->unk60 != NULL) {
            fn_8035A4FC(obj->unk60);
        }
        if (obj->unk98 != NULL) {
            fn_8035A4FC(obj->unk98);
        }
        if (obj->unk9C != NULL) {
            fn_8035A4FC(obj->unk9C);
        }
        fn_8035E00C(obj);
    }
    return 1;
}
