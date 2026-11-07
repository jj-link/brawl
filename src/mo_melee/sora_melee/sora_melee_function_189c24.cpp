#include <types.h>
#pragma force_active on

class WorkModule {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual int getInt(unsigned int);
    virtual void setInt(int, unsigned int);
    virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13();
    virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17();
    virtual void onFlag(unsigned int);
};

class MotionModule {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16();
    virtual unsigned int query();
};

class ModA8 {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27();
    virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31();
    virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35();
    virtual void v36(); virtual void v37();
    virtual void slot38(int);
    virtual void v39();
    virtual void slot40(int, float, int);
};

struct Base0 { char pad[0x3c]; };

#define V(n) virtual void f##n();
#define V10(n) V(n##0) V(n##1) V(n##2) V(n##3) V(n##4) V(n##5) V(n##6) V(n##7) V(n##8) V(n##9)
class Fighter : public Base0 {
public:
    V10(0) V10(1) V10(2) V10(3) V10(4) V10(5) V10(6) V10(7) V10(8) V10(9)
    V10(10) V10(11) V10(12) V10(13) V10(14) V10(15) V10(16) V10(17)
    V(180) V(181) V(182) V(183) V(184)
    virtual int get();
};

struct Modules {
    char pad0[8];
    MotionModule* motion;
    char pad1[0x64 - 0xc];
    WorkModule* work;
    char pad2[0xa8 - 0x68];
    ModA8* modA8;
};

struct Owner {
    char pad0[8];
    void* obj;
    char pad[0xd8 - 0xc];
    Modules* modules;
};

extern "C" void* __dynamic_cast(void*, long, const void*, const void*, long);
extern "C" const float lbl_27_rodata_251C;
extern char lbl_27_data_69C0[];
extern char lbl_27_data_248[];
extern "C" void fn_27_1D6434(int, int, int, int, Owner*);

extern "C" void fn_27_189C24(void*, Owner* owner) {
    int count = owner->modules->work->getInt(0x20000001);
    if (count > 0) {
        if (count - 1 <= 0) {
            owner->modules->work->onFlag(0x1200000c);
            owner->modules->modA8->slot40(0, lbl_27_rodata_251C, 0);
        }
        owner->modules->work->setInt(count - 1, 0x20000001);
    }
    if (owner->modules->motion->query() == 1U) {
        Fighter* f = (Fighter*)__dynamic_cast(owner->obj, 0x3c, lbl_27_data_69C0, lbl_27_data_248, 1);
        fn_27_1D6434(2, 0x68, 1, f->get(), owner);
        owner->modules->modA8->slot38(0);
    }
}
