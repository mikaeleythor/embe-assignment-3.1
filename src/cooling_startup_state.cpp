#include <context.h>
#include <cooling_ready_state.h>
#include <cooling_startup_state.h>
#include <util/delay.h>

void Cooling_startup_state::on_compressor_running() {
  this->context_->transition_to(new Cooling_ready_state);
}

void Cooling_startup_state::on_do() {};

void Cooling_startup_state::on_entry() {};

void Cooling_startup_state::on_exit() {};

void Cooling_startup_state::on_ok() {};

void Cooling_startup_state::on_failure() {};

void Cooling_startup_state::on_too_hot() {};

void Cooling_startup_state::on_too_cold() {};

void Cooling_startup_state::on_fan_running() {};

void Cooling_startup_state::on_cleared() {};

String Cooling_startup_state::get_name() { return this->name; }
