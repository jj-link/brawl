#pragma force_active on
typedef unsigned int u32;

extern "C" {
extern char lbl_96_data_BCA8[];
extern char lbl_96_data_C06C[];

void fn_27_C3418(void*, void*);
void fn_27_C3C40(void*);
void fn_27_C3C00(void*);
void fn_96_1C3E0(void*);
void fn_96_1DE6C(void*);
void __construct_array(void*, void (*)(void*), void (*)(void*),
                       unsigned long, unsigned long);
void postInitialize__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacell(
    void*, long, long);
void fn_96_1C3C4(void*);
void fn_27_C4104(void*, void*);
void fn_27_C3B38(void*, void*);
void fn_27_C3B40(void*, void*);
}

struct EntryInterface {
    virtual void slot2();
    virtual void* get(int);
};

struct ModuleInterface {
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual void m8();
    virtual void m9();
    virtual void m10();
    virtual void m11();
    virtual void m12();
    virtual void enable(int);
};

struct OwnerInterface {
    virtual void o2();
    virtual void o3();
    virtual void o4();
    virtual void o5();
    virtual void o6();
    virtual void o7();
    virtual void o8();
    virtual void o9();
    virtual void o10();
    virtual void o11();
    virtual void o12();
    virtual void o13();
    virtual void o14();
    virtual void o15();
    virtual void o16();
    virtual void o17();
    virtual void o18();
    virtual void o19();
    virtual void o20();
    virtual void o21();
    virtual void o22();
    virtual void o23();
    virtual void o24();
    virtual void o25();
    virtual void o26();
    virtual void o27();
    virtual void o28();
    virtual void attach(void*);
};

struct Flags {
    u32 a : 8;
    u32 b : 4;
    u32 c : 1;
    u32 d : 19;
};

struct Obj {
    void* vt;
    void* vt2;
    void* owner;
    char module[0x1c];
    void* av;
    void* calc;
    Flags flags;
    char entries[0x38];
    char items[7][0x18c];
    int fieldB40;
    char fieldB44[0x14];
    int fieldB58;
    int fieldB5C;
    int fieldB60;
};

extern "C" Obj* fn_96_1C244(Obj* self, void* owner) {
    self->vt = lbl_96_data_BCA8;
    self->vt2 = lbl_96_data_BCA8 + 12;
    self->owner = owner;

    fn_27_C3418(self->module, &self->av);

    self->av = lbl_96_data_C06C;
    self->calc = lbl_96_data_C06C + 0x48;
    self->flags.a = 0;
    self->flags.b = 7;
    self->flags.c = 0;

    __construct_array(self->entries, fn_27_C3C40, fn_27_C3C00, 8, 7);
    postInitialize__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacell(
        &self->calc, 7, 7);
    __construct_array(self->items, fn_96_1C3E0, fn_96_1DE6C, 0x18c, 7);

    self->fieldB40 = 0;
    fn_96_1C3C4(self->fieldB44);
    self->fieldB58 = 0;
    self->fieldB5C = 0;
    self->fieldB60 = -1;

    for (int i = 0; i < 7; i++) {
        void* entry = ((EntryInterface*)&self->av)->get(i);
        fn_27_C4104(entry, self->items[i]);
    }

    void* p = *(void**)((char*)self->owner + 0xd8);
    p = *(void**)((char*)p + 0x84);
    ((OwnerInterface*)p)->attach(self->module);
    ((ModuleInterface*)self->module)->enable(1);
    fn_27_C3B38(self->module, self);
    fn_27_C3B40(self->module, &self->vt2);

    return self;
}
