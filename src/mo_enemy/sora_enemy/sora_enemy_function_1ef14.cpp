#pragma force_active on
extern "C" {

extern void fn_41_1EC18(void*, void*, float, int);

void fn_41_1EF14(void* a, void* b) {
    fn_41_1EC18(a, b, *(float*)((unsigned char*)a + 0x5C), *(int*)((unsigned char*)a + 0x8C));
}

}
