#include <types.h>
#pragma force_active on

namespace {
class DededeArticleRecordSource {
public:
    virtual void slot08();
    virtual void slot0C();
    virtual void slot10();
    virtual int slot14();
};

struct DededeArticleRecordHolder {
    u8 vptr[4];
    DededeArticleRecordSource* next;
    int enabled;
    int count;
};
}

extern "C" int fn_117_181A8(DededeArticleRecordHolder* self) {
    int count = self->count;
    if (self->enabled == 0) {
        count = 0;
    }

    if (self->next != 0) {
        return count + self->next->slot14();
    }
    return count;
}
