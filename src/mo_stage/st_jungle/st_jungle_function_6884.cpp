#pragma force_active on
struct Member {
    unsigned int storage[2];
};

extern "C" unsigned int* fn_51_6884(Member* base, int index) {
    return &base[index].storage[1] + 2;
}
