#pragma force_active on
struct CamData {
    char pad[0x40];
    int x;
    int y;
};

struct CamHolder {
    CamData* arr[16];
};

struct SceneHolder {
    char pad[8];
    CamHolder* holder;
};

extern "C" void fn_1_6D4C(SceneHolder* arg0, int x, int y) {
    CamData* data = arg0->holder->arr[1];
    data->x = x;
    data->y = y;
}
