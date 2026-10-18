#pragma force_active on
extern "C" void* fn_112_16B24(void*, int);
extern "C" int fn_27_8D3E4(void*);

extern "C" void fn_112_16A48(void* object) {
    for (int index = 0; index < 10; ++index) {
        void* member = fn_112_16B24(static_cast<unsigned char*>(object) + 0x0C, index);
        if (fn_27_8D3E4(static_cast<unsigned char*>(member) + 0x88) == 0) {
            break;
        }
    }
}
