#pragma force_active on
extern "C" int fn_100_10794(void*, void*);
extern "C" void fn_100_F7F4();

extern "C" void fn_100_DFBC(void* unused, void* self, void* arg) {
    if (fn_100_10794(self, arg) == 0)
        fn_100_F7F4();
}
