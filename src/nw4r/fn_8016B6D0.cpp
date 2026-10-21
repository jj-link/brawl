#pragma force_active on
extern "C" void fn_8016C480(void*, void*);

struct __obj_8016B6D0 {
    char pad[0xC8];
    void* field_C8;
};

extern "C" void fn_8016B6D0(struct __obj_8016B6D0* arg) {
    fn_8016C480(arg->field_C8, arg);
}
