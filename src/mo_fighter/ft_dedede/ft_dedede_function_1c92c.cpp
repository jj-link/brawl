#pragma force_active on
struct DededeWaddleDeeStorage { void* data; };
struct DededeWaddleDeeRegistration { void* next; void* object; void* destructor; };

extern "C" {
extern DededeWaddleDeeStorage lbl_117_bss_47C;
extern DededeWaddleDeeRegistration lbl_117_bss_470;

void fn_117_1C974(void** object);
void* fn_117_1C8EC(void* object, short deleting);
void __register_global_object(void* object, void* destructor, void* registration);

// Static initializer: constructs the global Waddle Dee parameter block and
// registers its destructor with the runtime's global-object list.
void fn_117_1C92C() {
    fn_117_1C974(&lbl_117_bss_47C.data);
    __register_global_object(&lbl_117_bss_47C,
                             reinterpret_cast<void*>(fn_117_1C8EC),
                             &lbl_117_bss_470);
}
}

__declspec(section ".ctors") extern void* const fn_117_1C92C_ctor = (void*)fn_117_1C92C;
