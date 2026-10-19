#pragma force_active on
extern "C" void fn_119_8FFC(void*, void*);
extern "C" void fn_27_13138C(void*, int, int, void*, void*);

extern "C" void fn_119_8F90(void* self, int status, int previous, void* data, void* accesser) {
    switch (status) {
    case 0x126:
        fn_119_8FFC(self, accesser);
        break;
    }
    fn_27_13138C(self, status, previous, data, accesser);
}
