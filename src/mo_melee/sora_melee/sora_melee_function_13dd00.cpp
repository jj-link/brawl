#include <types.h>
#include <ft/ft_manager.h>
#include <so/so_external_value_accesser.h>
#pragma force_active on
extern "C" void fn_27_C5EB0(void*, int, int, int, f32);
extern int lbl_27_bss_2CBC;
#define MOD(s) (*(char**)(*(char**)((s) + 0x60) + 0xd8))
class Object_vptr_0 { public:
virtual void slot0();
virtual void slot1();
virtual void* slot2();
virtual int slot3();
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
virtual u32 slot17(u32, void*);
virtual void slot18();
virtual void slot19();
virtual int slot20(int);
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
virtual int slot32(int);
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
virtual u32 slot43(int);
};
struct Prefix { char pad[8]; };
class Object_vptr_8 : public Prefix { public:
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
virtual void slot17(int, f32);
};
extern "C" void fn_27_13DD00(void* arg0, u32 arg1, f32 farg0) {
char* self = (char*)arg0;
if (arg1 == *(u32*)(self + 0x28) ||
    (*(Object_vptr_0**)(MOD(self) + 0x60))->slot43(1) == 1U ||
    (*(Object_vptr_0**)(MOD(self) + 0x20))->slot20(0) != 0 ||
    (*(Object_vptr_0**)(MOD(self) + 0x20))->slot32(0) != 0 ||
    (*(Object_vptr_0**)(MOD(self) + 0x14))->slot3() == 5 ||
    (*(Object_vptr_0**)(MOD(self) + 0x64))->slot17(0x12000018, *(char**)(self + 0x60)) == 1U) return;
    Fighter* fighter = g_ftManager->getFighter(*(int*)((char*)g_ftManager + 0x74), -1);
    if (fighter != 0) {
        Object_vptr_0* p = *(Object_vptr_0**)(MOD(self) + 0x18);
        int team = soExternalValueAccesser::getTeamNo(fighter);
        int chain = (int)((Object_vptr_0*)p->slot2())->slot2();
        if (chain == team) return;
    }
    Object_vptr_8* o38 = *(Object_vptr_8**)(MOD(self) + 0x38);
    o38->slot17(0, farg0);
    int id = *(int*)((char*)g_ftManager + 0x74);
    if (g_ftManager->isValidEntryId(id) != 0) {
        Fighter* f2 = g_ftManager->getFighter(id, -1);
        if (f2 != 0) {
            fn_27_C5EB0(&lbl_27_bss_2CBC, *(int*)((char*)f2 + 0x28), *(int*)(self + 0x28), 0, farg0);
        }
    }
}
