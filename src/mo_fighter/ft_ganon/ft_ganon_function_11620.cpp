#pragma force_active on
extern "C" {

void __dl__FPv(void*);

void* fn_109_11620(void* self, short n) {
    if (self != 0) {
        if (n > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}

}
