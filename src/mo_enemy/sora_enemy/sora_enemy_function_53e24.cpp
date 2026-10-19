#pragma force_active on
extern "C" void* fn_41_53E90(unsigned char* self, int idx);
extern "C" int fn_27_8D3E4(void*);

extern "C" void fn_41_53E24(unsigned char* self) {
    for (int i = 0; i < 5; ++i) {
        if (fn_27_8D3E4(fn_41_53E90(self + 0x0C, i)) == 0) {
            break;
        }
    }
}
