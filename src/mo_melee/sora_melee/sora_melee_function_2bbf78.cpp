#include <types.h>
#pragma force_active on

struct Data {
    s32 a;
    s32 b;
    s16 c;
    s16 d;
};

struct Entry {
    Data data;
    s32 reserved[2];
};

class List {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual s32 size();

    s32 header[2];
    Entry entries[1];
};

extern "C" s32 fn_27_2BBB0C(List*, s32, s32);

extern "C" void fn_27_2BBF78(List* self, const Data* value) {
    s32 idx = fn_27_2BBB0C(self, self->size() - 1, -1);
    if (idx >= 0) {
        self->entries[idx].data = *value;
    }
}
