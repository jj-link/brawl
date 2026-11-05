#include <ft/ft_common_data_accesser.h>
#include <so/so_module_accesser.h>
#pragma force_active on

extern "C" {
extern const char lbl_94_data_520[], lbl_94_data_5010[];
extern const char lbl_94_data_98E4[], lbl_94_data_4570[];
extern const float lbl_94_rodata_48;
void* __dynamic_cast(void*, long, const void*, const void*, short);
void fn_27_12D7F0();
}

class SamusKineticEnergyController {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void update(int, Vec2f*, Vec3f*, soModuleAccesser*);
};

class SamusArticle {
public:
    virtual int v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual int v6();
};

class SamusArticleManager {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual SamusArticle* getArticle(int, bool, bool);
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void remove(SamusArticle*);
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual bool isExist(int);
};

extern "C" void fn_94_11170(void*, soModuleAccesser* accesser) {
    int kind = accesser->m_enumerationStart->m_statusModule->getStatusKind();
    soWorkManageModule* work = accesser->m_enumerationStart->m_workManageModule;
    char* ftd = reinterpret_cast<char*>(g_ftCommonDataAccesser.getData(static_cast<ftKind>(3)));
    char* r31 = *reinterpret_cast<char**>(ftd + 0x8C);
    float* params = reinterpret_cast<float*>(r31);

    switch (kind) {
    case 0x127:
    case 0x128:
        if (!work->isFlag(0x1200003D)) {
            if (__dynamic_cast(accesser->m_stageObject, 0x3C, lbl_94_data_520, lbl_94_data_5010, 0) != 0) {
                fn_27_12D7F0();
            }
            work->onFlag(0x1200003D);
            accesser->m_enumerationStart->m_situationModule->getKind();
            work->onFlag(0x22000010);
            work->setInt(*reinterpret_cast<int*>(r31 + 0x18), 0x10000044);
            work->setFloat(lbl_94_rodata_48, 0x11000014);
            work->setInt(-1, 0x10000046);
            work->setInt(-1, 0x10000045);
            SamusArticleManager* articles = static_cast<SamusArticleManager*>(accesser->m_enumerationStart->m_generateArticleManageModule);
            if (articles->isExist(5)) {
                SamusArticle* article = articles->getArticle(5, false, false);
                if (article->v0() == 0) {
                    articles->remove(article);
                    work->setInt(article->v6(), 0x10000045);
                }
            }
        }
        break;
    }

    switch (kind) {
    case 0x127:
    case 0x129:
    case 0x12B:
        accesser->m_enumerationStart->m_kineticModule->clearSpeedAll();
        break;
    case 0x128:
    case 0x12A:
    case 0x12C: {
        soKineticEnergy* energy = accesser->m_enumerationStart->m_kineticModule->getEnergy(1);
        SamusKineticEnergyController* ctl =
            static_cast<SamusKineticEnergyController*>(__dynamic_cast(energy, 0, lbl_94_data_98E4, lbl_94_data_4570, 1));
        bool useFlag = false;
        if (kind == 0x128 && work->isFlag(0x22000010)) {
            useFlag = true;
        }
        float f31;
        if (useFlag) {
            f31 = params[0];
        } else {
            f31 = lbl_94_rodata_48;
        }
        accesser->m_enumerationStart->m_kineticModule->clearSpeedAll();
        accesser->m_enumerationStart->m_kineticModule->unableEnergyAll();
        Vec3f b(lbl_94_rodata_48, lbl_94_rodata_48, lbl_94_rodata_48);
        Vec2f a(lbl_94_rodata_48, f31);
        ctl->update(0, &a, &b, accesser);
        *reinterpret_cast<float*>(reinterpret_cast<char*>(ctl) + 0x10) = -params[1];
        *reinterpret_cast<float*>(reinterpret_cast<char*>(ctl) + 0x14) = params[2];
        *reinterpret_cast<float*>(reinterpret_cast<char*>(ctl) + 0x1C) = params[2];
        unsigned char* flags = reinterpret_cast<unsigned char*>(ctl) + 5;
        *flags = *flags | 0x80;
        break;
    }
    }

    accesser->m_enumerationStart->m_visibilityModule->set(1, 2);
}
