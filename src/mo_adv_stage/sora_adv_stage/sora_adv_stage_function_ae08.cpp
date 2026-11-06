#pragma force_active on
#include <st/stage.h>
#include <st/st_data_container.h>
#include <gr/collision/gr_collision.h>
#include <gr/collision/gr_collision_data.h>
#include <sr/sr_common.h>

struct Entry {
    char pad[0x3c];
    unsigned char kind;
    unsigned char kind2;
};

namespace Matching {
struct grYakumono_base { char pad[0x3c]; };
class grYakumono : public grYakumono_base {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void slot26();
    virtual void slot27();
    virtual void slot28();
    virtual void slot29();
    virtual void slot30();
    virtual void slot31();
    virtual void slot32();
    virtual void slot33();
    virtual void slot34();
    virtual void slot35();
    virtual void slot36();
    virtual void slot37(gfArchive*, u32, u32);
    virtual void slot38();
    virtual void slot39();
    virtual void slot40();
    virtual void slot41();
    virtual void slot42();
    virtual void slot43();
    virtual void slot44();
    virtual void slot45();
    virtual void slot46();
    virtual void slot47();
    virtual void slot48();
    virtual void slot49();
    virtual void slot50();
    virtual void slot51();
    virtual void slot52();
    virtual void slot53();
    virtual void setNodeVisibilityAll();
    virtual void isNodeVisible();
    virtual void setNodeCollision();
    virtual void setNodeCollision_2();
    virtual void getNodeScale();
    virtual void getNodeScale_2();
    virtual void slot60();
    virtual void slot61();
    virtual void slot62();
    virtual void slot63();
    virtual void slot64();
    virtual void setMotionRatio();
    virtual void setMotionFrame();
    virtual void getMotionFrame();
    virtual void setMotionLoop();
    virtual void setMatAlphaMul();
    virtual void setMatAlpha();
    virtual void updateG3dProcCalcWorld();
    virtual void slot72();
    virtual void slot73();
    virtual void slot74();
    virtual void setTransparencyFlag();
    virtual void updateCallback();
    virtual void fixedPosition();
    virtual void setTgtNode();
    virtual void getTgtNode();
    virtual void setGimmickData(void*);
};
}

struct AdventureStage : Stage {
    gfArchive* resource;
};

extern "C" {
extern char lbl_40_data_1C8[];
Matching::grYakumono* fn_40_334A8(short, const char*);

void fn_40_AE08(AdventureStage* stage, u32 type, stDataMultiContainer* multi) {
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
            ground = fn_40_334A8((short)entry->kind, lbl_40_data_1C8);
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