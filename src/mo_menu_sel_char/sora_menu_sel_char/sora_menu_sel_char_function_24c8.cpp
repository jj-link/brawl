#pragma force_active on
struct CharacterSelection {
    unsigned char prefix[0x44];
    void* entries[1];
};

extern "C" void* fn_10_24C8(CharacterSelection* object, unsigned int index) {
    return object->entries[index];
}
