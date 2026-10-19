#pragma force_active on
extern "C" void* fn_41_4C5F8(void*, int);
extern "C" int fn_27_8D3E4(void*);

extern "C" void fn_41_4C58C(void* object) {
    for (int i = 0; i < 10; ++i) {
        if (fn_27_8D3E4(fn_41_4C5F8(static_cast<char*>(object) + 0x0C, i)) == 0) {
            break;
        }
    }
}
