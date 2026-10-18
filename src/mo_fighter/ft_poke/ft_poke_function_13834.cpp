#pragma force_active on
struct FtPokeVector2 { float x; float y; };

extern "C" {
void fn_116_13834(FtPokeVector2* object, float x, float y) {
    object->x = x;
    object->y = y;
}
}
