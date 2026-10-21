#pragma force_active on

struct utList {
    void* getNode(unsigned long index);
};

struct Target {
    char pad[0x30];
    unsigned int bits;
};

struct Node {
    Node* next;
    char pad[0x8];
    Target* target;
};

class MethodObj {
public:
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual void m8();
    virtual void m9();
    virtual void call(float f);
};

struct InnerObj {
    char pad[0xC4];
    MethodObj* obj;
};

struct DataInfo {
    char pad[0xD8];
    InnerObj* inner;
};

struct Accessor {
    char pad[0x44];
    DataInfo* data;
};

extern "C" Accessor* fn_27_6F30C(void* node);

struct Owner {
    char pad[0x14];
    utList list;
};

extern "C" void fn_27_6EA30(Owner* self, float f) {
    Node* node;
    for (node = (Node*)self->list.getNode(0); node != 0; node = node->next) {
        if ((node->target->bits >> 8) & 0x10000) {
            Accessor* acc = fn_27_6F30C(node);
            MethodObj* obj = acc->data->inner->obj;
            obj->call(f);
        }
    }
}
