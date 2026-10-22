#pragma force_active on
extern void* fn_8022EFF8(int);
extern void fn_80242908(void*);

int fn_80245B78(void* arg0, unsigned short arg1) {
    char* ptr = (char*)arg0;
    if (ptr == 0) {
        ptr = (char*)fn_8022EFF8(2);
        if (ptr == 0) {
            return 0;
        }
    }
    *(short*)(ptr + 2) = 5;
    *(short*)(ptr + 4) = 0;
    ptr[8] = 6;
    ptr[9] = 8;
    ptr[10] = 2;
    ptr[11] = (char)arg1;
    ptr[12] = (char)(arg1 >> 8);
    fn_80242908((void*)ptr);
    return 1;
}
