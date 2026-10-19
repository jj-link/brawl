#include <types.h>
#pragma force_active on

class QwzTable {
public:
    virtual void f0() {}
    virtual void f1() {}
    virtual void f2() {}
    virtual s32 size() const;
    QwzTable* m_link;
    void* m_elements;
    s32 m_size;
};

extern "C" s32 fn_27_211F8(const QwzTable* self) {
    s32 res = self->m_size;
    if (!self->m_elements) {
        res = 0;
    }
    if (self->m_link) {
        return res + self->m_link->size();
    }
    return res;
}
