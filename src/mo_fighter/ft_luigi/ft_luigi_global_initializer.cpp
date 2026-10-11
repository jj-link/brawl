struct LuigiParameterAccesser;
struct LuigiClassInfo;

struct LuigiGlobalRegistration {
    void* next;
    void* object;
    void* destructor;
};

extern "C" {
LuigiGlobalRegistration lbl_99_bss_8;
unsigned char luigiParameterStorage[0x168];
LuigiGlobalRegistration luigiClassInfoRegistration;
unsigned char luigiClassInfoStorage[0xc];
LuigiParameterAccesser* fn_99_B8E4(LuigiParameterAccesser*);
LuigiClassInfo* fn_99_B92C(LuigiClassInfo*);
void* fn_99_8534(void*, short);
LuigiClassInfo* fn_99_B984(LuigiClassInfo*, short);
void __register_global_object(void*, void*, void*);
}

extern "C" void fn_99_B880() {
    fn_99_B8E4(reinterpret_cast<LuigiParameterAccesser*>(luigiParameterStorage));
    __register_global_object(luigiParameterStorage,
                             reinterpret_cast<void*>(fn_99_8534),
                             &lbl_99_bss_8);
    fn_99_B92C(reinterpret_cast<LuigiClassInfo*>(luigiClassInfoStorage));
    __register_global_object(luigiClassInfoStorage,
                             reinterpret_cast<void*>(fn_99_B984),
                             &luigiClassInfoRegistration);
}

__declspec(section ".ctors") extern void (*const luigiGlobalInitializer)() = fn_99_B880;
