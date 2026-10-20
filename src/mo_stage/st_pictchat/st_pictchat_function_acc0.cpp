#pragma force_active on
struct PictChatEntry {
    unsigned char data[0x90];
};

extern "C" void* fn_73_ACC0(PictChatEntry* entries, int index) {
    return entries[index].data + 0x0C;
}
