#pragma force_active on
extern "C" int fn_73_39CC(void* obj, int index) {
    int** slot = (int**)((char*)obj + 0x44);
    return (*slot)[index];
}
