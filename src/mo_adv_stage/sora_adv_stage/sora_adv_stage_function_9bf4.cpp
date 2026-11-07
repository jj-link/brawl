#pragma force_active on
#include <st/stage.h>
#include <st/st_data_container.h>
#include <gr/collision/gr_collision.h>
#include <gr/collision/gr_collision_data.h>
#include <sr/sr_common.h>

struct Entry {
    char pad[0x1c];
    unsigned char kind;
    unsigned char kind2;
};

namespace Matching {
struct grYakumono_base { char pad[0x3c]; };
class grYakumono : public grYakumono_base {
public:
#define V(n) virtual void n();
    V(slot0) V(slot1) V(slot2) V(slot3) V(slot4) V(slot5) V(slot6) V(slot7) V(slot8) V(slot9)
    V(slot10) V(slot11) V(slot12) V(slot13) V(slot14) V(slot15) V(slot16) V(slot17) V(slot18) V(slot19)
    V(slot20) V(slot21) V(slot22) V(slot23) V(slot24) V(slot25) V(slot26) V(slot27) V(slot28) V(slot29)
    V(slot30) V(slot31) V(slot32) V(slot33) V(slot34) V(slot35) V(slot36)
    virtual void slot37(gfArchive*, u32, u32);
    V(slot38) V(slot39) V(slot40) V(slot41) V(slot42) V(slot43) V(slot44) V(slot45) V(slot46) V(slot47)
    V(slot48) V(slot49) V(slot50) V(slot51) V(slot52) V(slot53) V(slot54) V(slot55) V(slot56) V(slot57)
    V(slot58) V(slot59) V(slot60) V(slot61) V(slot62) V(slot63) V(slot64) V(slot65) V(slot66) V(slot67)
    V(slot68) V(slot69) V(slot70) V(slot71) V(slot72) V(slot73) V(slot74) V(slot75) V(slot76) V(slot77)
    V(slot78) V(slot79)
    virtual void setGimmickData(void*);
#undef V
};
}

struct AdventureStage : Stage {
    gfArchive* resource;
};

extern "C" {
extern char lbl_40_data_3D0[];
Matching::grYakumono* fn_40_371BC(short, const char*);

void fn_40_9BF4(AdventureStage* stage, u32 type, stDataMultiContainer* multi) {
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
            ground = fn_40_371BC((short)entry->kind, lbl_40_data_3D0);
            if (ground) {
                stage->addGround((Ground*)ground);
                ground->setGimmickData(entry);
                ground->slot37(stage->resource, 0, 0);
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