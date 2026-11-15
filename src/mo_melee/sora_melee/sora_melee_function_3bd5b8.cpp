#include <types.h>
#include <mt/mt_vector.h>
#include <so/so_enable.h>
#include <so/so_null.h>
#pragma force_active on

extern "C" float fn_27_192278(void*, unsigned long);
struct soModuleAccesser;

class soEnergyBase : public soNullable, public soEnable {
public:
    virtual void slot1(soModuleAccesser*);
    virtual Vec2f slot2();
    u8 suspended;
    Vec2f speed;
};

extern "C" void fn_27_3BD5B8(soEnergyBase* self, void* arg, soModuleAccesser* accesser) {
    self->speed = Vec2f(self->slot2().m_x * fn_27_192278(accesser, 0xfa2), self->slot2().m_y);
    if (self->isEnable() == true && self->suspended == 0) {
        self->slot1(accesser);
    }
}