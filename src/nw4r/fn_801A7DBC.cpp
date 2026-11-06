#pragma force_active on
extern "C" void fn_801A81D4(void**);
extern "C" void fn_801EC184(void*, void*);

extern "C" void fn_801A7DBC(void** arg0, void* arg1) {
    if (arg1 != 0) {
        void* data = *arg0;
        if (data != 0) {
            if ((*(unsigned int*)((char*)data + 0x70) & 8) == 0) {
                fn_801A81D4(arg0);
            }
            fn_801EC184(data, arg1);
        }
    }
}
