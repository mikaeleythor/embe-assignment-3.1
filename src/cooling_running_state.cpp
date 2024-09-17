#include <context.h>
#include <cooling_running_state.h>
#include <failure_state.h>
#include <idle_state.h>

void Cooling_running_state::on_ok() {
  this->context_->transition_to(new Idle_state);
}

void Cooling_running_state::on_failure() {
  this->context_->transition_to(new Failure_state);
}

void Cooling_running_state::on_do() {};

void Cooling_running_state::on_entry() {};

void Cooling_running_state::on_exit() {};

void Cooling_running_state::on_too_hot() {};

void Cooling_running_state::on_too_cold() {};

void Cooling_running_state::on_compressor_running() {};

void Cooling_running_state::on_fan_running() {};

void Cooling_running_state::on_cleared() {};

String Cooling_running_state::get_name() { return this->name; }
