#include <types.h>
#pragma force_active on

struct Entry {
    void* unk0;
    s32 unk4;
    s32 id;
};

struct Array {
    virtual void v0();
    virtual void v1();
    virtual Entry* get(s32 index);
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void select(s32 index);
};

struct Object {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual s32 size();
    void* pad0;
    void* pad1;
    void* pad2;
    Array array;
};

extern "C" void fn_27_1AC5D8(Object* self, s32 id) {
    s32 result;
    if (id <= -1) {
        result = -1;
    } else {
        s32 count = self->size();
        s32 i;
        result = 0;
        for (i = 0; i < count; i++) {
            if (self->array.get(i)->id == id) {
                result = i;
                goto exit;
            }
        }
        result = -1;
    }
exit:
    if (result >= 0) {
        self->array.select(result);
    }
}
