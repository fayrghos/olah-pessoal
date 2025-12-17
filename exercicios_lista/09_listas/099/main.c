#include "spellbook.h"

int main() {
    Spellbook *grimorio = create_spellbook();

    add_spell(grimorio, 1, "Aaa", 10);
    add_spell(grimorio, 2, "Bbb", 20);
    add_spell(grimorio, 3, "Ccc", 30);

    display_spellbook(grimorio);

    destroy_spellbook(grimorio);

    return 0;
}