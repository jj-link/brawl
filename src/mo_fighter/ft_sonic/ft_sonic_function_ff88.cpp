#include <types.h>
#pragma force_active on

namespace {
struct SonicRecord {
    u8 data[8];
};

class SonicRecordProvider {
public:
    virtual void slot08();
    virtual SonicRecord* getRecord(int index);
};

struct SonicRecordHolder {
    u8 vptr[4];
    SonicRecordProvider* next;
    SonicRecord* array;
    int count;
};
}

extern "C" SonicRecord* fn_123_FF88(SonicRecordHolder* self, int index) {
    if (index >= self->count && self->next != 0) {
        return self->next->getRecord(index - self->count);
    }
    return &self->array[index];
}
