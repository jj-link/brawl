#pragma force_active on
extern "C" {
int fn_8018E374(void* p);

int fn_68_2FCC(char* self) {
    if (*(int*)(self + 0xa50) != 0) {
        if (fn_8018E374(self + 0xa50)) {
            return 1;
        }
    }
    return 0;
}
}
