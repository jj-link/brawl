#pragma force_active on
extern "C" void fn_27_198524(void*, int, int);
extern "C" void fn_27_68888(void*, void*, void*, void*);

extern "C" void* fn_99_6CA0(void* object, void* arg1, void* arg2) {
    fn_27_198524(object, 4, 0);
    fn_27_68888(static_cast<char*>(object) + 0x7c, arg1, object, arg2);
    return object;
}
