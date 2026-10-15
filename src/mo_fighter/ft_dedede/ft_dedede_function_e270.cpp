// The interface pointer for this entry points 0xC4 bytes past the complete
// object; this vtable entry re-derives the complete object pointer and
// tail-calls the imported fn_27_135EB4 from the sora_melee module, which
// forwards the capture-status notification to the accesser's capture
// module. fn_27_135EB4's verified interface is
// (void* object, soModuleAccesser*, int, int, int) -> bool: it reads only
// the accesser and the three integer words and tail-calls the capture
// module's notifyEventCaptureStatus slot, declared bool in
// soCaptureEventObserver; the registered ft_luigi thunk's void declaration
// is contradicted by that header and the registered ft_metaknight adjustor
// already forwards through the bool form.
class soModuleAccesser;

extern "C" bool fn_27_135EB4(void* object, soModuleAccesser* accesser,
                             int taskId, int argument, int argument2);

extern "C" bool fn_117_E270(void* object, soModuleAccesser* accesser,
                            int taskId, int argument, int argument2) {
    return fn_27_135EB4(static_cast<unsigned char*>(object) - 0xC4, accesser,
                        taskId, argument, argument2);
}
