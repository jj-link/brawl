#pragma force_active on
extern "C" {

void* __dt__16soHeapModuleImplFv(void*, short);
void __dl__FPv(void*);

void* fn_110_4884(void* obj, short param) {
    if (obj) {
        __dt__16soHeapModuleImplFv(obj, -1);
        if (param > 0) {
            __dl__FPv(obj);
        }
    }
    return obj;
}

}
