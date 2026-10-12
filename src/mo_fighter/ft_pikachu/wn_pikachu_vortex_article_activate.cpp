#include <wn/weapon.h>
#include <so/so_module_accesser.h>

struct PikachuArticlePosition {
    float x, y, z;
};

extern "C" {
extern const char lbl_98_data_6D5C[], lbl_98_data_2F88[];
void* __dynamic_cast(void*, int, const void*, const void*, short);
void* fn_98_17D34(void*);
void fn_98_17D58(PikachuArticlePosition*, void*);
void fn_98_13B80(Weapon*, unsigned int, int, int,
                 const PikachuArticlePosition*, void*, unsigned int);
void fn_98_17D10(void*, Weapon*);
void fn_98_14950(void*, Weapon*);
void fn_98_141E8(void*, int, int);

bool fn_98_17B44(Weapon* article, soModuleAccesser* accesser) {
    soWorkManageModule* work = &accesser->getWorkManageModule();
    StageObject* owner = static_cast<StageObject*>(__dynamic_cast(
        accesser->m_stageObject, 0x3c, lbl_98_data_6D5C, lbl_98_data_2F88, short(1)));
    void* storage = fn_98_17D34(owner);
    unsigned int firstArticle = storage ? 0 : 1;
    PikachuArticlePosition position;
    fn_98_17D58(&position, owner);
    int valueC = work->getInt(0x1000000c);
    int valueE = work->getInt(0x1000000e);
    work->decInt(0x10000007);
    fn_98_13B80(article, owner->m_taskId, valueE, valueC, &position, owner, firstArticle);
    if (storage == 0) {
        fn_98_17D10(owner, article);
    } else {
        fn_98_14950(storage, article);
    }
    if (work->isFlag(0x12000005)) {
        int valueC = work->getInt(0x1000000c);
        int valueD = work->getInt(0x1000000d);
        fn_98_141E8(article, valueC, valueD);
    }
    return false;
}
}
