/* Do not remove the headers from this file! see /USAGE for more info. */

#include <mudlib.h>
inherit OBJ;
inherit M_GETTABLE;
inherit M_LOCKABLE;

create()
{
    object::create();
    set_id("key");
    set_adjectives( ({ "small", "shiny" }) );
    set_in_room_desc("A small shiny safe key");

    set_gettable(1);
    set_long("This is a small shiny safe key used to open a safe.\n");
}

mixed key_type()
{
    return "skeleton";
}
