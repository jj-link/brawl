#include <types.h>
#pragma force_active on

namespace {
class DededeArticleRecordProvider {
public:
    virtual void slot08();
    virtual void slot0C();
    virtual void slot10();
    virtual int getTotalCount();
    virtual bool isEmpty();
};
}

extern "C" bool fn_117_18250(DededeArticleRecordProvider* self) {
    return self->getTotalCount() == 0;
}
