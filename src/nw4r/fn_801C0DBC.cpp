#pragma force_active on
extern "C" void fn_801C6B94(void* self);

extern "C" void fn_801C0DBC(void* self) {
    int* p = (int*)self;
    p[0x108 / 4] = 0;
    fn_801C6B94(self);
}
