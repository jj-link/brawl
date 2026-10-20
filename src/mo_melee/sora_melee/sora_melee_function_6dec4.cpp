#pragma force_active on
struct Result {
    float x, y, z;
};

struct Object {
    virtual void unused();
    virtual char* get(unsigned int);
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
    virtual void unused12();
    virtual void unused13();
    virtual void unused14();
    virtual void unused15();
    virtual void unused16();
    virtual void unused17();
    virtual void unused18();
    virtual void unused19();
    virtual void unused20();
    virtual void unused21();
    virtual void unused22();
    virtual void unused23();
    virtual void unused24();
    virtual void unused25();
    virtual void unused26();
    virtual void unused27();
    virtual void unused28();
    virtual void unused29();
    virtual void unused30();
    virtual void unused31();
    virtual void unused32();
    virtual void unused33();
    virtual void unused34();
    virtual void unused35();
    virtual void unused36();
    virtual void unused37();
    virtual void unused38();
    virtual void unused39();
    virtual void unused40();
    virtual void unused41();
    virtual Result get(unsigned int, int);
};

struct ModuleHolder {
    char pad[4];
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

struct Context {
    char pad0[0x38];
    unsigned int index;
    char pad1[0xC];
    Object* object;
    char pad2[4];
    unsigned int value;
};

extern "C" Accessor* fn_27_6F30C(void*);

inline Data* getData(void* node) {
    return fn_27_6F30C(node)->data;
}

extern "C" Result fn_27_6DEC4(Context* context) {
    char* node = context->object->get(context->index);
    Data* data = getData(node + 0x1C);
    return data->holder->module->get(context->value, 0);
}
