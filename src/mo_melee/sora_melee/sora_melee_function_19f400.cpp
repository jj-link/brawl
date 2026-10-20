#pragma force_active on
extern "C" unsigned int fn_27_19F400(void* param_1) {
    union {
        unsigned int raw;
        struct {
            unsigned int : 12;
            unsigned int field : 1;
            unsigned int : 19;
        } bits;
    } u;
    u.raw = *(unsigned int*)((unsigned char*)param_1 + 8);
    return u.bits.field;
}
