#pragma force_active on

#include <so/so_array.h>

struct Self {
    virtual void v0(); virtual void v1(); virtual void v2();
    virtual void v3(); virtual void v4(); virtual void v5();
    virtual void v6(); virtual void v7(); virtual void v8();
    virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12();
    virtual int count();

    s32 m_freeIndex : 9;
    s32 m_topIndex : 9;
    s32 m_lastIndex : 9;
    s32 m_size : 9;

    soArrayListUnit<void*, s16> m_units[256];
};

extern "C" void fn_27_2AD784(Self* self) {
    self->m_freeIndex = 0;
    self->m_topIndex = -1;
    self->m_lastIndex = -1;
    self->m_size = 0;

    if (self->count() == 1) {
        self->m_units[0].m_prev = -1;
        self->m_units[0].m_next = -1;
        self->m_units[0].m_inUse = false;
    } else {
        Self* links = self;
        soArrayListUnit<void*, s16>* unit = self->m_units;

        for (int i = 0; i < self->count(); ++i) {
            links->m_units[0].m_prev = i - 1;
            links->m_units[0].m_next = i + 1;
            links = (Self*)((char*)links + 12);
            unit->m_inUse = false;
            ++unit;
        }

        soArrayListUnit<void*, s16>* last = &self->m_units[self->count() - 1];
        last->m_next = -1;
    }
}
