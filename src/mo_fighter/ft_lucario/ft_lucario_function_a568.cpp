#pragma force_active on
struct Table { unsigned int words[1]; };
struct Pair { unsigned int first[3]; Table* table; };

extern "C" unsigned int fn_118_A568(Pair* r3, int r4)
{
    return r3->table->words[r4];
}
