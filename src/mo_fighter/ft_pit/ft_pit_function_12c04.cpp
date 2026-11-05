#include <cm/cm_camera_controller.h>
#include <so/so_value_accesser.h>
#include <so/posture/so_posture_module_simple.h>
#include <so/ground/so_ground_module_impl.h>
#include <so/work/so_work_manage_module_impl.h>
#include <so/kinetic/so_kinetic_module_impl.h>
#include <mt/mt_prng.h>
#pragma force_active on
extern "C" {
extern const unsigned char lbl_112_rodata_68[];
extern char lbl_112_data_8C28[], lbl_112_data_1CEC[];
void* __dynamic_cast(void*, long, const void*, const void*, short);
}
struct Bounds { float left, right, top, bottom; };
struct Energy { char pad[8]; float x,y,z; };
inline void setDirection(float value, soModuleAccesser* a) { a->getWorkManageModule().setFloat(value, 0x21000000); }
extern "C" void fn_112_12C04(void*, soModuleAccesser* a) {
    Bounds rect = *reinterpret_cast<Bounds*>(CameraController::getInstance()->_328);
    Vec2f center;
    Vec2f size;
    size.m_x = 0.5f * (rect.right - rect.left);
    size.m_y = 0.5f * (rect.top - rect.bottom);
    center.m_x = rect.left + size.m_x;
    center.m_y = rect.bottom + size.m_y;
    size.m_x *= soValueAccesser::getConstantFloat(a, 0xfa0, 0);
    size.m_y *= soValueAccesser::getConstantFloat(a, 0xfa1, 0);
    center.m_y += 2.0f * size.m_y * soValueAccesser::getConstantFloat(a, 0xfa2, 0);
    rect.left = center.m_x - size.m_x;
    rect.bottom = center.m_y - size.m_y;
    Vec3f pos = a->getPostureModule().getPos();
    setDirection(pos.m_x < center.m_x ? 1.0f : -1.0f, a);
    float angle = a->getWorkManageModule().getFloat(0x21000001);
    Vec2f base;
    if (angle <= 1.5707963705062866f) { base.m_x = center.m_x; base.m_y = center.m_y; }
    else if (angle <= 3.1415927410125732f) { base.m_x = rect.left; base.m_y = center.m_y; }
    else if (angle <= 4.71238899230957f) { base.m_x = rect.left; base.m_y = rect.bottom; }
    else { base.m_x = center.m_x; base.m_y = rect.bottom; }
    Vec2f target;
    target.m_x = base.m_x + size.m_x * randf();
    target.m_y = base.m_y + size.m_y * randf();
    float frames = static_cast<float>(soValueAccesser::getConstantInt(a, 0x5dc0, 0));
    float scale = 1.0f / frames;
    Vec3f speed;
    speed.m_x = scale * (target.m_x - pos.m_x);
    speed.m_y = scale * (target.m_y - pos.m_y);
    speed.m_z = scale * (a->getGroundModule().getZ() - pos.m_z);
    Energy* energy = static_cast<Energy*>(__dynamic_cast(a->getKineticModule().getEnergy(0), 0, lbl_112_data_8C28, lbl_112_data_1CEC, 1));
    energy->x = speed.m_x;
    energy->y = speed.m_y;
    energy->z = speed.m_z;
}