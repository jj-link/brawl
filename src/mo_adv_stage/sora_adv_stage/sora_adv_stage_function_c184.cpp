#include <st/stage.h>
#include <st/st_data_container.h>

#include <gm/gm_global.h>
#pragma force_active on

struct Entry;
struct GBase { char pad[0x3c]; };
class MyGround : public GBase {
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
virtual void startup(gfArchive*, unsigned long, gfSceneRoot::LayerType);
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
virtual void slot54();
virtual void slot55();
virtual void slot56();
virtual void slot57();
virtual void slot58();
virtual void slot59();
virtual void slot60();
virtual void slot61();
virtual void slot62();
virtual void slot63();
virtual void slot64();
virtual void slot65();
virtual void slot66();
virtual void slot67();
virtual void slot68();
virtual void slot69();
virtual void slot70();
virtual void slot71();
virtual void slot72();
virtual void slot73();
virtual void slot74();
virtual void slot75();
virtual void slot76();
virtual void slot77();
virtual void slot78();
virtual void slot79();
virtual void setGimmickData(void*);
};
struct Entry {
    char pad[0x44];
    unsigned char kind;
    char pad1[0x1ec - 0x45];
    float f1ec;
    char pad2[0x240 - 0x1f0];
    int i240;
};
struct StageExtra {
    char pad[0x1a0];
    gfArchive* archive;
    char pad1[0x1c0 - 0x1a4];
    unsigned char* params;
};
extern "C" {
extern char lbl_40_data_1E8[];
MyGround* fn_40_27748(short, const char*);
void fn_40_C184(Stage* stage, unsigned long type, stDataMultiContainer* multi) {
    MyGround* ground;
    stDataContainer* container;
    unsigned long index = 0;
    while ((container = multi->searchContainer(type, index++)) != 0) {
        for (unsigned long i = 0; i < container->m_filedata->m_numFiles; i++) {
            Entry* entry = (Entry*)container->getData(i);
            ground = fn_40_27748((short)entry->kind, lbl_40_data_1E8);
            unsigned char* params = ((StageExtra*)stage)->params;
            if (params) {
                unsigned char* adv = (unsigned char*)g_GameGlobal->m_advData;
                unsigned char level = adv[0x5fd];
                int v = level - adv[0x4916];
                int min = level - 5;
                if (v < min) v = min;
                if (v < 0) v = 0;
                if (v > 14) v = 14;
                entry->i240 = (int)(entry->f1ec * (float)params[0x80 + (unsigned char)v]);
            } else {
                entry->i240 = (int)entry->f1ec;
            }
            if (ground) {
                stage->addGround((Ground*)ground);
                ground->setGimmickData(entry);
                ground->startup(((StageExtra*)stage)->archive, 0, (gfSceneRoot::LayerType)0);
            }
        }
    }
}
}
