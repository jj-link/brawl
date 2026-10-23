#pragma force_active on

extern "C" unsigned char fn_80107E50(void *a) {
    return *((unsigned char *)*(void **)((char *)a + 0x74) + 0x147);
}
