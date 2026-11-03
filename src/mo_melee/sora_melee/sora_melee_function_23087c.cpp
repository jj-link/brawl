// Status: 99.0% match (6 lines differ). Remaining diff: the original has `frsp`
// after `fabs` on the |normal.y| test.
#include <st/st_utility.h>
#include <nw4r/math/math_arithmetic.h>
#pragma force_active on

extern "C" {
extern const float lbl_27_rodata_3798[];
}

extern "C" void fn_27_23087C(void* arg0) {
    Vec3f dir;
    Vec3f hit;
    Vec3f normal;
    Vec3f hit2;

    dir.m_x = lbl_27_rodata_3798[27];
    dir.m_y = lbl_27_rodata_3798[69];
    dir.m_z = lbl_27_rodata_3798[27];

    char* p = (char*)arg0;
    u32 i = 0;
    do {
        Vec3f pos = *(Vec3f*)(p + 0x26C);
        pos.m_y += lbl_27_rodata_3798[28];
        if (stRayCheck(&pos, &dir, &hit, &normal, true, 0, false, 7)) {
            float ay = (float)(double)nw4r::math::FAbs(normal.m_y);
            if (ay < lbl_27_rodata_3798[70]) {
                if (normal.m_x > lbl_27_rodata_3798[27]) {
                    pos.m_x += lbl_27_rodata_3798[49];
                } else {
                    pos.m_x -= lbl_27_rodata_3798[49];
                }
                if (stRayCheck(&pos, &dir, &hit2, &normal, true, 0, false, 7)) {
                    hit = hit2;
                }
            }
            *(Vec3f*)(p + 0x26C) = hit;
        }
        i++;
        p += 12;
    } while (i < 4);
}
