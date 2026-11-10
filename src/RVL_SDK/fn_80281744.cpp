#include <types.h>
#pragma force_active on
class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual u32 slot2();
};
struct State {
    char pad[8];
    Object_vptr_0* object;
    char padC[4];
    void* first;
    void* last;
};
extern "C" u32 fn_80281744(State* self) {
    u32 result;
    if (self->object) {
        result = self->object->slot2() >> 24;
    } else {
        result = self->first != self->last;
    }
    return result << 24;
}