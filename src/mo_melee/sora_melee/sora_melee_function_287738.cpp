#pragma force_active on
#include <ft/ft_manager.h>
#include <so/so_external_value_accesser.h>

extern "C" int fn_27_10B21C(ftManager*, int*);

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual Object_vptr_0* slot2();
};

class Collision {
public:
    char padding[8];
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
    virtual void slot37();
    virtual bool slot38(void*, StageObject*);
};

extern "C" int fn_27_287738(void* self, StageObject** output, unsigned int flags) {
    ftManager* manager = g_ftManager;
    int team = -1;
    if (flags & 1) {
        Object_vptr_0* obj = (Object_vptr_0*)((char*)self + 0xf60);
        team = (int)obj->slot2()->slot2();
    }
    int entries[12];
    int n = fn_27_10B21C(manager, entries);
    int count = 0;
    for (int i = 0; i < n; ++i) {
        int id = entries[i];
        Fighter* fighters[2];
        fighters[0] = manager->getFighter(id, -1);
        fighters[1] = manager->getSubFighter(id);
        if (team != -1) {
            int otherTeam = manager->getTeam(id, true, true);
            if (otherTeam == team) continue;
        }
        {
            for (unsigned int k = 0; k < 2; ++k) {
                StageObject* fighter = fighters[k];
                if (fighter && soExternalValueAccesser::getSituationKind(fighter) != 5) {
                    Collision* collision = *(Collision**)((char*)self + 0x8d0);
                    if (collision->slot38(self, fighter)) {
                        *output++ = fighter;
                        ++count;
                    }
                }
            }
        }
    }
    return count;
}
