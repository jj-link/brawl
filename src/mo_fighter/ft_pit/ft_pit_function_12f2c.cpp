#pragma force_active on
struct fnObj {
    int m_dummy;
};

extern "C" fnObj* fn_112_12F2C(fnObj* p, short flag) {
    if (p != 0 && flag > 0) {
        delete p;
    }
    return p;
}
