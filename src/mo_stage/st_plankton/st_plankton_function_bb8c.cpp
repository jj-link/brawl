#pragma force_active on
struct Vec2 {
    float x, y;

    Vec2() {}
    Vec2(float a, float b) : x(a), y(b) {}

    Vec2& operator=(const Vec2& v) {
        x = v.x;
        y = v.y;
        return *this;
    }

    void set(float a, float b) {
        x = a;
        y = b;
    }
};

struct Obj;

struct Table {
    char pad[0x1dc];
    unsigned int (*test)(Obj*, Vec2*, Vec2*, Vec2*, Vec2*, Vec2*);
    float (*angle)(Obj*, float, float, float, float);
    void (*rotate)(Obj*, Vec2*, float, float, float);
    void (*finish)(Obj*, Vec2*, unsigned char);
};

struct Item {
    char pad[8];
    float x, y;
    char pad10[4];
    float x2, y2;
    char pad1c[5];
    unsigned char flag;
    char pad22[6];
};

struct Data {
    float x, y, x2, y2, vx, vy;
};

struct Base {
    char pad[0x3c];
};

struct Obj : Base {
    virtual void dummy0();
    virtual void dummy1();
    virtual void dummy2();
    virtual void dummy3();
    virtual void dummy4();
    virtual void dummy5();
    virtual void dummy6();
    virtual void dummy7();
    virtual void dummy8();
    virtual void dummy9();
    virtual void dummy10();
    virtual void dummy11();
    virtual void dummy12();
    virtual void dummy13();
    virtual void dummy14();
    virtual void dummy15();
    virtual void dummy16();
    virtual void dummy17();
    virtual void dummy18();
    virtual void dummy19();
    virtual void dummy20();
    virtual void dummy21();
    virtual void dummy22();
    virtual void dummy23();
    virtual void dummy24();
    virtual void dummy25();
    virtual void dummy26();
    virtual void dummy27();
    virtual void dummy28();
    virtual void dummy29();
    virtual void dummy30();
    virtual void dummy31();
    virtual void dummy32();
    virtual void dummy33();
    virtual void dummy34();
    virtual void dummy35();
    virtual void dummy36();
    virtual void dummy37();
    virtual void dummy38();
    virtual void dummy39();
    virtual void dummy40();
    virtual void dummy41();
    virtual void dummy42();
    virtual void dummy43();
    virtual void dummy44();
    virtual void dummy45();
    virtual void dummy46();
    virtual void dummy47();
    virtual void dummy48();
    virtual void dummy49();
    virtual void dummy50();
    virtual void dummy51();
    virtual void dummy52();
    virtual void dummy53();
    virtual void dummy54();
    virtual void dummy55();
    virtual void dummy56();
    virtual void dummy57();
    virtual void dummy58();
    virtual void dummy59();
    virtual void dummy60();
    virtual void dummy61();
    virtual void dummy62();
    virtual void dummy63();
    virtual void dummy64();
    virtual void dummy65();
    virtual void dummy66();
    virtual void dummy67();
    virtual void dummy68();
    virtual void dummy69();
    virtual void dummy70();
    virtual void dummy71();
    virtual void dummy72();
    virtual void dummy73();
    virtual void dummy74();
    virtual void dummy75();
    virtual void dummy76();
    virtual void dummy77();
    virtual void dummy78();
    virtual void dummy79();
    virtual void dummy80();
    virtual void dummy81();
    virtual void dummy82();
    virtual void dummy83();
    virtual void dummy84();
    virtual void dummy85();
    virtual void dummy86();
    virtual void dummy87();
    virtual void dummy88();
    virtual void dummy89();
    virtual void dummy90();
    virtual void dummy91();
    virtual void dummy92();
    virtual void dummy93();
    virtual void dummy94();
    virtual void dummy95();
    virtual void dummy96();
    virtual void dummy97();
    virtual void dummy98();
    virtual void dummy99();
    virtual void dummy100();
    virtual void dummy101();
    virtual void dummy102();
    virtual void dummy103();
    virtual void dummy104();
    virtual void dummy105();
    virtual void dummy106();
    virtual void dummy107();
    virtual void dummy108();
    virtual void dummy109();
    virtual void dummy110();
    virtual void dummy111();
    virtual void dummy112();
    virtual void dummy113();
    virtual void dummy114();
    virtual void dummy115();
    virtual void dummy116();
    virtual unsigned int test(Vec2*, Vec2*, Vec2*, Vec2*, Vec2*);
    virtual float angle(float, float, float, float);
    virtual void rotate(Vec2*, float, float, float);
    virtual void finish(Vec2*, unsigned char);

    char pad40[0x118];
    unsigned char facing;
    char pad159[7];
    Item* items;
    char pad164[0xc];
    Data* data;
};

extern "C" {

extern const float lbl_74_rodata_160[];
float fn_801622C4(float);
float fn_8016232C(float);

bool fn_74_BB8C(Obj* self) {
    unsigned int i = 0;
    const float* rodata = lbl_74_rodata_160;

    Vec2 a;
    a = *reinterpret_cast<Vec2*>(&self->data->x);
    Vec2 b;
    b = *reinterpret_cast<Vec2*>(&self->data->x2);
    Vec2 c, d, e, f;

    for (; i != 6; ++i) {
        c.set(self->items[(unsigned char)i].x2,
              self->items[(unsigned char)i].y2);
        d.set(self->items[(unsigned char)i].x,
              self->items[(unsigned char)i].y);

        if (self->test(&a, &b, &c, &d, &e) == 1)
            break;
    }

    if ((unsigned char)i == 6)
        return false;

    float angle = self->angle(c.x, c.y, d.x, d.y);
    f.x = self->data->x - e.x;
    f.y = self->data->y - e.y;

    self->rotate(&f, -angle, f.x, f.y);
    self->rotate(&f, angle, -f.x, f.y);

    float angle2 = self->angle(self->data->x, self->data->y,
                               self->data->x2, self->data->y2);
    float angle3 = self->angle(rodata[0], rodata[0], f.x, f.y);
    angle = angle3 - angle2;

    float sine = fn_801622C4(rodata[7] * angle);
    float cosine = fn_8016232C(rodata[7] * angle);

    f.x = self->data->vx;
    f.y = self->data->vy;

    self->data->vx = rodata[8] * (f.x * cosine - f.y * sine);
    self->data->vy = rodata[9] * (f.x * sine + f.y * cosine);
    self->data->x = e.x + rodata[10] * self->data->vx;
    self->data->y = e.y + rodata[10] * self->data->vy;

    if (self->data->vx < rodata[0])
        self->facing = 1;
    else
        self->facing = 0;

    self->items[(unsigned char)i].flag = 0;
    self->finish(&e, (unsigned char)i);
    return true;
}

}
