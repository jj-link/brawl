#include <so/so_module_accesser.h>
#include <so/so_value_accesser.h>
#include <mt/mt_vector.h>
#include <math.h>

#pragma force_active on

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual Vec3f slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual float slot9();
};

extern "C" {
extern const char lbl_96_data_608[], lbl_96_data_68D8[];
extern const float lbl_96_rodata_48[];

void* __dynamic_cast(void*, long, const void*, const void*, short);
void* fn_96_B488(void*);
void fn_96_14960(Vec3f*, const Vec3f*);
Vec3f* fn_96_BC54(Vec3f*, float, float, float);
}

extern "C" void fn_96_154C0(soModuleAccesser* accesser) {
    Vec3f end, start, hitnormal, pos, hit;
    const float* k = lbl_96_rodata_48;
    soGroundModule* ground = accesser->m_enumerationStart->m_groundModule;
    Object_vptr_0* posture =
        (Object_vptr_0*)accesser->m_enumerationStart->m_postureModule;
    float* data = (float*)fn_96_B488(__dynamic_cast(
        accesser->m_stageObject, 0x3c, lbl_96_data_608,
        lbl_96_data_68D8, 1));

    Vec3f tmp = posture->slot4();
    Vec3f diff;
    fn_96_14960(&pos, &tmp);

    Vec2f normal = ground->getTouchNormal((grCollStatus::TouchMask)8, 0);
    float y = normal.m_y;
    float x = normal.m_x;
    data[0] = x;
    data[1] = y;
    data[2] = k[1];

    Object_vptr_0* posture2 =
        (Object_vptr_0*)accesser->m_enumerationStart->m_postureModule;
    float angle = atan2f(data[0], data[1]);
    data[3] = angle * posture2->slot9();

    if (k[1] != data[0]) {
        float value = soValueAccesser::getConstantFloat(accesser, 0xfb6, 0);

        start.m_x = pos.m_x;
        start.m_y = pos.m_y + value;
        end.m_x = pos.m_x + data[1] * value * (data[0] > k[1] ? k[0] : k[8]);
        end.m_y = pos.m_y - value;
        end.m_z = k[1];
        start.m_z = k[1];

        Vec3fSub(&diff, &end, &start);
        if (!ground->rayCheck(&start, &diff, &hit, &hitnormal, true)) {
            Vec3f v;
            fn_96_14960(&hitnormal, fn_96_BC54(&v, k[1], k[0], k[1]));
        }

        if ((data[0] > k[1] && hitnormal.m_x < k[1]) ||
            (data[0] <= k[1] && hitnormal.m_x > k[1])) {
            Vec3f v;
            fn_96_14960((Vec3f*)data, fn_96_BC54(&v, k[1], k[0], k[1]));
            data[3] = k[1];
            data[0x25] = k[1];
            data[0x26] = k[1];
        }
    }
}
