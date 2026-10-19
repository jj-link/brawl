#pragma force_active on
typedef unsigned char u8;

extern "C" void* fn_41_38BB4(u8* p, int n);
extern "C" int fn_27_8D3E4(void* p);

extern "C" void fn_41_38B48(void* p) {
    for (int i = 0; i < 5; i++) {
        if (fn_27_8D3E4(fn_41_38BB4(static_cast<u8*>(p) + 0xc, i)) == 0) {
            break;
        }
    }
}
