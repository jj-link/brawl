#include <types.h>
#include <string.h>
#pragma force_active on

extern "C" {
extern char lbl_804656F0[];
extern int lbl_805A0508;
void *fn_80204E5C(void *, int);
void Insert__Q44nw4r2ut6detail12LinkListImplFQ54nw4r2ut6detail12LinkListImpl8IteratorPQ34nw4r2ut12LinkListNode(
    char *list, void **it, void *node);
}

class VObj {
public:
    virtual void slot00();
    virtual void slot01();
    virtual void slot02();
    virtual void slot03();
    virtual void slot04();
    virtual void slot05();
    virtual void slot06();
    virtual void slot07();
    virtual void slot08();
    virtual void slot09();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void *slot13(char *, int);
};

struct NodeRaw {
    void *next;
    void *prev;
    void *data;
    NodeRaw() : next(NULL), prev(NULL) {}
};

extern "C" void *fn_80183634(char *self, char *arg1, VObj *items) {
    void **head;
    s32 off;
    char *base;
    s32 i;

    head = (void **)(self + 0x10);
    *(void **)(self + 0x10) = NULL;
    *(void **)(self + 0x14) = NULL;
    *(char **)self = lbl_804656F0;
    *(s32 *)(self + 0x4) = 0;
    *(s32 *)(self + 0x8) = 0;
    *(s32 *)(self + 0xc) = 0;
    *head = (void *)head;
    head[1] = (void *)head;
    ((u8 *)head)[0x19] = 0;
    strncpy(self + 0x18, arg1 + 8, 0x10);
    self[0x28] = 0;

    base = arg1 + 0x1c;
    i = 0;
    off = 0;
    for (; i < *(u16 *)(arg1 + 0x18); i++) {
        void *vobj = items->slot13(base + off, 1);
        if (vobj != NULL) {
            void *r = fn_80204E5C((void *)lbl_805A0508, 0xc);
            if (r != NULL) {
                NodeRaw *node = new (r) NodeRaw;
                node->data = vobj;
                {
                    void *it = self + 0x10;
                    Insert__Q44nw4r2ut6detail12LinkListImplFQ54nw4r2ut6detail12LinkListImpl8IteratorPQ34nw4r2ut12LinkListNode(
                        self + 0xc, &it, node);
                }
            }
        }
        off += 0x10;
    }
    return self;
}
