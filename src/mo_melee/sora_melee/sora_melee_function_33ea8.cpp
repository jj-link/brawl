#include <types.h>
#pragma force_active on

struct Vec2 {
    f32 x;
    f32 y;
};

struct QBits {
    u8 hi : 1;
    u8 rest : 7;
};

struct Line {
    u32 a;
    void* b;
    void* c;
    u8 d;
    QBits q;

    Line() {
        a = 0;
        b = 0;
        c = 0;
        d = 0;
        q.hi = 0;
    }
};

class soNullable {
public:
    virtual void isNull();
    virtual void fn_27_31270();
    virtual int fn_27_31C88();
    virtual void fn_27_31DCC();
    virtual void fn_27_31E40();
    virtual void fn_27_32460();
    virtual void fn_27_325B8();
    virtual void fn_27_327D8();
    virtual void fn_27_32E84();
    virtual void fn_27_332E8();
    virtual void fn_27_33E20();

    u8 pad_4[4];
    u32 unk8;
    u8 pad_c[8];
    Vec2 pos;
    Vec2 vel;
};

struct Obj2Prefix {
    u32 pad[2];
};

class Obj2 : public Obj2Prefix {
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
    virtual Vec2 slot86(s32);

    u8 pad[8];
};

struct Id {
    u32 v;
};

struct IdRead {
    u8 pad[8];
    Id value;
};

extern "C" u32 fn_80111CB0(void*, void*);
extern "C" void fn_80111DE4(u32*, void*, f32*);
extern "C" Vec2 fn_80114CBC(void*, void*);
extern "C" const f32 lbl_27_rodata_450;

extern "C" void fn_27_33EA8(soNullable* self, u32 arg1, Obj2* arg2, s32 arg3, u32 arg4) {
    u32 contextId;
    u32 queryId;

    if (self->fn_27_31C88() != 0) {
        bool flag = false;
        Line l;
        s32 ok;

        if (((IdRead*)self)->value.v == 0xFFFF) {
            ok = 0;
        } else {
            Id id;
            id = ((IdRead*)self)->value;
            if (fn_80111CB0(&id, &l) == 0) {
                ok = 0;
            } else {
                flag = (l.a != 0) && (l.b != 0) && (l.c != 0);
                int result;
                if (flag && ((((u8*)l.b)[0x54] >> 4) & 1) &&
                    ((((u8*)l.c)[0x2C] >> 7) & 1)) {
                    result = 1;
                } else {
                    result = 0;
                }
                ok = result != 0;
            }
        }

        if (!ok) {
            self->fn_27_33E20();
            return;
        }

        if (arg1 != 1) {
            Vec2 zero = {lbl_27_rodata_450, lbl_27_rodata_450};
            self->vel = zero;

            Vec2 r = arg2->slot86(arg3);
            contextId = self->unk8;
            fn_80111DE4(&contextId, &r, &self->vel.x);

            Vec2 p = fn_80114CBC(&l, &self->pos);
            self->pos = p;
        }
    }
}
