#include <gf/gf_camera.h>
#include <cm/cm_camera_controller.h>
#include <cm/cm_stage_param.h>

#pragma force_active on

extern "C" {
void fn_8009D158(void*, void*);
void fn_800A4BA8(void*, void*);
void fn_800A5990(void*, float*);
void* __dynamic_cast(void*, long, const void*, const void*, short);
extern const char lbl_40_data_1590[];
extern const char lbl_40_data_15D8[];
}

struct Constants {
    char pad[0x2c];
    float zero;
    char pad2[0x48 - 0x30];
    float thirty;
    char pad3[0x9c - 0x4c];
    float minAngle;
    float maxAngle;
};
extern const Constants lbl_40_rodata_0;

struct V4 { float x, y, z, w; };
struct Object_vptr_3c_base { char pad[0x3c]; };
class Object_vptr_3c : public Object_vptr_3c_base {
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
    virtual void slot88();
    virtual void slot89();
    virtual void slot90();
    virtual void slot91();
    virtual void slot92();
    virtual void slot93();
    virtual void slot94();
    virtual void slot95();
    virtual void slot96();
    virtual void slot97();
    virtual void slot98();
    virtual void slot99();
    virtual void slot100();
    virtual void slot101();
    virtual bool slot102();
    virtual bool slot103();
    char pad2[0x180];
    char* data;
    char pad3[4];
    char* data2;
};

extern "C" void fn_40_71E8(Object_vptr_3c* self)
{
    const Constants* constants = &lbl_40_rodata_0;
    if (self->data) {
        gfCamera* camera = (gfCamera*)gfCameraManager::getManager();
        Vec3f pos;
        pos = camera->m_targetPos;
        cmStageParamPaused paused;
        paused.m_angle = *(float*)(self->data + 0x34);
        paused.m_zoomIn = *(float*)(self->data + 0x38);
        paused.m_zoomDefault = *(float*)(self->data + 0x3c);
        paused.m_zoomOUt = *(float*)(self->data + 0x40);
        paused.m_centerPos = pos;
        if (self->slot102() || self->slot103()) {
            paused.m_rotYMin = *(float*)(self->data + 0x44);
            paused.m_rotYMax = *(float*)(self->data + 0x48);
            paused.m_rotXMin = *(float*)(self->data + 0x4c);
            paused.m_rotXMax = *(float*)(self->data + 0x50);
            paused.m_offsetRange.m_0 = constants->minAngle;
            paused.m_offsetRange.m_4 = constants->maxAngle;
            paused.m_offsetRange.m_8 = constants->thirty;
            paused.m_offsetRange.m_12 = constants->zero;
            *(float*)((char*)&paused + 0x3c) = *(float*)(self->data + 0x54);
            *(float*)((char*)&paused + 0x40) = *(float*)(self->data + 0x58);
            *(float*)((char*)&paused + 0x44) = *(float*)(self->data + 0x5c);
            *(float*)((char*)&paused + 0x48) = *(float*)(self->data + 0x60);
        } else {
            paused.m_rotYMin = constants->zero;
            paused.m_rotYMax = constants->zero;
            paused.m_rotXMin = constants->zero;
            paused.m_rotXMax = constants->zero;
            paused.m_offsetRange.m_0 = -*(float*)(self->data + 0x50);
            paused.m_offsetRange.m_4 = *(float*)(self->data + 0x4c);
            paused.m_offsetRange.m_8 = *(float*)(self->data + 0x44);
            paused.m_offsetRange.m_12 = -*(float*)(self->data + 0x48);
            *(float*)((char*)&paused + 0x3c) = *(float*)(self->data + 0x54);
            *(float*)((char*)&paused + 0x40) = *(float*)(self->data + 0x58);
            *(float*)((char*)&paused + 0x44) = *(float*)(self->data + 0x5c);
            *(float*)((char*)&paused + 0x48) = *(float*)(self->data + 0x60);
        }
        if (CameraController::getInstance())
            fn_8009D158(CameraController::getInstance(), &paused);

        char* p = (char*)__dynamic_cast(
            *(void**)((char*)CameraController::getInstance() + 0x48),
            4, lbl_40_data_1590, lbl_40_data_15D8, 0);
        if (p && self->data2)
            fn_800A4BA8(p, self->data2 + 8);

        if (p && self->data) {
            *(float*)(p + 0xdc) = *(float*)(self->data + 4);
            fn_800A5990(p, (float*)(self->data + 8));
            float fw, fz, fy, fx;
            fy = *(float*)(self->data + 0x10);
            fx = *(float*)(self->data + 0xc);
            fw = *(float*)(self->data + 0x18);
            fz = *(float*)(self->data + 0x14);
            V4 v = {fx, fy, fz, fw};
            *(float*)(p + 0xe8) = v.x;
            *(float*)(p + 0xec) = v.y;
            *(float*)(p + 0xf0) = v.z;
            *(float*)(p + 0xf4) = v.w;
        }
    }
}
