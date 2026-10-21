#pragma force_active on

typedef unsigned int u32;

struct Vec {
    float x, y, z;
};

extern "C" {
    extern const float lbl_27_rodata_8030;

    void fn_27_1E1B14(
        void*, void*, int, void*, int, int, Vec*, u32,
        u32, int, int, int, int, int, int, int, int, int
    );

    int fn_27_3BB0B4(void* unused, void* a, unsigned char* b, int c, void* d) {
        Vec v;
        v.x = lbl_27_rodata_8030;
        v.y = lbl_27_rodata_8030;
        v.z = lbl_27_rodata_8030;

        fn_27_1E1B14(
            a, *(void**)(*(unsigned char**)(b + 8) + 0x28),
            c, d, 1, 0, &v, 65535,
            65535, 0, 1, 0, -1, 0, 0, 2, 0, 0
        );
        return 1;
    }
}
