#pragma force_active on
extern "C" {
int fn_8015E680(void* a, void* b);
extern char lbl_805A0193;
extern int lbl_805A018C;
extern char g_AlertFont[];
}

struct FontData {
    static int loadAlertFont(void* p1);
};

int FontData::loadAlertFont(void* p1) {
    int result = fn_8015E680(&g_AlertFont, p1);
    lbl_805A0193 = true;
    lbl_805A018C = 0;
    return result;
}
