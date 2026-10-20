#pragma force_active on
extern "C" void EnableScnMdlCallbackTiming__Q34nw4r3g3d12ScnMdlSimpleFUl(void* model, unsigned long flag);

extern "C" void updateCallback__9grGimmickFUl(void* self, unsigned long index)
{
    char* p = (char*)self;
    if (*(int*)(p + 0xd8) <= 0) return;
    void** models = (void**)(*(void**)(p + 0x44));
    void* model = models[index];
    char* mp = (char*)model;
    if (*(int*)(mp + 0x11c) == 0 && model != 0) {
        *(unsigned int*)(p + 0xdc) = 0;
        *(unsigned int*)(mp + 0x11c) = (unsigned int)self + 0xd0;
        EnableScnMdlCallbackTiming__Q34nw4r3g3d12ScnMdlSimpleFUl(model, 1);
        *(unsigned short*)(mp + 0x122) = *(unsigned int*)(*(unsigned int**)(p + 0xd4));
    }
}
