#pragma force_active on
typedef unsigned short u16;

struct Vec2 {
    float x;
    float y;
};

struct Entry {
    unsigned char pad00[0x0C];
    int id;
    int value;
    int flags;
    u16 node;
    u16 pad1A;
    Vec2 position;
    float scale;
};

struct ObjectBase {
    unsigned char pad00[0x3C];
};

struct Object : ObjectBase {
    virtual void slot00();
    virtual void slot01();
    virtual void slot02();
    virtual void slot03();
    virtual void slot04();
    virtual void slot05();
    virtual void slot06();
    virtual void slot07();
    virtual void slot08();
    virtual void slot09();
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
    virtual int getNodeIndex(unsigned long, const char*);

    unsigned char pad40[0x70];
    Entry* entries;
};

extern "C" char lbl_40_data_6380[];

extern "C" void fn_40_38DB8(Object* self, int index, int id, int value, int node, const Vec2* position, float scale)
{
    if (id > 0) {
        self->entries[index].id = id;
        self->entries[index].value = value;
        if (node == 0) {
            self->entries[index].node = self->getNodeIndex(0, lbl_40_data_6380);
        } else {
            self->entries[index].node = node;
        }
        self->entries[index].flags = 0;
        self->entries[index].position = *position;
        self->entries[index].scale = scale;
    }
}
