#include <types.h>
#include <string.h>
#include <stdio.h>
#include <revolution/OS/OSTime.h>
#pragma force_active on

typedef struct Entry { char data[12]; } Entry;

typedef struct StateBC0 {
    int state;
    int *handle;
    unsigned int count;
    int pad;
    s64 time;
    int index;
    Entry *object;
    unsigned char current;
    unsigned char arg;
    unsigned char mode;
    unsigned char done;
    int flag;
    char pad28[8];
    void (*callback)(int, int, void *);
    void *context;
    char pad38[0x18];
    void (*callback50)(int, void *);
    void *arg54;
} StateBC0;

typedef struct G6E84 {
    int unk0;
    char pad4[0x18];
    int unk1C;
    u8 unk20;
    u8 unk21;
    u8 unk22;
    u8 unk23;
    char pad24[0xC];
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
} G6E84;

typedef struct G70C0 { s32 unk0; char pad4[0x14]; s32 unk18; s32 unk1C; char pad20[0x18]; void (*unk38)(s32, u8, void *, s32); s32 unk3C; } G70C0;
typedef struct Arg70C0 { s32 unk0; s32 pad4; s32 unk8; } Arg70C0;
typedef struct S8 { s32 unk0; s32 unk4; char pad8[0x100]; } S8;

typedef struct S7310 {
    u32 f0;
    u32 f4;
    u32 f8;
    u32 fc;
    s64 t10;
} S7310;

typedef struct Str7350 {
    char pad[4];
    void **unk4;
} Str7350;

typedef struct Obj7350 {
    char pad[0x230];
    int unk230;
    char pad234[0x100];
    int unk234;
    char pad334[0x100];
    int unk334;
} Obj7350;

typedef struct State7474 {
    char pad0[4];
    void *connection;
    char pad1[0x14];
    Entry *entries;
    unsigned char index;
    unsigned char changed;
    unsigned char phase;
} State7474;

typedef struct Arg7E1C {
    int unk0;
    int unk4;
    int unk8;
    char *unkC;
} Arg7E1C;

typedef struct Manager {
    int unk0;
    char pad04[0x18];
    char *unk1C;
    u8 unk20;
    u8 unk21;
    u8 unk22;
    char pad23[0x15];
    void (*unk38)(int, u8, void *, void *);
    void *unk3C;
    char pad40[8];
    void (*unk48)(int, void *);
    void *unk4C;
} Manager;

typedef struct Info {
    char pad[0x24];
    unsigned int code;
} Info;

typedef struct State8128 {
    char pad0[4];
    void *ctx;
    char pad1[0x10];
    int count;
    void *entries;
} State8128;

typedef struct Arg8128 {
    int status;
    int id;
    char pad[0x86];
    char name[9];
    char code[4];
} Arg8128;

typedef struct State8358 {
    int state;
    char pad04[0x14];
    int count;
    Entry *entries;
    char pad20;
    unsigned char changed;
    char pad22[0x16];
    void (*callback)(int, unsigned char, void *, void *);
    void *context;
    char pad40[8];
    void (*callback2)(int, void *);
    void *context2;
} State8358;

typedef struct Result {
    int error;
    int id;
    char pad08[0x86];
    char name[1];
} Result;

typedef void (*Callback)(int, int, void *);

extern StateBC0 *lbl_805A0F70;
extern int lbl_805A0F74, lbl_805A0F78, lbl_805A0F7C;
extern char lbl_8059F080[8];

extern int fn_80339410(void);
extern int fn_8033891C(void);
extern int fn_803517BC(int, int);
extern int fn_803685D0(void *, int);
extern int fn_80368648(void *, int);
extern int fn_80335638(int, const char *, ...);
extern int fn_80335238(void);
extern s64 fn_803F1470(s64, s64);
extern int fn_80367C74(int *);
extern int fn_80383698(void);
extern int fn_803836B0(void);
extern void fn_80383470(void);
extern void fn_8033524C(int, int);
extern int fn_80367F78(int, int, int, int, void *, int);
extern int fn_803683E8(void *, int, void *);
extern int fn_80368538(void *, int, int *);
extern int fn_803683A0(void *, int *);
extern int fn_803680C8(void *, int, void *);
extern int fn_80367EA8(void *, int, int, int, int, void *, int, int, void (*)(void), int);
extern int fn_80350C4C(void *);
extern int fn_80350C70(void *);
extern void fn_80350C7C(void *);
extern void fn_80351A80(void *, int);
extern void fn_80351AE8(int, void *, void *);
extern u8 fn_80336698(void *, int, int, void *);
extern void fn_80368238(void *, int);
extern void fn_803682A8(void *, int);
extern int fn_803F6150(const char *, const char *, unsigned int);
extern int fn_803686D0(void **, int, int, int);

void fn_80337474(Entry *arg0, int arg1);
s32 fn_80337780(s32 arg0, s32 arg1, s32 arg2);
int fn_8033790C(int arg0, int arg1, int arg2);
int fn_80337BBC(int arg0);
void fn_80337E1C(int arg0, Arg7E1C *arg1, int arg2, int arg3);
void fn_80338128(void *a, Arg8128 *b);
void fn_80338358(void *arg0, Result *arg1);

void fn_803369F0(void *arg0) {
    int value;
    if (lbl_805A0F70 != 0 && fn_80339410() != 0 && fn_8033891C() != 0 &&
        (value = fn_803517BC(fn_8033891C(), (int)arg0)) != 0 && value != -1 &&
        fn_803685D0(*(void **)((char *)lbl_805A0F70 + 4), value) != 0) {
        fn_80368648(*(void **)((char *)lbl_805A0F70 + 4), value);
        fn_80335638(4, "DWC_DeleteBuddyFriendData : Deleted buddy.\n");
    } else {
        fn_80335638(4, "DWC_DeleteBuddyFriendData : Only clear data.\n");
    }
    memset(arg0, 0, 12);
}

int fn_80336AC8(int a, int b) {
    if (lbl_805A0F70 == 0) {
        return 0;
    }
    *(int*)((char*)lbl_805A0F70 + 0x48) = a;
    *(int*)((char*)lbl_805A0F70 + 0x4c) = b;
    return 1;
}

void fn_80336AF0(int *arg0, int arg1, int arg2, int arg3, int arg4) {
    lbl_805A0F70 = (StateBC0 *)arg0;
    *arg0 = 0;
    *(int *)((char *)lbl_805A0F70 + 0x04) = arg1;
    *(int *)((char *)lbl_805A0F70 + 0x08) = 0;
    *(long long *)((char *)lbl_805A0F70 + 0x10) = 0;
    *(int *)((char *)lbl_805A0F70 + 0x18) = arg4;
    *(int *)((char *)lbl_805A0F70 + 0x1C) = arg3;
    *((unsigned char *)lbl_805A0F70 + 0x20) = 0;
    *((unsigned char *)lbl_805A0F70 + 0x21) = 0;
    *((unsigned char *)lbl_805A0F70 + 0x22) = 0;
    *((unsigned char *)lbl_805A0F70 + 0x23) = 0;
    *(int *)((char *)lbl_805A0F70 + 0x24) = 0;
    *(int *)((char *)lbl_805A0F70 + 0x28) = 0;
    *(int *)((char *)lbl_805A0F70 + 0x2C) = arg2;
    *(int *)((char *)lbl_805A0F70 + 0x30) = 0;
    *(int *)((char *)lbl_805A0F70 + 0x34) = 0;
    *(int *)((char *)lbl_805A0F70 + 0x38) = 0;
    *(int *)((char *)lbl_805A0F70 + 0x3C) = 0;
    *(int *)((char *)lbl_805A0F70 + 0x40) = 0;
    *(int *)((char *)lbl_805A0F70 + 0x44) = 0;
    *(int *)((char *)lbl_805A0F70 + 0x48) = 0;
    *(int *)((char *)lbl_805A0F70 + 0x4C) = 0;
    *(int *)((char *)lbl_805A0F70 + 0x50) = 0;
    *(int *)((char *)lbl_805A0F70 + 0x54) = 0;
    *(int *)((char *)lbl_805A0F70 + 0x58) = 0;
    *(int *)((char *)lbl_805A0F70 + 0x5C) = 0;
}

void fn_80336BC0(void)
{
    s64 now;
    StateBC0 *p31;
    void *v30;

    if (lbl_805A0F70 == 0 || fn_80335238() != 0) {
        return;
    } else {
        if (lbl_805A0F70->object == 0) {
            if (lbl_805A0F70->handle != 0 && *lbl_805A0F70->handle != 0) {
                now = OSGetTime();
                v30 = lbl_805A0F70;
                if (fn_803F1470(now - ((StateBC0 *)v30)->time, OS_TIME_SPEED / 1000) >= 300) {
                    ((StateBC0 *)v30)->count++;
                    fn_80367C74(lbl_805A0F70->handle);
                    lbl_805A0F70->time = OSGetTime();
                }
            }
            return;
        }

        if (lbl_805A0F70->flag != 0 || fn_80383698() != 0) {
            lbl_805A0F78 = 1;
            lbl_805A0F7C = 0;
            if (fn_803836B0() == 0) {
                lbl_805A0F78 = 0;
                fn_80335638(8, "Connection to the stats server was lost\n");
            }
            lbl_805A0F78 = 0;
            if (lbl_805A0F7C == 1) {
                lbl_805A0F7C = 0;
                fn_80383470();
            }
        }

        if (lbl_805A0F70->handle != 0 && *lbl_805A0F70->handle != 0) {
            v30 = 0;
            now = OSGetTime();
            p31 = lbl_805A0F70;
            if (fn_803F1470(now - p31->time, OS_TIME_SPEED / 1000) >= 300) {
                p31->count++;
                v30 = (void *)(long)fn_80367C74(lbl_805A0F70->handle);
                now = OSGetTime();
                p31 = lbl_805A0F70;
                p31->time = now;
            }
            if (v30 != 0)
                return;
            if (p31->state == 0)
                return;
            if (p31->object != 0 && p31->mode != 3 && p31->count > 7) {
                if (p31->mode <= 1)
                    fn_80337474(p31->object, p31->index);
                if (lbl_805A0F70->current >= lbl_805A0F70->index) {
                    lbl_805A0F70->mode = 3;
                    lbl_805A0F70->done++;
                }
            }
        }

        if (lbl_805A0F70->done >= 2) {
            lbl_805A0F70->done = 0;
            lbl_805A0F70->callback(0, lbl_805A0F70->arg, lbl_805A0F70->context);
            lbl_805A0F70->state = 2;
        }
    }
}

#define GP ((G6E84 *)lbl_805A0F70)
void fn_80336E84(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7) {
    GP->unk30 = a2;
    GP->unk34 = a3;
    GP->unk38 = a4;
    GP->unk3C = a5;
    GP->unk40 = a6;
    GP->unk44 = a7;
    GP->unk21 = 0;
    GP->unk22 = 0;
    GP->unk23 = 0;
    GP->unk20 = 0;
    GP->unk0 = 1;
    if (GP->unk1C == 0) {
        GP->unk23 = GP->unk23 + 1;
    }
    GP->unk23 = GP->unk23 + 1;
}
#undef GP

void fn_80336F14(int arg0) {
    unsigned char *p;
    int type;

    if (lbl_805A0F70 == 0 || arg0 == 0) {
        return;
    }

    ((void (*)(void))fn_8033524C)();
    p = (unsigned char *)lbl_805A0F70;
    type = *(int *)p;

    if (type != 0 && type != 2) {
        ((void (*)(int, int, int))(*(int *)(p + 0x30)))(
            arg0, p[0x21], *(int *)(p + 0x34));
    }

    if (lbl_805A0F70 != 0) {
        *(int *)lbl_805A0F70 = 0;
        *((unsigned char *)lbl_805A0F70 + 0x22) = 0;
        *((unsigned char *)lbl_805A0F70 + 0x23) = 0;
    }
}

void fn_80336FAC(int arg0, int *arg1) {
    fn_80335638(0x20000, "Received buddy request from %u\n", *arg1);
    if (((int *)lbl_805A0F70)[7] != 0) {
        fn_80335638(0x20000, "Begin to search gpInfo.\n");
        fn_80367F78(arg0, *arg1, 0, 0, (void *)fn_80338128, 0);
    }
}

int fn_8033703C(int arg0, int *arg1) {
    fn_80335638(0x20000, "Received buddy authenticated message from %u.\n", *arg1);
    fn_80335638(0x20000, "Begin to search gpInfo.\n");
    fn_80367F78(arg0, *arg1, 0, 0, (void *)fn_80338358, 0);
    return 1;
}

#define GP ((G70C0 *)lbl_805A0F70)
static inline s32 find_index(s32 id) {
    s32 base, off, i, val;
    if (GP == NULL || id == 0) return -1;
    i = 0;
    off = 0;
    while (i < GP->unk18) {
        base = GP->unk1C;
        if (base == 0) val = 0;
        else {
            val = fn_803517BC(fn_8033891C(), base + off);
            if (val == 0) goto zero;
            if (val != -1) goto skip;
zero:       val = 0;
skip:       ;
        }
        if (id == val) return i;
        off += 12;
        i++;
    }
    return -1;
}
void fn_803370C0(s32 arg0, Arg70C0 *arg1) {
    u8 sp110[0x108];
    S8 sp8;
    s32 index;
    fn_80335638(0x20000, "RECV update friend status. p:%d\n", arg1->unk0);
    if (GP->unk38 != NULL) {
        index = find_index(arg1->unk0);
        if (index != -1) {
            fn_803683E8((void *)arg0, arg1->unk8, &sp8);
            GP->unk38(index, (u8)sp8.unk4, sp110, GP->unk3C);
        }
    }
}
#undef GP

int fn_803371DC(int arg0) {
    int base = *(int *)((char *)lbl_805A0F70 + 0x1c);
    int val;
    if (base == 0) return 0;
    val = fn_803517BC(fn_8033891C(), base + arg0 * 12);
    if (val != 0 && val != -1) {
    } else {
        val = 0;
    }
    return val;
}

s32 fn_80337248(s32 arg0) {
    s32 off;
    s32 base;
    s32 i;
    s32 val;

    if (lbl_805A0F70 == 0 || arg0 == 0) {
        return -1;
    }
    for (i = 0, off = 0; i < *(s32 *)((u8 *)lbl_805A0F70 + 0x18); off += 0xC, i++) {
        base = *(s32 *)((u8 *)lbl_805A0F70 + 0x1C);
        if (base == 0) {
            val = 0;
        } else {
            val = fn_803517BC(fn_8033891C(), base + off);
            if (val == 0) {
                goto zero;
            }
            if (val != -1) {
                goto skip;
            }
        zero:
            val = 0;
        skip:;
        }
        if (arg0 == val) {
            return i;
        }
    }
    return -1;
}

#define GP ((S7310 *)lbl_805A0F70)
void fn_80337310(void) {
    s64 t;
    if (lbl_805A0F70 != 0) {
        GP->f8 = 0;
        t = OSGetTime();
        GP->t10 = t;
    }
}
#undef GP

#define GP ((Str7350 *)lbl_805A0F70)
int fn_80337350(int arg0, int arg1, int arg2) {
    int var_r28;
    int var_r29;
    int var_r30;

    var_r30 = arg2;
    var_r29 = arg1;
    var_r28 = arg0;
    if (GP == 0 || fn_80339410() == 0) {
        return 0;
    }
    if (var_r28 == -1) {
        var_r28 = ((Obj7350 *)(*(GP->unk4)))->unk230;
    } else {
        fn_80335638(4, "Change GP status->status %d\n", var_r28);
    }
    if (var_r29 == 0) {
        var_r29 = (int)(*(GP->unk4)) + 0x234;
    } else {
        fn_80335638(4, "Change GP status->statusString %s\n", var_r29);
    }
    if (var_r30 == 0) {
        var_r30 = (int)(*(GP->unk4)) + 0x334;
    } else {
        fn_80335638(4, "Change GP status->locationString %s\n", var_r30);
    }
    return fn_803686D0(GP->unk4, var_r28, var_r29, var_r30);
}
#undef GP

void fn_80337468(void) {
    lbl_805A0F70 = 0;
}

#define GP ((State7474 *)lbl_805A0F70)
static inline int getPid(int idx) {
    int r;
    if (GP->entries == 0) return 0;
    r = fn_803517BC(fn_8033891C(), (int)&GP->entries[idx]);
    if (r == 0) goto zero;
    if (r != -1) goto done;
zero:
    return 0;
done:
    return r;
}
void fn_80337474(Entry *arg0, int arg1) {
    int count;
    int index;
    int data[0x82];
    char info[0x18];
    int i;
    int value;
    int off;
    Entry *entry;

    if (GP->phase == 0) {
        fn_80337BBC(fn_803683A0(GP->connection, &count));
        fn_80335638(0x20000, "gpGetNumBuddies -> %d\n", count);
        for (index = 0; index < count; index++) {
            fn_80337BBC(fn_803683E8(GP->connection, index, data));
            for (i = 0; i < arg1; i++) {
                if (data[0] == getPid(i)) {
                    off = i * 12;
                    if (fn_80350C4C((void *)((int)arg0 + off)) == 0) {
                        entry = (Entry *)((char *)arg0 + off);
                        fn_80351A80((void *)entry, data[0]);
                        fn_80350C7C((void *)entry);
                        GP->changed = 1;
                    }
                    break;
                }
            }
            if (i == arg1) {
                fn_80335638(0x20000, "Deleted buddy %u\n", data[0]);
                fn_80337BBC(fn_80368648(GP->connection, data[0]));
                count--;
                index--;
            }
        }
        GP->phase = 1;
    }

    while (GP->index < arg1) {
        value = getPid(GP->index);
        if (value != 0) {
            if (fn_80337780((s32)arg0, GP->index, value) == 0) {
                fn_80337BBC(fn_80368538(GP->connection, value, &index));
                if (index == -1) {
                    fn_80337BBC(fn_803680C8(GP->connection, value, lbl_8059F080));
                    fn_80335638(0x20000, "Send buddy request to %u\n", value);
                }
            }
        } else {
            if (fn_803517BC(fn_8033891C(), (int)(arg0 + GP->index)) == -1) {
                fn_80351AE8(fn_8033891C(), (void *)(arg0 + GP->index), info);
                fn_80367EA8(GP->connection, 0, 0, 0, 0, info, 0, 0, (void (*)(void))fn_80337E1C, GP->index);
                fn_80335638(0x20000, "Called gpProfileSearch().\n");
                GP->phase = 2;
                return;
            }
        }
        GP->index++;
    }
}
#undef GP

s32 fn_80337780(s32 arg0, s32 arg1, s32 arg2)
{
    void (*fn)(s32, s32, void *);
    s32 val;
    s32 base;
    s32 off;
    s32 destOff;
    s32 i;

    i = 0;
    off = 0;
    while (i < arg1) {
        base = *(s32 *)((u8 *)lbl_805A0F70 + 0x1C);
        if (base == 0) {
            val = 0;
        } else {
            val = fn_803517BC(fn_8033891C(), base + off);
            if (val == 0) {
                goto zero;
            }
            if (val != -1) {
                goto skip;
            }
        zero:
            val = 0;
        skip:;
        }

        if (val != 0 && val == arg2) {
            base = i * 0xC;
            fn_80335638(
                0x20000,
                "Found same friend in the list [%d] & [%d], %d\n",
                i,
                arg1,
                fn_80350C70((void *)(arg0 + base))
            );
            destOff = arg1 * 0xC;

            if (fn_80350C4C((u8 *)arg0 + destOff) != 0 &&
                fn_80350C4C((void *)(arg0 + base)) == 0) {
                if (lbl_805A0F70 != 0) {
                    memset((u8 *)arg0 + base, 0, 0xC);
                    fn = *(void (**)(s32, s32, void *))((u8 *)lbl_805A0F70 + 0x40);
                    if (fn != 0) {
                        fn(i, arg1, *(void **)((u8 *)lbl_805A0F70 + 0x44));
                    }
                }
            } else if (lbl_805A0F70 != 0) {
                memset((void *)(arg0 + destOff), 0, 0xC);
                fn = *(void (**)(s32, s32, void *))((u8 *)lbl_805A0F70 + 0x40);
                if (fn != 0) {
                    fn(arg1, i, *(void **)((u8 *)lbl_805A0F70 + 0x44));
                }
            }

            *((u8 *)lbl_805A0F70 + 0x21) = 1;
            return 1;
        }

        off += 0xC;
        i++;
    }

    return 0;
}

int fn_8033790C(int arg0, int arg1, int arg2)
{
    int val;
    int offset;
    int ptr_a;
    int ptr_b;
    int inner_a;
    int inner_b;
    int inner_off;
    int result;
    int i;
    int j;
    int field1c;
    int field1c2;
    int val2;
    int temp;
    Callback func;
    result = -1;
    ptr_a = arg0;
    ptr_b = arg0;
    i = 0;
    offset = 0;
    while (i < arg1) {
        field1c = *(int *)((char *)lbl_805A0F70 + 0x1C);
        if (field1c == 0) {
            val = 0;
        } else {
            temp = fn_803517BC(fn_8033891C(), field1c + offset);
            if (temp == 0) goto zero1;
            if (temp != -1) goto valid1;
zero1:      val = 0;
            goto end1;
valid1:     val = temp;
end1:       ;
        }
        if (val != 0) {
            if (val == arg2) result = i;
            j = i + 1;
            inner_off = j * 0xC;
            inner_a = arg0 + inner_off;
            inner_b = inner_a;
            while (j < arg1) {
                field1c2 = *(int *)((char *)lbl_805A0F70 + 0x1C);
                if (field1c2 == 0) {
                    val2 = 0;
                } else {
                    temp = fn_803517BC(fn_8033891C(), field1c2 + inner_off);
                    if (temp == 0) goto zero2;
                    if (temp != -1) goto valid2;
zero2:              val2 = 0;
                    goto end2;
valid2:             val2 = temp;
end2:               ;
                }
                if (val == val2) {
                    if (fn_80350C70((void *)ptr_a) == 2 && fn_80350C70((void *)inner_a) == 3)
                        fn_80351A80((void *)ptr_b, val);
                    if (fn_80350C4C((void *)inner_a) != 0) fn_80350C7C((void *)ptr_b);
                    fn_80335638(0x20000, "Found same friend in the list [%d] & [%d], %d\n", i, j, fn_80350C70((void *)ptr_a));
                    if (lbl_805A0F70 != 0) {
                        memset((void *)inner_b, 0, 0xC);
                        func = *(Callback *)((char *)lbl_805A0F70 + 0x40);
                        if (func != 0) func(j, i, *(void **)((char *)lbl_805A0F70 + 0x44));
                    }
                    *((unsigned char *)lbl_805A0F70 + 0x21) = 1;
                }
                inner_off += 0xC;
                inner_a += 0xC;
                inner_b += 0xC;
                j++;
            }
        }
        offset += 0xC;
        ptr_a += 0xC;
        ptr_b += 0xC;
        i++;
    }
    return result;
}

u8 fn_80337AF0(int arg0, int arg1) {
    int sp8;
    int temp;

    sp8 = 0;
    if (lbl_805A0F70 == 0 || fn_80339410() == 0) {
        return 0;
    }
    temp = fn_803517BC(fn_8033891C(), arg0);
    if (temp > 0 && fn_80368538(*(void **)((char *)lbl_805A0F70 + 4), temp, &sp8) != 0) {
        return 0;
    }
    if (temp <= 0 || sp8 == -1) {
        return 0;
    }
    return fn_803683E8(*(void **)((char *)lbl_805A0F70 + 4), sp8, (void *)arg1) == 0;
}

int fn_80337BBC(int arg0) {
    int var_r31;
    int var_r3;
    unsigned char *p;
    int type;

    if (arg0 == 0) {
        return 0;
    }

    var_r3 = fn_80335638(2, "Friend, GP error %d\n", arg0);
    switch (arg0) {
    case 1:
        var_r31 = 9;
        var_r3 = -1;
        break;
    case 2:
        var_r31 = 9;
        var_r3 = -2;
        break;
    case 3:
        var_r31 = 6;
        var_r3 = -10;
        break;
    case 4:
        var_r31 = 6;
        var_r3 = -20;
        break;
    }

    if (lbl_805A0F70 != 0 && var_r31 != 0) {
        fn_8033524C(var_r31, var_r3 - 0x11558);
        p = (unsigned char *)lbl_805A0F70;
        type = *(int *)p;

        if (type != 0 && type != 2) {
            ((void (*)(int, int, int))(*(int *)(p + 0x30)))(
                var_r31, p[0x21], *(int *)(p + 0x34));
        }

        if (lbl_805A0F70 != 0) {
            *(int *)lbl_805A0F70 = 0;
            *((unsigned char *)lbl_805A0F70 + 0x22) = 0;
            *((unsigned char *)lbl_805A0F70 + 0x23) = 0;
        }
    }

    return arg0;
}

char lbl_80489690[32] = "Friend, persistent error %d\n";

int fn_80337CE4(int arg0) {
    int var_r31;
    int var_r3;
    void (*fn)(int, void *);
    if (arg0 == 0) return 0;
    fn_80335638(2, lbl_80489690, arg0);
    switch (arg0) {
    case 1: var_r31 = 6; var_r3 = -50; break;
    case 2: var_r31 = 6; var_r3 = -30; break;
    case 3: var_r31 = 6; var_r3 = -20; break;
    case 5: var_r31 = 6; var_r3 = -40; break;
    case 7: var_r31 = 6; var_r3 = -70; break;
    }
    if (lbl_805A0F74 == 1 && lbl_805A0F70 != 0 && var_r31 != 0) {
        fn_8033524C(var_r31, var_r3 - 0x16760);
        if (lbl_805A0F78 == 1) lbl_805A0F7C = 1;
        else fn_80383470();
        lbl_805A0F74 = 0;
        if (lbl_805A0F70 != 0) lbl_805A0F70->flag = 0;
        fn = lbl_805A0F70->callback50;
        if (fn != 0) fn(var_r31, lbl_805A0F70->arg54);
    }
    return arg0;
}

void fn_80337E1C(int arg0, Arg7E1C *arg1, int arg2, int arg3)
{
    int id, off2, j, i, offset, sp8;
    struct {
        char pad[0x108];
        char data[0x100];
    } buffer;

    fn_80335638(4, "ProfileSearch: num:%d m:%x\n", arg1->unk4, arg1->unk8);
    if (arg1->unk0 == 0 && arg1->unk4 != 0 &&
        fn_80350C70((void *)(((Manager *)lbl_805A0F70)->unk1C + arg2 * 12)) != 0) {
        if (arg1->unk4 > 1)
            fn_80335638(0x20000, "Happned to find %d profiles.\n", arg1->unk4);

        if (((Manager *)lbl_805A0F70)->unk0 == 1) {
            for (i = 0, offset = 0; i < arg1->unk4; offset += 0xAC, ++i) {
                if (fn_80337780((s32)((Manager *)lbl_805A0F70)->unk1C,
                                arg2, *(int *)(arg1->unkC + offset)) != 0) {
                    ((Manager *)lbl_805A0F70)->unk20++;
                    ((Manager *)lbl_805A0F70)->unk22 = 1;
                    arg1->unk8 = 0x601;
                    return;
                }
            }

            for (j = 0, off2 = 0; j < arg1->unk4; off2 += 0xAC, ++j) {
                fn_80337BBC(fn_80368538((void *)arg0, *(int *)(arg1->unkC + off2), &sp8));
                if (sp8 == -1) {
                    id = *(int *)(arg1->unkC + off2);
                    fn_80337BBC(fn_803680C8(*(void **)((char *)lbl_805A0F70 + 4),
                                 id, lbl_8059F080));
                    fn_80335638(0x20000, "Send buddy request to %u\n", id);
                } else {
                    fn_80351A80(
                        (void *)(((Manager *)lbl_805A0F70)->unk1C + arg2 * 12),
                        *(int *)arg1->unkC);
                    fn_80350C7C(
                        (void *)(((Manager *)lbl_805A0F70)->unk1C + arg2 * 12));
                    if (((Manager *)lbl_805A0F70)->unk48 != 0 &&
                        ((Manager *)lbl_805A0F70)->unk0 != 1) {
                        ((Manager *)lbl_805A0F70)->unk48(
                            arg2, ((Manager *)lbl_805A0F70)->unk4C);
                    }
                    if (((Manager *)lbl_805A0F70)->unk38 != 0) {
                        u8 result = fn_80336698(
                            (void *)(((Manager *)lbl_805A0F70)->unk1C +
                                  arg2 * 12),
                            0, 0, buffer.data);
                        ((Manager *)lbl_805A0F70)->unk38(
                            arg2, result, buffer.data,
                            ((Manager *)lbl_805A0F70)->unk3C);
                    }
                    ((Manager *)lbl_805A0F70)->unk20++;
                    ((Manager *)lbl_805A0F70)->unk22 = 1;
                    arg1->unk8 = 0x601;
                    ((Manager *)lbl_805A0F70)->unk21 = 1;
                    return;
                }
            }

            if (arg1->unk8 != 0x600) {
                ((Manager *)lbl_805A0F70)->unk20++;
                ((Manager *)lbl_805A0F70)->unk22 = 1;
                return;
            }
            fn_80335638(4, "more profiles will come...\n");
            return;
        }
    } else if (arg1->unk0 != 0) {
        if (fn_80337BBC(arg1->unk0) == 0)
            return;
        return;
    } else {
        if (((Manager *)lbl_805A0F70)->unk0 == 1 ||
            fn_80350C70((void *)(((Manager *)lbl_805A0F70)->unk1C +
                              arg2 * 12)) == 0) {
            ((Manager *)lbl_805A0F70)->unk20++;
            ((Manager *)lbl_805A0F70)->unk22 = 1;
        }
    }
}

#define GP ((State8128 *)lbl_805A0F70)
void fn_80338128(void *a, Arg8128 *b)
{
    char code[8];
    char name[32];
    int rid;
    int off;
    int i;
    unsigned int v;
    int id;
    int found = 0;

    if (b->status != 0) {
        fn_80335638(0x20, " ERROR: GetInfo Req. why??? : %d\n", b->status);
        return;
    }

    fn_80335638(4, "GetInfo Req: profileID %u, lastname '%s'.\n", b->id, b->name);

    i = 0;
    off = 0;
    for (; i < GP->count; i++) {
        if (fn_80350C70((char *)GP->entries + off) == 1) {
            fn_80351AE8(fn_8033891C(), (char *)GP->entries + off, name);
            if (strcmp(name, b->name) == 0) {
                fn_80368238(a, b->id);
                fn_80351A80((char *)GP->entries + off, b->id);
                found = 1;
                fn_80335638(0x20000, "Auth buddy request from %u, friend[%d]mp.\n", b->id, i);
            }
        } else if (fn_80350C70((char *)GP->entries + off) == 3 ||
                   fn_80350C70((char *)GP->entries + off) == 2) {
            v = ((Info *)fn_8033891C())->code;
            snprintf(code, 5, "%c%c%c%c", v >> 24,
                     (v >> 16) & 0xff, (v >> 8) & 0xff, v & 0xff);
            id = b->id;
            if (id == fn_803517BC(fn_8033891C(), (int)((char *)GP->entries + off)) &&
                fn_803F6150(code, b->code, 4) == 0) {
                fn_80368238(a, id);
                found = 1;
                fn_80335638(0x20000, "Auth buddy request from %u, friend[%d]gs.\n", b->id, i);
            }
        }
        off += 12;
    }

    if (found) {
        rid = b->id;
        fn_80337BBC(fn_803680C8(GP->ctx, rid, lbl_8059F080));
        fn_80335638(0x20000, "Send buddy request to %u\n", rid);
        return;
    }

    fn_803682A8(a, b->id);
    fn_80335638(0x20000, "Denied buddy request from %u.\n", b->id);
}
#undef GP

#define GP ((State8358 *)lbl_805A0F70)
void fn_80338358(void *arg0, Result *arg1)
{
    char buf2[0x110];
    char buf[0x120];
    int offset;
    int i;
    int found = 0;
    int blocked = 0;
    int index;
    if (arg1->error != 0) {
        fn_80335638(0x20, " ERROR: GetInfo Auth. why??? : %d\n", arg1->error);
        return;
    }
    fn_80335638(4, "GetInfo Auth: profileID %u, lastname '%s'.\n", arg1->id, arg1->name);
    for (i = 0, offset = 0; i < GP->count; offset += 12, i++) {
        if (fn_80350C70((Entry *)((char *)GP->entries + offset)) == 1) {
            fn_80351AE8(fn_8033891C(), (Entry *)((char *)GP->entries + offset), buf);
            if (strcmp(buf, arg1->name) == 0) {
                fn_80351A80((Entry *)((char *)GP->entries + offset), arg1->id);
                fn_80350C7C((Entry *)((char *)GP->entries + offset));
                found = 1;
                fn_80335638(0x20000, "Established buddy with %u, friend[%d]mp.\n", arg1->id, i);
            }
        } else if (fn_80350C70((Entry *)((char *)GP->entries + offset)) == 3 ||
                   fn_80350C70((Entry *)((char *)GP->entries + offset)) == 2) {
            if (arg1->id == fn_803517BC(fn_8033891C(), (int)(Entry *)((char *)GP->entries + offset))) {
                if (fn_80350C4C((Entry *)((char *)GP->entries + offset)) == 1) {
                    fn_80335638(0x20000, "This profile is already my friend[%d].\n", i);
                    blocked = 1;
                } else {
                    fn_80351A80((Entry *)((char *)GP->entries + offset), arg1->id);
                    fn_80350C7C((Entry *)((char *)GP->entries + offset));
                    found = 1;
                    fn_80335638(0x20000, "Established buddy with %u, friend[%d]gs.\n", arg1->id, i);
                }
            }
        }
    }
    if (found) {
        index = fn_8033790C((int)GP->entries, GP->count, arg1->id);
        if (!blocked) {
            if (GP->callback2 != 0 && GP->state != 1)
                GP->callback2(index, GP->context2);
            if (GP->callback != 0) {
                unsigned char value = fn_80336698(&GP->entries[index], 0, 0, buf2);
                GP->callback(index, value, buf2, GP->context);
            }
        }
        GP->changed = 1;
    } else if (!blocked) {
        /* The bytes after the first terminator are the unused tail of this
           file's string data (text used by functions outside this group). */
        fn_80335638(0x20000,
            "Not Established buddy with %u.\n\0"
            "Stats server authentication failed.\n\0\0\0\0"
            "Stats server authentication succeeded.\n\0"
            "Persitent, Specified key is not exist.\n\0"
            "Loaded data from persistent server. -> %s\n\0\0"
            "Failed to load persistent data.\n\0\0\0\0"
            "Saved data to persistent server.\n\0\0\0"
            "Failed to save persistent data.\n\0\0\0", arg1->id);
    }
}
#undef GP
