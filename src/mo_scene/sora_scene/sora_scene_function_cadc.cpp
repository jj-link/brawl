#pragma force_active on
extern "C" void* getInstance__14gfSceneManagerFv();

extern "C" int fn_1_CADC(void* self) {
    unsigned char* p = *(unsigned char**)((char*)self + 0xC);
    if (p[0x44] != 0) {
        char* mgr = (char*)getInstance__14gfSceneManagerFv();
        *(int*)(mgr + 0x284) = 0;
        *(int*)(mgr + 0x288) = 2;
    }
    return 0;
}
