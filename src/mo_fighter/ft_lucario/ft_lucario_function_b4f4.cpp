#pragma force_active on
extern "C" void* fn_118_B628(char* object, int index);
extern "C" void* fn_118_B610(void* object, int flag);
extern "C" int fn_27_8D3E4(void* p);

extern "C" void fn_118_B4F4(char* object) {
    for (int i = 0; i < 3; i++) {
        if (fn_27_8D3E4((char*)fn_118_B628(object + 0x1e54, i) + 0x88) == 0) {
            return;
        }
    }
    for (int j = 0; j < 1; j++) {
        if (fn_27_8D3E4((char*)fn_118_B610(object + 0xc, j) + 0x88) == 0) {
            return;
        }
    }
}
