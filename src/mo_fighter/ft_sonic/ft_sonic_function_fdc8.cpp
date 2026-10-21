#include <types.h>
#pragma force_active on

namespace {
class ProviderBase {
public:
    virtual void slot00();
    virtual void slot04();
    virtual void slot08();
    virtual void slot0C();
    virtual bool isEmpty();
    virtual void slot14();
    virtual void advance();
};

class RecordHolder : public ProviderBase {
public:
    ProviderBase* next;
    u8* cursor;
    int count;
};
} // namespace

extern "C" void fn_123_FDC8(RecordHolder* self) {
    if (self->isEmpty()) {
        return;
    }
    int remaining = self->count;
    if (remaining > 0) {
        remaining -= 1;
        self->count = remaining;
        if (remaining <= 0) {
            self->cursor = 0;
        } else {
            self->cursor = self->cursor + 8;
        }
    } else if (self->next != 0) {
        self->next->advance();
    }
}
