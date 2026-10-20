#pragma force_active on
struct Vec3 {
    float x, y, z;
};

struct Base {
    char pad[0x3C];
};

struct Object : Base {
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
    virtual void getPosition(Vec3*, int, unsigned int);

    char pad1[0x11C];
    Vec3* first;
    Vec3* second;
    unsigned int nodes[9];
};

extern "C" void processAnim__6GroundFv(void*);

extern "C" void fn_54_34F4(Object* self) {
    processAnim__6GroundFv(self);

    if (self->first) {
        self->getPosition(&self->first[0], 0, self->nodes[0]);
        self->getPosition(&self->first[1], 0, self->nodes[1]);
        self->getPosition(&self->first[2], 0, self->nodes[2]);
        self->getPosition(&self->first[3], 0, self->nodes[3]);
        self->getPosition(&self->first[4], 0, self->nodes[4]);
    }

    if (self->second) {
        self->getPosition(&self->second[0], 0, self->nodes[5]);
        self->getPosition(&self->second[1], 0, self->nodes[6]);
        self->getPosition(&self->second[2], 0, self->nodes[7]);
        self->getPosition(&self->second[3], 0, self->nodes[8]);
    }
}
