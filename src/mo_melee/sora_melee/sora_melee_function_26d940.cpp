#include "cm/cm_camera_controller.h"

#pragma force_active on

typedef unsigned char u8;

extern "C" {
void* fn_8009CD44(void*);
int fn_80019C10(void*, float*);
extern const float lbl_27_rodata_4388;
}

struct ClippingSphere {
    int unk0;
    u32 flags;
    float x;
    float y;
    float z;
    char pad[0x48];
    float initX;
    char pad2[0x0C];
    float initY;
    char pad3[0x0C];
    float initZ;
    void setPosition(float a, float b, float c) { x = a; y = b; z = c; }
};

union Vec3Temp {
    u32 bits[3];
    float values[3];
};

struct grGimmickBase {
    char pad0[0x3C];
};

class grGimmick : public grGimmickBase {
public:
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
    virtual void slot48();
    virtual void slot49();
    virtual void slot50();
    virtual void slot51();
    virtual void slot52();
    virtual void slot53();
    virtual void slot54();
    virtual void slot55();
    virtual void slot56();
    virtual void slot57();
    virtual void slot58();
    virtual void slot59();
    virtual void slot60();
    virtual void slot61();
    virtual void slot62();
    virtual void slot63();
    virtual void slot64();
    virtual void slot65();
    virtual void slot66();
    virtual void slot67();
    virtual void slot68();
    virtual void slot69();
    virtual void slot70();
    virtual void slot71();
    virtual void slot72();
    virtual void slot73();
    virtual void slot74();
    virtual void slot75();
    virtual void slot76();
    virtual void slot77();
    virtual void slot78();
    virtual void slot79();
    virtual void slot80();
    virtual void slot81();
    virtual void slot82();
    virtual void slot83();
    virtual void slot84();
    virtual void slot85();
    virtual void slot86();
    virtual void slot87();
    virtual void setTransparency(u32, u32);

    char pad40[0x94];
    ClippingSphere* sphere;
    char padD8[9];
    u8 flag;
    char padE2[2];
    int stageId;
    char padE8[4];
    float posX;
    float posY;
    float posZ;
    float radius;

    void invalidatedByCameraClipping();
};

void grGimmick::invalidatedByCameraClipping() {
    if (stageId != 0) {
        void* manager = fn_8009CD44(CameraController::getInstance());
        if (manager != 0) {
            float bounds[4];
            Vec3Temp center;
            ClippingSphere* clippingSphere = sphere;

            if (clippingSphere != 0) {
                if (clippingSphere->flags & 0x8) {
                    clippingSphere->setPosition(clippingSphere->initX, clippingSphere->initY, clippingSphere->initZ);
                }

                center.bits[0] = ((u32*)sphere)[2];
                center.bits[1] = ((u32*)sphere)[3];
                center.bits[2] = ((u32*)sphere)[4];
            } else {
                center.values[0] = lbl_27_rodata_4388;
                center.values[1] = lbl_27_rodata_4388;
                center.values[2] = lbl_27_rodata_4388;
            }

            posX = center.values[0];
            float r = radius;
            posY = center.values[1];
            posZ = center.values[2];

            bounds[0] = center.values[0];
            bounds[1] = center.values[1];
            bounds[2] = center.values[2];
            bounds[3] = r;

            int clipped = fn_80019C10(manager, bounds);
            if (clipped == 0) {
                if (flag != 0) {
                    setTransparency(0, stageId);
                }
            } else if (flag == 0) {
                setTransparency(1, stageId);
            }
        }
    }
}
