#pragma force_active on
struct Box { float x_lo; float y_lo; float x_hi; float y_hi; int id; };
extern void* g_aiMgr;
extern "C" int fn_27_1F2A3C(const float* pos, int id, int mask) {
    unsigned char f;
    unsigned char* base = (unsigned char*)g_aiMgr;
    if (base[0x149] != 0) {
        Box* box = (Box*)(base + 0x14C);
        int i = 0;
        while (i < 24) {
            f = base[0x32C];
            if (f != 0 && (id < 0 || box->id != id) && (mask == 0 || (mask & f) != 0)) {
                float x = pos[0];
                if (!(x > box->x_hi) && !(x < box->x_lo)) {
                    float y = pos[1];
                    if (!(y > box->y_hi) && !(y < box->y_lo)) return 1;
                }
            }
            base++;
            i++;
            box++;
        }
    }
    return 0;
}