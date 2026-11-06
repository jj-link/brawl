#include <so/so_value_accesser.h>
#pragma force_active on

class Object_vptr_0 {
public:
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
    virtual void slot15();
    virtual void slot16(int, int);
};

class Base { public: char pad[8]; };
class B : public Base { public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void apply(soModuleAccesser*, int, void*);
};
class A : public Base { public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual B* get();
};
struct Modules { char pad[0x38]; A* a; char pad2[8]; Object_vptr_0* b; };
struct Params { char pad[0xc]; float value; char pad2[0x2c]; char data[1]; };

extern "C" int fn_27_63438(soModuleAccesser*, float);
extern "C" int fn_27_63914(soModuleAccesser*, Params*, float, int);
extern "C" float lbl_27_rodata_8C4;

extern "C" void fn_27_63098(void*, soModuleAccesser* acc, Params* p) {
    int level = fn_27_63438(acc, p->value * soValueAccesser::getConstantFloat(acc, 0x7d2, 0));
    A* a = ((Modules*)acc->m_enumerationStart)->a;
    B* b = a->get();
    b->apply(acc, level, p->data);
    int frames = fn_27_63914(acc, p, lbl_27_rodata_8C4, 1);
    if (frames > 0) {
        ((Modules*)acc->m_enumerationStart)->b->slot16(frames, 1);
    }
}