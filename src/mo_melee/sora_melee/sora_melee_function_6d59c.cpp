#pragma force_active on
struct Node {
    virtual void unused();
    virtual void* get(int);
};
struct Object {
    char pad[0x48];
    Node* node;
};
struct Module {
    char pad[8];
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
    virtual void set(float, unsigned int);
};
struct Modules {
    char pad[0x9c];
    Module* module;
};
struct Data {
    char pad[0xd8];
    Modules* modules;
};
struct Accessor {
    char pad[0x44];
    Data* data;
};
extern "C" Accessor* fn_27_6F30C(void*);
extern "C" void fn_27_6D59C(Object self, int id, float value, unsigned int index) {
    void* object = self.node->get(id);
    Accessor* accessor = fn_27_6F30C((char*)object + 0x1c);
    accessor->data->modules->module->set(value, index);
}
