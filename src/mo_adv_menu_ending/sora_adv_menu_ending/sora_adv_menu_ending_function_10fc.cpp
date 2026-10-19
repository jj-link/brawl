#pragma force_active on
extern "C" bool fn_8007EF64(void*);
extern "C" int fn_8007EF68(void*);

extern "C" int fn_37_10FC(void* self) {
    if ((int)fn_8007EF64(*(void**)((char*)self + 0x78)) != 1) {
        return 1;
    }
    *(int*)((char*)self + 0x80) = fn_8007EF68(*(void**)((char*)self + 0x78));
    return 0;
}
