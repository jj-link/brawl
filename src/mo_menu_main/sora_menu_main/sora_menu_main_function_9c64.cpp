#include <mt/mt_vector.h>
#include <nw4r/math/math_arithmetic.h>
#pragma force_active on

extern "C" {
extern const float lbl_2_rodata_218[];
extern char lbl_2_data_1360[];
extern char lbl_2_data_718[];

void* getInstance__16CameraControllerFv();
void* __dynamic_cast(void*, long, const void*, const void*, long);
float rsqrtf__Ff(float);
void fn_1_6D74(void*, void*);
void fn_1_6D60(void*, void*);
}

extern "C" void fn_2_9C64(char* self) {
    const float* constants = lbl_2_rodata_218;
    Vec3f camera, target, pos;
    Vec2f target2, camera2, disp;
    unsigned char flags[4];
    char* cam = *(char**)__dynamic_cast(
        *(void**)((char*)getInstance__16CameraControllerFv() + 0x48),
        4, lbl_2_data_1360, lbl_2_data_718, 0);

    if (*(unsigned int*)(self + 0x238) > 1U) {
        unsigned char* out = flags;
        char* p = self + 0x4C;
        char* row = self;
        int k;

        for (k = 0; k < 4; k++) {
            out[0] = 0;
            if ((*(unsigned char*)p >> 7) & 1) {
                if (*(int*)(row + 0x2EC) <= 0) {
                    out[0] = 1;
                } else {
                    int n = --*(int*)(row + 0x2EC);
                    if (n % 16 >= 8 || n <= 0) {
                        out[0] = 1;
                    }
                }
            }
            out++;
            p += 0x14;
            row += 4;
        }

        camera = *(Vec3f*)(cam + 0x6C);
        camera2.m_x = camera.m_x;
        camera2.m_y = camera.m_z;

        void* mdl;
        unsigned char* f = flags;
        unsigned char* r;
        char* e = self;
        char* m = self;
        int j;
        int i;

        for (i = 0; i < 4; i++) {
            if (*f != 0) {
                char* mdl = *(char**)(m + 0xF8);
                float z, x;
                x = *(float*)(e + 0x54);
                z = *(float*)(e + 0x58);
                target.m_x = x;
                target.m_z = z;
                pos = *(Vec3f*)(mdl + 0x3C);
                target.m_y = pos.m_y;

                if (pos.m_y <= camera.m_y &&
                    constants[0x14C / 4] + pos.m_y >= camera.m_y) {
                    target2.m_x = target.m_x;
                    target2.m_y = target.m_z;
                    float dy, dx;
                    dx = target2.m_x - camera2.m_x;
                    dy = target2.m_y - camera2.m_y;
                    disp.m_x = dx;
                    disp.m_y = dy;
                    float sq = disp.lengthSq();
                    float len;

                    if ((float)(double)nw4r::math::FAbs(sq) <= constants[0x150 / 4]) {
                        len = constants[0x88 / 4];
                    } else {
                        len = sq * rsqrtf(sq);
                    }

                    if (len < constants[0x14C / 4]) {
                        *f = 0;
                    }
                }
            }
            f += 1;
            e += 0x14;
            m += 4;
        }

        r = flags;
        f = (unsigned char*)self;

        for (j = 0; j < 4; j++) {
            mdl = *(void**)(f + 0x168);
            fn_1_6D74(*(void**)(self + 0x40), mdl);
            if (*r != 0) {
                fn_1_6D60(*(void**)(self + 0x40), mdl);
            }
            f += 4;
            r += 1;
        }
    }
}
