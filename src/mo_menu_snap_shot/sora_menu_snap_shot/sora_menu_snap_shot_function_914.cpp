#pragma force_active on
extern "C" {
int fn_800C39D8(void* p);
void* getInstance__14gfSceneManagerFv();
}

extern "C" void fn_8_914(void* self) {
    void* a = *(void**)((char*)self + 0x1ac);
    void* b = *(void**)((char*)a + 0x1ce4);
    if (fn_800C39D8(b)) {
        char* mgr = (char*)getInstance__14gfSceneManagerFv();
        *(int*)(mgr + 0x284) = 0;
        *(int*)(mgr + 0x288) = 2;
    }
}
