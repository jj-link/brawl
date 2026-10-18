#pragma force_active on
extern "C" {
void __dl__FPv(void*);

void* fn_2_37C(void* obj, int deleting) {
    if (obj && deleting > 0) {
        __dl__FPv(obj);
    }
    return obj;
}
}
