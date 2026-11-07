#include <st/st_melee.h>
#pragma force_active on

class FamicomGround : public grYakumono {
public:
    virtual void setStageData(void*);
    virtual void disableCalcCollision();
    virtual void slot112();
    virtual void slot113();
    virtual void slot114();
    virtual void slot115();
    virtual void slot116();
    virtual void slot117(void*);
    virtual void slot118(void*);
    virtual void slot119(void*);
    virtual void slot120();
    virtual void slot121();
    virtual void slot122();
    virtual void slot123(int);
    virtual void slot124(int);
};

extern "C" {
extern char lbl_68_data_40[];
extern char lbl_68_data_54[];
FamicomGround* fn_68_24D0(int, const char*, const char*);

void fn_68_9C4(stMelee* stage, int kind) {
    FamicomGround* ground;
    stCollisionWork* work;
    switch (kind) {
    case 1:
        ground = fn_68_24D0(1, lbl_68_data_40, lbl_68_data_54);
        work = (stCollisionWork*)((char*)stage + 0x218);
        break;
    default:
        ground = 0;
        break;
    }
    if (ground) {
        stage->addGround(ground);
        ground->slot124(0x15);
        ground->startup(*(gfArchive**)((char*)stage + 0x1a0), 0, (gfSceneRoot::LayerType)0);
        ground->setStageData(*(void**)((char*)stage + 0x9c));
        ground->slot117((char*)stage + 0x298);
        ground->slot118(*(void**)((char*)stage + 0x428));
        ground->slot119((char*)stage + 0x2ec);
        ground->slot123(0);
        stage->createCollisionSelf(work, ground, lbl_68_data_40, lbl_68_data_40, 0x41a);
        ground->disableCalcCollision();
    }
}
}