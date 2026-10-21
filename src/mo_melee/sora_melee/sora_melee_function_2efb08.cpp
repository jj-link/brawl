#pragma force_active on

struct Vec3 {
    float x, y, z;
};

struct Flags {
    unsigned char first : 1, second : 1, third : 1, fourth : 1;
    unsigned char fifth : 1, sixth : 1, seventh : 1, eighth : 1;
    unsigned char ninth : 1, tenth : 1, reserved : 6;
};

struct Param {
    int resource, team, teamOwner, teamAnother, index, owner;
    int reserved0, reserved1;
    Vec3 position;
    float facing;
    int parameter, variant, situation, status, reserved2, motion, reserved3;
    Flags flags;
};

struct Object {
    char pad[0x3c];
    virtual void pad0();
    virtual void pad1();
    virtual void pad2();
    virtual void pad3();
    virtual void pad4();
    virtual void pad5();
    virtual void pad6();
    virtual void pad7();
    virtual void pad8();
    virtual void pad9();
    virtual void pad10();
    virtual void pad11();
    virtual void pad12();
    virtual void pad13();
    virtual void pad14();
    virtual void pad15();
    virtual void pad16();
    virtual void pad17();
    virtual void pad18();
    virtual void pad19();
    virtual void pad20();
    virtual void pad21();
    virtual void pad22();
    virtual void pad23();
    virtual void pad24();
    virtual void pad25();
    virtual void pad26();
    virtual void pad27();
    virtual void pad28();
    virtual void pad29();
    virtual void pad30();
    virtual void pad31();
    virtual void pad32();
    virtual void pad33();
    virtual void pad34();
    virtual void pad35();
    virtual void pad36();
    virtual void pad37();
    virtual void pad38();
    virtual void pad39();
    virtual void pad40();
    virtual void pad41();
    virtual void pad42();
    virtual void pad43();
    virtual void pad44();
    virtual void pad45();
    virtual void pad46();
    virtual void pad47();
    virtual void pad48();
    virtual void pad49();
    virtual void pad50();
    virtual void pad51();
    virtual void pad52();
    virtual void pad53();
    virtual void pad54();
    virtual void pad55();
    virtual void pad56();
    virtual void pad57();
    virtual void pad58();
    virtual void pad59();
    virtual void pad60();
    virtual void pad61();
    virtual void pad62();
    virtual void pad63();
    virtual void pad64();
    virtual void pad65();
    virtual void pad66();
    virtual void pad67();
    virtual void pad68();
    virtual void pad69();
    virtual void pad70();
    virtual void pad71();
    virtual void pad72();
    virtual void pad73();
    virtual void pad74();
    virtual void pad75();
    virtual void pad76();
    virtual void pad77();
    virtual void pad78();
    virtual void pad79();
    virtual void pad80();
    virtual void pad81();
    virtual void pad82();
    virtual void pad83();
    virtual void pad84();
    virtual void pad85();
    virtual void pad86();
    virtual void pad87();
    virtual void pad88();
    virtual void pad89();
    virtual void pad90();
    virtual void pad91();
    virtual void pad92();
    virtual void pad93();
    virtual void pad94();
    virtual void pad95();
    virtual void pad96();
    virtual void pad97();
    virtual void pad98();
    virtual void pad99();
    virtual void pad100();
    virtual void pad101();
    virtual void pad102();
    virtual void pad103();
    virtual void pad104();
    virtual void pad105();
    virtual void set(int, int);
};

extern "C" {
extern const float lbl_27_rodata_648C;
void fn_27_1D8370(void*, const Param*);
void* __memcpy(void*, const void*, unsigned long);

void fn_27_2EFB08(Object* object, int resource, int team, int parameter) {
    Param p;
    p.resource = resource;
    p.team = team;
    p.teamOwner = team;
    p.teamAnother = team;
    p.index = -1;
    p.owner = -1;
    p.reserved0 = 0;
    p.reserved1 = 0;

    Vec3 position;
    position.x = lbl_27_rodata_648C;
    position.y = lbl_27_rodata_648C;
    position.z = lbl_27_rodata_648C;
    __memcpy(&p.position, &position, sizeof(Vec3));

    p.facing = lbl_27_rodata_648C;
    p.parameter = parameter;
    p.variant = 0;
    p.situation = 2;
    p.status = 0x80;
    p.reserved2 = 0;
    p.motion = 0x35f;
    p.reserved3 = 0;
    p.flags.first = 1;
    p.flags.second = 1;
    p.flags.third = 0;
    p.flags.fourth = 0;
    p.flags.fifth = 1;
    p.flags.sixth = 0;
    p.flags.seventh = 0;
    p.flags.eighth = 0;
    p.flags.ninth = 0;
    p.flags.tenth = 0;

    fn_27_1D8370(object, &p);
    object->set(0, 0);
}
}
