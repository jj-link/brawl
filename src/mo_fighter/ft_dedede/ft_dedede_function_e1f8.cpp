// The interface pointer for this entry points 0x64 bytes past the complete
// object; this vtable entry re-derives the complete object pointer and
// tail-calls the in-module status handler, forwarding the remaining
// arguments unchanged. fn_117_99E4's interface is
// (void* fighter, int status, int previous, soStatusData*, soModuleAccesser*)
// returning void, so the forwarded call needs no return-value conversion.
class soStatusData;
class soModuleAccesser;

extern "C" void fn_117_99E4(void*, int, int, soStatusData*, soModuleAccesser*);

extern "C" void fn_117_E1F8(void* interface, int status, int previous,
                            soStatusData* data, soModuleAccesser* accesser) {
    fn_117_99E4(static_cast<unsigned char*>(interface) - 0x64,
                status, previous, data, accesser);
}
