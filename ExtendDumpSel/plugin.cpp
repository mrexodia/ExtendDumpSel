#include "plugin.h"

static bool cbCommand(int argc, char* argv[])
{
    if(argc < 2)
        return false;
    auto size = Eval(argv[1]);
    auto start = Script::Gui::Dump::SelectionGetStart();
    Script::Gui::Dump::SelectionSet(start, start + size - 1);
    GuiUpdateAllViews();
    return true;
}

//Initialize your plugin data here.
bool pluginInit(PLUG_INITSTRUCT* initStruct)
{
    if(!_plugin_registercommand(pluginHandle, PLUGIN_NAME, cbCommand, false))
        _plugin_logputs("[" PLUGIN_NAME "] Error registering the \"" PLUGIN_NAME "\" command!");
    return true; //Return false to cancel loading the plugin.
}

//Deinitialize your plugin data here (clearing menus optional).
bool pluginStop()
{
    return true;
}

//Do GUI/Menu related things here.
void pluginSetup()
{
}
