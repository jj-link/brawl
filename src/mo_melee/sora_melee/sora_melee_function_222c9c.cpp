#include <cm/cm_camera_controller.h>
#include <cm/cm_stage_param.h>
#include <types.h>
#pragma force_active on

extern "C" {
extern const float lbl_27_rodata_33D0[];
extern void* g_GameGlobal;
void fn_8009D158(void* cam, void* p);
void fn_8009D21C(void* cam, void* p);
}

#define PTR98(s) (*(char**)((char*)(s) + 0x98))
#define FLD(p, off) (*(float*)((char*)(p) + (off)))

inline void initParam(float* arg1, float min) {
    const float* k = lbl_27_rodata_33D0 + 8;
    arg1[0] = k[3];
    arg1[1] = k[4];
    arg1[2] = k[-6];
    arg1[3] = k[-6];
    arg1[4] = k[5];
    arg1[5] = k[-6];
    arg1[6] = k[6];
    arg1[7] = k[5];
    arg1[8] = k[-6];
    arg1[9] = k[3];
    arg1[10] = k[7];
    arg1[11] = k[-6];
    arg1[12] = k[8];
    arg1[13] = k[9];
    arg1[14] = k[10];
    arg1[15] = min;
    arg1[16] = min - k[2];
    arg1[17] = k[2] + k[2];
    arg1[18] = k[2] + k[2];
    arg1[19] = k[1] - k[10];
    arg1[20] = k[11];
    arg1[21] = k[12];
    arg1[22] = k[10];
    arg1[23] = k[13];
    arg1[24] = k[-6];
    arg1[25] = k[-6];
    arg1[26] = k[-6];
    arg1[27] = k[-8];
    arg1[28] = k[-8];
    arg1[30] = k[-6];
    arg1[31] = k[14];
    arg1[29] = k[-8];
}

inline float toRadians(float value, const float* factor) { return factor[23] * value; }

extern "C" void fn_27_222C9C(void* arg0, float* arg1) {
    initParam(arg1, lbl_27_rodata_33D0[8]);
    char* a = PTR98(arg0);
    const float* k = lbl_27_rodata_33D0;
    if (a != 0) {
        arg1[27] = FLD(a, 0x44);
        arg1[28] = FLD(PTR98(arg0), 0x48);
        arg1[29] = FLD(PTR98(arg0), 0x4C);
        arg1[22] = FLD(PTR98(arg0), 0x2C);
        arg1[23] = FLD(PTR98(arg0), 0x30);
        {
            char* gg = *(char**)((char*)g_GameGlobal + 8);
            unsigned int b = (unsigned char)gg[0xd];
            if (((b >> 3) & 3) == 2) {
                arg1[30] = toRadians(FLD(PTR98(arg0), 0x38), k);
            } else {
                arg1[30] = toRadians(FLD(PTR98(arg0), 0x34), k);
            }
        }
        arg1[31] = toRadians(FLD(PTR98(arg0), 0x28), k);
        arg1[20] = FLD(PTR98(arg0), 0x40);
        arg1[21] = FLD(PTR98(arg0), 0x3C);
        if (CameraController::getInstance() != 0) {
            cmStageParamPaused paused;
            cmStageParamFixed fixed;
            paused.m_angle = FLD(PTR98(arg0), 0x6C);
            paused.m_zoomIn = FLD(PTR98(arg0), 0x70);
            paused.m_zoomDefault = FLD(PTR98(arg0), 0x74);
            paused.m_zoomOUt = FLD(PTR98(arg0), 0x78);
            paused.m_rotYMin = FLD(PTR98(arg0), 0x7C);
            paused.m_rotYMax = FLD(PTR98(arg0), 0x80);
            paused.m_rotXMin = FLD(PTR98(arg0), 0x84);
            paused.m_rotXMax = FLD(PTR98(arg0), 0x88);
            paused.m_centerPos.m_x = FLD(PTR98(arg0), 0x60);
            paused.m_centerPos.m_y = FLD(PTR98(arg0), 0x64);
            paused.m_centerPos.m_z = FLD(PTR98(arg0), 0x68);
            paused.m_offsetRange.m_0 = k[2];
            paused.m_offsetRange.m_4 = k[2];
            paused.m_offsetRange.m_8 = k[2];
            paused.m_offsetRange.m_12 = k[2];
            fn_8009D158(CameraController::getInstance(), &paused);
            fixed.m_centerPos.m_x = FLD(PTR98(arg0), 0x8C);
            fixed.m_centerPos.m_y = FLD(PTR98(arg0), 0x90);
            fixed.m_centerPos.m_z = FLD(PTR98(arg0), 0x94);
            fixed.m_fov = FLD(PTR98(arg0), 0x98);
            fixed.m_verticalAngle = FLD(PTR98(arg0), 0xA0);
            fixed.m_horizontalAngle = FLD(PTR98(arg0), 0x9C);
            fn_8009D21C(CameraController::getInstance(), &fixed);
        }
    }
}
