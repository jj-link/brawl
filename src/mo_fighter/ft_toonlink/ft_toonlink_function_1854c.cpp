#pragma force_active on
extern "C" void* fn_121_18624(void*, int);
extern "C" int fn_27_8D3E4(void*);

extern "C" void fn_121_1854C(void* object) {
    for (int index = 0; index < 1; ++index) {
        void* member = fn_121_18624(static_cast<char*>(object) + 0xC, index);
        if (fn_27_8D3E4(static_cast<char*>(member) + 0x88) == 0) {
            break;
        }
    }
}
