#pragma force_active on
extern "C" int fn_8007EF64(void*);
extern "C" int fn_8007EF68(void*);

extern "C" int fn_19_EF0(void* self) {
    if (fn_8007EF64(*(void**)((char*)self + 0x9AC)) != 1) {
        return 1;
    }
    *(int*)((char*)self + 0x9B0) = fn_8007EF68(*(void**)((char*)self + 0x9AC));
    return 0;
}
