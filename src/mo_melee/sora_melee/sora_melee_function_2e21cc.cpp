#pragma force_active on
struct soModuleAccesser;

extern "C" void __ct__16soStopModuleImplFP16soModuleAccesser(
    void*, soModuleAccesser*);

extern "C" void* fn_27_2E21CC(void* self, soModuleAccesser* accesser) {
    __ct__16soStopModuleImplFP16soModuleAccesser(self, accesser);
    return self;
}
