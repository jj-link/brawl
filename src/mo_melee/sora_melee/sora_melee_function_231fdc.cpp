#include <ut/ut_list.h>
#pragma force_active on
extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" int lbl_27_data_4BEC8;
struct Trigger : utListNode {
    int kind;
    int id;
    unsigned char keep;
    char pad[3];
    int a,b,c,d,e,f;
    unsigned char flag, flag2, flag3, flag4;
    void* vtable;
};
struct Manager {
    char pad[0x40];
    utList list;
};
inline Trigger* findTrigger(utList* list, int id, unsigned char keep) {
    Trigger* p = (Trigger*)*(utListNode**)list;
    while (p) {
        if (p->id == id && p->keep == keep)
            return p;
        p = (Trigger*)p->m_next;
    }
    return 0;
}
extern "C" Trigger* createTrigger__12stTriggerMngFQ27Gimmick8AreaKindi(Manager* mgr, int kind, int id) {
    Trigger* trigger = 0;
    if (id != -1) {
        trigger = findTrigger(&mgr->list, id, 0);
    }
    if (!trigger) {
        Trigger* p = (Trigger*)__nw__FUlQ25Heaps8HeapType(0x34,15);
        if (p) {
            p->vtable = &lbl_27_data_4BEC8;
            p->kind = kind;
            p->id = -1;
            p->keep = 0;
            p->a = 0; p->b = 0; p->c = 0; p->d = 0; p->e = 0; p->f = 0;
            p->flag = 0; p->flag2 = 0; p->flag3 = 0; p->flag4 = 0;
        }
        p->id = id;
        trigger = p;
        p->keep = 0;
        utListNode* node = *(utListNode**)&mgr->list;
        while (node) node = node->m_next;
        mgr->list.addTail(p);
    }
    if (id == 0 && trigger->flag4 == 0) trigger->flag = 1;
    return trigger;
}