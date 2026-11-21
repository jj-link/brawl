#include <types.h>
#include <mt/mt_vector.h>

#pragma force_active on

struct Entry {
    void* pad;
    void* ptr;
};

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual Entry* slot1(int);
};

struct Self {
    char pad[0x28];
    Object_vptr_0* array;
};

extern "C" u32 fn_80134344(void*, u32);
extern "C" void fn_80135BAC(void*, u32, Vec2f*);
extern "C" void fn_8003DBA8(Vec2f*);
extern const float lbl_27_rodata_3C0[];

inline float measure(Vec2f v) { return v.lengthSq(); }

extern "C" Vec2f fn_27_279A4(Self* self, u32 flags, int index) {
    const float* k = lbl_27_rodata_3C0;
    Vec2f result(k[1], k[1]);
    Vec2f out;

    if (flags == 8) {
        fn_80135BAC(self->array->slot1(index)->ptr, 3, &result);
    } else {
        u32 i = 0;

        for (u32 mask = 1; mask <= 0xff; mask <<= 1, ++i) {
            if ((flags & mask) &&
                fn_80134344(self->array->slot1(index)->ptr, i) == 1) {
                fn_80135BAC(self->array->slot1(index)->ptr, i, &out);
                float y;
                float x;
                x = result.m_x + out.m_x;
                y = result.m_y + out.m_y;
                if (measure(Vec2f(x, y)) > k[4]) {
                    result.m_x = x;
                    result.m_y = y;
                }
            }
        }

        if (!(k[1] == result.m_x && k[1] == result.m_y)) {
            fn_8003DBA8(&result);
        }
    }

    if (k[1] == result.m_x && k[1] == result.m_y) {
        result.m_y = k[0];
    }

    return result;
}