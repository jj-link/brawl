#pragma force_active on
struct Element {
    unsigned int storage[2];
};

extern "C" Element* fn_57_AE5C(Element* array, int index) {
    return reinterpret_cast<Element*>(
        reinterpret_cast<char*>(array) + index * 8 + 12
    );
}
