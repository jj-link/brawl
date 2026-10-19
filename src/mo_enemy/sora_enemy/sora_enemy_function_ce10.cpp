#pragma force_active on
extern "C" int* fn_41_CD5C(int* obj, int index);

extern "C" {
int fn_41_CE10(int* obj) {
    unsigned int i;
    for (i = 0; i < (unsigned int)obj[0]; i++) {
        int* entry = fn_41_CD5C(obj, (int)i);
        if (entry != 0 && *(unsigned char*)entry == 0) {
            return (int)i;
        }
    }
    return -1;
}
}
