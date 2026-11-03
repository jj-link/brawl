#include <revolution/OS/OSInterrupt.h>
#pragma force_active on

typedef struct Item {
    char pad[0x40];
    unsigned char addr[6];
    char pad2[0x13];
    unsigned char state;
} Item;
typedef struct Node {
    Item *item;
    struct Node *prev;
    struct Node *next;
} Node;
typedef struct Global {
    char pad[0x64];
    Node *head;
    char pad2[4];
    Node nodes[10];
} Global;
extern Global lbl_804FB4A0;
extern int fn_803F6150(const void *, const void *, unsigned long);

void fn_8022D0D0(Item *arg)
{
    Global *p;
    Node *node;
    Global *base = &lbl_804FB4A0;
    int i;
    BOOL enabled;
    Node *cur;
    Item *item;
    unsigned char *addr;
    Node *head;

    enabled = OSDisableInterrupts();
    p = base;
    node = base->nodes;
    for (i = 0; i < 10; i++, p = (Global *)((char *)p + 12), node++) {
        addr = p->nodes[0].item->addr;
        if (fn_803F6150(addr, arg->addr, 6) == 0) {
            head = base->head;
            cur = head;
            while (cur != 0) {
                item = cur->item;
                if (fn_803F6150(item->addr, arg->addr, 6) != 0 && item->state <= 1) {
                    if (fn_803F6150(head->item->addr, addr, 6) == 0) {
                        if (cur == head->next)
                            break;
                        base->head = p->nodes[0].next;
                    } else {
                        p->nodes[0].prev->next = p->nodes[0].next;
                    }
                    p->nodes[0].next->prev = p->nodes[0].prev;
                    if (cur != base->head) {
                        p->nodes[0].prev = cur->prev;
                        p->nodes[0].next = cur;
                        cur->prev->next = node;
                        cur->prev = node;
                    } else {
                        p->nodes[0].prev = cur;
                        p->nodes[0].next = cur->next;
                        cur->next->prev = node;
                        cur->next = node;
                    }
                    break;
                }
                cur = cur->next;
            }
        }
    }
    OSRestoreInterrupts(enabled);
}