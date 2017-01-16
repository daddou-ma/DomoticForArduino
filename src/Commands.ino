#include <Commands.h>

CommandEnum Commands::getEnum(String command) {

  if (command == "getStats") {
    return getStats;
  }
  else if (command == "setStats") {
    return setStats;
  }
  else if (command == "getPin") {
    return getPin;
  }
  else if (command == "setPin") {
    return setPin;
  }
  else if (command == "setTimer") {
    return setTimer;
  }
  else {
    return NullCommand;
  }
}
