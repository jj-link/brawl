#pragma force_active on
extern "C" void* __dynamic_cast(void*, long, const void*, const void*, short);
extern "C" int fn_27_28874C(void*, void*, void*);
extern "C" void fn_27_28880C(void*, int);
extern "C" const char lbl_27_data_248[];
extern "C" const char lbl_27_data_4A000[];
extern "C" const float lbl_27_rodata_5EA8[];
extern "C" const float lbl_27_rodata_5EB0[];

class Work {
public:
    virtual ~Work();
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
    virtual float getFloat(int);
    virtual void setFloat(int, float);
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void setFlag(int);
};

struct Mid {
    char pad[0x64];
    Work* work;
};

struct ObjBase {
    char pad[0x3c];
};

class Obj : public ObjBase {
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
    virtual void slot119();
    virtual void slot120();
    virtual void slot121();
    virtual void slot122();
    virtual void slot123();
    virtual void slot124();
    virtual void slot125();
    virtual void slot126();
    virtual void slot127();
    virtual void slot128();
    virtual void slot129();
    virtual void slot130();
    virtual void slot131();
    virtual void slot132();
    virtual void slot133();
    virtual void slot134();
    virtual void slot135();
    virtual void slot136();
    virtual void slot137();
    virtual void slot138();
    virtual void slot139();
    virtual void slot140();
    virtual void slot141();
    virtual void slot142();
    virtual void slot143();
    virtual void slot144();
    virtual void slot145();
    virtual void slot146();
    virtual void slot147();
    virtual void slot148();
    virtual void slot149();
    virtual void slot150();
    virtual void slot151();
    virtual void slot152();
    virtual void slot153();
    virtual void slot154();
    virtual void slot155();
    virtual void slot156();
    virtual void slot157();
    virtual void slot158();
    virtual void slot159();
    virtual void slot160();
    virtual void slot161();
    virtual void slot162();
    virtual void slot163();
    virtual void slot164();
    virtual void slot165();
    virtual void slot166();
    virtual void slot167();
    virtual void slot168(void*, void*);
};

struct A3 {
    char pad0[8];
    void* p8;
    char pad1[0xcc];
    Mid* mid;
};

struct A4 {
    char pad[0x28];
    float f28;
};

extern "C" void fn_27_2B348C(void*, void* a2, A3* a3, A4* a4, int a5) {
    Work* work;
    Obj* obj = (Obj*)__dynamic_cast(a3->p8, 0x3c, lbl_27_data_4A000, lbl_27_data_248, 1);
    work = a3->mid->work;
    if (fn_27_28874C(obj, a2, a4) != 0) {
        work->setFlag(0x22000001);
        work->setFlag(0x12000004);
        float f = work->getFloat(0x11000006);
        if (f > lbl_27_rodata_5EA8[0]) {
            float d = f - a4->f28;
            if (d <= lbl_27_rodata_5EB0[0]) {
                work->setFlag(0x22000002);
                d = lbl_27_rodata_5EA8[0];
            }
            work->setFloat(0x11000006, d);
        }
        fn_27_28880C(obj, 0);
        if (a5 != 0) {
            obj->slot168(a2, a4);
        }
    }
}
