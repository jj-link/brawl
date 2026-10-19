#pragma force_active on
extern "C" void fn_112_AB34(void* self, int value, int index) {
    reinterpret_cast<int*>(*reinterpret_cast<void**>(reinterpret_cast<char*>(self) + 0xc))[index] = value;
}
