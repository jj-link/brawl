#include <types.h>
#pragma force_active on

struct Entry {
    s32 unused;
    s32 id;
};

class Array {
public:
    virtual void v0();
    virtual void v1();
    virtual Entry* at(s32 index);
};

class Object {
public:
    virtual void y0();
    virtual void y1();
    virtual void y2();
    virtual void y3();
    virtual s32 size();
    char pad[12];
    Array m_array;
};

extern "C" s32 fn_27_38FC04(Object* self, s32 id) {
    s32 result;
    if (id <= -1) {
        result = -1;
    } else {
        s32 n = self->size();
        s32 i;
        result = 0;
        for (i = 0; i < n; i++) {
            if (self->m_array.at(i)->id == id) {
                result = i;
                goto exit;
            }
        }
        result = -1;
    }
exit:
    return (u32)result >> 31 ^ 1;
}
