#pragma force_active on

extern "C" int fn_80331494(void* arg0, int arg1, int arg2) {
    int* p = *(int**)((char*)arg0 + 0x14);
    char* v = (char*)p[arg1];
    if (v != 0) {
        return (int)(v + arg2);
    }
    return 0;
}
