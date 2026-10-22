#pragma force_active on
extern "C" void fn_801AB038(void*, int);
extern "C" void fn_801AB0B8(void*, int);
extern "C" char lbl_8045C30C[];

extern "C" void* fn_800FB65C(void* arg0, void* arg1, float farg0, float farg1) {
    char* obj = static_cast<char*>(arg0);
    char* owner = static_cast<char*>(arg1);
    void* temp_r31;

    *(float*)(obj + 0x4) = farg0;
    *(char**)(obj + 0x0) = lbl_8045C30C;
    *(float*)(obj + 0x8) = farg1;
    temp_r31 = *(void**)(owner + 0x10);
    *(void**)((char*)temp_r31 + 0xD4) = arg0;
    fn_801AB038(temp_r31, 1);
    fn_801AB038(temp_r31, 4);
    fn_801AB0B8(temp_r31, 0x10);
    fn_801AB0B8(temp_r31, 0x20);
    return arg0;
}
