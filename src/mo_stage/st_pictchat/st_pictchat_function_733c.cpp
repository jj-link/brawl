#pragma force_active on

struct Vec2f {
    float x, y;

    Vec2f() {}
    void set(float a, float b) { x = a; y = b; }
};

struct Vec3f {
    float x, y, z;
};

struct StageBase {
    char pad[0x3c];
};

struct Stage : StageBase {
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
    virtual void getPosition(Vec3f*, int, const char*);

    char pad40[0x274];
    int dangerZone;
};

struct aiMgr;

extern "C" {
extern const float lbl_73_rodata_78[];
extern const char lbl_73_data_11C8[];
extern aiMgr* g_aiMgr;

int setDangerZone__5aiMgrFP5Vec2fP5Vec2fibb(
    aiMgr*, Vec2f*, Vec2f*, int, bool, bool);

void fn_73_733C(Stage* self) {
    float* c = (float*)lbl_73_rodata_78;
    Vec3f pos;
    Vec2f bottomRight;
    Vec2f topLeft;

    self->getPosition(&pos, 0, lbl_73_data_11C8);
    topLeft.set(pos.x - c[30], c[15] + pos.y);
    bottomRight.set(c[31] + pos.x, pos.y - c[15]);

    self->dangerZone = setDangerZone__5aiMgrFP5Vec2fP5Vec2fibb(
        g_aiMgr, &topLeft, &bottomRight, self->dangerZone, false, false);
}
}
