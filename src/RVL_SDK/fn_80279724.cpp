#include <types.h>
#pragma force_active on

extern "C" {
void fn_8015C144(void*, void*);
void* fn_8015C1B0(void*, void*);
void fn_80204E6C(int, void*);
void __dl__FPv(void*);
extern int lbl_80485F58[];
extern int lbl_80485FAC[];
}

class Class_80485F60 {
public:
    virtual void fn_80278AEC();
    virtual void fn_80279274();
    virtual void fn_802795DC();
    virtual void fn_80278ADC();
    virtual void fn_80279644();
    virtual void fn_80279724(int);
};

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5(int);
};

struct Node {
    void* next;
    Object_vptr_0* object;
};

struct Obj {
    void* vtbl;
    int unk4;
    void* list2;
    int unkC;
    int unk10;
    int allocator;
    void* list1;
};

extern "C" void* fn_80279724(void* arg0, s32 arg1) {
    Obj* obj;
    Node* curr;

    obj = (Obj*)arg0;
    if (obj != 0) {
        obj->vtbl = lbl_80485F58;
        curr = (Node*)fn_8015C1B0(&obj->list1, 0);
        while (curr != 0) {
            fn_8015C144(&obj->list1, curr);
            if (obj->allocator != 0) {
                fn_80204E6C(obj->allocator, curr->object);
                fn_80204E6C(obj->allocator, curr);
            } else {
                Object_vptr_0* object = curr->object;
                if (object != 0) {
                    object->slot5(1);
                }
                __dl__FPv(curr);
            }
            curr = (Node*)fn_8015C1B0(&obj->list1, 0);
        }

        if (obj != 0) {
            obj->vtbl = lbl_80485FAC;
            curr = (Node*)fn_8015C1B0(&obj->list2, 0);
            while (curr != 0) {
                fn_8015C144(&obj->list2, curr);
                if (obj->allocator != 0) {
                    fn_80204E6C(obj->allocator, curr);
                } else {
                    __dl__FPv(curr);
                }
                curr = (Node*)fn_8015C1B0(&obj->list2, 0);
            }
        }

        if (arg1 > 0) {
            __dl__FPv(obj);
        }
    }
    return arg0;
}
