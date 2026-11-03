#pragma force_active on
typedef unsigned char u8;
typedef int s32;

extern void fn_803900A0(void *p);
extern void *fn_803970D4(s32 a, void *b);

typedef struct Node {
    struct Node *next;
} Node;

typedef void (*Callback)(void *, void (*)(void *), s32);

typedef struct Obj {
    u8 pad00[0x1C];
    s32 unk1C;
    void *unk20;
    void *unk24;
    void *unk28;
    u8 pad2C[4];
    Callback unk30;
    void *unk34;
    u8 pad38[0x438 - 0x38];
    s32 unk438;
} Obj;

typedef struct Ret {
    u8 pad00[0x14];
    s32 unk14;
} Ret;

void fn_80391B8C(s32 arg0, Obj *arg1) {
    Node *node;
    Node *next;
    Ret *r;

    while (arg1->unk34 != 0) {
        node = arg1->unk34;
        next = node->next;
        fn_803900A0(node);
        arg1->unk34 = next;
    }
    if (arg1->unk20 != 0) {
        fn_803900A0(arg1->unk20);
    }
    if (arg1->unk24 != 0) {
        fn_803900A0(arg1->unk24);
    }
    if (arg1->unk30 != 0) {
        arg1->unk30(arg1->unk28, fn_803900A0, arg1->unk438);
        arg1->unk28 = 0;
        arg1->unk1C = 0;
    }
    r = fn_803970D4(arg0, arg1);
    if (r != 0) {
        r->unk14 = 0;
    }
    fn_803900A0(arg1);
}
