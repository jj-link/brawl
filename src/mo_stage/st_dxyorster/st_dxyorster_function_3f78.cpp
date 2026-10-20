#pragma force_active on
extern "C" void fn_76_3F78(void* self) {
    unsigned int* field = reinterpret_cast<unsigned int*>(reinterpret_cast<unsigned char*>(self) + 8);
    *field &= 0xFFFEFFFFu;
}
