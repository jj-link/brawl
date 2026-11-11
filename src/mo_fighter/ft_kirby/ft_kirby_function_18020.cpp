#include <types.h>
#include <so/so_module_accesser.h>
#include <so/so_value_accesser.h>
#include <mt/mt_prng.h>
#include <it/it_manager.h>
#pragma force_active on

struct KirbyArticleManageModule {
    virtual ~KirbyArticleManageModule();
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void clear(int, int, int);
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual bool has(int);
};

extern "C" {
void fn_27_89DAC(int, soModuleAccesser*);
void fn_96_1B7F4(void*, soModuleAccesser*);
void fn_96_1B8E8(void*, soModuleAccesser*);
void fn_96_1BA64(void*, soModuleAccesser*);
ItemKind fn_27_2AA57C(itManager*);
extern const float lbl_96_rodata_A8;
extern const double lbl_96_rodata_B0;
}

inline int chooseItemKind(itManager* manager) {
    ItemKind item = fn_27_2AA57C(manager);
    return item.m_kind;
}

extern "C" void fn_96_18020(void* process, soModuleAccesser* accesser) {
    switch (accesser->getStatusModule().getStatusKind()) {
    case 0x116:
        if (accesser->getSituationModule().getKind() == 0)
            fn_96_1B7F4(process, accesser);
        else
            fn_96_1B8E8(process, accesser);

        accesser->getWorkManageModule().onFlag(0x12000001);
        if (accesser->getWorkManageModule().isFlag(0x12000042) &&
            static_cast<KirbyArticleManageModule*>(
                accesser->m_enumerationStart->m_generateArticleManageModule)
                ->has(10) &&
            accesser->getWorkManageModule().getInt(0x10000048) != 0x23)
            static_cast<KirbyArticleManageModule*>(
                accesser->m_enumerationStart->m_generateArticleManageModule)
                ->clear(10, 0, 0);

        accesser->getWorkManageModule().offFlag(0x2200001D);
        accesser->getWorkManageModule().offFlag(0x2200001E);
        break;

    case 0x12E:
        fn_96_1BA64(process, accesser);
        fn_27_89DAC(3, accesser);
        fn_27_89DAC(1, accesser);
        accesser->getWorkManageModule().setInt(
            soValueAccesser::getConstantInt(accesser, 0x5DD4, 0),
            0x2000000D);
        break;

    case 0x12F:
        fn_96_1BA64(process, accesser);
        accesser->getWorkManageModule().setFloat(lbl_96_rodata_A8, 0x21000005);
        fn_27_89DAC(3, accesser);
        fn_27_89DAC(1, accesser);
        break;

    case 0x130:
        fn_96_1BA64(process, accesser);
        break;

    case 0x131: {
        accesser->getWorkManageModule().setInt(0, 0x2000001A);
        accesser->getWorkManageModule().setInt(1, 0x2000001B);
        accesser->getWorkManageModule().setInt(2, 0x2000001C);
        accesser->getWorkManageModule().setInt(3, 0x2000001D);
        accesser->getWorkManageModule().setInt(4, 0x2000001E);
        accesser->getWorkManageModule().setInt(5, 0x2000001F);

        fn_96_1BA64(process, accesser);
        accesser->getWorkManageModule().setFloat(lbl_96_rodata_A8, 0x21000005);
        accesser->getWorkManageModule().setInt(0, 0x2000000D);

        int count = accesser->getWorkManageModule().getInt(0x2000000A);
        float countFloat = (float)count;
        float factor = soValueAccesser::getConstantFloat(
            accesser, 0xFBC, 0);
        int frames = (int)(factor * countFloat);
        accesser->getWorkManageModule().setInt(frames, 0x20000018);

        int size = accesser->getWorkManageModule().getInt(0x20000006);
        if (size >= 2) {
            int random, old, i;
            for (i = 0; i < size; ++i) {
                random = randi(size);
                old = accesser->getWorkManageModule().getInt(i + 0x2000001A);
                accesser->getWorkManageModule().setInt(
                    random, i + 0x2000001A);

                if (random != old) {
                    for (int j = 0; j < size; ++j) {
                        if (random == accesser->getWorkManageModule().getInt(
                                          j + 0x2000001A)) {
                            accesser->getWorkManageModule().setInt(
                                old, j + 0x2000001A);
                            break;
                        }
                    }
                }
            }
        }

        accesser->getWorkManageModule().setInt(
            frames + size, 0x2000000F);

        if (randi(
                soValueAccesser::getConstantInt(
                    accesser, 0x5DCE, 0)) == 1) {
            accesser->getWorkManageModule().onFlag(0x22000017);
            int kind = chooseItemKind(itManager::getInstance());
            accesser->getWorkManageModule().setInt(kind, 0x20000013);
        }

        accesser->getWorkManageModule().setFloat(
            accesser->getMotionModule().getEndFrame(0x201), 0x21000008);

        Vec3f position =
            accesser->getLinkModule().getParentModelNodeGlobalPosition(
                6, (u32)0, false);
        accesser->getWorkManageModule().setFloat(
            position.m_x, 0x21000006);
        accesser->getWorkManageModule().setFloat(
            position.m_y, 0x21000007);
        accesser->getWorkManageModule().onFlag(0x22000022);
        accesser->getWorkManageModule().onFlag(0x22000023);
        break;
    }

    case 0x132:
        break;
    }

    fn_27_89DAC(2, accesser);
    fn_27_89DAC(4, accesser);
    fn_27_89DAC(0, accesser);
}
