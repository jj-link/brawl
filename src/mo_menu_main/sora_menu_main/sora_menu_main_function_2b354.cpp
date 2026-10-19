#pragma force_active on
struct Renderer {
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
    virtual void remove(void*);
};

struct Resources {
    char pad[0x54];
    void* first;
    void* second;
};

struct Data {
    char pad[0x2B4];
    void* resource;
};

struct Effect {
    char pad[0x3C];
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
    virtual void destroy();
};

struct Menu {
    char pad[0x64C];
    Data* data;
    Resources* resources;
    Renderer* renderer;
    char pad658[0x1C];
    void* object;
    char pad678[0xA4];
    Effect* effect;
};

extern "C" void fn_800B8EDC(void*, void*);
extern "C" void fn_800B8A0C(void*, int);

extern "C" void fn_2_2B354(Menu* self) {
    self->renderer->remove(self->resources->first);
    self->renderer->remove(self->resources->second);
    fn_800B8EDC(self->object, self->data->resource);
    fn_800B8A0C(self->object, 1);
    if (self->effect) {
        self->effect->destroy();
        self->effect = 0;
    }
}
