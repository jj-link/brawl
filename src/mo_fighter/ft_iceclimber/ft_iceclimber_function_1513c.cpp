#include <types.h>
#include <so/so_module_accesser.h>
#pragma force_active on

extern "C" {
void fn_105_1553C(void*, soModuleAccesser*);
void fn_105_15658(void*, soModuleAccesser*);
void fn_105_BD50(void*, int, float, float, unsigned char, unsigned char, int, unsigned char);
Vec3f* fn_105_C1C0(Vec3f*, float, float, float);
extern float lbl_105_rodata_68;
extern float lbl_105_rodata_6C;
}

struct BD50Data {
    int field0;
    float field1;
    float field2;
    unsigned char field3;
    unsigned char field4;
    unsigned char field5;
    unsigned char field6;
};

extern "C" void fn_105_1513C(void* self, soModuleAccesser* accesser) {
    if (accesser->getWorkManageModule().isFlag(0x22000011) == true) {
        BD50Data data;
        accesser->getWorkManageModule().offFlag(0x22000011);
        float frame = lbl_105_rodata_68;
        int flag = 0;
        if (accesser->getMotionModule().getKind() == 0x1E9) {
            frame = accesser->getMotionModule().getFrame();
            flag = 1;
        }
        fn_105_BD50(&data, 0x1E5, frame, lbl_105_rodata_6C, 0, 0, flag, 0);
        accesser->getMotionModule().changeMotionRequest(reinterpret_cast<soMotionChangeParam*>(&data));
    } else if (accesser->getWorkManageModule().isFlag(0x22000012) == true) {
        BD50Data data;
        accesser->getWorkManageModule().offFlag(0x22000012);
        float frame = lbl_105_rodata_68;
        int flag = 0;
        if (accesser->getMotionModule().getKind() == 0x1E5) {
            frame = accesser->getMotionModule().getFrame();
            flag = 1;
        }
        fn_105_BD50(&data, 0x1E9, frame, lbl_105_rodata_6C, 0, 0, flag, 0);
        accesser->getMotionModule().changeMotionRequest(reinterpret_cast<soMotionChangeParam*>(&data));
    }

    if (accesser->getWorkManageModule().isFlag(0x22000010) == true) {
        accesser->getWorkManageModule().offFlag(0x22000010);
        fn_105_1553C(self, accesser);
        bool isNormal = true;
        Vec3f vec;
        soModelModule& model = accesser->getModelModule();
        model.setNodeTranslate(2, fn_105_C1C0(&vec, lbl_105_rodata_68, lbl_105_rodata_68, lbl_105_rodata_68));
        if (accesser->getMotionModule().getKind() != 0x1E9) {
            if (accesser->getGroundModule().attachGround(0) == 1) {
                isNormal = false;
                accesser->getSituationModule().setKind(static_cast<SituationKind>(0), isNormal);
                accesser->getStatusModule().changeStatusRequest(0, accesser);
            }
        }
        if (isNormal == true) {
            fn_105_15658(self, accesser);
            accesser->getSituationModule().setKind(static_cast<SituationKind>(2), false);
            accesser->getStatusModule().changeStatusRequest(0xE, accesser);
        }
    }
}
