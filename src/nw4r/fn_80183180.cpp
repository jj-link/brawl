#pragma force_active on

struct ListNode {
    ListNode* next;
};

class Obj {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16(int, int);
    virtual void f17();
    virtual void f18();

    char pad[0x10];
    ListNode sentinel;
};

extern "C" void fn_80183180(Obj* self, int arg1, int arg2) {
    self->f18();
    if (arg2 != 0) {
        ListNode* node;
        ListNode* head = &self->sentinel;
        node = head->next;
        while (node != head) {
            Obj* o = (Obj*)((char*)node - 4);
            o->f16(arg1, arg2);
            node = node->next;
        }
    }
}
