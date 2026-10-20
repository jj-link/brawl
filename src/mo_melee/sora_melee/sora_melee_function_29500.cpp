#pragma force_active on
typedef unsigned int u32;
typedef unsigned long long u64;

struct Result {
    u32 unused;
    void* data;
};

struct Interface {
    virtual void unused();
    virtual Result* get();
};

struct Object {
    unsigned char padding[0x28];
    Interface* interface;
};

struct Matrix {
    u32 words[12];
};

extern "C" void fn_801341D8(void*, Matrix*);

extern "C" u64 fn_27_29500(Object self) {
    Matrix matrix;
    fn_801341D8(self.interface->get()->data, &matrix);
    return ((u64)matrix.words[2] << 32) | matrix.words[3];
}
