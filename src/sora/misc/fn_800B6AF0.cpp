#pragma force_active on
extern "C" void* GetResNode__Q34nw4r3g3d6ResMdlCFPCc(void* self, const char* name);

extern "C" int fn_800B6AF0(char* arg0, const char* arg1) {
    void* local = *(void**)(*(char**)(arg0 + 0x10) + 0xE8);
    void* res = GetResNode__Q34nw4r3g3d6ResMdlCFPCc(&local, arg1);
    if (res != 0) {
        return *(int*)((char*)res + 0xC);
    }
    return 0;
}
