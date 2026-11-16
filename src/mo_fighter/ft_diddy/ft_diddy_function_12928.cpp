#include <so/so_module_accesser.h>
#include <mt/mt_vector.h>
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
    virtual int spawn(int, int, Vec3f*, Vec3f*, float, int, int, int, int);
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void remove(int);
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual bool isExist(int);
};

extern "C" {
float fn_115_E59C(float value);
Vec3f* fn_115_8EF8(Vec3f*, float, float, float);
extern const float lbl_115_rodata_C0;
}

extern "C" void fn_115_12928(void*, soModuleAccesser* accesser) {
    const float* c = &lbl_115_rodata_C0;
    float stickX = accesser->getControllerModule().getStickX();
    if (accesser->getControllerModule().getStickY() > c[2] ||
        fn_115_E59C(stickX) > c[8]) {
        DiddyArticleModule* articles;
        if (accesser->getWorkManageModule().isFlag(0x2200001A)) {
            articles = reinterpret_cast<DiddyArticleModule*>(accesser->getWorkManageModule().getInt(0x20000001));
            if (reinterpret_cast<DiddyArticleModule*>(accesser->m_enumerationStart->m_effectModule)
                    ->isExist(reinterpret_cast<int>(articles))) {
                reinterpret_cast<DiddyArticleModule*>(accesser->m_enumerationStart->m_effectModule)
                    ->remove(reinterpret_cast<int>(articles));
            }
            accesser->getWorkManageModule().offFlag(0x2200001A);
        }
        if (!accesser->getWorkManageModule().isFlag(0x2200001B)) {
            Vec3f velocity;
            Vec3f offset;
            articles =
                reinterpret_cast<DiddyArticleModule*>(accesser->m_enumerationStart->m_effectModule);
            int id = articles->spawn(0xF90002, 0x12, fn_115_8EF8(&velocity, c[2], c[2], c[2]),
                                     fn_115_8EF8(&offset, c[2], c[2], c[2]), c[1], 0, 6, 0, -1);
            accesser->getWorkManageModule().setInt(id, 0x20000002);
            accesser->getWorkManageModule().onFlag(0x2200001B);
        }
    } else {
        if (accesser->getWorkManageModule().isFlag(0x2200001B)) {
            int value = accesser->getWorkManageModule().getInt(0x20000002);
            if (reinterpret_cast<DiddyArticleModule*>(accesser->m_enumerationStart->m_effectModule)
                    ->isExist(value)) {
                reinterpret_cast<DiddyArticleModule*>(accesser->m_enumerationStart->m_effectModule)
                    ->remove(value);
            }
            accesser->getWorkManageModule().offFlag(0x2200001B);
        }
        if (!accesser->getWorkManageModule().isFlag(0x2200001A)) {
            DiddyArticleModule* articles =
                reinterpret_cast<DiddyArticleModule*>(accesser->m_enumerationStart->m_effectModule);
            Vec3f velocity;
            Vec3f offset;
            int id = articles->spawn(0xF90001, 0x12, fn_115_8EF8(&velocity, c[2], c[2], c[2]),
                                     fn_115_8EF8(&offset, c[2], c[2], c[2]), c[1], 0, 6, 0, -1);
            accesser->getWorkManageModule().setInt(id, 0x20000001);
            accesser->getWorkManageModule().onFlag(0x2200001A);
        }
    }
}
