#include <wn/weapon.h>

namespace {
inline Weapon* articleAt(char* pool, int index) {
    // Four embedded weapon slots follow the article-bank header.
    return reinterpret_cast<Weapon*>(pool + 0x18 + index * 0x1fbc);
}
}

extern "C" Weapon* fn_117_C308(void* pool, int index) {
    char* storage = static_cast<char*>(pool);
    if (index == 3) return articleAt(storage, 3);
    if (index == 2) return articleAt(storage, 2);
    if (index == 1) return articleAt(storage, 1);
    if (index == 0) return articleAt(storage, 0);
    return 0;
}
