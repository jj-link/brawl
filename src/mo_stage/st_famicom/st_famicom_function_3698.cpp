#pragma force_active on
struct Vec3 {
    float x, y, z;

    Vec3() {}

    void set(float a, float b, float c) {
        x = a;
        y = b;
        z = c;
    }
};

struct Vertex {
    Vec3 pos;
    unsigned char pad[20];
};

struct Prefix {
    unsigned char pad0[0x3c];
};

struct Stage : Prefix {
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

    unsigned char pad1[0x128];
    unsigned int nodes[36];
    Vertex vertices[62];
    unsigned char pad2[6];
    unsigned char count;
    unsigned char pad3;
    float width, height;
};

extern "C" const float lbl_68_rodata_60;

extern "C" void fn_68_3698(Stage* self) {
    int count = self->count;
    for (int i = 0, j = 2 * (count + 1) - 1; i != count; --j, ++i) {
        Vec3 pos;
        self->getPosition(&pos, 0, self->nodes[i]);

        self->vertices[i].pos.set(
            pos.x - lbl_68_rodata_60 * self->width,
            pos.y + lbl_68_rodata_60 * self->height,
            pos.z);

        self->vertices[j].pos.set(
            pos.x - lbl_68_rodata_60 * self->width,
            pos.y - lbl_68_rodata_60 * self->height,
            pos.z);

        if (i == count - 1) {
            self->vertices[i + 1].pos.set(
                pos.x + lbl_68_rodata_60 * self->width,
                pos.y + lbl_68_rodata_60 * self->height,
                pos.z);

            self->vertices[j - 1].pos.set(
                pos.x + lbl_68_rodata_60 * self->width,
                pos.y - lbl_68_rodata_60 * self->height,
                pos.z);
        }
    }
}
