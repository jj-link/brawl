#pragma force_active on
extern "C" bool fn_800EB300(const void* self) {
    return *reinterpret_cast<const unsigned int*>(static_cast<const char*>(self) + 0x40) != 0;
}
