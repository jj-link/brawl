#pragma force_active on
struct fn27Owner {
    char pad[0x24];
    signed char* data;
};

extern "C" {
int fn_27_5BC40(fn27Owner* self, int idx) {
    signed char* p = self->data;
    return ((signed char*)(p + ((idx << 2) - idx)))[1];
}
}
