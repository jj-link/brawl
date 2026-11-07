#include <em/em_weapon_manager.h>
#pragma force_active on
extern "C" char lbl_41_data_4018[];
extern "C" void wnemReport__FPCce(const char*, ...);
extern "C" void fn_41_31708(void*);
extern "C" void fn_41_2C4F0(emWeaponManager*, unsigned int);

class Object_vptr_0 {
public:
    virtual bool slot0();
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
    virtual void slot21(int);
};
class Object_noarg {
public:
    virtual bool slot0();
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
};
struct Object_vptr_24_base { char pad[0x24]; };
class Object_vptr_24 : public Object_vptr_24_base {
public:
    virtual void slot0();
    virtual void fn_41_2BFE8();
    virtual void fn_41_2C050();
    virtual void fn_41_2C934();
    virtual void fn_41_2CA04(void*);
};
struct InnerBase { char pad[0x3c]; };
class Inner : public InnerBase {
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
    virtual void slot116();
    virtual void slot117();
    virtual void slot118();
    virtual unsigned int getId();
};
extern "C" void fn_41_310BC(unsigned char* self) {
    unsigned int id;
    char* base = lbl_41_data_4018;
    if ((unsigned char)self[0x21b4]) {
        wnemReport__FPCce(base + 0x1f4);
        fn_41_31708(self);
        if (*(Object_vptr_0**)(self + 0x2208)) {
            wnemReport__FPCce(base + 0x224);
            if (!(*(Object_vptr_0**)(self + 0x2208))->slot0()) {
                (*(Object_noarg**)(self + 0x2208))->slot21();
            }
            *(Object_vptr_0**)(self + 0x2208) = 0;
        } else if ((unsigned char)self[0x221a]) {
            wnemReport__FPCce(base + 0x25c);
            id = ((Inner*)(self + 0xc))->getId();
            fn_41_2C4F0(emWeaponManager::getInstance(), id);
        }
        if ((unsigned char)self[0x221b]) {
            wnemReport__FPCce(base + 0x2a1);
            ((Object_vptr_24*)emWeaponManager::getInstance())->fn_41_2CA04(self);
            self[0x221b] = 0;
        }
        *(int*)(self + 0x220c) = 0;
        *(int*)(self + 0x2210) = -1;
        Object_vptr_0* obj = *(Object_vptr_0**)(*(char**)(*(char**)(self + 0x6c) + 0xd8) + 0x88);
        obj->slot21(0);
    }
}