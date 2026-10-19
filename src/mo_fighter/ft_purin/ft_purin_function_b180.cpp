#pragma force_active on
extern "C" {
void __ct__21ftExtendParamAccesserF6ftKind(void*, int);
extern char __vt__26ftPurinExtendParamAccesser[];
}

struct ftPurinExtendParamAccesser {
    void* vtable;
    char pad[4];
    void* vtable2;
};

extern "C" ftPurinExtendParamAccesser* __ct__26ftPurinExtendParamAccesserFv(ftPurinExtendParamAccesser* self) {
    __ct__21ftExtendParamAccesserF6ftKind(self, 0x25);
    self->vtable2 = __vt__26ftPurinExtendParamAccesser;
    self->vtable = __vt__26ftPurinExtendParamAccesser + 8;
    return self;
}
