#pragma force_active on
void operator delete(void*);
extern "C" void fn_2_37C(void*, int);
extern "C" void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);

extern "C" void* fn_2_16A60(char* obj, int deleting) {
    if (obj) {
        if (obj) {
            __destroy_arr(obj + 0x48, fn_2_37C, 0xA8, 9);
        }
        if (deleting > 0) {
            operator delete(obj);
        }
    }
    return obj;
}
