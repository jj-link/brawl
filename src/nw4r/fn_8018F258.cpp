#pragma force_active on
extern "C" void fn_8018CF30(void**);

extern "C" void GetResMat__Q34nw4r3g3d6ResMdlCFPCc(const void* self, const char* name)
{
    const void* data = *(const void**)self;
    int offset = *(const int*)((const char*)data + 0x28);
    void* result;
    if (offset) {
        result = (void*)((char*)data + offset);
    } else {
        result = 0;
    }
    fn_8018CF30(&result);
}
