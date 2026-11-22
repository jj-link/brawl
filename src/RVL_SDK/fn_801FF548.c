#pragma force_active on

typedef struct Node {
    struct Node* older;
    struct Node* newer;
    unsigned int unk8;
    unsigned int fC;
    void (*cb)(struct Node*);
    unsigned int f14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int f20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    unsigned int unk30;
    unsigned int unk34;
    unsigned short f38;
} Node;

extern int OSDisableInterrupts(void);
extern void OSRestoreInterrupts(int);
extern void fn_80201EF8(void*);
extern Node* lbl_804E4850[32];
extern Node* lbl_804E48D0[36];

Node* fn_801FF548(unsigned int arg0, unsigned int arg1, unsigned int arg2)
{
    unsigned int i;

    int enabled = OSDisableInterrupts();
    Node* node = lbl_804E4850[0];

    if (node != 0) {
        lbl_804E4850[0] = node->older;
    }

    if (node == 0) {
        Node** p = &lbl_804E4850[1];
        Node** t = &lbl_804E48D0[1];
        for (i = 1; i < arg0; i++, p++, t++) {
            Node* n = *p;
            node = 0;
            if (n != 0) {
                Node* tail = *t;
                if (n == tail) {
                    *t = 0;
                    node = n;
                    *p = 0;
                } else if (tail != 0) {
                    node = tail;
                    *t = tail->newer;
                    (*t)->older = 0;
                }
            }
            if (node != 0) {
                if (node->f38 == 1) {
                    node->f20 = 1;
                }
                if (node->cb != 0) {
                    node->cb(node);
                }
                break;
            }
        }
    }

    if (node != 0) {
        node->older = lbl_804E4850[arg0];
        node->newer = 0;
        if (node->older != 0) {
            lbl_804E4850[arg0]->newer = node;
            lbl_804E4850[arg0] = node;
        } else {
            lbl_804E4850[arg0] = node;
            lbl_804E48D0[arg0] = node;
        }
        node->fC = arg0;
        node->cb = (void (*)(struct Node*))arg1;
        node->f14 = arg2;
        fn_80201EF8(node);
    }

    OSRestoreInterrupts(enabled);
    return node;
}
