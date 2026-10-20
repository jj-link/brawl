#pragma force_active on
struct Result {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual int getValue();
};

struct Module {
    int field0;
    int field4;
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual Result* getResult();
};

struct OwnerData {
    char padding[0x28];
    void* value;
};

struct ModuleHolder {
    Module* module;
};

struct Context {
    char padding0[8];
    OwnerData* owner;
    char padding1[0xCC];
    ModuleHolder* holder;
};

extern "C" void fn_27_3ABCF8(void*, void*, int);

extern "C" int fn_122_DEE0(void* self, Context* context) {
    void* value = context->owner->value;
    Result* result = context->holder->module->getResult();
    int id = result->getValue();
    fn_27_3ABCF8(self, value, id);
    return 1;
}
