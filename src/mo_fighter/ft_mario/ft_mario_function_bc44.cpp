#pragma force_active on
extern "C" {
void* fn_91_BE54(unsigned char*, int);
void* fn_91_BDFC(void*, int);
void* fn_91_BDE4(unsigned char*, int);
void* fn_91_BDCC(unsigned char*, int);
int fn_27_8D3E4(void*);
void fn_91_BC44(unsigned char* self) {
    for (int i = 0; i < 1; ++i) {
        if (fn_27_8D3E4(static_cast<unsigned char*>(fn_91_BE54(self + 0x24688, i)) + 0x88) == 0) return;
    }
    for (int i = 0; i < 5; ++i) {
        if (fn_27_8D3E4(static_cast<unsigned char*>(fn_91_BDFC(self - 0x55f8 + 0x20000, i)) + 0x88) == 0) return;
    }
    for (int i = 0; i < 1; ++i) {
        if (fn_27_8D3E4(static_cast<unsigned char*>(fn_91_BDE4(self + 0x1fd4, i)) + 0x88) == 0) return;
    }
    for (int i = 0; i < 1; ++i) {
        if (fn_27_8D3E4(static_cast<unsigned char*>(fn_91_BDCC(self + 0xc, i)) + 0x88) == 0) return;
    }
}
}
