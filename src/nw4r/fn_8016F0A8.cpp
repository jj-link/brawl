#pragma force_active on
extern "C" void* fn_8015C1B0(void*, void*);
extern "C" void fn_8015C144(void*, void*);

extern "C" int fn_8016F0A8(char* self, char* arg) {
    char* node = (char*)fn_8015C1B0(self + 0x10, 0);
    while (node != 0) {
        if (node == arg) {
            fn_8015C144(self + 0x10, arg);
            int n;
            if (arg != 0) {
                n = *(unsigned short*)(arg + *(int*)arg + 4);
            } else {
                n = *(int*)(self + 0x1c);
            }
            *(int*)(self + 0x1c) -= n;
            return 1;
        }
        node = (char*)fn_8015C1B0(self + 0x10, node);
    }
    return 0;
}
