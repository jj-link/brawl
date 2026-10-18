#pragma force_active on
typedef unsigned int u32;

struct FloatArrayHolder {
    unsigned char pad[0x14];
    float* m_floats;
};

extern "C" float fn_92_9AB8(const FloatArrayHolder* holder, u32 index) {
    return holder->m_floats[index];
}
