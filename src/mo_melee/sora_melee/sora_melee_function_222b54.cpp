#pragma force_active on
extern "C" void __dl__FPv(void*);

struct Stage {
    char pad[0x80];
    void* m_cameraParam;

    void clearCameraParam();
};

void Stage::clearCameraParam() {
    if (m_cameraParam) {
        __dl__FPv(m_cameraParam);
        m_cameraParam = 0;
    }
}
