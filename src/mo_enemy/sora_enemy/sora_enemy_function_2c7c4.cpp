#include <ft/ft_external_value_accesser.h>
#include <mt/mt_vector.h>
#include <nw4r/ut/ut_algorithm.h>
#pragma force_active on

extern "C" {

extern const float lbl_41_rodata_DF8;
Fighter* fn_41_237A8(int);

// The compiler-generated constant pool still has a different relocation symbol.
Fighter* fn_41_2C7C4(const Vec2f* pos, float range) {
    int ids[4] = {0, 1, 2, 3};
    float closest = 3.402823466e38f;
    Fighter* result = 0;

    for (int i = 0; i < 4; ++i) {
        Fighter* fighter = fn_41_237A8(ids[i]);
        if (fighter) {
            Vec3f hip = ftExternalValueAccesser::getHipPos(fighter);
            Vec2f b;
            Vec2f a;
            a.m_x = hip.m_x;
            a.m_y = hip.m_y;
            b.m_x = pos->m_x;
            b.m_y = pos->m_y;

            Vec2f d;
            d.m_x = (float)b.m_x - (float)a.m_x;
            d.m_y = (float)b.m_y - (float)a.m_y;
            float sq = (float)d.m_x * (float)d.m_x
                     + (float)d.m_y * (float)d.m_y;
            float dist;

            if ((float)(double)nw4r::ut::Abs(sq) <= 1.17549435e-38f)
                dist = 0.0f;
            else
                dist = sq * rsqrtf(sq);

            if (!(range < dist) && closest > dist) {
                result = fighter;
                closest = dist;
            }
        }
    }

    return result;
}

}
