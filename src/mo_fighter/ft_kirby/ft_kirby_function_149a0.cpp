#include <so/so_module_accesser.h>
#pragma force_active on
class ArticleModule {
public:
    virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0c();
    virtual void v10(); virtual void v14(); virtual void v18(); virtual void v1c();
    virtual void v20(); virtual void v24(); virtual void v28(); virtual void v2c();
    virtual void v30(); virtual void v34(); virtual void v38(); virtual void v3c();
    virtual void remove(int, int);
};
extern "C" void fn_96_14A80(void*, int);
extern "C" void fn_96_15108(soModuleAccesser*, int);
extern "C" void fn_96_149A0(void*, soModuleAccesser* accesser, int param) {
    soWorkManageModule& work = accesser->getWorkManageModule();
    int handle = work.getInt(0x20000004);
    if (handle != 0) {
        accesser->getEffectModule().kill(handle, true, true);
        work.setInt(0, 0x20000004);
    }
    if (param != 0x12c) {
        ((ArticleModule*)accesser->m_enumerationStart->m_generateArticleManageModule)->remove(3, 0);
        fn_96_14A80(accesser, 0);
    }
    fn_96_15108(accesser, param);
}