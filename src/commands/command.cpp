
#include "../../include/commands/command.h"

Command::Command(CommandImpl *command) : bridge(command) {}

bool Command::execute() const { return bridge->execute(); }
