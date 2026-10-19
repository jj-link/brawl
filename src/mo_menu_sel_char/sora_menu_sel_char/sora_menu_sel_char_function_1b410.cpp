#pragma force_active on
typedef unsigned char u8;

extern "C" {
int fn_10_1B2A4(u8* self, u8* a, u8* b);

void fn_10_1B410(u8* self) {
    *(int*)(self + 0xac) = fn_10_1B2A4(self, self + 0xb0, self + 0xb4);
}
}
