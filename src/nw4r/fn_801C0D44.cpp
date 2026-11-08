#pragma force_active on

extern "C" void fn_801C7130(void* self);
extern "C" void fn_801C6B8C(void* self, void* arg);
extern "C" void fn_801C7288(void* self, int a, int b);
extern "C" void fn_801C71E0(void* self, int a, int b);

extern "C" int fn_801C0D44(char* self, int arg) {
    fn_801C7130(self + 0x10C);
    fn_801C6B8C(self, self + 0x10C);
    fn_801C7288(self + 0x10C, *(int*)(self + 0x124) + arg, *(int*)(self + 0x128));
    fn_801C71E0(self + 0x10C, *(int*)(self + 0x11C) + arg, *(int*)(self + 0x120));
    *(int*)(self + 0x108) = arg;
    return 1;
}
