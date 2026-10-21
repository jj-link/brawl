#pragma force_active on
extern "C" int fn_8009D2C8(void* self) {
    int x = *(int*)((char*)self + 0x188);
    return (unsigned)((-x) & ~x) >> 31;
}
