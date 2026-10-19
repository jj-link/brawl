#pragma force_active on
extern "C" void fn_27_309CC(void*);
extern "C" void fn_80134440(void*, int);

extern "C" void fn_27_30C44(void* arg0, void* arg1) {
    fn_27_309CC(arg0);
    fn_80134440(*reinterpret_cast<void**>(reinterpret_cast<unsigned char*>(arg1) + 4), 0);
}
