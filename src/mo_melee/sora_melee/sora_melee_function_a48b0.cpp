#include <types.h>
#pragma force_active on

struct Arr {
    virtual void isNull() const = 0;
    virtual s32 at(s32 i);
    virtual s32 atC(s32 i) const;
    virtual s32 size() const;
};

struct Owner {
    char _pad[0x30];
    Arr* m_arr;
};

extern "C" u32 fn_27_A75B0(s32);

extern "C" s32 fn_27_A48B0(Owner* o, u32 target) {
    s32 end = o->m_arr->size();
    s32 i = 0;
    while (i < end) {
        if (fn_27_A75B0(o->m_arr->at(i)) == target)
            return i;
        i++;
    }
    return -1;
}
