#include <cm/cm_camera_controller.h>
#include <cm/cm_stage_param.h>
#include <types.h>

#pragma force_active on

struct Output {
    float f0;
    float f4;
    float f8;
    float fc;
    float f10;
    float f14;
    float f18;
    float f1c;
    float f20;
    float f24;
    float f28;
    float f2c;
    float f30;
    float f34;
    float f38;
    float f3c;
    float f40;
    float f44;
    float f48;
    float f4c;
    float f50;
    float f54;
};

struct Input {
    char pad0[8];
    int mode;
    char padc[0x44];
    unsigned char flag;
    char pad51[0x6f];
    float c0;
    float c4;
    char padc8[0x38];
    float f100;
};

extern "C" {
extern const float lbl_805A205C;
extern const float lbl_805A2064;
extern const float lbl_805A2068;
extern const float lbl_805A206C;
extern const float lbl_805A2070;
extern const float lbl_805A2074;
extern const float lbl_805A2078;
extern const float lbl_805A207C;
extern const float lbl_805A2080;
extern const float lbl_805A2084;
extern const float lbl_805A2088;

void fn_800A6E78(Output* out, Input* in) {
    if (in->mode == 0 || in->mode == 2) {
        CameraController* c = CameraController::getInstance();
        cmStageParamPaused* p = &c->m_stageCameraParamPaused;

        out->f0 = lbl_805A2064 * (p->m_angle / lbl_805A2068);
        out->f4 = p->m_zoomDefault;
        out->f8 = p->m_zoomIn;
        out->fc = p->m_zoomIn;
        out->f10 = p->m_zoomOUt;
        out->f14 = lbl_805A2064 * (p->m_rotYMin / lbl_805A2068);
        out->f18 = lbl_805A2064 * (p->m_rotYMax / lbl_805A2068);
        out->f1c = lbl_805A2064 * (p->m_rotXMax / lbl_805A2068);
        out->f20 = lbl_805A2064 * (p->m_rotXMin / lbl_805A2068);
        out->f30 = *(float*)((char*)c + 0x100);
        out->f34 = *(float*)((char*)c + 0x104);
        out->f38 = *(float*)((char*)c + 0x108);
        out->f3c = *(float*)((char*)c + 0x10c);

        if (in->mode == 0) {
            out->f24 = p->m_centerPos.m_x;
            out->f28 = *(float*)((char*)c + 0xe8);
            out->f2c = *(float*)((char*)c + 0xec);
            float v = in->flag ? lbl_805A205C : p->m_offsetRange.m_12;
            out->f40 = *(float*)((char*)c + 0xf0);
            out->f44 = v;
            out->f48 = lbl_805A206C;
            float range4;
            float range8;
            range8 = p->m_offsetRange.m_8;
            range4 = p->m_offsetRange.m_4;
            out->f4c = range4;
            out->f50 = range8;
            out->f54 = lbl_805A2070;
        } else {
            out->f24 = in->c0;
            out->f28 = in->c4;
            out->f2c = lbl_805A205C;
            float range0;
            float range12;
            range12 = p->m_offsetRange.m_12;
            range0 = p->m_offsetRange.m_0;
            out->f40 = range0;
            out->f44 = range12;
            out->f48 = lbl_805A205C;
            float range4;
            float range8;
            range8 = p->m_offsetRange.m_8;
            range4 = p->m_offsetRange.m_4;
            out->f4c = range4;
            out->f50 = range8;
            out->f54 = lbl_805A205C;
            out->f10 = in->f100;
        }
    } else {
        out->f0 = lbl_805A2074;
        out->f4 = lbl_805A2068;
        out->f8 = lbl_805A2078;
        out->fc = lbl_805A207C;
        out->f10 = lbl_805A2080;
        out->f14 = lbl_805A205C;
        out->f18 = lbl_805A2084;
        out->f1c = lbl_805A2088;
        out->f20 = lbl_805A2088;
        out->f24 = lbl_805A205C;
        out->f28 = lbl_805A205C;
        out->f2c = lbl_805A205C;

        struct RangeTemp { char padding[0x2C]; cmStageParamPausedOffsetRange range; char tail[0x10]; } stack;
        float y = stack.range.m_12;
        float x = stack.range.m_0;
        out->f40 = x;
        out->f44 = y;
        out->f48 = lbl_805A206C;
        float range4;
        float range8;
        range8 = stack.range.m_8;
        range4 = stack.range.m_4;
        out->f4c = range4;
        out->f50 = range8;
        out->f54 = lbl_805A2070;
    }
}
}