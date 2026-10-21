extern "C" void fn_800F6DF4(void* self, int a, int b, int c, int d);

#pragma force_active on
extern "C" void fn_800F6F60(void* self, int arg1) {
    if (arg1 >= 0) {
        fn_800F6DF4(self, 0, 1, arg1, 1);
        *(int*)((char*)self + 0x42C) = arg1;
    }
}
