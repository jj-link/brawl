extern "C" int fn_99_10B70(void* object);

// Recover the complete observer from its secondary-interface receiver.
extern "C" int fn_99_10D04(void* object) {
    return fn_99_10B70(static_cast<unsigned char*>(object) - 0x88);
}
