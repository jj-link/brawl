#include <StaticAssert.h>
#include <types.h>
#pragma force_active on

namespace {
class PikminEntity {
public:
    virtual void slot08();
    virtual void slot0C();
    virtual void slot10();
    virtual int slot14();
};

struct PikminData {
    u32 _field0;
    PikminEntity* entity;
    u32 flag;
    s32 base;
};
} // namespace

extern "C" s32 fn_113_23064(PikminData* self) {
    s32 base = self->base;
    if (!self->flag)
        base = 0;
    if (self->entity) {
        return base + self->entity->slot14();
    }
    return base;
}
