#include <types.h>
#pragma force_active on

struct Ret {
    int pad0;
    int id;
};

struct Sub {
    virtual void v0();
    virtual void v1();
    virtual Ret* get(int idx);
};

struct Base {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual int count();

    int pad4[3];
    Sub m_sub;

    s32 find(s32 id) {
        if (id <= -1)
            return -1;

        s32 n = count();
        for (s32 idx = 0; idx < n; idx++) {
            if (id == m_sub.get(idx)->id)
                return idx;
        }
        return -1;
    }
};

extern "C" s32 fn_27_FDD0C(Base* self, s32 id) {
    return self->find(id);
}
