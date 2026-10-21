#pragma force_active on

extern "C" void fn_8004E880(char** ptr) {
    char* data = *ptr;
    *(int*)(data + 0x14) = 0;
    *(char*)(data + 0x18) = 0;
}
