#pragma force_active on
extern "C" void* getInstance__9itManagerFv();
extern "C" void* getItemFromInstanceId__9itManagerFi(void*, int);
extern "C" int fn_27_28CCF0(void*, int);

extern "C" int fn_68_CAF0(void* self) {
    if (*(int*)((char*)self + 0x1a8) == 0) {
        return 0;
    }
    void* mgr = getInstance__9itManagerFv();
    if (mgr == 0) {
        return 0;
    }
    void* item = getItemFromInstanceId__9itManagerFi(mgr, *(int*)((char*)self + 0x1a8));
    if (item == 0) {
        return 0;
    }
    return fn_27_28CCF0(item, 0x10000009) <= 1;
}
