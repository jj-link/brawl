#pragma force_active on
extern "C" {
void* fn_8009A75C(void* arg0, int arg1, int arg2);

void* fn_8008AC5C(void* arg0, int arg1, int arg2) {
    char* self = (char*)arg0;
    *(void**)(self + 0x0) = 0;
    *(void**)(self + 0x4) = 0;
    *(unsigned char*)(self + 0x8) = 0;
    *(unsigned char*)(self + 0x9) = 0;
    *(unsigned char*)(self + 0xA) = 0;
    *(void**)(self + 0x0) = fn_8009A75C((void*)arg1, 0, 0);
    *(void**)(self + 0x4) = fn_8009A75C((void*)arg2, 0, 0);
    *(unsigned char*)(*(char**)(self + 0x0) + 0x40) = 1;
    *(unsigned char*)(*(char**)(self + 0x4) + 0x40) = 1;
    return arg0;
}
}
