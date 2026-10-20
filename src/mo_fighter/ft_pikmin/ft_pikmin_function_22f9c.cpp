#include <StaticAssert.h>
#include <types.h>
#pragma force_active on

namespace {
struct PikminRecordProvider {
    virtual void slot08();
    virtual void slot0C();
    virtual void slot10();
    virtual void slot14();
    virtual int slot18();
    virtual void slot1C();
    virtual void slot20();
    virtual void slot24();
};

struct PikminRecordHolder {
    u8 vptr[4];
    PikminRecordProvider* next;
    void* array;
    int count;
};
static_assert(sizeof(PikminRecordHolder) == 0x10, "Holder view layout");
} // namespace

extern "C" void fn_113_22F9C(PikminRecordHolder* self) {
    if (self->next != 0 && self->next->slot18() == 0) {
        self->next->slot24();
    } else {
        if (self->count > 0) {
            self->count = self->count - 1;
        }
    }
}
