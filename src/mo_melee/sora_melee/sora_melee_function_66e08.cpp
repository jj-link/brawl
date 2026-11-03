#include <types.h>
#pragma force_active on

extern const float lbl_27_rodata_910[];

struct Vec3 {
    f32 x;
    f32 y;
    f32 z;
};

struct Buf {
    u32 a;
    u8 b;
    u8 c;
};

class soNullable {
public:
    virtual void isNull();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6(u32);
    virtual void slot7();
    virtual void slot8(u32);
    virtual u32 slot9(u32, void*);
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15(u32, void*, u8);
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
    virtual void slot85(void*, void*);
    virtual void slot86();
    virtual void slot87(u32);
};

class Inner {
public:
    char pad[0x54];
    soNullable* m_obj;
};

class Mid {
public:
    char pad[0xd8];
    Inner* m_inner;
};

class Self {
public:
    char pad0[0x10];
    Mid* m_mid;
    char pad1[0x19];
    u8 m_2d;
    char pad2[0x3];
    u8 m_31;
};

extern "C" void fn_27_66E08(Self* self, u32 arg) {
    if (self->m_mid->m_inner->m_obj->slot9(0, self->m_mid) == 1) {
        Buf buf;
        u8 val = self->m_31;
        buf.a = 0xe;
        buf.b = 0;
        buf.c = val;
        self->m_mid->m_inner->m_obj->slot15(0, &buf, val);
        if (self->m_2d == 1) {
            if (arg == 1) {
                Vec3 v1;
                Vec3 v2;
                v1.x = lbl_27_rodata_910[0];
                v1.y = lbl_27_rodata_910[0];
                v1.z = lbl_27_rodata_910[0];
                v2.x = lbl_27_rodata_910[0];
                v2.y = lbl_27_rodata_910[0];
                v2.z = lbl_27_rodata_910[0];
                self->m_mid->m_inner->m_obj->slot85(&v1, &v2);
            }
            self->m_mid->m_inner->m_obj->slot87(1);
        }
        self->m_mid->m_inner->m_obj->slot8(0);
    }
    self->m_mid->m_inner->m_obj->slot6(2);
}
