/* Do not remove the headers from this file! see /USAGE for more info. */

#include <mudlib.h>
#include <bodyslots.h>

inherit OBJ;
inherit M_GETTABLE;
inherit M_WEARABLE;
inherit M_VALUABLE;

void setup() {
    set_adj("red");
    set_id("scarf");
#ifdef USE_BODYSLOTS
    set_slot(TORSO);
#endif
    set_value(10);
}
