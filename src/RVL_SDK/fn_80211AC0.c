#pragma force_active on
#ifdef __cplusplus
extern "C"
#endif
int fn_80211AC0(int i) {
    union { unsigned int address; int* pointer; } base;
    base.address = 0xCD000000;
    return base.pointer[i];
}
