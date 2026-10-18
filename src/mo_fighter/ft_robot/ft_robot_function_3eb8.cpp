#pragma force_active on
struct ftRobotObj {
    int m_dummy;
};

extern "C" ftRobotObj* fn_120_3EB8(ftRobotObj* p, short flags) {
    if (p && flags > 0) {
        delete p;
    }
    return p;
}
