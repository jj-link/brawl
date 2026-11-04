#pragma force_active on
extern const float lbl_61_rodata_54;

typedef unsigned char u8;
typedef unsigned short u16;

extern "C" {
float fn_61_5CFC(void* self, int idx) {
    void** table = *(void***)((u8*)self + 0x48);
    void* obj = table[idx];
    if (obj == 0) {
        return lbl_61_rodata_54;
    }
    void* a = *(void**)((u8*)obj + 0x0c);
    void* b = *(void**)((u8*)a + 0x2c);
    float val = *(u16*)((u8*)b + 0x1c);
    return val;
}
}
