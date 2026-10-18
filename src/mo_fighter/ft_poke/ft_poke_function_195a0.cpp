#pragma force_active on
extern "C" {
void* fn_116_1964C(void*, int);
int fn_27_8D3E4(void*);
void fn_116_195A0(void* object) {
    for (int i = 0; i < 10; ++i) {
        void* member = fn_116_1964C(static_cast<unsigned char*>(object) + 0xc, i);
        if (fn_27_8D3E4(static_cast<unsigned char*>(member) + 0x88) == 0) break;
    }
}
}
