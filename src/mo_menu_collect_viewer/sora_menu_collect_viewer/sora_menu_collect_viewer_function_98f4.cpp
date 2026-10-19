#pragma force_active on
extern "C" void fn_8014F490(void*, int, int);

extern "C" void fn_6_98F4(void* object) {
    fn_8014F490(*reinterpret_cast<void**>(static_cast<char*>(object) + 0x730), 1, 0);
}
