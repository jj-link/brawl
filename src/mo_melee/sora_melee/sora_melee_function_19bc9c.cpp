#pragma force_active on
extern "C" {
void __dt__18soModelVirtualNodeFv(void*, int);
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void __dl__FPv(void*);

void* fn_27_19BC9C(void* obj, int flag) {
    if (obj) {
        __destroy_arr((char*)obj + 0xC, __dt__18soModelVirtualNodeFv, 0x14, 1);
        if (flag > 0) {
            __dl__FPv(obj);
        }
    }
    return obj;
}
}
