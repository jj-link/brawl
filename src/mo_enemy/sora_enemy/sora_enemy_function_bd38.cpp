#pragma force_active on
struct fnObj {
    int m_dummy;
};

extern "C" fnObj* fn_41_BD38(fnObj* p, short n) {
    if (p != 0 && n > 0) {
        delete p;
    }
    return p;
}
