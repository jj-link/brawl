#include <types.h>
#include <so/event/so_event_system.h>
#include <so/anim/so_anim_chr.h>
#include <nw4r/g3d/g3d_obj.h>
#pragma force_active on

namespace layout {
class soNullable {
public:
    virtual void isNull();
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
    virtual void slot119();
    virtual void slot120();
    virtual void slot121();
    virtual void slot122();
    virtual void slot123();
    virtual int slot124(int, int);
};
}
class soAnimCmdEventObserver;
template <typename T> class soEventObserver {
public:
    static void __vt(int, int);
};
extern "C" {
extern char lbl_27_data_1248[];
extern char lbl_27_data_1F78[];
extern char lbl_27_data_1180[];
void fn_27_13EF4(void*);
void fn_8018E808(int*);
void fn_27_6610(void*, int);
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void* fn_27_1F9CC(void*, int);
void* fn_27_20ECC(void*, int);
void __dl__FPv(void*);
}
struct Observer {
    void* vt;
    short manager, event, send, pad;
};
struct Obj {
    void* vt;
    Observer obs[4];
    char pad34[0x94 - 0x34];
    nw4r::g3d::G3dObj* obj94;
};

#define RELEASE(i, table) \
 if (&self->obs[i] != 0 && &self->obs[i] != 0) { \
 short id = self->obs[i].manager; self->obs[i].vt = table; \
 if (soEventSystem::getInstance()->getInstanceManager().isContain(id) == 1U) \
 soEventSystem::getInstance()->getManager(self->obs[i].manager)->eraseObserver(self->obs[i].event, self->obs[i].send); \
 self->obs[i].send = -1; self->obs[i].manager = -1; }

extern "C" Obj* fn_27_13C90(Obj* self, int flag) {
    if (self) {
        char* p = (char*)self;
        self->vt = lbl_27_data_1248;
        self->obs[0].vt = lbl_27_data_1248 + 0x1b4;
        self->obs[1].vt = lbl_27_data_1248 + 0x1c4;
        self->obs[2].vt = lbl_27_data_1248 + 0x1d8;
        self->obs[3].vt = lbl_27_data_1248 + 0x1ec;
        fn_27_13EF4(self);
        if (self->obj94) {
            self->obj94->Destroy();
            self->obj94 = 0;
        }
        int file = reinterpret_cast<layout::soNullable*>(self)->slot124(0, 0);
        if (file) fn_8018E808(&file);
        if (p + 0xf4) __destroy_arr(p + 0x100, fn_27_6610, 0x10, 4);
        fn_27_1F9CC(p + 0xc8, -1);
        reinterpret_cast<soAnimChr*>(p + 0x6c)->~soAnimChr();
        reinterpret_cast<soAnimChr*>(p + 0x3c)->~soAnimChr();
        fn_27_20ECC(p + 0x34, -1);
        RELEASE(2, lbl_27_data_1F78);
        RELEASE(1, (void*)soEventObserver<soAnimCmdEventObserver>::__vt);
        RELEASE(0, lbl_27_data_1180);
        if (flag > 0) __dl__FPv(self);
    }
    return self;
}
