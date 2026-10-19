#pragma force_active on
extern "C" {
int fn_800C39D8(void* p);
void* getInstance__14gfSceneManagerFv();

void fn_5_132DC(char* self) {
    char* obj = *(char**)(self + 0x1ac);
    if (fn_800C39D8(*(void**)(obj + 0x1ce4))) {
        void* val = *(void**)(*(char**)(self + 0x1ac) + 0x1d40);
        char* mgr = (char*)getInstance__14gfSceneManagerFv();
        *(void**)(mgr + 0x284) = val;
        *(int*)(mgr + 0x288) = 2;
    }
}
}
