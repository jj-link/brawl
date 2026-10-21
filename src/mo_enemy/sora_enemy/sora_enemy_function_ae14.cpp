#include <so/so_module_accesser.h>
#pragma force_active on

extern "C" void* fn_41_473DC(void*, int);
extern "C" void fn_41_47470(void*, void*, void*);
extern "C" void fn_41_47544(unsigned char*, void*);
extern "C" void fn_41_47A2C(void*, void*, int);
extern "C" void fn_41_47E80(void*, unsigned char, void*, void*, void*);

namespace {
class Value {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual int getValue(int);
};
}

extern "C" int fn_41_AE14(void* self, soModuleAccesser* acc) {
    void* value = acc->m_enumerationStart->m_workManageModule;
    int x = static_cast<Value*>(value)->getValue(0x10000007);
    void* p = fn_41_473DC(acc, x);

    int local[3];
    fn_41_47470(local, p, acc);

    unsigned char flag = 0;
    fn_41_47544(&flag, p);
    fn_41_47A2C(p, acc, 1);
    fn_41_47E80(local, flag, self, p, acc);
    return 0;
}
