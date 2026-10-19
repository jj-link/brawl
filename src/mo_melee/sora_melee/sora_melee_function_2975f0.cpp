#pragma force_active on
typedef unsigned int u32;

extern "C" {
void* fn_27_2C2FB0(void* a, void* b, u32 c);

void fn_27_2975F0(void* unused, void* obj) {
    char* self = (char*)obj;
    char* r = (char*)fn_27_2C2FB0(self, *(void**)(self + 0x8dc), 0x80);
    if (r) {
        *(u32*)(self + 0x3d2c) = *(u32*)(r + 0x28);
    }
}
}
