#pragma force_active on
class Class_80487F38 {
public:
    virtual void fn_802E3814(int);
    virtual void fn_80080A64();
    virtual void fn_802E3958();
    virtual void fn_802E3A90();
    virtual int fn_802E3950();
    unsigned short size;
    short refs;
};
class SoHeapAllocator {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual Class_80487F38* alloc(int, int);
};
struct Owner {
    char pad[0x68];
    Class_80487F38* object;
};
extern SoHeapAllocator* lbl_805A0EB8;
extern char lbl_80532FF0[16];
extern "C" void fn_802E2CB0(Owner*, Class_80487F38*);
extern "C" Class_80487F38* fn_802E38AC(Class_80487F38*);
extern "C" void fn_802E3284(Owner* self, int kind) {
    if (self->object == 0 || kind != self->object->fn_802E3950()) {
        switch (kind) {
        case 1:
            fn_802E2CB0(self, (Class_80487F38*)lbl_80532FF0);
            break;
        case 2:
            Class_80487F38* p = lbl_805A0EB8->alloc(0x70, 0x29);
            p->size = 0x70;
            if (p != 0)
                p = fn_802E38AC(p);
            fn_802E2CB0(self, p);
            if (p->size != 0) {
                if (--p->refs == 0 && p != 0)
                    p->fn_802E3814(1);
            }
            break;
        }
    }
}