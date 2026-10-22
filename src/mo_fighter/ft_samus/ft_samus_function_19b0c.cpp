#pragma force_active on

struct Pair { void* a; void* b; };
struct GlobalRegistration { void* next; void* object; void* destructor; };

struct SamusBlock {
    GlobalRegistration parameterRegistration;
    unsigned char parameterStorage[0x90];
    Pair pair0;
    Pair pair1;
    GlobalRegistration classInfoRegistration;
    unsigned char classInfoStorage[0x18];
};

#pragma push
#pragma opt_propagation off
#pragma scheduling off
extern "C" {
extern SamusBlock lbl_94_bss_210;
void* fn_94_19B90(void*);
void* fn_94_186D4(void*, short);
void* fn_94_19BE4(void*);
void fn_94_19BD8(Pair*, void*, void*);
void __register_global_object(void*, void*, void*);
void* fn_94_19C3C(void*, short);

void fn_94_19B0C() {
    SamusBlock* base = &lbl_94_bss_210;
    GlobalRegistration SamusBlock::* reg = &SamusBlock::parameterRegistration;
    fn_94_19B90(base->parameterStorage);
    __register_global_object(base->parameterStorage, (void*)fn_94_186D4, &(base->*reg));
    fn_94_19BD8(&base->pair0, (void*)0xff, 0);
    fn_94_19BD8(&base->pair1, (void*)0xff, (void*)1);
    fn_94_19BE4(base->classInfoStorage);
    __register_global_object(base->classInfoStorage, (void*)fn_94_19C3C, &base->classInfoRegistration);
}
}
#pragma pop

__declspec(section ".ctors") extern void* const fn_94_19B0C_ctor = (void*)fn_94_19B0C;
