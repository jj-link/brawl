#pragma force_active on

typedef unsigned int u32;
typedef unsigned char u8;
typedef int s32;

struct Vec2f {
    float x;
    float y;
};

struct Object {
    u32 unused;
    void* data;
};

struct FlagsA { u8 pad[0xe]; u8 flags; };
struct FlagsB { u8 pad[0x54]; u8 flags; };
struct FlagsC { u8 pad[0x2c]; u8 flags; };

struct QBits { u8 hi : 1; u8 rest : 7; };

struct Line {
    FlagsA* a;
    FlagsB* b;
    FlagsC* c;
    u8 byte;
    QBits q;
};

class Getter {
public:
    virtual void slot0();
    virtual Object* slot1();
};

class Big {
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
    virtual s32 slot111(float f);
};

struct LevelB {
    u8 pad[0x54];
    Big* m_54;
};

struct LevelA {
    u8 pad[0xd8];
    LevelB* m_d8;
};

struct Self {
    u8 pad[0x28];
    Getter* m_28;
    u8 pad2[0x28];
    LevelA* m_54;
};

extern "C" {
extern const float lbl_27_rodata_3C0[];
u32 fn_80134344(void* p, u32 idx);
u32 fn_80134534(void* p, u32 idx);
u32 fn_80111CB0(void* q, void* line);
void fn_80135FA0(void* p, u32 idx, Vec2f* out, float f);
float fn_27_301D8(void* obj);
float fn_27_30240(void* obj);
}

static inline s32 check(Object* obj, u32 mode) {
    u32 q = fn_80134534(obj->data, mode);
    if (q != 0xFFFFu) {
        u32 id;
        Line l;
        s32 valid = 0;
        id = q;
        l.a = 0;
        l.b = 0;
        l.c = 0;
        l.byte = 0;
        l.q.hi = 0;
        s32 ok = (fn_80111CB0(&id, &l.a) == 1);
        if (ok) {
            if (l.a != 0 && l.b != 0 && l.c != 0)
                valid = 1;
            s32 en;
            if (valid != 0 && ((((FlagsB*)l.b)->flags >> 4) & 1) &&
                ((((FlagsC*)l.c)->flags >> 7) & 1))
                en = 1;
            else
                en = 0;
            ok = (en == 1);
        }
        if (ok)
            ok = ((FlagsA*)l.a)->flags & 1;
        if (ok)
            return 1;
    }
    return 0;
}

extern "C" s32 fn_27_28A54(Self self, float farg0) {
    const float* k = lbl_27_rodata_3C0;
    Object* obj = self.m_28->slot1();

    if (fn_80134344(obj->data, 0) == 1 && fn_80134344(obj->data, 3) == 1 &&
        farg0 >= fn_27_301D8(obj)) {
        s32 ok = (check(obj, 0) == 1);
        if (ok == 0)
            ok = (check(obj, 3) == 1);
        if (ok != 0) {
            Vec2f v0;
            v0.x = k[1];
            v0.y = k[3];
            fn_80135FA0(obj->data, 0, &v0, k[1]);
            Vec2f v3;
            v3.x = k[1];
            v3.y = k[0];
            fn_80135FA0(obj->data, 3, &v3, k[1]);
            if (k[0] == farg0 || k[1] != v0.y || k[1] != v3.y) {
                if (k[1] == v0.y)
                    v0.y = k[3];
                if (k[1] == v3.y)
                    v3.y = k[0];
                return (v0.y * v3.y) < k[1];
            }
        }
    }

    if (fn_80134344(obj->data, 2) == 1 && fn_80134344(obj->data, 1) == 1 &&
        farg0 >= fn_27_30240(obj)) {
        s32 ok = (check(obj, 2) == 1);
        if (ok == 0)
            ok = (check(obj, 1) == 1);
        if (ok != 0) {
            Vec2f v2;
            v2.x = k[3];
            v2.y = k[1];
            fn_80135FA0(obj->data, 2, &v2, k[3]);
            Vec2f v1;
            v1.x = k[0];
            v1.y = k[1];
            fn_80135FA0(obj->data, 1, &v1, k[0]);
            if (k[0] == farg0 || k[1] != v2.x || k[1] != v1.x) {
                if (k[1] == v2.x)
                    v2.x = k[3];
                if (k[1] == v1.x)
                    v1.x = k[0];
                return (v2.x * v1.x) < k[1];
            }
        }
    }

    return self.m_54->m_d8->m_54->slot111(farg0);
}
