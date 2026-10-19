#pragma force_active on
typedef unsigned int u32;

struct State {
    char pad[0xE8];
    u32 value;
};

struct Base {
    u32 unk0;
    u32 unk4;
};

class Module : public Base {
public:
    virtual void unused0();
    virtual void unused1();
    virtual void unused2();
    virtual void unused3();
    virtual void set(void*, u32);
    virtual void unused5();
    virtual void unused6();
    virtual void unused7();
    virtual void unused8();
    virtual void unused9();
    virtual void unused10();
    virtual void unused11();
    virtual void unused12();
    virtual State* get();
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
    virtual void unused42();
    virtual void unused43();
    virtual void unused44();
    virtual void unused45();
    virtual void unused46();
    virtual void unused47();
    virtual void unused48();
    virtual void unused49();
    virtual void unused50();
    virtual void unused51();
    virtual void unused52();
    virtual void unused53();
    virtual void unused54();
    virtual void unused55();
    virtual void unused56();
    virtual void unused57();
    virtual void unused58();
    virtual void unused59();
    virtual void unused60();
    virtual void unused61();
    virtual void unused62();
    virtual void unused63();
    virtual void unused64();
    virtual void unused65();
    virtual void unused66();
    virtual void unused67();
    virtual void unused68();
    virtual void unused69();
    virtual void unused70();
    virtual void unused71();
    virtual void unused72();
    virtual void unused73();
    virtual void unused74();
    virtual void unused75();
    virtual void unused76();
    virtual void unused77();
    virtual u32 id();
};

struct Modules {
    u32 unk;
    Module* module;
};

struct Accessor {
    char pad[0xD8];
    Modules* modules;
};

class Context : public Base {
public:
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
    virtual u32 query();

    char pad[0x18];
    Accessor* accessor;
    void* resource;
};

extern "C" u32 fn_8008DEE8(void*, void*, u32*);
extern "C" void fn_8008B320(void*, u32, State*, int, int);

extern "C" void fn_27_11450(Context* self) {
    if (self->resource && self->query() == 1) {
        u32 id = self->accessor->modules->module->id();
        State* state = self->accessor->modules->module->get();
        char buffer[0x320];
        u32 value = state->value;
        u32 result = fn_8008DEE8(self->resource, buffer, &value);
        self->accessor->modules->module->set(buffer, result);
        fn_8008B320(self->resource, id,
                   self->accessor->modules->module->get(), 1, 0);
    }
}
