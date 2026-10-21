#include <types.h>
#pragma force_active on

class Arr {
public:
    virtual void v0();
    virtual void* at(s32 i);
    virtual void v2();
    virtual s32 size();
};

struct Obj {
    u8 pad[4];
    Arr* m_arr;
};

extern "C" {

u32 fn_27_C41A8(void* self);

s32 fn_27_C3C54(Obj* self, s32 arg) {
    Arr* arr = self->m_arr;
    if (arr == 0) {
        return 0;
    }
    s32 n = arr->size();
    for (s32 i = 0; i < n; i++) {
        void* e = self->m_arr->at(i);
        if (arg == (s32)fn_27_C41A8(e)) {
            return 1;
        }
    }
    return 0;
}

}
