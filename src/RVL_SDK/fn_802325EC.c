#pragma force_active on
typedef signed int s32;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct Ent Ent;
typedef struct Head Head;

struct Ent {
    Ent *next;
    u32 unk4;
    void (*fn)(Ent *);
    s32 unkC;
    u32 unk10;
    u16 unk14;
};

struct Head {
    Ent *head;
    u32 unk4;
    s32 unk8;
    s32 unkC;
    u8 unk10;
};

extern void *fn_8022EE58(unsigned short size);
extern void fn_8022FFDC(unsigned char);
extern void fn_80230078(Head *, s32);
extern void fn_802301F0(Head *, Ent *);
extern void fn_802324E0(void *);

void fn_802325EC(Head *arg0) {
    Ent *ent;
    u16 *p;

    fn_80230078(arg0, arg0->unkC);
    goto cond;
body:
    fn_802301F0(arg0, ent);
    if (ent->fn != 0) {
        ent->fn(ent);
    } else if (ent->unk14 != 0) {
        p = fn_8022EE58(8);
        if (p != 0) {
            *p = ent->unk14;
            fn_802324E0(p);
        }
    }
cond:
    ent = arg0->head;
    if (ent != 0 && ent->unkC <= 0) {
        goto body;
    }
    if (ent == 0) {
        fn_8022FFDC(arg0->unk10);
    }
}
