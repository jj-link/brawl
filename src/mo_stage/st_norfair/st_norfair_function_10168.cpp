#pragma force_active on
struct NorfairElement {
    unsigned char data[0x0C];
};

extern "C" NorfairElement* fn_54_10168(NorfairElement* base, int index) {
    return reinterpret_cast<NorfairElement*>(
        reinterpret_cast<char*>(base) + index * 0x90 + 0x0C);
}
