#pragma force_active on
extern "C" void fn_78_2C9C(void* obj, float x, float y, float z) {
    *(float*)((char*)obj + 0x160) = x;
    *(float*)((char*)obj + 0x164) = y;
    *(float*)((char*)obj + 0x168) = z;
}
