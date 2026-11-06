// I could not resolve the two relocations to lbl_27_rodata_2120.
extern "C" int randi__Fl(long);

struct Selection {
    int unused;
    int group;
    int index;
};

struct ResourceBase {
    int pad0;
    int pad1;
};

struct Resource : ResourceBase {
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
    virtual Selection* get();
};

struct Request {
    int id;
    float frame;
    float rate;
    bool flag0;
    bool flag1;
    bool flag2;
    bool flag3;
};

struct Actor;

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
    virtual void slot16(Actor*);
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual int slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void slot26();
    virtual void slot27();
    virtual void slot28();
    virtual void slot29();
    virtual void slot30(const Request*);
};

struct Modules {
    char pad[8];
    soNullable* motion;
    char gap[0x2c];
    Resource* resource;
};

struct Actor {
    char pad[0xd8];
    Modules* modules;
};

#pragma force_active on

extern "C" void fn_27_16AFD0(soNullable* self, Actor* actor) {
    const Selection* const selection = actor->modules->resource->get();
    const int ids[4][3] = {
        {158, 155, 152},
        {159, 156, 153},
        {160, 157, 154},
        {0, 0, 0}
    };

    long group = selection->group;
    long index = selection->index;
    if (group >= 3)
        group = 2;

    const int* const row = ids[group];
    if (row[index] == actor->modules->motion->slot21()) {
        index += randi__Fl(2L) + 1;
        if (index >= 3)
            index -= 3;
    }

    Request request;
    request.id = row[index];
    request.frame = 0.0f;
    request.rate = 1.0f;
    request.flag0 = false;
    request.flag1 = false;
    request.flag2 = false;
    request.flag3 = false;

    actor->modules->motion->slot30(&request);
    self->slot16(actor);
}
