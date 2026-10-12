#include <so/so_module_accesser.h>
#include <it/it_manager.h>
#include <it/item.h>

// The shared accesser exposes this private article-manager interface as void*.
class DededeItemReleaseArticles {
public:
    virtual void slot08();
    virtual void slot0C();
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual void shoot(int kind, int target, bool immediate);
    virtual void slot20();
    virtual void slot24();
    virtual void slot28();
    virtual void slot2C();
    virtual void slot30();
    virtual void slot34();
    virtual void slot38();
    virtual void slot3C();
    virtual void slot40();
    virtual void slot44();
    virtual void remove(int kind, int target);
    virtual void slot4C();
    virtual bool isExist(int kind);
};

extern "C" {
extern const float lbl_117_rodata_60;
Vec3f* fn_117_92AC(Vec3f*, float, float, float);
void fn_27_28E48C(BaseItem*, Vec3f*, float);
}

extern "C" void fn_117_10B18(void*, soModuleAccesser* accesser) {
    if (accesser->getWorkManageModule().getInt(0x20000000) == 3) {
        if (accesser->getWorkManageModule().isFlag(0x22000017)) {
            int instanceId = accesser->getWorkManageModule().getInt(0x20000001);
            BaseItem* item = itManager::getInstance()->getItemFromInstanceId(instanceId);
            Vec3f velocity;
            fn_117_92AC(&velocity, lbl_117_rodata_60, lbl_117_rodata_60, lbl_117_rodata_60);
            if (item)
                fn_27_28E48C(item, &velocity, accesser->getPostureModule().getLr());
        }
    } else if (accesser->getWorkManageModule().isFlag(0x22000017)) {
        if (accesser->getWorkManageModule().isFlag(0x22000012)) {
            if (static_cast<DededeItemReleaseArticles*>(accesser->m_enumerationStart->m_generateArticleManageModule)->isExist(4)) {
                accesser->getWorkManageModule().onFlag(0x22000016);
                static_cast<DededeItemReleaseArticles*>(accesser->m_enumerationStart->m_generateArticleManageModule)->shoot(4, 2, false);
            }
        } else {
            static_cast<DededeItemReleaseArticles*>(accesser->m_enumerationStart->m_generateArticleManageModule)->remove(4, 2);
        }
        accesser->getWorkManageModule().offFlag(0x22000017);
        accesser->getWorkManageModule().offFlag(0x22000013);
    }
}
