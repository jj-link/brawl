#pragma force_active on
extern "C" void* __vt__10soNullable[];

struct soNullableRaw {
    void* vtable;
    bool m_isNull;
};

extern "C" soNullableRaw* fn_41_2360(soNullableRaw* p, bool b) {
    p->vtable = __vt__10soNullable;
    p->m_isNull = b;
    return p;
}
