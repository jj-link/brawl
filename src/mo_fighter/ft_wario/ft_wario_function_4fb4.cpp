#pragma force_active on
struct ftWarioObj {
    int m_dummy;
};

extern "C" {
ftWarioObj* fn_110_4FB4(ftWarioObj* p, short n) {
    if (p != 0 && n > 0) {
        delete p;
    }
    return p;
}
}
