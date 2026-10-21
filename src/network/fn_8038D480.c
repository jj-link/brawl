#pragma force_active on
typedef unsigned int size_t;

void* memcpy(void*, const void*, size_t);

void fn_8038D480(char* arg0, int arg1, void* arg2) {
    *(int*)(arg0 + 0x28) = arg1;
    memcpy(arg0 + 0x2C, arg2, 0x19);
    *(int*)(arg0 + 0x24) = 1;
}
