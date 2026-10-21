#pragma force_active on
extern "C" int registScene__14gfSceneManagerFv(void* mgr, void* scene) {
    char* base = (char*)mgr;
    int count = *(int*)(base + 0x270);
    *(int*)(base + 0x270) = count + 1;
    *(void**)(base + 0x18 + count * 4) = scene;
    return count;
}
