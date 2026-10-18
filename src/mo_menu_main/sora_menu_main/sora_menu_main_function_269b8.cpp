#pragma force_active on
extern "C" void fn_800B8EDC(void*, void*);
extern "C" void fn_800B8A0C(void*, int);

struct Node {
    char pad[0x10];
    void* value;
};

struct Data {
    char pad[0x1BC];
    Node* node;
    char pad2[0x60];
    void* value;
};

struct Other {
    char pad[0x34];
    void* value;
};

struct Target {
    virtual void unused0();
    virtual void unused1();
    virtual void unused2();
    virtual void unused3();
    virtual void unused4();
    virtual void unused5();
    virtual void unused6();
    virtual void unused7();
    virtual void unused8();
    virtual void unused9();
    virtual void unused10();
    virtual void unused11();
    virtual void unused12();
    virtual void call(void*);
};

struct Object {
    char pad[0x64C];
    Data* data;
    Other* other;
    Target* target;
    char pad2[0x38];
    void* handle;
};

extern "C" void fn_2_269B8(Object* self) {
    fn_800B8EDC(self->handle, self->data->value);
    fn_800B8A0C(self->handle, 1);
    self->target->call(self->data->node->value);
    self->target->call(self->other->value);
}
