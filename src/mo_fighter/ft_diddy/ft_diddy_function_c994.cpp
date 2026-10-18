#pragma force_active on
struct Pair { unsigned int x; unsigned int y; };
struct Wrapper { unsigned int pad[2]; Pair pair; };
extern "C" Pair fn_115_C994(const Wrapper* object) {
    return object->pair;
}
