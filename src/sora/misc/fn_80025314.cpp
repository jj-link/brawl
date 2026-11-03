#include <gf/gf_camera.h>
#pragma force_active on

extern "C" void fn_8002503C(int*, float*, float, float);
extern "C" void fn_801F1564(
    unsigned short, unsigned short, unsigned short, unsigned short);
extern "C" void fn_801F15C8(
    unsigned long, unsigned long, unsigned long, unsigned long);
extern "C" void fn_801F1E60(void*, unsigned long);

extern "C" unsigned char lbl_80494EE8[];
extern "C" unsigned char lbl_804951C0[];
extern "C" unsigned char lbl_805A0024;

extern "C" void fn_80025314()
{
    Vec3f target;
    int point[3];
    int* pointPtr;
    int quad[4];
    int* quadPtr;

    gfCamera* camera = (gfCamera*)gfCameraManager::getManager();
    float width = *(float*)((char*)camera + 0x11C);
    float height = *(float*)((char*)camera + 0x120);
    int widthInt = (int)width;
    int heightInt = (int)height;

    target.m_x = *(float*)((char*)camera + 0x60);
    target.m_y = *(float*)((char*)camera + 0x64);
    target.m_z = *(float*)((char*)camera + 0x68);
    Vec2f cameraPoint;
    camera->calcProjection3Dto2D(&target, &cameraPoint);

    pointPtr = point;
    quadPtr = quad;

    for (unsigned char i = 0; i < 7; ++i) {
        unsigned char* entry = lbl_80494EE8 + i * 0x68;
        if (*(int*)(entry + 0x48) != 0) {
            point[0] = *(int*)(entry + 0x58);
            point[1] = *(int*)(entry + 0x5C);
            point[2] = *(int*)(entry + 0x60);

            Vec2f projected;
            camera->calcProjection3Dto2D((Vec3f*)pointPtr, &projected);

            quad[0] = *(int*)&cameraPoint.m_x;
            quad[1] = *(int*)&cameraPoint.m_y;
            quad[2] = *(int*)&projected.m_x;
            quad[3] = *(int*)&projected.m_y;

            float result[2];
            fn_8002503C(quadPtr, result, width, height);

            int x = (unsigned short)(int)result[0];
            int y = (unsigned short)(int)result[1];

            if (y >= (unsigned short)heightInt) {
                y = (unsigned short)heightInt;
                --y;
            }
            if ((int)y < 0)
                y = 0;
            if (x >= (unsigned short)widthInt) {
                x = (unsigned short)widthInt;
                --x;
            }
            if ((int)x < 0)
                x = 0;

            x &= ~1;
            y &= ~1;
            if (x + 4 >= (unsigned short)widthInt) {
                x = (unsigned short)widthInt;
                x -= 4;
            }
            if (y + 4 >= (unsigned short)heightInt) {
                y = (unsigned short)heightInt;
                y -= 4;
            }

            fn_801F1564(x, y, 4, 4);
            fn_801F15C8(4, 4, 6, 0);
            fn_801F1E60(lbl_804951C0 + i * 0x40, 0);
            *(&lbl_805A0024 + i) = 0;
        }
    }
}
