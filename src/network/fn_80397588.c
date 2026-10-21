#pragma force_active on
void fn_80397588(void* self, int value) {
    if (self) {
        *(int*)((char*)self + 0x2C) = value;
    }
}
