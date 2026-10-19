#pragma force_active on
struct GameOverMenu {
    char pad[0x3F4];
    void* resource;
};

extern "C" {

int fn_1_3E50(void*);
int isLoadFinishMenuSound__6muMenuFv();

int fn_33_B48(const GameOverMenu* self) {
    void* resource = self->resource;
    int result = 0;

    if (fn_1_3E50(resource) && isLoadFinishMenuSound__6muMenuFv()) {
        result = 1;
    }

    return result;
}

}
