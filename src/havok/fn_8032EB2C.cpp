#pragma force_active on
extern "C" void fn_8032EB5C(void*);

extern "C" void* fn_8032EB2C(void* self) {
    fn_8032EB5C(self);
    return (char*)self + 0x10;
}
