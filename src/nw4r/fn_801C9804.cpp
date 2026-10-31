#include <types.h>
#pragma force_active on

extern "C" {

class Thing {
public:
    virtual void slot0() = 0;
    virtual void slot1() = 0;
    virtual s32 getResult() = 0;
};

class Other {
public:
    virtual void slot0() = 0;
    virtual s32 getResult(s32 arg) = 0;
};

s32 fn_801C6C24(Thing* self, s32 idx, u32 value, u32* out);
s32 fn_801C6C2C(Thing* self, s32 arg, u32* out);
s32 fn_801C6C34(Thing* self, s32 arg, u32 i, u32* out);

struct Entry {
    u32 count;
    u32 pad;
};

struct Obj {
    u8 pad[0x10];
    Thing* obj;
    Entry* entries;
    Other* other;
};

s32 fn_801C9804(Obj* self, s32 arg) {
    u32 resultData[8];
    u32 queryData[4];
    u32 itemData[2];
    s32 value;
    u32 i;
    s32 result;
    Entry* entries;
    u32 index;

    result = self->obj->getResult();
    if (result != 0) {
        return result;
    }
    if (self->other != 0) {
        result = self->other->getResult(arg);
        if (result != 0) {
            return result;
        }
    }
    if (fn_801C6C2C(self->obj, arg, queryData) == 0) {
        return 0;
    }
    for (i = 0; i < queryData[3]; i++) {
        if (fn_801C6C34(self->obj, arg, i, itemData) != 0) {
            index = itemData[0];
            entries = self->entries;
            if (entries == 0) {
                value = 0;
            } else if (index >= entries->count) {
                value = 0;
            } else {
                value = ((s32*)entries)[index * 2 + 2];
            }
            if (value != 0 &&
                fn_801C6C24(self->obj, index, itemData[1], resultData) != 0) {
                return value + resultData[3];
            }
        }
    }
    return 0;
}

}
