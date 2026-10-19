#pragma force_active on
extern "C" bool fn_8007EF64(void*);
extern "C" int fn_8007EF68(void*);

extern "C" int fn_24_16F0(void* self) {
    if ((int)fn_8007EF64(*(void**)((char*)self + 0x54)) != 1) {
        return 1;
    }

    *(int*)((char*)self + 0x58) =
        fn_8007EF68(*(void**)((char*)self + 0x54));
    return 0;
}
