#pragma force_active on
extern "C" int fn_2_376B4(void*);
extern "C" void* getInstance__14gfSceneManagerFv();

extern "C" int fn_1_A978(void* self) {
    if (fn_2_376B4(*(void**)((char*)self + 8))) {
        char* mgr = (char*)getInstance__14gfSceneManagerFv();
        *(int*)(mgr + 0x284) = 0;
        *(int*)(mgr + 0x288) = 2;
    }
    return 0;
}
