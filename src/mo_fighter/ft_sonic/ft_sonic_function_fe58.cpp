#include <StaticAssert.h>
#include <types.h>
#pragma force_active on

namespace {
struct SonicArticleRecord {
    u8 data[0x6C];
};

class SonicRecordProvider {
public:
    virtual void slot08();
    virtual void slot0C();
    virtual void slot10();
    virtual void slot14();
    virtual int slot18();
    virtual void slot1C();
    virtual void slot20();
    virtual void slot24();
};

struct SonicRecordHolder {
    u8 vptr[4];
    SonicRecordProvider* next;
    SonicArticleRecord* array;
    int count;
};
} // namespace

extern "C" void fn_123_FE58(SonicRecordHolder* self) {
    if (self->next != 0 && self->next->slot18() == 0) {
        self->next->slot24();
    } else {
        if (self->count > 0) {
            self->count = self->count - 1;
        }
    }
}
