#pragma force_active on
struct ArrayHeader;
extern "C" {
ArrayHeader* fn_27_C944C(ArrayHeader* array, int release);
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void __dl__FPv(void*);

void* fn_27_C87A8(void* self, int release) {
    if (self) {
        __destroy_arr((char*)self + 8, (void (*)(void*, int))fn_27_C944C, 0x18, 0xB);
        if (release > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
}
