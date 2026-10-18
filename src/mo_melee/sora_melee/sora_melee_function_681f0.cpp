#pragma force_active on
struct soStopModuleImpl {
    unsigned char _00[0x1c];
    unsigned char m_stop : 1;
    bool isStop();
};

bool soStopModuleImpl::isStop() {
    return m_stop;
}
