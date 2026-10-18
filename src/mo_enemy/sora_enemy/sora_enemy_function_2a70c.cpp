#pragma force_active on
extern "C" void fn_41_2A6F4(void*);

extern "C" void fn_41_2A70C(void* self) {
    fn_41_2A6F4(*reinterpret_cast<void**>(
        reinterpret_cast<unsigned char*>(*reinterpret_cast<void**>(self)) + 4));
}
