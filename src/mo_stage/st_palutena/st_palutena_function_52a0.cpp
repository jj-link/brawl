#pragma force_active on
extern "C" void* fn_67_52A0(void* self, int index) {
    int v = ((int*)self)[2] >> 28;
    int i = v + index;
    i = (i >= 6) ? i - 6 : i;
    return (char*)self + (i << 3) + 12;
}
