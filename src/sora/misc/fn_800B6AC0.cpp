#pragma force_active on
extern "C" {

void* GetResNode__Q34nw4r3g3d6ResMdlCFPCc(void* self, const char* name);

void* fn_800B6AC0(void* self, const char* name) {
    void* ptr = *(void**)((char*)self + 0x10);
    void* local = *(void**)((char*)ptr + 0xe8);
    return GetResNode__Q34nw4r3g3d6ResMdlCFPCc(&local, name);
}

}
