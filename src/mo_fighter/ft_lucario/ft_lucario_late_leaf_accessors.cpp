// Leaf virtual callbacks retain their existing module export names.
// The concrete input layout is not exposed here; this accessor reads word 0xB8.
extern "C" void fn_118_13B64(void*) {}
extern "C" void fn_118_13B68(void*) {}
extern "C" void fn_118_13B6C(void*) {}
extern "C" void fn_118_13B70(void*) {}

extern "C" unsigned int fn_118_13B74(void* object) {
    return *reinterpret_cast<unsigned int*>(static_cast<unsigned char*>(object) + 0xB8);
}

extern "C" int fn_118_13B7C(void*) {
    return 2;
}
