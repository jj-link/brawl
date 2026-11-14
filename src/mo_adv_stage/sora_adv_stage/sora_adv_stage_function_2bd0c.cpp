#pragma force_active on

extern "C" float mtSqrtf__Ff(float);
extern "C" void setVisibility__6GroundFUl(void* self, unsigned long flag);
extern "C" void setAttackGimmick__10grYakumonoFiiUlPQ29grGimmick10AttackDataPQ29grGimmick13AttackDetails(void*, int, int, unsigned long, void*, void*);
extern const float lbl_40_rodata_468[];
extern const float lbl_40_rodata_4B0[];

struct Vec4 {
    float x, y, z, w;
};

struct Pair {
    Vec4 a;
    Vec4 b;
};

struct Frame {
    Vec4 v0;
    Vec4 v1;
    Vec4 v2;
    Vec4 v3;
    Pair out;
    Vec4 extra;
};

struct Mid {
    unsigned char pad[0x1c];
    unsigned short unk1c;
};

class Class_5648 {
public:
    virtual void fn_40_215A4();
    virtual void fn_40_20A6C();
    virtual void fn_40_20A7C();
    virtual void fn_40_1E5E0();
    virtual void fn_40_1E2A0();
    virtual void fn_40_1DE6C();
    virtual float fn_40_20D70(void* p);

    unsigned char pad04[0x2c - 0x04];
    Mid* unk2c;
};

struct Holder {
    unsigned char pad0[0xc];
    Class_5648* q;
};

struct grYakumono_base {
    unsigned char pad[0x3c];
};

class grYakumono : public grYakumono_base {
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
    virtual int slot50(void* out, unsigned long a, unsigned long b);

    unsigned char pad40[0x48 - 0x40];
    Holder** unk48;
    unsigned char pad4C[0xBC - 0x4C];
    void* unkBC;
    unsigned char padC0[0x170 - 0xC0];
    int unk170;
    unsigned char pad174[0x17C - 0x174];
    float unk17C;
    unsigned char pad180[0x194 - 0x180];
    float unk194;
};

extern "C" void fn_40_2BD0C(grYakumono* self) {
    Frame f;
    float minLen;

    Class_5648* q = (*self->unk48)->q;
    Mid* m = q->unk2c;
    unsigned short r31 = m->unk1c;
    if (q->fn_40_20D70(m) >= (float)r31) {
        self->unk170 = 1;
        self->unk17C = lbl_40_rodata_468[0];
    }
    if (self->slot50(&f.out, 0, 0) != 0) {
        f.v2.x = f.out.a.x;
        f.v2.y = f.out.a.y;
        f.v2.z = f.out.a.z;
        f.v2.w = f.out.a.w;
        f.v0.x = f.out.a.x;
        f.v0.y = f.out.a.y;
        f.v0.z = f.out.a.z;
        f.v0.w = f.out.a.w;
        f.v3.x = f.out.b.x;
        f.v3.y = f.out.b.y;
        f.v3.z = f.out.b.z;
        f.v3.w = f.out.b.w;
        f.v1.x = f.out.b.x;
        f.v1.y = f.out.b.y;
        f.v1.z = f.out.b.z;
        f.v1.w = f.out.b.w;
        float len1 = mtSqrtf__Ff(f.out.a.x * f.out.a.x + f.out.a.y * f.out.a.y + f.out.a.z * f.out.a.z);
        float len2 = mtSqrtf__Ff(f.v1.z * f.v1.z + (f.v1.x * f.v1.x + f.v1.y * f.v1.y));
        if (len1 < len2) {
            minLen = len1;
        } else {
            minLen = len2;
        }
    } else {
        minLen = lbl_40_rodata_4B0[0];
    }
    if (self->unk194 < minLen) {
        setVisibility__6GroundFUl(self, 1);
        void* bk = self->unkBC;
        if (*(unsigned char*)((char*)bk + 0x24d) == 0) {
            setAttackGimmick__10grYakumonoFiiUlPQ29grGimmick10AttackDataPQ29grGimmick13AttackDetails(self, 0, 0, 0, (char*)bk + 0x1e4, 0);
        }
    }
}
