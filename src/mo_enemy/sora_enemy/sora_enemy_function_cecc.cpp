#pragma force_active on
typedef unsigned int u32;

extern "C" void* fn_41_CD80(void* p);

extern "C" u32 fn_41_CECC(void* p) {
    return *(u32*)((char*)fn_41_CD80(p) + 0x14);
}
