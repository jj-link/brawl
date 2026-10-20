#include <so/so_module_accesser.h>
#pragma force_active on

extern "C" {
extern unsigned char g_ftCommonDataAccesser[];

void* getData__20ftCommonDataAccesserCF6ftKind(const void*, int);
float getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(
    soModuleAccesser*, unsigned long, unsigned long);
void fn_107_141A0(void*, soModuleAccesser*);
}

// Views reproducing only the vtable layout used here.
class ftGwWorkManageView {
public:
    virtual void s02();
    virtual void s03();
    virtual void s04();
    virtual void s05();
    virtual void s06();
    virtual void addInt(int addValue, unsigned long index);      // +0x1C
    virtual void s08();
    virtual void s09();
    virtual void s10();
    virtual void s11();
    virtual void s12();
    virtual void s13();
    virtual void s14();
    virtual void addFloat(float addValue, unsigned long index);  // +0x3C
    virtual void s16();
    virtual void s17();
    virtual void s18();
    virtual void s19();
    virtual void turnOffFlag(unsigned long index);               // +0x50
    virtual void clearAll(unsigned long index);                  // +0x54
};

class ftGwPostureView {
public:
    virtual void s02();
    virtual void s03();
    virtual void s04();
    virtual void s05();
    virtual void s06();
    virtual void s07();
    virtual void s08();
    virtual void s09();
    virtual void s10();
    virtual float getValue();  // +0x2C
};

extern "C" void fn_107_13974(void* owner, soModuleAccesser* accesser) {
    ftGwWorkManageView* workManage;

    const void* data = getData__20ftCommonDataAccesserCF6ftKind(g_ftCommonDataAccesser, 0x12);
    const void* table =
        *reinterpret_cast<void* const*>(static_cast<const char*>(data) + 0xb8);

    workManage =
        reinterpret_cast<ftGwWorkManageView*>(accesser->m_enumerationStart->m_workManageModule);

    workManage->addFloat(
        reinterpret_cast<ftGwPostureView*>(accesser->m_enumerationStart->m_postureModule)
            ->getValue(),
        0x21000005);
    workManage->clearAll(0x22000011);
    workManage->addFloat(
        getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(accesser, 0xc3b, 0),
        0x21000004);
    workManage->clearAll(0x22000010);
    workManage->addInt(*reinterpret_cast<const int*>(static_cast<const char*>(table) + 0x28),
                       0x20000000);

    fn_107_141A0(owner, accesser);
}
