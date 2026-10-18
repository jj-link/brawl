#pragma force_active on
extern "C" {
void* fn_110_2074C(void*, int);
int fn_27_8D3E4(void*);

void fn_110_206A4(void* object) {
    for (int index = 0; index < 1; ++index) {
        void* member = fn_110_2074C(static_cast<unsigned char*>(object) + 0xc, index);
        if (fn_27_8D3E4(static_cast<unsigned char*>(member) + 0x88) == 0) break;
    }
}
}
