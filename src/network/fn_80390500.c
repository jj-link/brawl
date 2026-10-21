#pragma force_active on
extern int fn_8039037C(void* param);

int fn_80390500(void* self) {
    if (*(int*)((char*)self + 4)) {
        return 0;
    }
    return fn_8039037C((char*)self + 0x30);
}
