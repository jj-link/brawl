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
    char pad0[0x3c];
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

    char pad40[0x110];
    unsigned char state;
    char pad151[0x143];
    char sound[8];
    int soundHandle;
    int danger1;
    int danger2;
};

struct aiMgr;

extern "C" {
extern float lbl_73_rodata_104[];
extern char lbl_73_data_11F8[];
extern char lbl_73_data_1208[];
extern aiMgr* g_aiMgr;

int setDangerZone__5aiMgrFP5Vec2fP5Vec2fibb(
    aiMgr*, Vec2f*, Vec2f*, int, bool, bool);
void stopSE__14snd3DGeneratorFll(void*, int, int);

void fn_73_8454(Stage* self) {
    switch (self->state) {
    case 3:
        if (self->danger1 == -1 || self->danger2 == -1) {
            Vec3f pos;
            Vec2f bottomRight;
            Vec2f topLeft;

            self->getPosition(&pos, 0, lbl_73_data_11F8);
            topLeft.set(pos.x - lbl_73_rodata_104[0],
                        lbl_73_rodata_104[0] + pos.y);
            bottomRight.set(lbl_73_rodata_104[0] + pos.x,
                            pos.y - lbl_73_rodata_104[0]);
            self->danger1 = setDangerZone__5aiMgrFP5Vec2fP5Vec2fibb(
                g_aiMgr, &topLeft, &bottomRight,
                self->danger1, false, false);

            self->getPosition(&pos, 0, lbl_73_data_1208);
            topLeft.set(pos.x - lbl_73_rodata_104[0],
                        lbl_73_rodata_104[0] + pos.y);
            bottomRight.set(lbl_73_rodata_104[0] + pos.x,
                            pos.y - lbl_73_rodata_104[0]);
            self->danger2 = setDangerZone__5aiMgrFP5Vec2fP5Vec2fibb(
                g_aiMgr, &topLeft, &bottomRight,
                self->danger2, false, false);
        }
        break;

    case 4:
        if (self->soundHandle != -1) {
            stopSE__14snd3DGeneratorFll(self->sound, self->soundHandle, 0);
            self->soundHandle = -1;
        }
        break;
    }
}
}
