#include <so/so_module_accesser.h>
#include <it/item.h>
#pragma force_active on

extern "C" {
extern const char lbl_122_data_168[], lbl_122_data_774[], lbl_122_data_8554[], lbl_122_data_8C98[];
extern const float lbl_122_rodata_C, lbl_122_rodata_4;
void* __dynamic_cast(void*, long, const void*, const void*, short);
Vec3f* fn_122_D580(Vec3f*, float, float, float);
void fn_27_28E108(BaseItem*, float, Vec3f*, float);
void fn_27_28E48C(BaseItem*, Vec3f*, float);
}

class GlowModule {
public:
    virtual void slot08();
    virtual void slot0c();
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual void slot1c();
    virtual unsigned int get();
};

struct Params {
    char pad[8];
    float x1, y1, x2, y2, x3, y3;
};

struct Data {
    char pad[0x7c];
    Params* params;
};

extern "C" int fn_122_E2B0(void* object, void*, soModuleAccesser* accesser) {
    BaseItem* item = static_cast<BaseItem*>(__dynamic_cast(
        object, 0, lbl_122_data_168, lbl_122_data_8554, 0));
    if (!item)
        return 0;

    char* cast = static_cast<char*>(__dynamic_cast(
        accesser->m_stageObject, 0x3c, lbl_122_data_774, lbl_122_data_8C98, 0));
    if (!cast)
        return 0;

    Data* data = *reinterpret_cast<Data**>(cast + 0x2d03c);
    if (accesser->getStatusModule().getStatusKind() == 0x12d) {
        Vec3f velocity;
        fn_122_D580(&velocity, data->params->x2, data->params->y2, lbl_122_rodata_C);

        switch (accesser->getMotionModule().getKind()) {
        case 0x1de:
        case 0x1e4:
            velocity.m_x = data->params->x1;
            velocity.m_y = data->params->y1;
            break;
        case 0x1df:
        case 0x1e5:
            velocity.m_x = data->params->x3;
            velocity.m_y = data->params->y3;
            break;
        }

        if (accesser->getPostureModule().getLr() < lbl_122_rodata_C)
            velocity.m_x = -velocity.m_x;

        fn_27_28E108(item, accesser->getPostureModule().getLr(), &velocity, lbl_122_rodata_4);

        if (static_cast<GlowModule*>(accesser->m_enumerationStart->m_glowModule)->get() == 1) {
            int value = accesser->getWorkManageModule().getInt(0x10000040);
            int total = item->getGlowAttack();
            total += value;
            item->setGlowAttack(total);
        }
    } else {
        data = reinterpret_cast<Data*>(&accesser->getPostureModule());
        Vec3f velocity;
        Vec3f* p = fn_122_D580(
            &velocity, lbl_122_rodata_C, lbl_122_rodata_C, lbl_122_rodata_C);
        fn_27_28E48C(item, p, reinterpret_cast<soPostureModule*>(data)->getLr());
    }

    return 1;
}
