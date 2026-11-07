#include <ft/ft_manager.h>
#include <ft/ft_audience_manager.h>
#include <so/so_value_accesser.h>

#pragma force_active on

extern "C" void setSUlcide__9ftManagerFi(ftManager*, int);
extern "C" const float lbl_27_rodata_1048;

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5(int, bool, bool, bool);
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
    virtual void slot18(unsigned int);
    virtual void slot19();
    virtual void slot20();
    virtual void slot21(int, int);
    virtual void slot22();
    virtual void slot23();
    virtual void* slot24();
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
    virtual void slot38(int, float);
    virtual void slot39();
    virtual void slot40();
    virtual void slot41();
    virtual void slot42();
    virtual void slot43(int);
};

struct Object_vptr_c_base {
    char pad[0xc];
};

class Object_vptr_c : public Object_vptr_c_base {
public:
    virtual void slot0();
    virtual void slot1();
};

struct SoundBase {
    char pad[8];
};

class SoundCall : public SoundBase {
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
    virtual void slot15(int, int);
};

struct MotionInner {
    char pad[0x18];
    void* ptr;
};

struct MotionData {
    char pad[8];
    int value;
};

extern "C" void fn_27_131020(Fighter* self) {
    soModuleAccesser* a = self->m_moduleAccesser;

    if (!self->getOwner()->isSubOwner()) {
        if (g_ftManager->isProcessHeartSwap(self->m_entryId) == 1) {
            soDamageAttackerInfo info;
            a->m_enumerationStart->m_damageModule->getAttackerInfo(&info);
            g_ftManager->toKnockOutHeartSwapOpposite(self->m_entryId, &info);
            return;
        }

        ((Object_vptr_0*)a->m_enumerationStart->m_effectModule)->slot38(
            0x28, lbl_27_rodata_1048);

        void* data = ((Object_vptr_0*)a->m_enumerationStart->m_soundModule)->slot24();
        ((Object_vptr_0*)a->m_enumerationStart->m_soundModule)->slot5(
            ((MotionData*)((MotionInner**)data)[0]->ptr)->value, true, true, false);

        if (!((*((unsigned char*)g_ftManager + 0x6c) >> 5) & 1)) {
            ((Object_vptr_0*)a->m_enumerationStart->m_effectModule)->slot43(7);
            SoundCall* sound = (SoundCall*)a->m_enumerationStart->m_slowModule;
            sound->slot15(
                soValueAccesser::getConstantInt(a, 0x5a4e, 0),
                soValueAccesser::getConstantInt(a, 0x5a4f, 0));

            soDamageAttackerInfo info;
            a->m_enumerationStart->m_damageModule->getAttackerInfo(&info);

            if (info.m_indirectSoKind == 0 &&
                g_ftManager->isValidEntryId(info.m_indirectEntryId) == 1) {
                g_ftAudienceManager->m_audience->checkCheerDefeat(info.m_indirectEntryId);
                g_ftManager->setBeat(self->m_entryId, info.m_indirectEntryId);
            } else {
                setSUlcide__9ftManagerFi(g_ftManager, self->m_entryId);
            }

            g_ftManager->setDead(self->m_entryId, 5, -1);
            self->m_outsideEventPresenter.notifyOutsideEventKnockout();
        }
    }

    self->setCurry(false, -1);
    ((Object_vptr_0*)a->m_enumerationStart->m_collisionHitModule)->slot21(0, 0);
    ((Object_vptr_0*)a->m_enumerationStart->m_workManageModule)->slot18(0x12000018);
    ((Object_vptr_0*)self->m_moduleAccesser->m_enumerationStart->m_controllerModule)->slot43(1);

    int status = a->m_enumerationStart->m_situationModule->getKind() == 0 ? 0x4b : 0x49;
    a->m_enumerationStart->m_statusModule->changeStatusRequest(status, a);
}
