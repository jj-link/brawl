class soStatusData;
class soModuleAccesser;

extern "C" void fn_27_1DA1F4(void*, int, int, soStatusData*, soModuleAccesser*);

extern "C" void fn_99_10C64(void* object, int status, int previousStatus,
                           soStatusData* data, soModuleAccesser* accesser) {
    fn_27_1DA1F4(static_cast<unsigned char*>(object) - 0x64,
                 status, previousStatus, data, accesser);
}
