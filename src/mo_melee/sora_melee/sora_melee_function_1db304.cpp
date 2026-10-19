#pragma force_active on
extern "C" {
void* fn_27_8CB9C();
void fn_27_8D454(void* dst, void* src);

struct fn_27_1DB304_Obj {
    char pad[0x88];
};

void fn_27_1DB304(fn_27_1DB304_Obj* self) {
    void* src = fn_27_8CB9C();
    fn_27_8D454(reinterpret_cast<char*>(self) + 0x88, src);
}
}
