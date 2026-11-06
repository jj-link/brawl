#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef int s32;

typedef struct Vol {
    u16 sectorSize;
    u8 pad2[0x1a];
    s32 state;
    u8 pad20[0xc];
    u32 cursor;
    u32 end;
} Vol;

typedef struct Node {
    u8 pad0[8];
    void *data;
} Node;

extern void fn_803E2074(void);
extern s32 fn_803DA454(Vol *, s32, Node **, s32 *);
extern void fn_803DA55C(Vol *, Node *);
extern void fn_803D634C(void *, s32, u32);
extern s32 PFSEC_WriteData(void *, void *, s32, s32, s32, u32 *, s32);
extern void fn_803D6C50(Vol *, void *);
extern void PF_enterCritical(void *);
extern void PF_exitCritical(void *);
extern char lbl_805644C0[];
extern char lbl_80492FD8[];

s32 fn_803DD9DC(Vol *arg0) {
    Node *node;
    u32 written;
    s32 unused;
    s32 r;
    u32 i;

    switch (arg0->state) {
    case 2:
        fn_803E2074();
        break;
    case 0:
    case 1:
        r = fn_803DA454(arg0, -1, &node, &unused);
        if (r != 0) {
            return r;
        }
        fn_803D634C(node->data, 0, arg0->sectorSize);
        for (i = arg0->cursor; i < arg0->end; i++) {
            r = PFSEC_WriteData(arg0, node->data, i, 0, arg0->sectorSize, &written, 0);
            if (r != 0) {
                fn_803DA55C(arg0, node);
                return r;
            }
            if (written != arg0->sectorSize) {
                fn_803DA55C(arg0, node);
                return 0x11;
            }
        }
        fn_803DA55C(arg0, node);
        break;
    default:
        return 7;
    }
    PF_enterCritical(lbl_805644C0 + 0x64);
    fn_803D6C50(arg0, lbl_80492FD8);
    PF_exitCritical(lbl_805644C0 + 0x64);
    return 0;
}
