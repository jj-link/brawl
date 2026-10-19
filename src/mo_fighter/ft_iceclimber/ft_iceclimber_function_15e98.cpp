#include <mt/mt_vector.h>
#pragma force_active on

class WorkModule {
public:
    virtual void slot0() = 0;
    virtual void slot1() = 0;
    virtual void slot2() = 0;
    virtual void slot3() = 0;
    virtual int get(int) = 0;
    virtual void slot5() = 0;
    virtual void slot6() = 0;
    virtual void slot7() = 0;
    virtual void slot8() = 0;
    virtual void slot9() = 0;
    virtual void slot10() = 0;
    virtual void slot11() = 0;
    virtual void slot12() = 0;
    virtual void slot13() = 0;
    virtual void slot14() = 0;
    virtual void slot15() = 0;
    virtual void slot16() = 0;
    virtual bool flag(int) = 0;
};

class PostureModule {
public:
    virtual void slot0() = 0;
    virtual void slot1() = 0;
    virtual void slot2() = 0;
    virtual void slot3() = 0;
    virtual Vec3f getRough() = 0;
    virtual void setRough(Vec3f*) = 0;
};

struct ModuleTable {
    void* unused0[3];
    PostureModule* posture;
    void* unused10[21];
    WorkModule* work;
};

struct FighterLike {
    char unused[0xD8];
    ModuleTable* modules;
};

extern "C" void* g_ftManager;
extern "C" void* getSubFighter__9ftManagerFi(void*, int);
extern "C" float lbl_105_rodata_80;
extern "C" void fn_27_1733F8(void*, void*);

extern "C" void fn_105_15E98(void* arg1, FighterLike* arg2) {
    void* manager = g_ftManager;
    int entryId = arg2->modules->work->get(0x10000000);
    if (getSubFighter__9ftManagerFi(manager, entryId) != 0) {
        Vec3f pos = arg2->modules->posture->getRough();
        if (!arg2->modules->work->flag(0x1200003E)) {
            pos.m_x += lbl_105_rodata_80;
        } else {
            pos.m_x -= lbl_105_rodata_80;
        }
        arg2->modules->posture->setRough(&pos);
    }
    fn_27_1733F8(arg1, arg2);
}
