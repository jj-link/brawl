#pragma force_active on
typedef struct FieldWord
{
    unsigned int top : 4;
    unsigned int rest : 28;
} FieldWord;

typedef struct Holder
{
    int pad0;
    int pad1;
    FieldWord word;
} Holder;

extern "C" void fn_68_D754(Holder *p, unsigned int v)
{
    p->word.top = v;
}
