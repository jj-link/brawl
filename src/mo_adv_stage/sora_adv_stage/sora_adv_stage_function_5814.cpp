#pragma force_active on

struct Vec3f { float x; float y; float z; };
struct Vec2f { float x; float y; };

struct Stage_base { char pad[0x3c]; };
struct StageUnk524 { char pad[0x604]; unsigned char m604; };

class Stage : public Stage_base {
public:
    virtual void slot_08();
    virtual void slot_0c();
    virtual void slot_10();
    virtual void slot_14();
    virtual void slot_18();
    virtual void slot_1c();
    virtual void slot_20();
    virtual void slot_24();
    virtual void slot_28();
    virtual void slot_2c();
    virtual void slot_30();
    virtual void slot_34();
    virtual void slot_38();
    virtual void slot_3c();
    virtual void slot_40();
    virtual void slot_44();
    virtual void slot_48();
    virtual void slot_4c();
    virtual void slot_50();
    virtual void slot_54();
    virtual void slot_58();
    virtual void slot_5c();
    virtual void slot_60();
    virtual void slot_64();
    virtual void slot_68();
    virtual void slot_6c();
    virtual void slot_70();
    virtual void slot_74();
    virtual void slot_78();
    virtual void slot_7c();
    virtual void slot_80();
    virtual void slot_84();
    virtual void slot_88();
    virtual void slot_8c();
    virtual void slot_90();
    virtual void slot_94();
    virtual void slot_98();
    virtual void slot_9c();
    virtual void slot_a0();
    virtual void slot_a4();
    virtual void slot_a8();
    virtual void slot_ac();
    virtual void slot_b0();
    virtual void slot_b4();
    virtual void slot_b8();
    virtual void slot_bc();
    virtual void slot_c0();
    virtual void slot_c4();
    virtual void slot_c8();
    virtual void slot_cc();
    virtual void slot_d0();
    virtual void slot_d4();
    virtual void slot_d8();
    virtual void slot_dc(Vec3f* v, int mode);

    char pad_40[0x524 - 0x40];
    StageUnk524* m_524;
    char pad_528[0x560 - 0x528];
    float m_560;
    float m_564;
    float m_568;
};

struct FtOwner_base { char pad[0xc]; };
class FtOwner : public FtOwner_base {
public:
    virtual void slot_08();
    virtual void slot_0c();
    virtual void slot_10();
    virtual void slot_14();
    virtual void slot_18();
};

extern "C" {
extern void* g_ftManager;
extern void* g_efScreen;
extern const float lbl_40_rodata_2C[];
extern const float lbl_40_rodata_80[];
extern const char lbl_40_data_B18[];
extern const char __RTTI__6Ground[];
extern const char lbl_40_data_1590[];
extern const char lbl_40_data_15D8[];

char* strncpy(char* dst, const char* src, unsigned long n);
int getEntryId__9ftManagerFi(void* self, int playerNo);
void* getOwner__9ftManagerFi(void* self, int entryId);
void fn_27_109D88(void* self, int kind, Vec3f* v, float f);
unsigned int getGroundNum__5StageFv(Stage* self);
void* getGround__5StageFi(Stage* self, int index);
void* __dynamic_cast(void* p, long srcOffset, const void* src, const void* dst, short hint);
void fn_27_26DA78(void* self, float f);
void* getInstance__16CameraControllerFv();
void fn_800A58C0(void* self, Vec2f* v, float f, int i);
void fn_8005D5C8(void* efScreen);

void fn_40_5814(Stage* self, const char* name, int flag)
{
    Vec3f vecA;
    Vec3f vecB;
    Vec3f vecC;
    Vec2f vec2;
    float zero;
    int id;
    FtOwner* owner;
    void* p;

    strncpy((char*)self + 0x530, name, 0x1f);
    int i = 0;
    do {
        id = getEntryId__9ftManagerFi(g_ftManager, i);
        if (id != -1) {
            owner = (FtOwner*)getOwner__9ftManagerFi(g_ftManager, id);
            owner->slot_14();
            owner->slot_18();
        }
        i++;
    } while (i < 4);

    zero = lbl_40_rodata_2C[0];
    vecA.x = zero;
    vecA.y = zero;
    vecA.z = zero;
    id = getEntryId__9ftManagerFi(g_ftManager, 0);
    if (id != -1) {
        self->slot_dc(&vecA, 0);
        fn_27_109D88(g_ftManager, id, &vecA, lbl_40_rodata_80[0]);
        self->m_560 = vecA.x;
        self->m_564 = vecA.y;
        self->m_568 = vecA.z;
    }

    if (flag != 0) {
        zero = lbl_40_rodata_2C[0];
        vecB.x = zero;
        vecB.y = zero;
        vecB.z = zero;
        id = getEntryId__9ftManagerFi(g_ftManager, 1);
        if (id != -1) {
            self->slot_dc(&vecB, 1);
            fn_27_109D88(g_ftManager, id, &vecB, lbl_40_rodata_80[0]);
        }
    }

    unsigned int j = 0;
    unsigned int n = getGroundNum__5StageFv(self);
    for (; j != n; j++) {
        void* ground = getGround__5StageFi(self, j);
        void* g = __dynamic_cast(ground, 0x3c, lbl_40_data_B18, __RTTI__6Ground, 0);
        if (g != 0) {
            fn_27_26DA78(g, lbl_40_rodata_2C[0]);
        }
    }

    void* cam = getInstance__16CameraControllerFv();
    p = __dynamic_cast(*(void**)((char*)cam + 0x48), 4, lbl_40_data_1590, lbl_40_data_15D8, 0);
    if (p != 0) {
        self->slot_dc(&vecC, 0);
        vec2.x = vecC.x;
        vec2.y = vecC.y;
        fn_800A58C0(p, &vec2, lbl_40_rodata_2C[0], 0);
        unsigned char t = self->m_524->m604;
        if (t == 0 || t == 4) {
            self->m_560 = vecC.x;
            self->m_564 = vecC.y;
            self->m_568 = vecC.z;
        }
    }

    fn_8005D5C8(g_efScreen);
}
}
