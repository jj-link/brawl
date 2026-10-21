#pragma force_active on
struct Vec3f {
    float x, y, z;
};

struct CollisionHeader {
    char pad[8];
};

struct Collision : CollisionHeader {
    virtual void unused0();
    virtual void unused1();
    virtual void unused2();
    virtual void unused3();
    virtual void unused4();
    virtual void unused5();
    virtual void unused6();
    virtual void unused7();
    virtual void unused8();
    virtual void warp(Vec3f*, int);
    virtual void unused9();
    virtual void update(int);
};

struct Posture {
    virtual void unused0();
    virtual void unused1();
    virtual void unused2();
    virtual void setPos(Vec3f*);
};

struct ItemHeader {
    char pad[0x3c];
};

struct BaseItem : ItemHeader {
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
    virtual void update();

    char pad1[0xdb4 - 0x40];
    Posture posture;
    char pad2[0xe7c - 0xdb8];
    Collision collision;
};

extern "C" void warp__8BaseItemFP5Vec3f(BaseItem* self, Vec3f* pos) {
    self->collision.warp(pos, 0);
    self->posture.setPos(pos);
    self->update();
    self->collision.update(1);
}
