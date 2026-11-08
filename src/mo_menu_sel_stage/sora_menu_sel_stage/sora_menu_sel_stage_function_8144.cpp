#pragma force_active on

extern "C" void* fn_800390C8(void* p);

extern "C" void* fn_11_8144(void* self) {
    if (*(int*)((char*)self + 0x40) != 5) {
        return 0;
    }
    return fn_800390C8(*(void**)((char*)self + 0x68));
}
