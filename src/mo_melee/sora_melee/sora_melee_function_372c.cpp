#pragma force_active on
#pragma optimization_level 1

extern "C" void fn_8015BFB4(void*, void*);

extern "C" void fn_27_372C(void* base, int index, void* node) {
    fn_8015BFB4((char*)base + index * 12, node);
}
