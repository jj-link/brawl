#pragma force_active on
extern "C" void* __dynamic_cast(void*, long, const void*, const void*, short);
extern char __RTTI__16emAreaModuleImpl[];
extern char __RTTI__12soAreaModule[];

class soModuleAccesser;

class emAreaModuleImpl {
public:
    int checkArea(soModuleAccesser* acc, unsigned long p2, unsigned long p3);
};

extern "C" bool fn_41_278F8(char* self, unsigned long p2) {
    short one = 1;
    void* acc = *(void**)(self + 0x14);
    void* mod = *(void**)((char*)*(void**)((char*)acc + 0xD8) + 0x90);
    emAreaModuleImpl* area = (emAreaModuleImpl*)__dynamic_cast(mod, 0, __RTTI__16emAreaModuleImpl, __RTTI__12soAreaModule, one);
    return area->checkArea((soModuleAccesser*)*(void**)(self + 0x14), p2, 4) == one;
}
