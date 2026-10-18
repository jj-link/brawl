#pragma force_active on
typedef unsigned int u32;

struct IkeWork {
    char pad[0x14];
    float *m_floats;
};

extern "C" void fn_119_9984(IkeWork *work, u32 index, float value) {
    work->m_floats[index] -= value;
}
