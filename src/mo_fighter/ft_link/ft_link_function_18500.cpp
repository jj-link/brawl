#pragma force_active on
extern "C" void* fn_93_185D8(void*, int);
extern "C" int fn_27_8D3E4(void*);

extern "C" void fn_93_18500(void* object) {
    for (int index = 0; index < 1; ++index) {
        void* member = fn_93_185D8(static_cast<unsigned char*>(object) + 0xc, index);
        if (fn_27_8D3E4(static_cast<unsigned char*>(member) + 0x88) == 0) break;
    }
}
