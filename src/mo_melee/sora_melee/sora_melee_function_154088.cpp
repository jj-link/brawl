#pragma force_active on
struct soModuleAccesser;

extern "C" void __ct__16soStopModuleImplFP16soModuleAccesser(
    void*, soModuleAccesser*);
extern "C" unsigned char lbl_27_data_2DB30[];

extern "C" void* fn_27_154088(void* self, soModuleAccesser* accesser) {
    __ct__16soStopModuleImplFP16soModuleAccesser(self, accesser);
    void** fields = static_cast<void**>(self);
    fields[0] = lbl_27_data_2DB30;
    fields[1] = lbl_27_data_2DB30 + 0x50;
    return self;
}
