#pragma force_active on
struct Inner {
    char pad[0x48e];
    unsigned char : 1;
    unsigned char : 1;
    unsigned char m_flag : 1;
};

struct Outer {
    Inner* m_inner;
};

extern "C" {
    bool fn_27_11139C(Outer* o) {
        return o->m_inner->m_flag;
    }
}
