#pragma force_active on
#include <types.h>

struct Sub {
    u32 pad0;
    u32 count;
};

struct Element {
    float value;
    char pad4[0x54 - 4];
    s32 result54;
    char pad58[0x85 - 0x58];
    u8 kind85;
};

class Container {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual Element* getElement(u32 idx);
    u32 pad4;
    Sub* sub;
};

struct Pad3C {
    char pad[0x38];
};

class GroundBase {
public:
    virtual ~GroundBase();
};

class Ground : public Pad3C, public GroundBase {
public:
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
    virtual void startup(void* archive, u32 unk1, u32 unk2);
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
    virtual void setGimmickData(void* data);
};

class Stage {
public:
    char pad0[0x1A0];
    void* m_archive;
    char pad1[0x1C0 - 0x1A4];
    u8* m_table;
    void addGround(Ground* ground);
};

struct GameSub {
    char pad0[0x5FD];
    u8 b5FD;
    char pad1[0x4916 - 0x5FE];
    u8 b4916;
};

struct GameGlobal {
    char pad0[0x30];
    GameSub* sub30;
};

extern GameGlobal* g_GameGlobal;
extern char lbl_40_data_334[];

extern "C" {
Ground* fn_40_2ED9C(s16 kind, const char* name);
Container* searchContainer__20stDataMultiContainerFUlUl(void* self, u32 a, u32 b);
}

extern "C" void fn_40_A330(Stage* arg0, u32 arg1, void* arg2) {
    Ground* ground;
    Container* c;
    u32 idx = 0;
    u32 j;
    Element* elem;
    while ((c = searchContainer__20stDataMultiContainerFUlUl(arg2, arg1, idx++)) != 0) {
        for (j = 0; j < c->sub->count; j++) {
            elem = c->getElement(j);
            ground = fn_40_2ED9C((s16)elem->kind85, lbl_40_data_334);
            if (arg0->m_table != 0) {
                GameSub* gs = g_GameGlobal->sub30;
                int a = gs->b5FD;
                int d = a - gs->b4916;
                int lo = a - 5;
                if (d < lo) d = lo;
                if (d < 0) d = 0;
                if (d > 14) d = 14;
                u8 t = ((u8*)arg0->m_table + (u8)d)[0x80];
                elem->result54 = (s32)(elem->value * (float)t);
            } else {
                elem->result54 = (s32)elem->value;
            }
            ground->setGimmickData(elem);
            arg0->addGround(ground);
            ground->startup(arg0->m_archive, 0, 0);
        }
    }
}
