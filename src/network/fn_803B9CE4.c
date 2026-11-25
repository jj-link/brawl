#pragma force_active on

typedef struct {
    unsigned short unk00;
    char pad02[0x1E];
    unsigned char unk20;
    char pad21[0x243];
    unsigned int unk264;
    int unk268;
} Node;

typedef struct {
    int pad00;
    int pad04;
    Node *node;
    int pad0C[4];
    unsigned int unk1C;
    int unk20;
    int unk24;
    unsigned short unk28;
} Obj;

static inline unsigned int BlockCount(Node *v, unsigned int p)
{
    return (p >> v->unk20) + ((p & (v->unk00 - 1)) ? 1 : 0);
}

extern int fn_803B7080(void *, unsigned int, int, void *);
extern void fn_803B9BC8(void *, int, int);
extern int fn_803C0080(unsigned short *, int, int, unsigned short, unsigned int, int *, int);

int fn_803B9CE4(unsigned short *arg0, Obj *arg1, int arg2, unsigned int arg3, int *arg4)
{
    int sp8;
    unsigned int temp7;
    int r;
    Node *nd;
    unsigned int temp;
    unsigned int a;
    unsigned int b;

    *arg4 = 0;

    if (arg1->unk28 == 0) {
        return 0;
    }

    temp7 = *arg0 - arg1->unk28;
    if (arg3 > temp7) {
        arg3 = temp7;
    }

    if ((unsigned int)(arg1->unk1C + arg3) >
        (unsigned int)arg1->node->unk264) {
        arg3 = arg1->node->unk264 - arg1->unk1C;
        if (arg3 < temp7) {
            return 0;
        }
    }

    if ((unsigned int)(arg1->unk20 + 0x10000) == 0xFFFF) {
        r = fn_803B7080((char *)arg1->node + 4, arg1->unk24, 0,
                        (char *)arg1 + 0x20);
        if (r != 0) {
            return r;
        }

        if ((unsigned int)(arg1->unk20 + 0x10000) == 0xFFFF) {
            temp = arg1->node->unk264;
            nd = (arg1 == 0) ? 0 : (Node *)arg1->node->unk268;
            a = BlockCount(nd, arg1->unk1C);
            b = BlockCount(nd, temp);
            if (a != b) {
                arg1->unk20 = -1;
            }
            arg1->unk1C = temp;
            nd = (arg1 == 0) ? 0 : (Node *)arg1->node->unk268;
            arg1->unk24 = arg1->unk1C >> nd->unk20;
            arg1->unk28 = arg1->unk1C & (nd->unk00 - 1);
            return 0x1C;
        }

        if ((unsigned int)(arg1->unk1C + arg3) >
            (unsigned int)arg1->node->unk264) {
            temp = arg1->node->unk264;
            nd = (arg1 == 0) ? 0 : (Node *)arg1->node->unk268;
            a = BlockCount(nd, arg1->unk1C);
            b = BlockCount(nd, temp);
            if (a != b) {
                arg1->unk20 = -1;
            }
            arg1->unk1C = temp;
            nd = (arg1 == 0) ? 0 : (Node *)arg1->node->unk268;
            arg1->unk24 = arg1->unk1C >> nd->unk20;
            arg1->unk28 = arg1->unk1C & (nd->unk00 - 1);
            return 0x1B;
        }
    }

    r = fn_803C0080(arg0, arg2, arg1->unk20, arg1->unk28, arg3, &sp8, 1);
    if (r != 0 && sp8 == 0) {
        return r;
    }

    *arg4 = sp8;
    fn_803B9BC8(arg1, sp8, arg1->unk20);
    return 0;
}
