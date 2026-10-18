#pragma force_active on
struct GlobalObjectStorage {
    unsigned char data[0x68];
};

struct DestructorChain {
    void *next;
    void *destructor;
    void *object;
};

extern "C" {
extern signed char lbl_50_bss_48;
extern GlobalObjectStorage lbl_50_bss_50;
extern float lbl_50_rodata_C8;
extern DestructorChain lbl_50_bss_24;

void fn_50_4C00();
void __register_global_object(void *, void *, void *);

GlobalObjectStorage *fn_50_6148()
{
    if (lbl_50_bss_48 == 0) {
        float value = lbl_50_rodata_C8;
        unsigned int flags = *reinterpret_cast<unsigned int *>(
            reinterpret_cast<unsigned char *>(&lbl_50_bss_50) + 0x38);

        *reinterpret_cast<float *>(reinterpret_cast<unsigned char *>(&lbl_50_bss_50) + 0x24) = value;
        *reinterpret_cast<float *>(reinterpret_cast<unsigned char *>(&lbl_50_bss_50) + 0x28) = value;
        *reinterpret_cast<float *>(reinterpret_cast<unsigned char *>(&lbl_50_bss_50) + 0x2C) = value;
        *reinterpret_cast<unsigned int *>(reinterpret_cast<unsigned char *>(&lbl_50_bss_50) + 0x38) =
            flags & ~31U;

        __register_global_object(&lbl_50_bss_50,
                                 reinterpret_cast<void *>(fn_50_4C00),
                                 &lbl_50_bss_24);
        lbl_50_bss_48 = 1;
    }
    return &lbl_50_bss_50;
}
}
