#pragma force_active on
struct Entry {
    int id;
    int weight;
};

extern "C" int randi__Fl(long);

extern "C" int fn_27_BEB3C(Entry* table, int def) {
    if (table != 0) {
        int r = randi__Fl(100) + 1;
        int sum = 0;
        Entry* p = table;
        while (p->id != -1) {
            sum += p->weight;
            if (r <= sum) {
                return p->id;
            }
            p++;
        }
    }
    return def;
}
