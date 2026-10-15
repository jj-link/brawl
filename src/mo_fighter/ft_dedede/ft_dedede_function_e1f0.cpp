// The interface pointer for this entry points 0x54 bytes past the complete
// object (the secondary vtable header stores an offset-to-top of -0x54
// immediately before this slot); the entry re-derives the complete object
// pointer and tail-calls fn_117_94DC, which forwards the event to the
// DededeEventHandler::handle member function.
struct DededeEvent;
struct DededeEventHandler;
class soModuleAccesser;

extern "C" void fn_117_94DC(DededeEventHandler*, DededeEvent*,
                            soModuleAccesser*, void*, int);

extern "C" void fn_117_E1F0(void* object, DededeEvent* event,
                            soModuleAccesser* accesser, void* param, int kind) {
    fn_117_94DC(reinterpret_cast<DededeEventHandler*>(
                    static_cast<unsigned char*>(object) - 0x54),
                event, accesser, param, kind);
}
