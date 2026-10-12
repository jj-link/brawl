#include <so/so_module_accesser.h>
#include <so/stageobject.h>

extern "C" {
extern const unsigned char lbl_101_data_7F90[], lbl_101_data_4330[];
extern const unsigned char lbl_101_data_9840[], lbl_101_data_3890[];
void* __dynamic_cast(void*, long, const void*, const void*, short);
Vec2f* fn_101_FE5C(Vec2f*, const Vec2f*);
}

extern "C" void fn_101_24250(void*, soModuleAccesser* accesser) {
    unsigned char* object = static_cast<unsigned char*>(__dynamic_cast(
        accesser->m_stageObject, 0x3C, lbl_101_data_7F90, lbl_101_data_4330, 1));
    const float* parameters = *reinterpret_cast<const float**>(object + 0x2168);
    float lr = accesser->getPostureModule().getLr();
    Vec2f speed;
    speed.m_x = parameters[3] * lr;
    speed.m_y = parameters[6];
    Vec2f acceleration;
    acceleration.m_x = parameters[4] * lr;
    acceleration.m_y = -parameters[7];
    Vec2f limit;
    limit.m_x = parameters[5];
    limit.m_y = parameters[8];
    unsigned char* energy = static_cast<unsigned char*>(__dynamic_cast(
        accesser->getKineticModule().getEnergy(0),
        0, lbl_101_data_9840, lbl_101_data_3890, 1));
    fn_101_FE5C(reinterpret_cast<Vec2f*>(energy + 0x08), &speed);
    fn_101_FE5C(reinterpret_cast<Vec2f*>(energy + 0x10), &acceleration);
    fn_101_FE5C(reinterpret_cast<Vec2f*>(energy + 0x18), &limit);
    fn_101_FE5C(reinterpret_cast<Vec2f*>(energy + 0x28), &limit);
    energy[5] |= 0x80;
    accesser->getStageObject().updateNodeSRT();
}
