#pragma force_active on
extern "C" void* getInstance__14gfSceneManagerFv();

extern "C" int fn_1_B318(char* self) {
    char* task = *(char**)(self + 8);
    int state = *(int*)(task + 0x48);
    switch (state) {
    case 1: {
        char* mgr = (char*)getInstance__14gfSceneManagerFv();
        *(int*)(mgr + 0x284) = 1;
        *(int*)(mgr + 0x288) = 2;
        break;
    }
    case 2: {
        char* mgr = (char*)getInstance__14gfSceneManagerFv();
        *(int*)(mgr + 0x284) = 0;
        *(int*)(mgr + 0x288) = 2;
        break;
    }
    }
    return 0;
}
