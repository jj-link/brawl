#pragma force_active on
extern "C" void fn_78_4B8C(void* self, unsigned int a, unsigned int b) {
    *(unsigned int*)((char*)self + 0x520) = a;
    *(unsigned int*)((char*)self + 0x528) = b;
}
