#pragma force_active on
extern "C" {
void* fn_105_3710(void*, short);
void __dl__FPv(void*);
void* fn_105_102B8(void* self, short flags);
}

void* fn_105_102B8(void* self, short flags) {
    if (self) {
        if (self && (char*)self + 4 && (char*)self + 0xc && (char*)self + 0x10) {
            fn_105_3710((char*)self + 0x10, 0);
        }
        if (flags > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
