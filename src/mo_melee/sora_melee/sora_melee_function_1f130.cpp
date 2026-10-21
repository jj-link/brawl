#pragma force_active on
extern "C" {
void fn_27_13844(void*, void*, void*, void*, void*, void*, void*, void*, short, int, void*);
extern unsigned char lbl_27_data_20E0[];
}

extern "C" void* fn_27_1F130(void* self, void* a, void* b, void* c, void* d, void* e, void* f,
                             void* g, short s, unsigned char u, void* h) {
    fn_27_13844(self, a, b, c, d, e, f, g, s, u, h);
    unsigned char* base = lbl_27_data_20E0;
    *(unsigned char**)((char*)self + 0x00) = base;
    *(unsigned char**)((char*)self + 0x04) = base + 0x1B4;
    *(unsigned char**)((char*)self + 0x10) = base + 0x1C4;
    *(unsigned char**)((char*)self + 0x1C) = base + 0x1D8;
    *(unsigned char**)((char*)self + 0x28) = base + 0x1EC;
    *(int*)((char*)self + 0x170) = 0;
    *(int*)((char*)self + 0x174) = 0xFFFF;
    return self;
}
