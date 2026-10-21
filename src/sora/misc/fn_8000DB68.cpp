#pragma force_active on
extern "C" unsigned char* getLightObj__11gfSceneRootFUc(void* self, void* idx)
{
    void* p = *(void**)((char*)self + 0x40);
    void* base = *(void**)((char*)p + 0x287c);
    int offset = ((int)(char*)idx + 0x12) * 0x44;
    return (unsigned char*)base + offset;
}
