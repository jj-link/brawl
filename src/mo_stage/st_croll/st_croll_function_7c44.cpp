#include <nw4r/math/math_arithmetic.h>
#include <ms/ms_message.h>
#include <gf/gf_camera.h>

#pragma force_active on

struct Context {
    Message* msg;
    int count;
    float x, y, width, height;
};

extern "C" void fn_80069F2C(void*, signed char*);
extern "C" void fn_8006B698(void*, float*, int);
extern "C" void fn_80018610(void*, int);
extern "C" void fn_8007270C(void*, int, int, int, float, float, float, float);

extern "C" const float lbl_90_rodata_0;
extern "C" const float lbl_90_rodata_40;
extern "C" const float lbl_90_rodata_128;
extern "C" const float lbl_90_rodata_12C;
extern "C" const float lbl_90_rodata_130;

extern "C" void fn_90_7C44(
    void* arg0, Context* arg1, signed char* arg2, int arg3, int arg4)
{
    void* obj = (char*)arg0 + 0x10;

    if (arg2 != 0 && *arg2) {
        float ext[4];
        gfCamera camera;

        arg1->msg->clearMsgBuf();
        arg1->msg->setFixedWidth(lbl_90_rodata_40);
        fn_80069F2C(arg1->msg, arg2);

        ext[0] = lbl_90_rodata_0;
        ext[1] = lbl_90_rodata_0;
        ext[2] = lbl_90_rodata_0;
        ext[3] = lbl_90_rodata_0;

        fn_8006B698(
            arg1->msg, ext,
            *(int*)((char*)*(void**)((char*)arg1->msg + 0x1D0) + 0x50));

        if (arg1->count == 0) {
            arg1->x = ext[0];
            arg1->y = ext[1];
            arg1->width = ext[2];
            arg1->height = ext[3];
        } else {
            register f32 d, r;
            register f32 h = arg1->height;
            register f32 w = arg1->width;
            register f32 y = arg1->y;
            {
                register f32 x = arg1->x;
                register f32 n = ext[0];
                asm { ps_sub d, n, x }
                asm { ps_sel r, d, x, n }
                arg1->x = r;
            }
            {
                register f32 n = ext[1];
                asm { ps_sub d, n, y }
                asm { ps_sel r, d, y, n }
                arg1->y = r;
            }
            {
                register f32 n = ext[2];
                asm { ps_sub d, n, w }
                asm { ps_sel r, d, n, w }
                arg1->width = r;
            }
            {
                register f32 n = ext[3];
                asm { ps_sub d, n, h }
                asm { ps_sel r, d, n, h }
                arg1->height = r;
            }
        }

        fn_80018610(&camera, arg1->count++);
        camera.m_projectionType = gfCamera::Projection_Orthogonal;
        *(float*)((char*)&camera + 0x114) = lbl_90_rodata_0;
        *(float*)((char*)&camera + 0x118) = lbl_90_rodata_0;
        *(float*)((char*)&camera + 0x11C) = lbl_90_rodata_128;
        *(float*)((char*)&camera + 0x120) = lbl_90_rodata_12C;
        *(float*)((char*)&camera + 0x124) = lbl_90_rodata_0;
        *(float*)((char*)&camera + 0x128) = lbl_90_rodata_130;
        *(unsigned short*)((char*)&camera + 0x12C) = 0;
        *(unsigned short*)((char*)&camera + 0x12E) = 0;
        *(unsigned short*)((char*)&camera + 0x130) = 0x280;
        *(unsigned short*)((char*)&camera + 0x132) = 0x1E0;
        camera.setGX();

        Message::drawBoxLine(
            255, 0, 0, ext[0], ext[1], ext[2], ext[3], lbl_90_rodata_0);
        arg1->msg->changeMsgBuf(-1);
        arg1->msg->printMsgBuf((FontData::FONT_RESOURCE)9);
        fn_8007270C(obj, 5, 0x2B, 0, ext[0], ext[1], ext[2], ext[3]);
    }

    *(int*)arg0 = arg3;
    *(short*)((char*)arg0 + 8) = (short)*(int*)((char*)arg0 + 0x44);
    *(short*)((char*)arg0 + 0xA) = (short)*(int*)((char*)arg0 + 0x48);
    *(int*)((char*)arg0 + 0xC) = arg4;
    *(void**)((char*)arg0 + 4) = arg2;
}
