/* Do not remove the headers from this file! see /USAGE for more info. */

#include <mudlib.h>

inherit CMD;
inherit M_INPUT;


private nomask void handle_piping(string verb, string arg)
{
    if( arg == "**" || arg == "." )
    {
	write("Done.\n");
        modal_pop();
	return;
    }

    this_user()->force_me(sprintf("%s %s", verb, arg));
}

private nomask void main(mixed * arg)
{
    write("Entering pipe mode. Type '**' to quit.\n");
    modal_push((: handle_piping, arg[0] :), "*\b");
}
