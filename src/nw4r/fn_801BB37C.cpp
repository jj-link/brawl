#pragma force_active on
#pragma opt_loop_invariants off

typedef unsigned char u8;
typedef unsigned short u16;

struct Inner {
    char pad[0x38];
    u16 type;
};

struct Item {
    Inner* inner;
    char pad4[0x19];
    u8 f1d;
    char pad1e[0x1a];
    void (*fn)(Item*, int, int);
    int arg;
};

struct Node;

struct Mgr {
    int count0;
    Node* head0;
    int pad8;
    int countC;
    Node* head10;
    int pad14;
    int count18;
    Node* head1C;
    int pad20;
    u8 flag;
};

extern "C" {
int OSDisableInterrupts();
void OSRestoreInterrupts(int);
void fn_8015C2BC(void* list, Node** out);
void fn_801B885C(void*, int);
void fn_801FF4CC(void*);
void fn_802022DC(void*, int);
void Erase__Q44nw4r2ut6detail12LinkListImplFPQ34nw4r2ut12LinkListNode(void*, Node*);
void Insert__Q44nw4r2ut6detail12LinkListImplFQ54nw4r2ut6detail12LinkListImpl8IteratorPQ34nw4r2ut12LinkListNode(void*, Node**, Node*);
}

extern "C" void fn_801BB37C(Mgr* self) {
    if (self->flag == 0)
        return;
    while (self->count0 != 0) {
        int s1;
        int s2;
        Node* tmp = self->head0;
        Item* obj = (Item*)((char*)tmp - 0x40);
        fn_8015C2BC(self, &tmp);
        if (obj->inner == 0)
            continue;
        {
            int b = 0;
            if (obj->inner != 0 && obj->inner->type == 1)
                b = 1;
            if (b != 0)
                fn_802022DC(obj->inner, 0);
        }
        if (obj->fn != 0)
            obj->fn(obj, 0, obj->arg);
        s1 = OSDisableInterrupts();
        Inner* in = obj->inner;
        if (in != 0)
            fn_801FF4CC(in);
        fn_801B885C(obj, -1);
        s2 = OSDisableInterrupts();
        Node* n;
        if (obj->f1d != 0) {
            n = (Node*)((char*)obj + 0x40);
            Erase__Q44nw4r2ut6detail12LinkListImplFPQ34nw4r2ut12LinkListNode((char*)self + 0x18, n);
        } else {
            n = (Node*)((char*)obj + 0x40);
            Erase__Q44nw4r2ut6detail12LinkListImplFPQ34nw4r2ut12LinkListNode(self, n);
        }
        Node* it = (Node*)((char*)self + 0x10);
        Insert__Q44nw4r2ut6detail12LinkListImplFQ54nw4r2ut6detail12LinkListImpl8IteratorPQ34nw4r2ut12LinkListNode((char*)self + 0xC, &it, n);
        OSRestoreInterrupts(s2);
        OSRestoreInterrupts(s1);
    }
    while (self->count18 != 0) {
        Node* head = self->head1C;
        Item* obj = (Item*)((char*)head - 0x40);
        Node* tmp = self->head0;
        fn_8015C2BC(self, &tmp);
        if (obj->inner == 0)
            continue;
        {
            int b = 0;
            if (obj->inner != 0 && obj->inner->type == 1)
                b = 1;
            if (b != 0)
                fn_802022DC(obj->inner, 0);
        }
        if (obj->fn != 0)
            obj->fn(obj, 0, obj->arg);
        int s1 = OSDisableInterrupts();
        Inner* in = obj->inner;
        if (in != 0)
            fn_801FF4CC(in);
        fn_801B885C(obj, -1);
        int s2 = OSDisableInterrupts();
        Node* n;
        if (obj->f1d != 0) {
            n = (Node*)((char*)obj + 0x40);
            Erase__Q44nw4r2ut6detail12LinkListImplFPQ34nw4r2ut12LinkListNode((char*)self + 0x18, n);
        } else {
            n = (Node*)((char*)obj + 0x40);
            Erase__Q44nw4r2ut6detail12LinkListImplFPQ34nw4r2ut12LinkListNode(self, n);
        }
        Node* it = (Node*)((char*)self + 0x10);
        Insert__Q44nw4r2ut6detail12LinkListImplFQ54nw4r2ut6detail12LinkListImpl8IteratorPQ34nw4r2ut12LinkListNode((char*)self + 0xC, &it, n);
        OSRestoreInterrupts(s2);
        OSRestoreInterrupts(s1);
    }
    while (self->countC != 0) {
        Node* head = self->head10;
        Node* tmp = head;
        fn_8015C2BC((char*)self + 0xC, &tmp);
        fn_801B885C((char*)head - 0x40, -1);
    }
    self->flag = 0;
}
