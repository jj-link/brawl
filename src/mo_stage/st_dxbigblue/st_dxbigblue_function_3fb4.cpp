#pragma force_active on
extern "C" void fn_81_3FB4(void* self, unsigned char value, unsigned int word, float scalar) {
    unsigned char* bytes = static_cast<unsigned char*>(self);
    bytes[0x184] = value;
    *reinterpret_cast<unsigned int*>(bytes + 0x188) = word;
    *reinterpret_cast<float*>(bytes + 0x18C) = scalar;
}
