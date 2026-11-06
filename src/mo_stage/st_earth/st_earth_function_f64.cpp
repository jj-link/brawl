#include <st/stage.h>
#include <gr/gr_yakumono.h>
#pragma force_active on

class EarthGround : public grYakumono {
public:
    virtual void setStageData(void*);
    virtual void slot112();
    virtual void slot113();
    virtual void slot114(void*);
    virtual void slot115(void*);
};

extern "C" {
extern char lbl_66_data_0[];
EarthGround* fn_66_13640(int, const char*, const char*);

void fn_66_F64(Stage* self, int kind) {
    char* data = lbl_66_data_0;
    EarthGround* ground;
    void* info;
    switch (kind) {
    case 10:
        ground = fn_66_13640(0x14, data + 0x158, data + 0x168);
        info = 0;
        break;
    case 11:
        ground = fn_66_13640(0x15, data + 0x17c, data + 0x188);
        info = (char*)self + 0x1fc;
        break;
    case 12:
        ground = fn_66_13640(0x16, data + 0x1a0, data + 0x1ac);
        info = (char*)self + 0x214;
        break;
    case 13:
        ground = fn_66_13640(0x17, data + 0x1c4, data + 0x1d0);
        info = (char*)self + 0x208;
        break;
    default:
        ground = 0;
        break;
    }
    if (ground) {
        self->addGround(ground);
        ground->startup(*(gfArchive**)((char*)self + 0x1a0), 0, (gfSceneRoot::LayerType)0);
        ground->setStageData(*(void**)((char*)self + 0x9c));
        ground->slot114((char*)self + 0x230);
        ground->slot115(info);
    }
}
}