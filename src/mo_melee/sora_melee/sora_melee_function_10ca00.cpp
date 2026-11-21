// Matches the original except for three lines: the team-block flag is in r21 here, r22 in the original.
#include <ft/ft_manager.h>
#include <so/so_external_value_accesser.h>
#pragma force_active on

struct Class_90D8_base {
    char pad[8];
};

class Class_90D8 : public Class_90D8_base {
public:
    virtual void fn_27_7B274();
    virtual ftEntry** fn_27_7AC18(int);
    virtual void fn_27_7AC28();
    virtual void fn_27_7AB50();
};

struct TaskBase {
    char pad[0x3c];
};

class Task : public TaskBase {
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
    virtual void processCamera();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void renderOpa();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void init();
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
    virtual void slot38();
    virtual void fn_27_248088();
    virtual void slot40();
    virtual bool slot41();
};

extern "C" {
extern float lbl_27_rodata_F08;
extern float lbl_27_rodata_F14;

int fn_27_1190D0(ftEntryManager*, unsigned long);
int fn_27_116F60(ftEntry*, unsigned int, unsigned int);
void* fn_27_115E3C(ftEntry*, Vec3f*, int, float*, float);
}

inline int entryTeam(ftManager* self, ftEntry* entry) {
    int flag = 0;
    int entryId = entry->m_entryId;
    if ((((unsigned int)*((unsigned char*)self + 0x6e) >> 7) & 1) == 1 &&
        (((unsigned int)*((unsigned char*)self + 0x6e) >> 6) & 1) == 1)
        flag = 1;
    return fn_27_116F60(self->m_entryManager->getEntity(entryId), flag, 1);
}

Fighter* ftManager::searchNearFighter(
    float direction, float range, Vec3f* pos, int team, bool partner)
{
    float limit;
    float best = lbl_27_rodata_F08;
    ftEntry* entry;
    void* result = 0;

    for (int count = ((soArrayFixed<ftEntry*>*)((char*)m_entryManager + 8))->size(),
             i = (limit = lbl_27_rodata_F14, 0);
         count > i; i++) {
        entry = ((soArrayFixed<ftEntry*>*)((char*)m_entryManager + 8))->at(i);
        bool usePartner = partner;
        StageObject* fighter = (StageObject*)entry->m_entryId;

        if (!fn_27_1190D0(m_entryManager, (unsigned long)fighter)) {
            fighter = 0;
        } else {
            ftEntry* e = m_entryManager->getEntity((unsigned long)fighter);
            fighter = (StageObject*)
                e->m_instances[(unsigned char)e->m_activeInstanceIndex].m_fighter;
        }

        bool valid = fighter && ((Task*)fighter)->slot41() &&
            soExternalValueAccesser::getSituationKind(fighter) != 5;

        if (valid) {
            if (partner == 1) {
                unsigned long partnerId = entry->m_entryId;
                fighter = !fn_27_1190D0(m_entryManager, partnerId)
                    ? 0
                    : m_entryManager->getEntity(partnerId)->m_characterKind == 0x10
                        ? (StageObject*)m_entryManager->getEntity(partnerId)
                              ->m_instances[1].m_fighter
                        : 0;

                bool partnerValid = fighter && ((Task*)fighter)->slot41() &&
                    soExternalValueAccesser::getSituationKind(fighter) != 5;
                if (!partnerValid) {
                    usePartner = false;
                }
            }

            if (team != -1) {
                if (team == entryTeam(this, entry)) {
                    continue;
                }
            }

            float dist;
            void* found =
                fn_27_115E3C(entry, pos, usePartner, &dist, direction);
            if (found && (limit == range || !(dist > range * range)) &&
                dist < best) {
                best = dist;
                result = found;
            }
        }
    }
    return (Fighter*)result;
}
