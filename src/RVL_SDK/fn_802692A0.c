#pragma force_active on
void fn_802692A0(void* in, int* out) {
    int a = *(int*)in;
    int b = *(int*)((char*)in + 4);
    int c = *(int*)((char*)in + 0x14);
    *out = c + (b - a);
}
