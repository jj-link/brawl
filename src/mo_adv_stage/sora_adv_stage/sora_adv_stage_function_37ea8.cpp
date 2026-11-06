#include <ft/ft_manager.h>
#include <gr/gr_gimmick.h>
#include <ef/ef_screen.h>
#pragma force_active on
struct Object_vptr_3c_base { char pad[0x3c]; };
class Object_vptr_3c : public Object_vptr_3c_base { public:
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
virtual void slot113(int);
virtual void slot114();
};
struct Data { char pad[0x30]; char name[0x3c]; stTriggerData trigger; };
struct Self { char pad[0x150]; Data* data; unsigned char state; char pad155[3]; float timer; char pad15c[0x44]; unsigned char flag; };
extern "C" {
extern float lbl_27_data_547E0;
extern void* lbl_40_bss_15C;
extern Object_vptr_3c* lbl_27_bss_5668;
int fn_27_10A9DC(ftManager*, int);
int fn_27_10A78C(ftManager*, int);
void fn_27_109F30(ftManager*, int, int);
void fn_27_112E0C(ftOwner*, int);
void fn_40_5CD8(void*, int);
void fn_40_5814(void*, const char*, int);
}
extern "C" void fn_40_37EA8(Self& self) {
    int a, b;
    float delta = lbl_27_data_547E0;
    switch (self.state) {
    case 1: {
        a = g_ftManager->getEntryId(0);
        b = g_ftManager->getEntryId(1);
        if (a == -1 || !fn_27_10A9DC(g_ftManager, a)) { self.state = 0; break; }
        fn_40_5CD8(lbl_40_bss_15C, 0);
        fn_40_5CD8(lbl_40_bss_15C, 1);
        g_stTriggerMng->setTriggerFlag(&self.data->trigger);
        ((grGimmick*)&self)->startGimmickSE(0);
        ((grGimmick*)&self)->startGimmickEffect(0);
        if (fn_27_10A78C(g_ftManager, a)) fn_27_112E0C(g_ftManager->getOwner(a), 1);
        fn_27_109F30(g_ftManager, a, 1);
        self.flag = 0;
        if (b != -1 && fn_27_10A9DC(g_ftManager, b)) {
            if (fn_27_10A78C(g_ftManager, b)) fn_27_112E0C(g_ftManager->getOwner(b), 1);
            fn_27_109F30(g_ftManager, b, 1);
            self.flag = 1;
        }
        self.state = 2;
        GXColor color = {0, 0, 0, 255};
        g_efScreen->requestFill(60.0f, 7, 0, &color);
        if (lbl_27_bss_5668) lbl_27_bss_5668->slot113(0);
        break;
    }
    case 2:
        if (self.timer >= 60.0f) {
            fn_40_5814(lbl_40_bss_15C, self.data->name, self.flag);
            self.state = 0;
            self.timer = 0.0f;
            if (lbl_27_bss_5668) lbl_27_bss_5668->slot114();
        }
        break;
    }
    self.timer += delta;
}