class soModuleAccesser;

extern "C" void fn_99_8208(void*, void*, soModuleAccesser*, void*, int);
extern "C" void fn_27_13138C(void*, int, int, void*, soModuleAccesser*);

extern "C" void fn_99_BAC0(void* object, void* event,
                          soModuleAccesser* accesser, void* context, int index) {
    fn_99_8208(static_cast<unsigned char*>(object) - 0x54,
               event, accesser, context, index);
}

extern "C" void fn_99_BAC8(void* object, int status, int previousStatus,
                          void* context, soModuleAccesser* accesser) {
    fn_27_13138C(static_cast<unsigned char*>(object) - 0x64,
                 status, previousStatus, context, accesser);
}
