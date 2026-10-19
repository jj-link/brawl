#include <types.h>
#pragma force_active on

namespace {
struct DededeArticleRecordProvider {
    virtual void slot08();
    virtual void slot0C();
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual void slot1C();
    virtual void slot20();
    virtual void slot24();
    virtual void slot28();
};

struct DededeArticleRecordHolder {
    u8 vptr[4];
    DededeArticleRecordProvider* next;
    void* array;
    int count;
};
}

extern "C" void fn_117_18158(DededeArticleRecordHolder* self) {
    if (self->next != 0) {
        self->next->slot28();
    }
    self->array = 0;
    self->count = 0;
}
