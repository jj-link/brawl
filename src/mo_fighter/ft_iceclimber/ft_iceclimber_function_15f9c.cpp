#pragma force_active on
#include <mt/mt_vector.h>

class WorkModule {
public:
    virtual void slot0() = 0;
    virtual void slot1() = 0;
    virtual void slot2() = 0;
    virtual void slot3() = 0;
    virtual int get(int) = 0;
};

struct ModuleTable {
    void* unused0[3];
    void* posture;
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
extern "C" void fn_27_173BCC(void*, void*, Vec3f*);

extern "C" void fn_105_15F9C(void* arg0, FighterLike* arg1, Vec3f* arg2) {
    Vec3f pos = *arg2;
    void* manager = g_ftManager;
    int entryId = arg1->modules->work->get(0x10000000);
    if (getSubFighter__9ftManagerFi(manager, entryId) != 0) {
        pos.m_x -= lbl_105_rodata_80;
    }
    fn_27_173BCC(arg0, arg1, &pos);
}