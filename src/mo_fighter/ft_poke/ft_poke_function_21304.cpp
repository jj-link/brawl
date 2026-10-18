#pragma force_active on
extern "C" {
void* fn_116_21460(void*, int);
void* fn_116_21428(void*, int);
void* fn_116_21410(void*, int);
int fn_27_8D3E4(void*);

void fn_116_21304(void* object) {
    for (int index = 0; index < 2; ++index) {
        void* member = fn_116_21460(static_cast<char*>(object) + 0x63a8, index);
        if (fn_27_8D3E4(static_cast<char*>(member) + 0x88) == 0) return;
    }
    for (int index = 0; index < 3; ++index) {
        void* member = fn_116_21428(static_cast<char*>(object) + 0x1f94, index);
        if (fn_27_8D3E4(static_cast<char*>(member) + 0x88) == 0) return;
    }
    for (int index = 0; index < 1; ++index) {
        void* member = fn_116_21410(static_cast<char*>(object) + 0xc, index);
        if (fn_27_8D3E4(static_cast<char*>(member) + 0x88) == 0) return;
    }
}
}
