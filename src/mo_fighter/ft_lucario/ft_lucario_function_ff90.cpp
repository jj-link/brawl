#include <so/kinetic/so_kinetic_energy.h>
#pragma force_active on
class Class_1500 {
public:
    virtual void fn_118_6D04(); virtual void fn_118_1A20(); virtual void fn_118_A2DC(); virtual void fn_118_A2D4(); virtual void fn_118_A2CC(); virtual void fn_118_A2C4(); virtual void* fn_118_A2BC();
};
extern "C" {
extern const char lbl_118_data_6708[], lbl_118_data_620C[], lbl_118_data_17B0[];
void* __dynamic_cast(void*, long, const void*, const void*, short);
void fn_118_C3EC(void*, const Vec2f*);
}
extern "C" void fn_118_FF90(Class_1500* obj, int kind, float x, float y) {
    switch (kind) {
    case 1: {
        soKineticEnergy* energy = static_cast<soKineticEnergy*>(__dynamic_cast(obj->fn_118_A2BC(), 0, lbl_118_data_6708, lbl_118_data_17B0, 1));
        Vec2f speed = energy->getSpeed();
        reinterpret_cast<Vec2f*>(reinterpret_cast<char*>(energy) + 8)->m_y = speed.m_y * y;
        break;
    }
    default: {
        soKineticEnergy* energy = static_cast<soKineticEnergy*>(__dynamic_cast(obj->fn_118_A2BC(), 0, lbl_118_data_620C, lbl_118_data_17B0, 1));
        Vec2f result = energy->getSpeed();
        result.m_x *= x;
        result.m_y *= y;
        fn_118_C3EC(reinterpret_cast<char*>(energy) + 8, &result);
        break;
    }
    }
}