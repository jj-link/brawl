#pragma force_active on
typedef unsigned int u32;
typedef unsigned char u8;

struct Data {
    u32 a, b, c, d, e;
};

extern "C" {
void fn_801092E0(void* obj, Data* data);

void fn_800DCEA8(u8* self, const Data* src) {
    if (*(void**)(self + 0x94) != 0) {
        Data data = *src;
        fn_801092E0(*(void**)(self + 0x94), &data);
    }
}
}
