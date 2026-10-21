#pragma force_active on
extern "C" void fn_80294880(void* arg0, float farg0, float farg1) {
    *(float*)((char*)arg0 + 0xc) = farg0 * farg1;
}
