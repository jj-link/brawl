#pragma force_active on
extern "C" char* fn_101_19FC4(void* array, int index);
extern "C" int fn_27_8D3E4(void* object);

extern "C" void fn_101_19EE8(void* object) {
    for (int i = 0; i < 6; ++i) {
        if (fn_27_8D3E4(fn_101_19FC4(static_cast<char*>(object) + 0xC, i) + 0x88) == 0) {
            return;
        }
    }
}
