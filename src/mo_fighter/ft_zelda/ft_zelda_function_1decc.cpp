#include <so/so_module_accesser.h>

#pragma force_active on

class MySit {
public:
    virtual void a0();
    virtual void a1();
    virtual void a2();
    virtual int a3(const soModuleEnumeration&);
};

class MyKin {
public:
    virtual void k0();
    virtual void k1();
    virtual void k2();
    virtual void k3();
    virtual void k4();
    virtual void k5();
    virtual void* k6(int);
    virtual void k7();
    virtual void k8();
    virtual void k9();
    virtual void k10();
    virtual void k11();
    virtual void k12();
    virtual void k13();
    virtual void k14();
    virtual void k15();
    virtual void k16();
    virtual void k17();
    virtual void k18();
    virtual void k19();
    virtual void k20();
    virtual void k21(int, soModuleAccesser*);
};

struct Flags {
    char pad[5];
    unsigned char bit : 1;
};

extern "C" {
void* __dynamic_cast(void*, long, const void*, const void*, short);
extern const char lbl_104_data_72B4[];
extern const char lbl_104_data_2404[];

void fn_104_1DECC(void*, soModuleAccesser* accesser) {
    MySit* sit;
    const soModuleEnumeration* e = accesser->m_enumerationStart;
    MySit* t3_10 = (MySit*)e->m_situationModule;
    sit = t3_10;
    MyKin* kin = (MyKin*)e->m_kineticModule;

    if (sit->a3(*e) == 0) {
        kin->k21(0xF, accesser);
    } else {
        kin->k21(0x64, accesser);
        unsigned char* c = (unsigned char*)__dynamic_cast(
            kin->k6(1), 0, lbl_104_data_72B4, lbl_104_data_2404, 1);
        ((Flags*)c)->bit = 0;
    }
}
}