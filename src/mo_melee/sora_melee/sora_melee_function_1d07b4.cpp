#pragma force_active on
extern "C" {

int fn_27_1D07B4(void* p) {
    int val = *(int*)((char*)p + 8);
    return (val >> 19) & 1;
}

}
