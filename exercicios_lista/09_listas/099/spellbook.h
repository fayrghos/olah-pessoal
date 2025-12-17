typedef struct {
    int id;
    char nome[50];
    int mana_cost;
} Spell;

typedef struct no {
    Spell spell;
    struct no *proximo;
} No;

typedef struct {
    No *inicio;
} Spellbook;

Spellbook *create_spellbook();

void add_spell(Spellbook *book, int id, const char *name, int mana_cost);

void display_spellbook(Spellbook *book);

void destroy_spellbook(Spellbook *book);