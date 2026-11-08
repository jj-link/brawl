#pragma force_active on
#include <st/stage.h>
#include <st/st_data_container.h>
#include <gr/collision/gr_collision.h>
#include <gr/collision/gr_collision_data.h>
#include <sr/sr_common.h>

struct Entry {
    char pad[0x18];
    unsigned char kind;
    unsigned char kind2;
};

namespace Matching {
struct grYakumono_base { char pad[0x3c]; };
class grYakumono : public grYakumono_base {
public:
#define V(n) virtual void slot##n();
    V(2) V(3) V(4) V(5) V(6) V(7) V(8) V(9)
    V(10) V(11) V(12) V(13) V(14) V(15) V(16) V(17) V(18) V(19)
    V(20) V(21) V(22) V(23) V(24) V(25) V(26) V(27) V(28) V(29)
    V(30) V(31) V(32) V(33) V(34) V(35) V(36) V(37) V(38)
    virtual void slot39(gfArchive*, u32, u32);
    V(40) V(41) V(42) V(43) V(44) V(45) V(46) V(47) V(48) V(49)
    V(50) V(51) V(52) V(53) V(54) V(55) V(56) V(57) V(58) V(59)
    V(60) V(61) V(62) V(63) V(64) V(65) V(66) V(67) V(68) V(69)
    V(70) V(71) V(72) V(73) V(74) V(75) V(76) V(77) V(78) V(79)
    V(80) V(81)
    virtual void setGimmickData(void*);
#undef V
};
}

struct AdventureStage : Stage {
    char pad[0x1a0 - sizeof(Stage)];
    gfArchive* resource;
};

extern "C" {
extern char lbl_40_data_2EC[];
Matching::grYakumono* fn_40_2DE24(short, const char*);

void fn_40_A9F4(AdventureStage* stage, u32 type, stDataMultiContainer* multi) {
    grCollData* collData;
    unsigned char kind2;
    Entry* entry;
    Matching::grYakumono* ground;
    stDataContainer* container;
    u32 index = 0;
    u32 i;

    while ((container = multi->searchContainer(type, index++)) != 0) {
        for (i = 0; i < container->m_filedata->m_numFiles; ++i) {
            entry = (Entry*)container->getData(i);
            ground = fn_40_2DE24((short)entry->kind, lbl_40_data_2EC);
            if (ground) {
                stage->addGround((Ground*)ground);
                ground->setGimmickData(entry);
                ground->slot39(stage->resource, 0, 0);
                kind2 = entry->kind2;
                if (kind2 != 0xFF) {
                    collData = (grCollData*)::operator new(0x28, Heaps::StageInstance);
                    if (collData) {
                        stage->testCollDataInit(stage->resource, collData, kind2);
                        stage->setCollision(grCollision::create(stage, collData, (Ground*)ground, 1));
                    }
                    ::operator delete(collData);
                }
            }
        }
    }
}
}
