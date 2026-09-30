typedef unsigned long u32;

struct FILE {
    u32 x0, x4, x8, xc, x10, x14, x18, x1c, x20, x24, x28, x2c, x30, x34;
};

void __prep_buffer(struct FILE* file) {
    u32 base = file->x18;
    u32 size = file->x20;
    u32 storage = file->x1c;
    u32 mask = file->x2c;
    file->x24 = storage;
    file->x28 = size - (base & mask);
    file->x34 = base;
}
