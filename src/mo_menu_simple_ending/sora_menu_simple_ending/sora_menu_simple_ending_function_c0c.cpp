#pragma force_active on
class gfTask;

extern "C" {
void __dt__6gfTaskFv(void*, int);
void __dl__FPv(void*);
}

extern "C" gfTask* fn_19_C0C(gfTask* self, int flag) {
    if (self) {
        __dt__6gfTaskFv(self, 0);
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
