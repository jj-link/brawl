#include <st/stage.h>
#pragma force_active on
class BlueGround : public Ground {
public:
virtual void setStageData(void*);
virtual void slot76();
virtual void slot77();
virtual void slot78();
virtual void slot79();
virtual void slot80();
virtual void slot81();
virtual void slot82();
virtual void slot83();
virtual void slot84();
virtual void slot85();
virtual void slot86();
virtual void slot87();
virtual void slot88();
virtual void slot89();
virtual void slot90();
virtual void slot91();
virtual void slot92();
virtual void slot93();
virtual void slot94();
virtual void slot95();
virtual void slot96();
virtual void slot97();
virtual void slot98();
virtual void slot99();
virtual void slot100();
virtual void slot101();
virtual void slot102();
virtual void slot103();
virtual void slot104();
virtual void slot105();
virtual void slot106();
virtual void slot107();
virtual void slot108();
virtual void slot109();
virtual void slot110();
virtual void slot111();
virtual void slot112();
virtual void slot113();
virtual void slot114();
virtual void slot115();
virtual void slot116(void*);
virtual void slot117(void*);
virtual void slot118(void*);
virtual void slot119(void*);
virtual void slot120(int);
virtual void slot121(void*);
virtual void slot122(void*);
};
extern "C" {
extern char lbl_81_data_0[];
BlueGround* fn_81_4650(int, const char*, const char*);
BlueGround* fn_81_78F8(int, const char*, const char*);
void fn_81_ED8(Stage* self, unsigned int kind) {
    char* data = lbl_81_data_0;
    BlueGround* ground;
    int index;
    switch(kind) {
case 2: ground = fn_81_4650(31, data + 0x144, data + 0x158); index = 0; break;
case 3: ground = fn_81_4650(32, data + 0x16c, data + 0x180); index = 1; break;
case 4: ground = fn_81_4650(33, data + 0x194, data + 0x1a8); index = 2; break;
case 5: ground = fn_81_4650(34, data + 0x1bc, data + 0x1d0); index = 3; break;
case 6: ground = fn_81_78F8(35, data + 0x1e4, data + 0x1f8); index = 4; break;
case 7: ground = fn_81_4650(36, data + 0x20c, data + 0x220); index = 5; break;
case 8: ground = fn_81_4650(37, data + 0x234, data + 0x248); index = 6; break;
case 9: ground = fn_81_4650(38, data + 0x260, data + 0x278); index = 7; break;
case 10: ground = fn_81_4650(39, data + 0x290, data + 0x2a8); index = 8; break;
case 11: ground = fn_81_4650(40, data + 0x2c0, data + 0x2d8); index = 9; break;
case 12: ground = fn_81_4650(41, data + 0x2f0, data + 0x308); index = 10; break;
case 13: ground = fn_81_4650(42, data + 0x320, data + 0x334); index = 11; break;
default: ground = 0; break;
    }
    if (ground) {
        self->addGround(ground);
        ground->startup(*(gfArchive**)((char*)self + 0x1a0), 0, (gfSceneRoot::LayerType)0);
        ground->setStageData(self->m_stageData);
        ground->slot116((char*)self + 0x230);
        ground->slot117((char*)self + 0x1e0);
        ground->slot118((char*)self + 0x1fc);
        ground->slot119((char*)self + 0x208);
        ground->slot120(index);
        ground->slot121((char*)self + 0x35c);
        ground->slot122((char*)self + 0x350 + index);
    }
}
}