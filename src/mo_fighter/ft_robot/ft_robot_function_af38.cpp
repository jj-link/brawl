#pragma force_active on
extern "C" void fn_120_AF38(void* object, unsigned char value) {
    *(static_cast<unsigned char*>(object) + 0x9ebc) = value;
}
