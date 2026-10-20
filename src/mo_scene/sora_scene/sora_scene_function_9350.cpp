#pragma force_active on
extern "C" void* getInstance__14gfSceneManagerFv();

extern "C" int fn_1_9350(char* r3) {
    int r0 = *(int*)(*(char**)(r3 + 8) + 0x48);
    switch (r0) {
        case 1: {
            char* mgr = (char*)getInstance__14gfSceneManagerFv();
            *(int*)(mgr + 0x284) = 2;
            *(int*)(mgr + 0x288) = 2;
            break;
        }
        case 2: {
            char* mgr = (char*)getInstance__14gfSceneManagerFv();
            *(int*)(mgr + 0x284) = 1;
            *(int*)(mgr + 0x288) = 2;
            break;
        }
        case 3: {
            char* mgr = (char*)getInstance__14gfSceneManagerFv();
            *(int*)(mgr + 0x284) = 0;
            *(int*)(mgr + 0x288) = 2;
            break;
        }
        default:
            break;
    }
    return 0;
}
