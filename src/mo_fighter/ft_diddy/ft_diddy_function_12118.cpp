#include <ft/ft_common_data_accesser.h>
#include <so/so_module_accesser.h>
#pragma force_active on

struct DiddyArticleModule {
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
    virtual void setup(void*, int);
};

extern "C" void fn_115_12CD8(void*, soModuleAccesser*);
extern "C" void fn_115_12FD0(void*, soModuleAccesser*);

extern "C" void fn_115_12118(void* self, soModuleAccesser* accesser, int kind) {
    switch (kind) {
    case 0x116:
    case 0x12c:
    case 0x12d:
        break;
    case 0x12e:
        fn_115_12CD8(self, accesser);
        fn_115_12FD0(self, accesser);
        break;
    default:
        fn_115_12CD8(self, accesser);
        fn_115_12FD0(self, accesser);
        accesser->m_enumerationStart->m_effectModule->removeCommon(0x26);
        accesser->m_enumerationStart->m_effectModule->removeCommon(0x25);
        ftData* data = g_ftCommonDataAccesser.getData((ftKind)0x1b);
        static_cast<DiddyArticleModule*>(accesser->m_enumerationStart->m_generateArticleManageModule)->setup(
            *reinterpret_cast<void**>(reinterpret_cast<char*>(data) + 0x90), 0);
        for (int i = 0; i < 9; ++i) {
            accesser->m_enumerationStart->m_areaModule->enableArea(i, true, -1);
        }
        break;
    }
}
