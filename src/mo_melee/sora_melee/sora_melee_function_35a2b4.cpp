#pragma force_active on
#include <ft/fighter.h>

extern "C" {
void* __dynamic_cast(void*, long, const void*, const void*, short);
extern char lbl_27_data_8F8F0[];
extern char lbl_27_data_8F788[];
extern char lbl_27_data_C938[];
extern char lbl_27_data_2C0C0[];
extern char lbl_27_data_CBA0[];
extern char lbl_27_data_69C0[];
extern char lbl_27_data_248[];
int fn_27_111364(ftOwner*);
void fn_27_35C0C4(void*, int, int, int, int, int);
void fn_27_35F3C8(void*, int, int, int);
}

struct Object {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual int kind();
};

struct Base {
    char pad[8];
};

struct Module : Base {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void* get();
};

struct Accesser {
    Module* module;
};

struct OwnerVT {
    char pad[0x2ec];
    int (*f)(void*);
};

struct Owner {
    char pad[0x28];
    int value;
    char pad2[0x10];
    OwnerVT* vt;
};

struct Context {
    char pad0[8];
    Owner* info;
    char pad[0xd8 - 0xc];
    Accesser* acc;
};

struct Target {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual void f20();
    virtual int get(int);
};

static inline void buildArrow(void* c, Context* k, int v) {
    Fighter* o = (Fighter*)__dynamic_cast(k->info, 0x3c, lbl_27_data_69C0, lbl_27_data_248, 1);
    int val = o->m_taskId;
    int id = fn_27_111364(o->getOwner());
    fn_27_35F3C8(c, val, v, id);
}
extern "C" int fn_27_35A2B4(void* self, Object* obj, Context* ctx) {
    Context* k = ctx;
    int kind = obj->kind();
    switch (kind) {
    case 13: {
        Target* t;
        void* c = __dynamic_cast(obj, 0, lbl_27_data_8F8F0, lbl_27_data_C938, 0);
        t = (Target*)__dynamic_cast(k->acc->module->get(), 0, lbl_27_data_2C0C0, lbl_27_data_CBA0, 1);
        int v = t->get(0x17);
        fn_27_35C0C4(c, k->info->value, v, v, 1, 1);
        return 1;
    }
    case 14: {
        int v;
        Target* t;
        void* c = __dynamic_cast(obj, 0, lbl_27_data_8F788, lbl_27_data_C938, 0);
        t = (Target*)__dynamic_cast(k->acc->module->get(), 0, lbl_27_data_2C0C0, lbl_27_data_CBA0, 1);
        buildArrow(c, k, t->get(0x17));
        return 1;
    }
    default:
        return 0;
    }
}
