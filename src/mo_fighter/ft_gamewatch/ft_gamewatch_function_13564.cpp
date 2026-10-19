#include <so/so_module_accesser.h>
#pragma force_active on

extern "C" {
extern unsigned char g_ftCommonDataAccesser[];
extern const float lbl_107_rodata_98;

void* getData__20ftCommonDataAccesserCF6ftKind(const void*, int);
void fn_107_141A0(void*, soModuleAccesser*);
}

// Views of the module classes that only reproduce the vtable layout used here.
// Observed: the first declared method of each class sits at vtable offset 0x8
// (two entries precede it), so declared index i is at byte offset (i + 2) * 4.
class ftGwWorkManageView {
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
    virtual void s11();
    virtual void s12();
    virtual void s13();
    virtual void s14();
    virtual void subFloat(float value, unsigned long index);  // +0x3C
    virtual void s16();
    virtual void s17();
    virtual void s18();
    virtual void s19();
    virtual void turnOffFlag(unsigned long index);            // +0x50
    virtual void clearAll(unsigned long index);               // +0x54
};

class ftGwStatusView {
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
    virtual void s11();
    virtual void s12();
    virtual void s13();
    virtual void s14();
    virtual void s15();
    virtual void s16();
    virtual void s17();
    virtual int getStatusKind();                              // +0x48
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
    virtual float getValue();                                 // +0x2C
    virtual void s12();
    virtual void update();                                    // +0x34
};

class ftGwKineticView {
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
    virtual void resumeAll();                                 // +0x2C
};

extern "C" void fn_107_13564(void* owner, soModuleAccesser* accesser) {
    const char* data = *reinterpret_cast<const char* const*>(
        static_cast<char*>(getData__20ftCommonDataAccesserCF6ftKind(g_ftCommonDataAccesser, 0x12)) + 0xb8);

    if (reinterpret_cast<ftGwStatusView*>(accesser->m_enumerationStart->m_statusModule)->getStatusKind() == 0x123) {
        reinterpret_cast<ftGwWorkManageView*>(accesser->m_enumerationStart->m_workManageModule)
            ->subFloat(lbl_107_rodata_98, 0x21000005);
        reinterpret_cast<ftGwWorkManageView*>(accesser->m_enumerationStart->m_workManageModule)
            ->turnOffFlag(0x22000010);
    } else {
        const float speed = *reinterpret_cast<const float*>(data + 0xa8);
        reinterpret_cast<ftGwWorkManageView*>(accesser->m_enumerationStart->m_workManageModule)
            ->subFloat(speed, 0x21000005);
        reinterpret_cast<ftGwWorkManageView*>(accesser->m_enumerationStart->m_workManageModule)
            ->clearAll(0x22000010);
    }

    reinterpret_cast<ftGwWorkManageView*>(accesser->m_enumerationStart->m_workManageModule)
        ->clearAll(0x22000012);

    ftGwWorkManageView* workManage =
        reinterpret_cast<ftGwWorkManageView*>(accesser->m_enumerationStart->m_workManageModule);
    workManage->subFloat(
        reinterpret_cast<ftGwPostureView*>(accesser->m_enumerationStart->m_postureModule)->getValue(),
        0x21000004);
    reinterpret_cast<ftGwPostureView*>(accesser->m_enumerationStart->m_postureModule)->update();
    reinterpret_cast<ftGwKineticView*>(accesser->m_enumerationStart->m_kineticModule)->resumeAll();
    fn_107_141A0(owner, accesser);
}
