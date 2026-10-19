#pragma force_active on
struct FtFloatArrayHolder {
    char pad[0x14];
    float* m_floats;
};

extern "C" float fn_125_B2F8(FtFloatArrayHolder* holder, unsigned int index) {
    return holder->m_floats[index];
}
