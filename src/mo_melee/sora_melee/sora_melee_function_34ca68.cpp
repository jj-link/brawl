#pragma force_active on
extern "C" void fn_27_34CF20(void*, void*);
extern "C" void fn_27_BEB00(void*);

extern "C" void fn_27_34CA68(void* object, void* arg) {
    fn_27_34CF20(arg, static_cast<char*>(object) + 4);
    fn_27_BEB00(static_cast<char*>(object) + 0x14);
}
