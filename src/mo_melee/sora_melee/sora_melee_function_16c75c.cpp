struct Selection { int unused; int group; int index; };
struct Request { int id; float frame; float rate; bool flag0; bool flag1; bool flag2; bool flag3; };
struct Resource {
    char pad[8];
    virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3();
    virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7();
    virtual void slot8(); virtual void slot9(); virtual void slot10(); virtual void slot11();
    virtual void slot12(); virtual void slot13(); virtual void slot14(); virtual void slot15();
    virtual void slot16(); virtual void slot17(); virtual void slot18(); virtual void slot19();
    virtual void slot20(); virtual void slot21(); virtual void slot22(); virtual void slot23();
    virtual void slot24(); virtual void slot25(); virtual void slot26(); virtual void slot27();
    virtual void slot28(); virtual void slot29(); virtual void slot30(); virtual void slot31();
    virtual Selection* get(void*);
};
struct Motion {
    virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3();
    virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7();
    virtual void slot8(); virtual void slot9(); virtual void slot10(); virtual void slot11();
    virtual void slot12(); virtual void slot13(); virtual void slot14(); virtual void slot15();
    virtual void slot16(); virtual void slot17(); virtual void slot18(); virtual void slot19();
    virtual void slot20(); virtual void slot21(); virtual void slot22(); virtual void slot23();
    virtual void slot24(); virtual void slot25(); virtual void slot26(); virtual void slot27();
    virtual void slot28(); virtual void slot29(); virtual void slot30(const Request*);
};
struct Modules { char pad[8]; Motion* motion; char gap[0x2c]; Resource* resource; };
struct Actor { char pad[0xd8]; Modules* modules; };
struct Rodata { int words[12]; float frame; float rate; };
extern Rodata lbl_27_rodata_2160;
extern "C" void fn_27_16AD28(void*, Actor*);
#pragma force_active on
extern "C" void fn_27_16C75C(void* self, Actor* actor) {
    Selection* selection = actor->modules->resource->get(actor);
    int ids[4][3] = {
        {161, 161, 161}, {162, 162, 162}, {163, 163, 163}, {0, 0, 0}
    };
    int group = selection->group;
    int index = selection->index;
    if (group >= 3) group = 2;
    Request request;
    request.id = ids[group][index];
    request.frame = 0.0f;
    request.rate = 1.0f;
    request.flag0 = false;
    request.flag1 = false;
    request.flag2 = false;
    request.flag3 = false;
    Modules* modules = actor->modules;
    modules->motion->slot30(&request);
    fn_27_16AD28(self, actor);
}