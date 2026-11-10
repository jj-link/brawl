#include <types.h>
#pragma force_active on

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void* slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19(void* a);
};

struct Node {
    void* a;
    void* b;
};

extern "C" {

void* fn_80204E5C(void* p, int size);
void* __nw__FUl(u32 size);
void fn_8015BFB4(void* list, void* node);

void fn_80279308(void* arg0, Object_vptr_0* arg1) {
    void* temp_r31 = arg1->slot6();
    arg1->slot19(arg0);

    void* ptr = *(void**)((char*)arg0 + 0x14);
    Node* node;
    if (ptr != 0) {
        node = (Node*)fn_80204E5C(ptr, 0x10);
        if (node != 0) {
            node->a = temp_r31;
            node->b = arg1;
        }
        fn_8015BFB4((char*)arg0 + 8, node);
    } else {
        node = (Node*)__nw__FUl(0x10);
        if (node != 0) {
            node->a = temp_r31;
            node->b = arg1;
        }
        fn_8015BFB4((char*)arg0 + 8, node);
    }
}

}