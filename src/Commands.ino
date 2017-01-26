#include "Commands.h"

void Commands::execCommand(CommandEnum command, JsonObject& json) {

  switch (command) {
    case CommandEnum::initStats:
      initStats(json);
    break;
    case CommandEnum::setPin:
      // TODO : function
    break;
    case CommandEnum::setTimer:
      // TODO : function
    break;
    case CommandEnum::NullCommand:
    default:
      // TODO : function
    break;
  }
}


void Commands::initStats(JsonObject& json) {
  if (JsonHelper::isValidInitStatsCommand(json)) {
    if (Stats::initStats(json)) {
      Response::success("Stats Init Done");
    }
    else {
      Response::success("Error in initStats");
    }
  }
  else {
    Response::success("Unvalid Json !");
  }
}
