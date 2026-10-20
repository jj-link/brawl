#pragma force_active on
extern "C" {

void __dt__6gfTaskFv(void*, int);
void __dl__FPv(void*);

void* fn_27_23AB44(void* object, int deleting) {
    if (object) {
        __dt__6gfTaskFv(object, 0);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}

}
