#include <ft/ft_common_data_accesser.h>
#include <so/so_module_accesser.h>
#pragma force_active on

extern "C" {
extern const char lbl_94_data_520[], lbl_94_data_5010[];
void* __dynamic_cast(void*, long, const void*, const void*, short);
void fn_27_12D904(void*, bool, bool, int);
}

class SamusMod8 {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27();
    virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31();
    virtual void v32(); virtual void v33();
    virtual void fn90();
};

class SamusArticleMgr {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5();
    virtual void setState(int, int, bool);
    virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10();
    virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
    virtual void v15();
    virtual void fn48(int, int);
    virtual void v17();
    virtual int check(int);
};

extern "C" void fn_94_1189C(void*, soModuleAccesser* accesser, int status) {
    int kind = accesser->m_enumerationStart->m_statusModule->getStatusKind();
    soWorkManageModule* work = accesser->m_enumerationStart->m_workManageModule;

    switch (kind) {
    case 0x116:
        break;
    case 0x127:
    case 0x128:
        if (status >= 0x129 || status < 0x127) {
            work->onFlag(0x22000010);
        }
        break;
    case 0x129:
    case 0x12A:
        if (status >= 0x12B || status < 0x129) {
            work->onFlag(0x22000010);
        }
        reinterpret_cast<SamusMod8*>(accesser->m_enumerationStart->m_motionModule)->fn90();
        work->setInt(-1, 0x10000046);
        break;
    case 0x12B:
    case 0x12C:
        if (status >= 0x12D || status < 0x12B) {
            work->onFlag(0x22000010);
        }
        break;
    }

    switch (status) {
    case 0x127:
    case 0x128:
    case 0x129:
    case 0x12A:
    case 0x12B:
    case 0x12C: {
        SamusArticleMgr* mgr = static_cast<SamusArticleMgr*>(accesser->m_enumerationStart->m_generateArticleManageModule);
        int id = work->getInt(0x10000045);
        if (mgr->check(id) != 0) {
            int code;
            switch (status) {
            case 0x127: code = 5; status = 0x128; break;
            case 0x128: code = 3; status = 0x127; break;
            case 0x129: code = 0; status = 0x12A; break;
            case 0x12A: code = 1; status = 0x129; break;
            case 0x12B: code = 4; status = 0x12C; break;
            case 0x12C: code = 2; status = 0x12B; break;
            }
            mgr->setState(id, code, kind == status);
        }
        break;
    }
    default: {
        void* obj = __dynamic_cast(accesser->m_stageObject, 0x3C, lbl_94_data_520, lbl_94_data_5010, 0);
        if (obj != 0) {
            fn_27_12D904(obj, true, true, 0);
        }
        if (status != 0xBD) {
            work->offFlag(0x1200003D);
        }
        char* ftd = reinterpret_cast<char*>(g_ftCommonDataAccesser.getData(static_cast<ftKind>(3)));
        SamusArticleMgr* mgr = static_cast<SamusArticleMgr*>(accesser->m_enumerationStart->m_generateArticleManageModule);
        mgr->fn48(*reinterpret_cast<int*>(ftd + 0xB0), 0);
        mgr = static_cast<SamusArticleMgr*>(accesser->m_enumerationStart->m_generateArticleManageModule);
        mgr->fn48(*reinterpret_cast<int*>(ftd + 0xB8), 0);
        mgr = static_cast<SamusArticleMgr*>(accesser->m_enumerationStart->m_generateArticleManageModule);
        mgr->fn48(*reinterpret_cast<int*>(ftd + 0xC0), 0);
        accesser->m_enumerationStart->m_visibilityModule->set(1, 0);
        break;
    }
    }
}
