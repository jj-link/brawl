#include <so/so_module_accesser.h>
#include <so/so_value_accesser.h>
#include <so/controller/so_controller_module_impl.h>
#include <so/stageobject.h>
#pragma force_active on

extern "C" {
void* __memcpy(void*, const void*, unsigned long);
extern unsigned char lbl_27_bss_466C[0xC];
extern const float lbl_27_rodata_1FC0;
s32 fn_27_14DF14(void* unused, s32 kind, s32 idx);
void fn_27_89D08(int, soModuleAccesser*, int, Vec2f*, Vec3f*);
}

extern "C" void fn_27_161C90(int, int, const Vec2f* input, soModuleAccesser* accesser) {
    Vec2f speed;
    __memcpy(&speed, input, sizeof(speed));
    int kind = accesser->getStageObject().soGetSubKind();
    if (fn_27_14DF14(lbl_27_bss_466C, kind, 5) == 2) {
        void* p = soValueAccesser::getConstantIndefinite(accesser, 0xA80A, 0);
        speed.m_x = *(float*)((char*)p + 0x8) * accesser->getControllerModule().getStickX();
        speed.m_y = soValueAccesser::getConstantFloat(accesser, 0xD8F, 0) * **(float**)((char*)p + 0x10);
    } else {
        float c1 = soValueAccesser::getConstantFloat(accesser, 0xBCA, 0);
        speed.m_x = c1 * accesser->getControllerModule().getStickX();
        float c3c2 = soValueAccesser::getConstantFloat(accesser, 0xBC9, 0) * soValueAccesser::getConstantFloat(accesser, 0xD8F, 0);
        speed.m_y = c3c2 * soValueAccesser::getConstantFloat(accesser, 0xBC5, 0);
    }

    Vec2f motion;
    Vec2f gravity;
    Vec3f zero2;
    Vec3f zero1;

    gravity.m_y = speed.m_y;
    zero1.m_x = lbl_27_rodata_1FC0;
    zero1.m_y = lbl_27_rodata_1FC0;
    zero1.m_z = lbl_27_rodata_1FC0;
    gravity.m_x = lbl_27_rodata_1FC0;
    fn_27_89D08(1, accesser, 0, &gravity, &zero1);

    float sx = speed.m_x;
    zero2.m_x = lbl_27_rodata_1FC0;
    zero2.m_y = lbl_27_rodata_1FC0;
    zero2.m_z = lbl_27_rodata_1FC0;
    motion.m_x = sx;
    motion.m_y = lbl_27_rodata_1FC0;
    fn_27_89D08(2, accesser, 0, &motion, &zero2);
}
