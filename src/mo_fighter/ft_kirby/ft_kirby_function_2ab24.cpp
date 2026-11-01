#pragma force_active on
union Vec3f {
    struct {
        float x, y, z;
    };
    float v[3];
};

struct Param {
    int founder;
    int ids[3];
    int indices[2];
    int groups[2];
    Vec3f position;
    float rotation;
    int variant;
    int unknown34;
    int category;
    int mask;
    int unknown40;
    int filter;
    int unknown48;
    unsigned char active : 1;
    unsigned char middle : 3;
    unsigned char collision : 1;
    unsigned char low : 3;
    unsigned char upper : 1;
    unsigned char next : 1;
    unsigned char remaining : 6;
};

class Action {
public:
    virtual void unused08();
    virtual void set(int);
    virtual void unused10();
    virtual void add(int, int, int);
    virtual void end();
};

class Status {
public:
    virtual void unused0();
    virtual void unused1();
    virtual void unused2();
    virtual void unused3();
    virtual void unused4();
    virtual void unused5();
    virtual void unused6();
    virtual void unused7();
    virtual void unused8();
    virtual void unused9();
    virtual void unused10();
    virtual void unused11();
    virtual void unused12();
    virtual void unused13();
    virtual void unused14();
    virtual void unused15();
    virtual void unused16();
    virtual void unused17();
    virtual void unused18();
    virtual void unused19();
    virtual void unused20();
    virtual void unused21();
    virtual void unused22();
    virtual void unused23();
    virtual void unused24();
    virtual void unused25();
    virtual void unused26();
    virtual void unused27();
    virtual void unused28();
    virtual void unused29();
    virtual void unused30();
    virtual void unused31();
    virtual void unused32();
    virtual void unused33();
    virtual void unused34();
    virtual void unused35();
    virtual void unused36();
    virtual void unused37();
    virtual void unused38();
    virtual void unused39();
    virtual void unused40();
    virtual void unused41();
    virtual void unused42();
    virtual void unused43();
    virtual void unused44();
    virtual void unused45();
    virtual void unused46();
    virtual void unused47();
    virtual void unused48();
    virtual void unused49();
    virtual void unused50();
    virtual void unused51();
    virtual void unused52();
    virtual void unused53();
    virtual void unused54();
    virtual void unused55();
    virtual void unused56();
    virtual void unused57();
    virtual void unused58();
    virtual void unused59();
    virtual void unused60();
    virtual void unused61();
    virtual void unused62();
    virtual void unused63();
    virtual void unused64();
    virtual void unused65();
    virtual void unused66();
    virtual void unused67();
    virtual void unused68();
    virtual void unused69();
    virtual void unused70();
    virtual void unused71();
    virtual void unused72();
    virtual void unused73();
    virtual void unused74();
    virtual void unused75();
    virtual void unused76();
    virtual void unused77();
    virtual void unused78();
    virtual void unused79();
    virtual void unused80();
    virtual void unused81();
    virtual void unused82();
    virtual void unused83();
    virtual void unused84();
    virtual void unused85();
    virtual void unused86();
    virtual void unused87();
    virtual void unused88();
    virtual void unused89();
    virtual void unused90();
    virtual void unused91();
    virtual void unused92();
    virtual void unused93();
    virtual void unused94();
    virtual void unused95();
    virtual void unused96();
    virtual void unused97();
    virtual void unused98();
    virtual void call(int, int, int);
};

struct Modules {
    char pad[0x54];
    Status* status;
    void* action;
};

struct Access {
    char pad[0xD8];
    Modules* modules;
};

struct Object {
    char pad[0x60];
    Access* access;
};

struct Data {
    int a, b, c, d;
};

struct Common {
    char pad[0x38];
    Data* data[5];
};

extern "C" {
extern char lbl_96_data_DA3C[];
extern char g_ftCommonDataAccesser[];
extern const float lbl_96_rodata_594;
extern char lbl_96_data_E018[];
extern char lbl_96_data_E074[];

void OSReport(const char*, ...);
Common* fn_27_147C38(void*);
Vec3f* fn_96_BC54(Vec3f*, float, float, float);
void fn_27_1D8370(Object*, const Param*);
void fn_27_1DA698(Object*, int, int, int);
void* __dynamic_cast(void*, long, const void*, const void*, short);

void fn_96_2AB24(Object* obj, int founder, int id, int variant, int kind) {
    if (kind < 0 || kind >= 5) {
        OSReport(lbl_96_data_DA3C, kind);
    }

    Data* data = fn_27_147C38(g_ftCommonDataAccesser)->data[kind];

    Vec3f zero;
    fn_96_BC54(&zero, lbl_96_rodata_594,
               lbl_96_rodata_594, lbl_96_rodata_594);

    Param p;
    p.founder = founder;
    p.ids[0] = id;
    p.ids[1] = id;
    p.ids[2] = id;
    p.indices[1] = -1;
    p.groups[0] = 0;
    p.groups[1] = 0;
    p.position = zero;
    p.rotation = lbl_96_rodata_594;
    p.variant = variant;
    p.unknown34 = 0;
    p.category = 2;
    p.mask = 0x80;
    p.unknown40 = 0;
    p.filter = 0x35F;
    p.unknown48 = 0;
    p.active = 1;
    p.middle = 0;
    p.collision = 1;
    p.low = 0;
    p.upper = 0;
    p.next = 0;
    p.indices[0] = kind + 4;
    p.unknown48 = data->d;
    p.upper = 1;

    fn_27_1D8370(obj, &p);

    Access* access = obj->access;
    fn_27_1DA698(obj, founder, data->c, data->b);

    Status* status = access->modules->status;
    status->call(3, 7, 0);

    Action* action = (Action*)__dynamic_cast(
        obj->access->modules->action, 0,
        lbl_96_data_E018, lbl_96_data_E074, 1);

    action->set(data->a);

    int zeroArg = ~(data->b | ~data->b);
    for (int i = 0; i < 2; i++) {
        action->add(zeroArg = 0, 0, zeroArg);
    }

    action->end();
}
}
