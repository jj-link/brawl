#pragma force_active on

extern "C" void* fn_8018D4D0(void*, void*);
extern "C" void* GetResMat__Q34nw4r3g3d6ResMdlCFPCc(void*, void*);
extern "C" void fn_800B7224(void*, void*, void*, void*);

extern "C" void fn_800B7184(void* arg0, void* arg1, void* arg2, void* arg3) {
    void* ptr;
    if (arg3 == 0) {
        ptr = (void*)((char*)arg0 + 4);
    } else {
        ptr = arg3;
    }
    
    void* result = fn_8018D4D0(ptr, arg2);
    int offset = *(int*)((char*)result + 0x14);
    void* var;
    if (offset != 0) {
        var = (void*)((char*)result + offset);
    } else {
        var = (void*)0;
    }
    
    void* mat = GetResMat__Q34nw4r3g3d6ResMdlCFPCc((char*)arg0 + 8, arg1);
    void* mat_field = *(void**)((char*)mat + 0xc);
    fn_800B7224(arg0, mat_field, var, arg3);
}
