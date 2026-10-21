#pragma force_active on
extern "C" void fn_802DBF08(void* arg0, void* arg1) {
    char* a = (char*)arg0;
    char* b = (char*)arg1;
    int t6 = (int)(a + 0xC);
    int t5 = (int)(a + 0x18);
    int z = 0;
    *(void**)(b + 0x10) = (void*)t6;
    *(int*)(b + 0x14) = t5 - t6;
    *(int*)(b + 0x00) = z;
    *(int*)(b + 0x04) = z;
    *(int*)(b + 0x08) = z;
    *(int*)(b + 0x0C) = z;
    *(int*)(b + 0x00) = *(int*)(a + 0x18);
    *(int*)(b + 0x04) = *(int*)(a + 0x1C);
    *(int*)(b + 0x08) = *(int*)(a + 0x20);
    *(int*)(b + 0x0C) = *(int*)(a + 0x24);
}
