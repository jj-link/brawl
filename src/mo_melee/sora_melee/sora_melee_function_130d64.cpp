#include <ft/ft_manager.h>
#include <ft/ft_audience_manager.h>
#pragma force_active on
extern "C" void fn_27_12D904(void*, bool, bool, int);
extern "C" void fn_27_C6308(void*, int, int, int, int);
extern "C" void setSUlcide__9ftManagerFi(ftManager*, int);
extern "C" unsigned char lbl_27_rodata_1E18[];
extern "C" int lbl_27_bss_2CBC;
class ControllerCall {
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
virtual void slot37();
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
virtual void slot57(int);
};
extern "C" void fn_27_130D64(Fighter* self) {
    soModuleAccesser* accesser = self->m_moduleAccesser;
    if ((lbl_27_rodata_1E18[self->getFtKind()] & 1) ||
        accesser->m_enumerationStart->m_workManageModule->isFlag(0x12000008) == 1) {
        fn_27_12D904(self, true, false, 0);
    }
    if (!self->getOwner()->isSubOwner()) {
        soDamageAttackerInfo info;
        accesser->m_enumerationStart->m_damageModule->getAttackerInfo(&info);
        if (!*((unsigned char*)g_ftManager + 0x6d) ||
            !self->m_moduleAccesser->m_enumerationStart->m_workManageModule->isFlag(0x12000018)) {
            if (info.m_indirectSoKind == 0 && g_ftManager->isValidEntryId(info.m_indirectEntryId) == 1) {
                g_ftAudienceManager->m_audience->checkCheerDefeat(info.m_indirectEntryId);
                g_ftManager->setBeat(self->m_entryId, info.m_indirectEntryId);
            } else {
                setSUlcide__9ftManagerFi(g_ftManager, self->m_entryId);
            }
            int entry;
            ftManager* manager;
            soWorkManageModule* work;
            work = accesser->m_enumerationStart->m_workManageModule;
            entry = self->m_entryId;
            manager = g_ftManager;
            manager->setDead(entry, work->getInt(0x10000028), work->getInt(0x1000002a));
        }
        soWorkManageModule* work = accesser->m_enumerationStart->m_workManageModule;
        int attacker = info.m_indirectEntryId;
        int entry = self->m_entryId;
        fn_27_C6308(&lbl_27_bss_2CBC, entry, attacker, work->getInt(0x10000028), work->getInt(0x10000029));
    }
    ((ControllerCall*)accesser->m_enumerationStart->m_controllerModule)->slot57(1);
}