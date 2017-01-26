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
      Response::message(StatusCode::Success, 0);
    }
    else {
      Response::message(StatusCode::Error, 0);
    }
  }
  else {
    Response::message(StatusCode::JsonError, 0);
  }
}
