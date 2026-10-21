#pragma force_active on
struct Container {
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
    virtual void call(void*);
};

struct Entry {
    char pad[0x10];
    void* value;
};

struct ReplayData {
    char pad[0x16C];
    Entry* entries[4];
    char pad17C[0x18];
    Container* container;
};

struct ReplayBase {
    char pad[0x3C];
};

struct Replay : ReplayBase {
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
    virtual void call(Container*);

    char pad40[0x16C];
    ReplayData* data;
};

extern "C" void fn_7_111C(Replay* self) {
    self->call(self->data->container);

    for (int i = 0; i < 4; ++i) {
        Container* container = self->data->container;
        container->call(self->data->entries[i]->value);
    }
}
