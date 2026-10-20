#pragma force_active on
struct Inner {
    unsigned char _pad[0x818];
    float m_818;
};

struct Outer {
    Inner* m_inner;
};

extern "C" float fn_27_112BBC(const Outer* outer) {
    return outer->m_inner->m_818;
}
