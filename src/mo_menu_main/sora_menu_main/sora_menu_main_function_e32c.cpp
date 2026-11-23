#include <mt/mt_matrix.h>
#include <cm/cm_camera_controller.h>
#pragma force_active on

extern "C" {
void* __dynamic_cast(void*, long, const void*, const void*, long);
void fn_1_6DB4(void*, void*);
void fn_2_B918(void*, int);
void fn_800B330C(void*, void*, int);
float fn_2_B184(void*, int, float, float);
Matrix fn_2_A618(void*, int);
void fn_800B6838(void*, Vec3f*);
void fn_800A970C(void*, void*);
}

extern char lbl_2_data_1360[];
extern char lbl_2_data_718[];
extern char lbl_2_data_127C[];
extern const float lbl_2_rodata_2A0;
extern const float lbl_2_rodata_370;

static inline void setPos(Vec3f& p, float x, float y, float z) {
    p.m_x = x;
    p.m_y = y;
    p.m_z = z;
}

extern "C" void fn_2_E32C(char* self) {
    char* cam = (char*)__dynamic_cast(
        *(void**)((char*)CameraController::getInstance() + 0x48),
        4, lbl_2_data_1360, lbl_2_data_718, 0);

    fn_1_6DB4(*(void**)(self + 0x40), *(void**)(self + 0x178));
    self[0x259] = 1;
    fn_2_B918(self, 1);

    int j = 0;
    char* q = self;
    for (; j < 4; j++, q += 4) {
        fn_800B330C(*(void**)(q + 0x108), lbl_2_data_127C, 0);
    }

    float y;
    int i = 0;
    void* obj;
    char* p = self + 0x4c;
    char* v = self;
    char* w = self;

    for (; i < 4; i++, p += 0x14, v += 0x14, w += 4) {
        if (((unsigned char)p[0] >> 7) & 1) {
            float z, x;
            x = *(float*)(v + 0x54);
            z = *(float*)(v + 0x58);
            y = fn_2_B184(self, i, x, z);
            obj = *(void**)(w + 0xf8);
            Matrix m(true);
            m = fn_2_A618(self, i);
            Vec3f out, pos, in;

            in.m_x = lbl_2_rodata_2A0;
            in.m_y = lbl_2_rodata_2A0;
            in.m_z = lbl_2_rodata_2A0;
            m.mulPos(&in, &out);

            setPos(pos, x + out.m_x, lbl_2_rodata_370 + (y + out.m_y), z + out.m_z);
            fn_800B6838(obj, &pos);

            *(float*)(p + 8) = x;
            *(float*)(p + 12) = z;
        }
    }

    void* cam2 = __dynamic_cast(
        *(void**)((char*)CameraController::getInstance() + 0x48),
        4, lbl_2_data_1360, lbl_2_data_718, 0);

    if (*(unsigned char*)(self + 0x2e8) != 0) {
        fn_800A970C(cam2, self + 0x2c0);
    }
    *(int*)(self + 0x2fc) = *(int*)(cam + 0x40);
}
