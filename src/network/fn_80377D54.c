#pragma force_active on
typedef unsigned int u32;
typedef unsigned short u16;

struct Key {
    u32 m_00;
    u16 m_04;
};

int fn_80377D54(struct Key **arg0, struct Key **arg1) {
    struct Key *a = *arg0;
    struct Key *b = *arg1;
    if (a->m_00 != b->m_00) {
        return a->m_00 - b->m_00;
    }
    return (short)(a->m_04 - b->m_04);
}
