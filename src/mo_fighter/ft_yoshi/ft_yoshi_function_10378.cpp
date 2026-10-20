#include <so/so_module_accesser.h>
#pragma force_active on

extern "C" {
extern unsigned char g_ftCommonDataAccesser;
void* getData__20ftCommonDataAccesserCF6ftKind(const void*, int);
float fn_95_A8B4(float);
extern const float lbl_95_rodata_6C;
}

struct YoshiSpecialData {
    char pad0[8];
    int decrement;
    char padC[0x28];
    float groundSpeed;
    char pad38[0xC];
    float airSpeed;
    char pad48[0x3C];
    float brake;
};

struct YoshiData {
    char pad[0x7C];
    YoshiSpecialData* special;
};

extern "C" void fn_95_10378(soModuleAccesser* accesser) {
    soWorkManageModule& work = accesser->getWorkManageModule();
    soSituationModule& situation = accesser->getSituationModule();
    YoshiSpecialData* data =
        ((YoshiData*)getData__20ftCommonDataAccesserCF6ftKind(
            &g_ftCommonDataAccesser, 4))->special;

    int value = work.getInt(0x20000000);
    int other = work.getInt(0x20000003);
    float limit;
    float speed = work.getFloat(0x21000006);

    if (accesser->getStatusModule().getStatusKind() == 0x119) {
        value -= data->decrement;

        if (situation.getKind() == 2) {
            limit = data->airSpeed;
        } else {
            limit = data->groundSpeed;
        }

        if (fn_95_A8B4(speed) > limit) {
            if (speed > lbl_95_rodata_6C) {
                speed -= data->brake;
                if (speed < limit) {
                    speed = limit;
                }
            } else {
                speed += data->brake;
                if (speed > -limit) {
                    speed = -limit;
                }
            }
        } else if (lbl_95_rodata_6C == speed) {
            speed = limit * accesser->getPostureModule().getLr();
        }
    }

    work.setInt(value, 0x20000000);
    work.setInt(other, 0x20000003);
    work.setFloat(speed, 0x21000006);
}
