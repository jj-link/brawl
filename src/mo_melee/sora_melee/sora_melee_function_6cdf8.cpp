#pragma force_active on
#pragma opt_prolog_schedule on
struct Provider {
    virtual void unused();
    virtual void* get();
};
struct Owner {
    char pad[0x48];
    Provider* provider;
};
struct Module {
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
    virtual void unused13();
    virtual void unused14();
    virtual void unused15();
    virtual void unused16();
    virtual void unused17();
    virtual void unused18();
    virtual void unused19();
    virtual void unused20();
    virtual void invoke(void*);
};
struct ModuleHolder {
    char pad[0xC8];
    Module* module;
};
struct Data {
    char pad[0xD8];
    ModuleHolder* holder;
};
struct Accessor {
    char pad[0x44];
    Data* data;
};
extern "C" Accessor* fn_27_6F30C(void*);
extern "C" void fn_27_6CDF8(Owner self, int id, void* value) {
    void* object = self.provider->get();
    Accessor* accessor = fn_27_6F30C(static_cast<char*>(object) + 0x1C);
    accessor->data->holder->module->invoke(value);
}
