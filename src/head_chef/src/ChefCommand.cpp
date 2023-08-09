#include "ChefCommand.h"

ChefCommand::ChefCommand() {
	comm_ = Noop;
}

ChefCommand::ChefCommand(Command comm) {
	comm_ = comm;
}

ChefCommand::ChefCommand(Command comm, double param) {
	comm_ = comm;
	param_ = param;
}
