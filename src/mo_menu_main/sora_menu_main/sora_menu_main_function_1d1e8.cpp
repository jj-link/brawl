#pragma force_active on
struct MenuData {
    unsigned int pad[8];
    unsigned int values[117];
};

extern "C" {
extern void* g_GameGlobal;
unsigned int* fn_8004E5F8(void*);

int fn_2_1D1E8(const void* lhs, const void* rhs) {
    MenuData* data = (MenuData*)fn_8004E5F8(g_GameGlobal);
    int a = *(const int*)lhs;
    int b = *(const int*)rhs;
    unsigned int x = data->values[a];
    unsigned int y = data->values[b];

    if (x != y) {
        if (x < y) return -1;
    } else {
        if (a < b) return -1;
    }
    return 1;
}
}
