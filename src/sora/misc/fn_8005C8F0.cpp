#pragma force_active on
extern "C" int fn_8016FBC8(void*);
extern "C" void* fn_8016FBF4(void*);
extern "C" unsigned short fn_801643D0(void*);
extern "C" char* fn_801643D8(void*, unsigned short);
extern "C" int fn_8005D50C(int*, void*);

extern "C" int fn_8005C8F0(char* self) {
    int result = 0;
    if (fn_8016FBC8(self + 0x4c)) {
        void* handle = fn_8016FBF4(self + 0x4c);
        unsigned short count = fn_801643D0(handle);
        for (unsigned short i = 0; i < count; i++) {
            if (*(int*)(fn_801643D8(handle, i) + 0xc) == 1) {
                result = 1;
                break;
            }
        }
        int out;
        if (!result && fn_8005D50C(&out, handle)) {
            result = 1;
        }
    }
    return result;
}